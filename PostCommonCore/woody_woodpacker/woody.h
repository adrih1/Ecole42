typedef struct s_woody {
    uint64_t cave_offset; // Physical Position physique in the file
    uint64_t cave_vaddr;  // Virtual address for the CPU
    uint64_t old_entry;   // Original entry point 
} t_woody;
