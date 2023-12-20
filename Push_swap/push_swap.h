/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:58:14 by ahors             #+#    #+#             */
/*   Updated: 2023/12/19 18:30:42 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
/*
---------------------------------------------------------------------------------
|                                    LIBRAIRIE                                  |
---------------------------------------------------------------------------------
*/

#include <stddef.h>
#include <stdbool.h>


/*
---------------------------------------------------------------------------------
|                                    FONCTIONS                                  |
---------------------------------------------------------------------------------
*/

// Partie Bonus
typedef struct s_stack_node
{
	int	nbr;
	int	index;
	int	push_cost;
	bool	above_median;
	bool	cheapest;
	
	struct pile	*target_node;
	struct pile	*next;
	struct pile	*prev;
} t_stack_node;

//Handle Errors

//Stack initiation
void    ft_init_stack(t_stack_node **c, char **argv);

//Nodes initiation


//Stack utils
char	**ft_split(char const *s, char c);

//Commands

//Algorithms

#endif
