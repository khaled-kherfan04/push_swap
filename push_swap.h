/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkharfan <kkharfan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:08:25 by kkharfan          #+#    #+#             */
/*   Updated: 2026/01/08 18:10:42 by kkharfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/ft_printf.h"
# include <limits.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/* ************************************************************************** */
/*                              STRUCTURES                                    */
/* ************************************************************************** */

// Node structure for linked list stack
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

// Stack structure
typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

// Operation counter structure
typedef struct s_opcounts
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
}					t_opcounts;

// Strategy enumeration
typedef enum e_strategy
{
	Simple,
	Medium,
	Complex,
	Adaptive
}					t_strategy;

/* ************************************************************************** */
/*                          PARSING FUNCTIONS                                 */
/* ************************************************************************** */

// Parse arguments and create stack
t_stack				*parse_arg(int argc, char **argv);

// Parse strategy from command line
t_strategy			parse_strategy(int argc, char **argv);

// Check if benchmark mode is enabled
int					is_bench_mode(int argc, char **argv);

int					check_duplicates(t_stack *st);

// Safe string to integer conversion
long				ft_atoi(const char *str, int *error);

// Error handling
void				print_error(void);

/* ************************************************************************** */
/*                          STACK UTILITY FUNCTIONS                           */
/* ************************************************************************** */

// Stack creation and destruction
t_stack				*stack_new(void);
void				stack_free(t_stack *stack);

// Stack basic operations
void				stack_push(t_stack *stack, int value);
int					stack_pop(t_stack *stack);
int					stack_peek(t_stack *stack);

// Stack information
int					stack_is_empty(t_stack *stack);
int					stack_is_sorted(t_stack *stack);
int					stack_size(t_stack *stack);

// Stack search operations
int					stack_get_min(t_stack *stack);
int					stack_get_max(t_stack *stack);
int					stack_get_at(t_stack *stack, int pos);
int					stack_find_position(t_stack *stack, int value);

// Stack utility
void				stack_print(t_stack *stack, char *name);

/* ************************************************************************** */
/*                          PUSH_SWAP OPERATIONS                              */
/* ************************************************************************** */

// Swap operations
void				sa(t_stack *a, t_opcounts *ops);
void				sb(t_stack *b, t_opcounts *ops);
void				ss(t_stack *a, t_stack *b, t_opcounts *ops);

// Push operations
void				pa(t_stack *a, t_stack *b, t_opcounts *ops);
void				pb(t_stack *a, t_stack *b, t_opcounts *ops);

// Rotate operations
void				ra(t_stack *a, t_opcounts *ops);
void				rb(t_stack *b, t_opcounts *ops);
void				rr(t_stack *a, t_stack *b, t_opcounts *ops);

// Reverse rotate operations
void				rra(t_stack *a, t_opcounts *ops);
void				rrb(t_stack *b, t_opcounts *ops);
void				rrr(t_stack *a, t_stack *b, t_opcounts *ops);

/* ************************************************************************** */
/*                          DISORDER FUNCTIONS                                */
/* ************************************************************************** */

// Calculate disorder metric (0.0 to 1.0)
double				compute_disorder(t_stack *stack);

// Get disorder category string
char				*get_disorder_category(double disorder);

// Print disorder information
void				print_disorder_info(t_stack *stack);

/* ************************************************************************** */
/*                          SORTING ALGORITHMS                                */
/* ************************************************************************** */

// Simple O(n²) sorting
void				sort_simple(t_stack *a, t_stack *b, t_opcounts *ops);
void				sort_three(t_stack *a, t_opcounts *ops);
void				sort_five(t_stack *a, t_stack *b, t_opcounts *ops);

// Simple sort helpers
void				push_min_to_b(t_stack *a, t_stack *b, t_opcounts *ops);
int					find_min_position(t_stack *stack);

// Medium O(n√n) sorting
void				sort_medium(t_stack *a, t_stack *b, t_opcounts *ops);
void				create_chunks(t_stack *stack, int num_chunks);
void				sort_by_chunks(t_stack *a, t_stack *b, t_opcounts *ops);
int					get_chunk_size(int stack_size);
void				assign_indices(t_stack *a);

// Complex O(n log n) sorting
// static int      count_bits(int max);
// static int      get_bit(int num, int position);
void				sort_complex(t_stack *a, t_stack *b, t_opcounts *ops);

// Adaptive sorting
void				sort_adaptive(t_stack *a, t_stack *b, t_opcounts *ops);
void				select_strategy(t_stack *a, t_stack *b, t_opcounts *ops,
						double disorder);

/* ************************************************************************** */
/*                          BENCHMARK FUNCTIONS                               */
/* ************************************************************************** */

// Print benchmark information
void				print_benchmark(t_opcounts *ops, double disorder,
						t_strategy strategy);

// Get strategy name
char				*get_strategy_name(t_strategy strategy);

// Get complexity string
char				*get_complexity_string(t_strategy strategy);

#endif
