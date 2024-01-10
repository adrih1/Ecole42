/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:58:14 by ahors             #+#    #+#             */
/*   Updated: 2024/01/10 11:32:53 by adrienhors       ###   ########.fr       */
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
#include <limits.h>
#include <unistd.h>


/*
---------------------------------------------------------------------------------
|                                    FONCTIONS                                  |
---------------------------------------------------------------------------------
*/

typedef struct s_stack_node
{
	int	nbr;
	int	index;
	int	push_cost;
	bool	above_median;
	bool	cheapest;
	
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
} t_stack_node;

//Commands
//Push
void	push(t_stack_node **dst, t_stack_node **src);
void	pa(t_stack_node **a, t_stack_node **b, bool print);
void	pb(t_stack_node **b, t_stack_node **a, bool print);
//Rotate
static void	rotate(t_stack_node **stack);
void	ra(t_stack_node **a, bool print);
void	rb(t_stack_node **b, bool print);
void	rr(t_stack_node **a, t_stack_node **b, bool print);

//Handle Errors
int 	ft_error_syntax(char *argv);
int		ft_error_duplicate(t_stack_node *a, int n);
void	ft_free_errors(t_stack_node **a);

//Stack Initiation
void    ft_init_stack(t_stack_node **a, char **argv);
int		ft_atoi(char *str);

//Nodes Initiation 
void    ft_init_nodes_a(t_stack_node *a, t_stack_node *b);
void    ft_current_index(t_stack_node *stack); 
void    ft_set_target_a(t_stack_node *a, t_stack_node *b); 
void    ft_set_target_b(t_stack_node *a, t_stack_node *b); 
void    ft_cost_analaysis(t_stack_node  *a, t_stack_node *b);
void    ft_set_cheapest(t_stack_node *stack); 

//Nodes Append
void    ft_append_node(t_stack_node **stack, int n);

//Cost Analysis
void    ft_cost_analaysis(t_stack_node  *a, t_stack_node *b);

//Find Tools
int ft_stack_len(t_stack_node *stack);
t_stack_node    ft_find_last_node(t_stack_node *stack);
t_stack_node	*ft_find_max(t_stack_node *stack);
t_stack_node	*ft_find_min(t_stack_node *stack);
t_stack_node    ft_get_cheapest(t_stack_node *stack);

//Stack utils
char	**ft_split(char const *s, char c);
bool    ft_stack_sorted(t_stack_node *stack);

//Sort
void    ft_sort_three(t_stack_node **a);
void    ft_sort_stacks(t_stack_node **a, t_stack_node **b);

//Rotate
void    ft_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node); 

#endif
