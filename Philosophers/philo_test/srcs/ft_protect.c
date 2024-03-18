#include "../header/philo.h"

void	*ft_safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if(!ret)
		ft_error_exit("Error with the malloc");
	return(ret);
}

void	ft_safe_mutex_handle(t_mtx *mutex, t_opcode opcode)
{
	if(LOCK == opcode)
		pthread_mutex_lock(mutex);
	else if(UNLOCK == opcode)
		pthread_mutex_unlock(mutex);
	else if(INIT == opcode)
		pthread_mutex_init(mutex, NULL);
	else if(DESTROY == opcode)
		pthread_mutex_destroy(mutex);
	else 
		ft_error_exit("Wrong opcode for mutex handle");
}

 