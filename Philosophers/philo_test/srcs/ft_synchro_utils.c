#include "../header/philo.h"

void     ft_wait_all_threads(t_program *program)
{
    while (!ft_get_bool(&program->program_mtx, &program->all_threads_ready))
        ;
}

// Mintor waits until all threads are not running 

bool    ft_all_threads_running()
{
    
}