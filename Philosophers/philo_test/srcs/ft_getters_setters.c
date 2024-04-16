#include "../header/philo.h"

// Small File to avoid writing LOCK UNLOCK everywhere


//BOOLEANS
void    ft_set_bool(t_mtx *mutex, bool *dest, bool value)
{
    ft_safe_mutex_handle(mutex, LOCK);
    *dest = value;
    ft_safe_mutex_handle(mutex, UNLOCK);
}

bool    ft_get_bool(t_mtx *mutex, bool *value)
{
    bool    ret; 
    
    ft_safe_mutex_handle(mutex, LOCK);
    ret = *value;
    ft_safe_mutex_handle(mutex, UNLOCK);
    return(ret);
}


//LONGS
void    ft_set_long(t_mtx *mutex, long *dest, long value)
{
    ft_safe_mutex_handle(mutex, LOCK);
    *dest = value;
    ft_safe_mutex_handle(mutex, UNLOCK);
}
 
bool    ft_get_long(t_mtx *mutex, long *value)
{
    long    ret; 
    
    ft_safe_mutex_handle(mutex, LOCK);
    ret = *value;
    ft_safe_mutex_handle(mutex, UNLOCK);
    return(ret);
}


//Simulation Finished 
bool    ft_simulation_finished(t_program *program)
{
    return (ft_get_bool(&program->program_mtx, &program->end_simulation));
}