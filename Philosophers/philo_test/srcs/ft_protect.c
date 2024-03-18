#include "../header/philo.h"

void	*ft_safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if(!ret)
		ft_error_exit("Error with the malloc");
	return(ret);
}


 