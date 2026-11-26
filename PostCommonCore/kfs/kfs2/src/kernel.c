#include "terminal.h"
#include "tty.h"
#include "gdt.h"

#define SHELL_LINE_MAX 64

extern uint32_t stack_top[]; // boot.s: highest address of the kernel stack

/**
 * Print the kernel stack from ESP (top of the stack) up to stack_top.
 * One 32-bit word per line: address: value. Limited to 16 lines.
 */
void print_kernel_stack(void)
{
    uint32_t *esp;

    asm volatile("mov %%esp, %0" : "=r"(esp)); // Read the ESP register
    printk("Kernel stack: esp=%x top=%x (%d bytes used)\n",
           (uint32_t)esp, (uint32_t)stack_top, (int)((stack_top - esp) * 4));
    for (int i = 0; esp + i < stack_top && i < 16; i++)
        printk("  %x: %x\n", (uint32_t)(esp + i), esp[i]);
}

static int str_eq(const char *a, const char *b)
{
    while (*a && *a == *b) {
        a++;
        b++;
    }
    return *a == *b;
}

/**
 * Bonus: run one shell command.
 */
static void shell_exec(const char *cmd)
{
    if (str_eq(cmd, "help"))
        printk("Commands: help, stack, clear, reboot, halt\n");
    else if (str_eq(cmd, "stack"))
        print_kernel_stack();
    else if (str_eq(cmd, "clear"))
        terminal_initialize();
    else if (str_eq(cmd, "reboot")) {
        while (inb(0x64) & 0x02) {} // Wait until the keyboard controller is ready
        outb(0x64, 0xFE);           // Ask it to pulse the CPU reset line
    }
    else if (str_eq(cmd, "halt")) {
        printk("System halted.\n");
        while (1)
            asm volatile("cli; hlt"); // No interrupts: the CPU sleeps forever
    }
    else if (cmd[0])
        printk("Unknown command: %s\n", cmd);
}

void kernel_main(void) {
    char line[SHELL_LINE_MAX]; // Shell: current command line
    int len = 0;

    gdt_init(); // Load our GDT at 0x800 before anything else
    terminal_initialize();
    tty_init(); // Initialize screens buffers

    terminal_setcolor(VGA_COLOR_CYAN, VGA_COLOR_BLACK);
    printk("KFS-2 Kernel loaded successfully !\n");

    terminal_setcolor(VGA_COLOR_LIGHT_RED, VGA_COLOR_BLACK);
    printk("42\n");

    terminal_setcolor(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
    printk("Kernel Loaded. Use F1, F2, F3 to switch screens.\n");
    print_kernel_stack();
    printk("Type 'help' for commands.\n> ");

    while (1) {

        // 0x64 is the status
        // 0x60 is the data port 
        if (inb(0x64) & 0x01) // receive a byte --> & 0x01 looks at the Bit 0 (output buffer full --> A key has been pressed) 
        { 
            uint8_t scancode = inb(0x60);
            
            if (scancode == 0x3B) 
                tty_switch(0);  // F1
            else if (scancode == 0x3C) 
                tty_switch(1);  // F2
            else if (scancode == 0x3D) 
                tty_switch(2);  // F3
            else if (scancode < 0x80) {
                char c = g_kbd_qwerty[scancode];

                if (c == '\n') {                // Enter: run the line
                    terminal_putchar('\n');
                    line[len] = '\0';
                    shell_exec(line);
                    len = 0;
                    printk("> ");
                } else if (c == '\b') {         // Backspace: erase one char
                    if (len > 0) {
                        len--;
                        terminal_putchar('\b');
                    }
                } else if (c >= ' ' && len < SHELL_LINE_MAX - 1) { // Printable char
                    line[len++] = c;
                    terminal_putchar(c);
                }
            }
        }
    }
}
