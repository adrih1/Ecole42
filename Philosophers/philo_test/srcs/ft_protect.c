#include "../header/philo.h"

void	*ft_safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if(!ret)
		ft_error_exit("Error with the malloc");
	return(ret);
}


//MUTEX
//Toutes les fonctions mutex retournent 0 si elles sont correctes.  Nous gérons ici les retours de erno (EINVAL, et autres)
//Mutex Error Handle 
void	ft_mutex_error_handle(int status, t_opcode opcode)
{
	if (0 == status)
		return;
	if(EINVAL == status && (LOCK == opcode || UNLOCK == opcode || DESTROY == opcode))
		ft_error_exit("The value specified by mutex is invalid.\n");
	else if (EINVAL == status && INIT == opcode)
		ft_error_exit("The value specified by attr is invalid.\n");
	else if (EDEADLK == status)
		ft_error_exit("A deadlock would occur if the thread blocked waiting for mutex .\n");
	else if (EPERM  == status)
		ft_error_exit("The current thread does not hold a lock on mutex.\n");
	else if (ENOMEM  == status)
		ft_error_exit("The process cannot allocate enough memory to create another mutex.\n");
	else if (EBUSY  == status)
		ft_error_exit("Mutex is locked.\n");
}
 
// Mutex  Safe
void	ft_safe_mutex_handle(t_mtx *mutex, t_opcode opcode)
{
	if (LOCK == opcode)
		ft_mutex_error_handle(pthread_mutex_lock(mutex), opcode); 
	else if (UNLOCK == opcode)
		ft_mutex_error_handle(pthread_mutex_unlock(mutex), opcode); 
	else if (INIT == opcode)
		ft_mutex_error_handle(pthread_mutex_init(mutex, NULL), opcode); 
	else if (DESTROY == opcode)
		ft_mutex_error_handle(pthread_mutex_destroy(mutex), opcode); 
	else
		ft_error_exit("Wrong opcode for mutex handle");
}



// THREADS
// Thread Error Handle 
static void	ft_thread_error_handle(int status, t_opcode opcode)
{
	if (0 == status)
		return ;
	if (EAGAIN == status)
		error_exit("No resources to create another thread");
	else if (EPERM == status)
		error_exit("The caller does not have appropriate permission\n");
	else if (EINVAL == status && CREATE == opcode)
		error_exit("The value specified by attr is invalid.");
	else if (EINVAL == status && (JOIN == opcode || DETACH == opcode))
		error_exit("The value specified by thread is not joinable\n");
	else if (ESRCH == status)
		error_exit("No thread could be found corresponding to that"
			"specified by the given thread ID, thread.");
	else if (EDEADLK == status)
		error_exit("A deadlock was detected or the value of"
			"thread specifies the calling thread.");
}



// Thread Safe
void	ft_safe_thread_handle(pthread_t *thread, void *(* foo)(void *), void *data, t_opcode opcode)
{
	if (CREATE == opcode)
		ft_thread_error_handle(pthread_create(thread, NULL, foo, data), opcode);
	else if (JOIN == opcode)
		ft_thread_error_handle(pthread_join(*thread, NULL), opcode);
	else if (DETACH == opcode)
		ft_thread_error_handle(pthread_detach(*thread), opcode);
	else
		ft_error_exit("Wrong opcode for thread handle.\n Use CREATE, JOIN or DETACH.");
}