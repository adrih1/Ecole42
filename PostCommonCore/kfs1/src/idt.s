global load_idt
global irq1_handler  ; IRQ1 est l'interruption du clavier
extern keyboard_handler_main

load_idt:
    mov eax, [esp + 4]    ; Récupère le pointeur vers idt_ptr
    lidt [eax]            ; Charge l'IDT dans le processeur
    ret

irq1_handler:
    pushad                ; Sauvegarde tous les registres (EAX, EBX, etc.)
    call keyboard_handler_main
    popad                 ; Restaure les registres
    iretd                 ; Instruction magique pour "Interruption Return"