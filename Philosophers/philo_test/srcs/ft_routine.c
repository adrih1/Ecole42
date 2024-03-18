#include "../header/philo.h"

long    meals_eaten = 0; 
pthread_mutex_t mutex; 

void *routine()
{
    pthread_mutex_lock(&mutex);
    meals_eaten++;
    pthread_mutex_unlock(&mutex);
    return (NULL);
}


int main(int ac, char **av)
{
    int i; 
    
    i = 0;
    pthread_t philos[10];
    pthread_mutex_init(&mutex, NULL);
    while (i < 10)
    {
        printf("Starting thread %d\n", i);
        if(pthread_create(&philos[i], NULL, &routine, NULL) != 0)
            return (1);
        i++;
    }
    i = 0; 
    while (i < 10)
    {
        printf("Finishing thread %d\n", i);
        if(pthread_join(philos[i], NULL) != 0)
            return (2);
        i++;
    }
    pthread_mutex_destroy(&mutex);
    printf("Meals Eaten %ld\n", meals_eaten);
    return(0);
}