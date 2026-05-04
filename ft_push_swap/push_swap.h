/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okahrama <okahrama@student.42istanbul.c>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:47:13 by okahrama          #+#    #+#             */
/*   Updated: 2026/04/26 16:40:22 by okahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_ps_list
{
	int					content;
	int					index;
	struct s_ps_list	*next;
}						t_ps_node;

typedef struct s_counts
{
	int					sa;
	int					sb;
	int					ss;
	int					pa;
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
	int					total;
	int					strategy;
	int					adaptive_strategy;
	int					size;
	int					numb_size;
	int					alg_numb;
	float				disorder;
}						t_count;

typedef struct s_medium
{
	int					chunk_size;
	int					chunk_count;
	int					chunk_min;
	int					chunk_max;
	int					chunk_mid;
	int					full_size;
}						t_medium;

void					push_swap(int argc, char **argv);

int						dup_number(t_ps_node *new_list);
int						ft_atoi(const char *nptr);
t_ps_node				*new_node(int content);
int						ft_lstsize(t_ps_node *lst);
void					ft_lstadd_back(t_ps_node **lst, t_ps_node *new);
void					ft_lstadd_front(t_ps_node **lst, t_ps_node *new);
t_ps_node				*ft_lstlast(t_ps_node *lst);
t_ps_node				*parse_control(int argc, char **argv, t_count *counter);
int						control(char *nptr);
size_t					countword(const char *s, char c);
size_t					word_len(const char *s, char c);
void					free_all(char **arr, size_t j);
char					**arrmaker(const char *s, char c, char **arr);
char					**ft_split(const char *s, char c);

int						is_sorted(t_ps_node *list);

void					ps_sb(t_ps_node **list);
void					sb(t_ps_node **list, t_count *counter);

void					ps_sa(t_ps_node **list);
void					sa(t_ps_node **list, t_count *counter);

void					ps_ss(t_ps_node **list_a, t_ps_node **list_b);
void					ss(t_ps_node **list_a, t_ps_node **list_b,
							t_count *counter);

void					ps_patob(t_ps_node **list_b, t_ps_node **list_a);
void					patob(t_ps_node **list_b, t_ps_node **list_a,
							t_count *counter);

void					ps_pbtoa(t_ps_node **list_a, t_ps_node **list_b);
void					pbtoa(t_ps_node **list_a, t_ps_node **list_b,
							t_count *counter);

void					ps_ra(t_ps_node **list_a);
void					ra(t_ps_node **list_a, t_count *counter);

void					ps_rb(t_ps_node **list_b);
void					rb(t_ps_node **list_b, t_count *counter);

void					ps_rr(t_ps_node **list_b, t_ps_node **list_a);
void					rr(t_ps_node **list_b, t_ps_node **list_a,
							t_count *counter);

void					ps_rra(t_ps_node **list_a);
void					rra(t_ps_node **list_a, t_count *counter);

void					ps_rrb(t_ps_node **list_b);
void					rrb(t_ps_node **list_b, t_count *counter);

void					ps_rrr(t_ps_node **list_b, t_ps_node **list_a);
void					rrr(t_ps_node **list_b, t_ps_node **list_a,
							t_count *counter);

t_ps_node				*take_first(t_ps_node **list);

void					selection_sort(t_ps_node **list_a, t_ps_node **list_b,
							t_count *counter);
int						find_min_index(t_ps_node *list_a);
void					operations(t_ps_node **list_a, t_ps_node **list_b,
							int min_index, t_count *counter);
void					index_creater(t_ps_node *list_a);
void					chunk_sort(t_ps_node **list_a, t_ps_node **list_b,
							t_count *counter);
int						first_index(t_ps_node *list_a, int value);
void					chunk_bstack_side(t_ps_node **list_a,
							t_ps_node **list_b, t_count *counter);
void					max_index_founder(t_ps_node *list_b, int *max_pos);
void					radix_sort(t_ps_node **list_a, t_ps_node **list_b,
							t_count *counter);
int						max_index_founder_radix(t_ps_node *list_b);
int						get_bit_count(int *size, t_ps_node *list_a);
char					**ft_split(char const *s, char c);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
size_t					ft_strlen(const char *s);
char					*ft_strdup(const char *s);
void					disorder(t_ps_node *list_a, t_count *counter);
int						ft_strcmp(char *s1, char *s2);
void					pick_algorithm(t_ps_node **list_a, t_ps_node **list_b,
							t_count *counter);
void					adaptive(t_ps_node **list_a, t_ps_node **list_b,
							t_count *counter);
void					init_counter(t_count *counter);
void					print_bench(t_count *counter);
void					disorder_part(t_count *counter);
void					strategy_part(t_count *counter);
void					ops_part(t_count *counter);
void					total_ops_part(t_count *counter);
void					ft_putnbr_fd(int n);
void					ft_putstr_fd(char *s);
void					is_flag(char **argv, t_count *counter);
char					*ft_strchr(const char *s, int c);
void					free_list(t_ps_node *list);
void					free_split(char **split);
void					chunk_update(t_medium *setup, int *j);
void					medium_setup(t_medium *setup, t_ps_node *list_a);
void					algorithm_selection(t_count *counter, char **argv);
int						parse_digits(char *nptr, int i, int sign);
int						handle_split(char *arg, t_ps_node **list);
int						handle_single(char *arg, t_ps_node **list);

#endif
