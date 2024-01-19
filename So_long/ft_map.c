#include "so_long.h"


void ft_free_map(t_map *map)
{
    int i;

    i = 0;
    while (i < map->height)
    {
        free(map->grid[i]);
        i++;
    }
    free(map->grid);
}


// Fonction pour vérifier la validité de la carte
int ft_validate_map(const t_map *map, const t_map_info *map_info)
{
    // Implémentez les vérifications de la carte selon vos critères
    // Renvoyez 1 si la carte est valide, 0 sinon
}


// Fonction pour parser la carte
int ft_parse_map(const char *file, t_map *map, t_map_info *map_info)
{
    int i;

    
    i = 0;
    while (file)
    {
        map->grid[i] = get_next_line(file); 
        // Ici on peut vérifier que il y a toujours un seul P et un seul E 
        i++; 
    }
    // Ici on vérifie que le carte ait bien des murs tout autour
}



int ft_parse_map(const char *file, t_map *map, t_map_info *map_info)
{
    int i = 0;
    char *line;

    // Récupèrer la height de la map (nombre de lignes)

    // Allouez l'espace pour map->grid
    map->grid = (char **)malloc(map->height * sizeof(char *));
    if (!map->grid)
        return 0;

    while ((line = get_next_line(file)) != NULL)
    {
        // Allouez l'espace pour chaque ligne
        map->grid[i] = strdup(line);
        free(line);  // Libérez la mémoire allouée par get_next_line
        if (!map->grid[i])
            return 0;

        // Ajoutez la logique pour compter les P et E
        i++;
    }

    // Ajoutez la logique pour vérifier qu'il y a exactement un P et un E


    // Ajoutez la logique pour vérifier les murs tout autour


    return 1; 
}
