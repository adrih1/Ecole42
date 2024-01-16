/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:58:14 by ahors             #+#    #+#             */
/*   Updated: 2024/01/16 14:37:25 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
/*
---------------------------------------------------------------------------------
|                                    LIBRAIRIE                                  |
---------------------------------------------------------------------------------
*/

# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*
---------------------------------------------------------------------------------
|                                    FONCTIONS                                  |
---------------------------------------------------------------------------------
*/

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;

	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// Commands
void					sa(t_stack_node **a, bool print);
void					sb(t_stack_node **b, bool print);
void					ss(t_stack_node **a, t_stack_node **b, bool print);
void					ra(t_stack_node **a, bool print);
void					rb(t_stack_node **b, bool print);
void					rr(t_stack_node **a, t_stack_node **b, bool print);
void					rra(t_stack_node **a, bool print);
void					rrb(t_stack_node **b, bool print);
void					rrr(t_stack_node **a, t_stack_node **b, bool print);
void					pa(t_stack_node **a, t_stack_node **b, bool print);
void					pb(t_stack_node **b, t_stack_node **a, bool print);

// Commands Bis
void					ft_rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);
void					ft_rev_rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);

// Sort
void					ft_sort_three(t_stack_node **a);
void					ft_sort_stacks(t_stack_node **a, t_stack_node **b);

// Handle Errors
int						ft_error_syntax(char *argv);
int						ft_error_duplicate(t_stack_node *a, int n);
void					ft_free_errors(t_stack_node **a);
void					ft_free_stack(t_stack_node **stack);

// Stack Initiation
void					ft_init_stack(t_stack_node **a, char **argv);
void					ft_append_node(t_stack_node **stack, int n);
int						ft_atoi(char *str);

// Nodes Initiation
void					ft_init_nodes_a(t_stack_node *a, t_stack_node *b);
void					ft_init_nodes_b(t_stack_node *a, t_stack_node *b);
void					ft_current_index(t_stack_node *stack);
void					ft_set_target_a(t_stack_node *a, t_stack_node *b);
void					ft_set_target_b(t_stack_node *a, t_stack_node *b);
void					ft_cost_analysis(t_stack_node *a, t_stack_node *b);
void					ft_set_cheapest(t_stack_node *stack);
t_stack_node			*ft_get_cheapest(t_stack_node *stack);
void					ft_prep_for_push(t_stack_node **s, t_stack_node *n,
							char c);

// Cost Analysis
void					ft_cost_analysis(t_stack_node *a, t_stack_node *b);

// Find Tools
t_stack_node			*ft_find_last_node(t_stack_node *stack);
t_stack_node			*ft_find_max(t_stack_node *stack);
t_stack_node			*ft_find_min(t_stack_node *stack);

// Stack utils
char					**ft_split(char const *s, char c);
bool					ft_stack_sorted(t_stack_node *stack);
int						ft_stack_len(t_stack_node *stack);

// Other Utils
int						ft_strlen(char *str);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);

#endif
