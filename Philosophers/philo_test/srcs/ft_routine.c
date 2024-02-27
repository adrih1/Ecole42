#include "../header/philo.h"

long    meals_eaten; 
pthread_mutex_t mutex; 


void *routine()
{

    pthread_mutex_lock(&mutex);
    meals_eaten++;
    pthread_mutex_unlock(&mutex);
}


int main()
{
    int i; 
    
    i = 0;
    pthread_t philos[10];
    pthread_mutex_init(&mutex, NULL);
    while (i < 10)
    {
        if(pthread_create(&philos[i], NULL, &routine, NULL) != 0)
            return (1);
    }
    i = 0; 
    while (i < 10)
    {
        if(pthread_join(philos[i], NULL) != 0)
            return (2);
    }
    pthread_mutex_destroy(&mutex);
    return(0);
}