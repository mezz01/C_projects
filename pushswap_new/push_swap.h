/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 06:21:45 by mmezzat           #+#    #+#             */
/*   Updated: 2023/09/30 06:13:23 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define LONG_NEG -2147483648
# define LONG_POS 2147483647

// the single node linked_list structure :
typedef struct s_node
{
	int				number;
	int				n_index;
	struct s_node	*next_link;
}					t_node;

// utils :
int					ft_isdigit(int chr);
char				**ft_split(char const *s, char c);
void				ft_putstr_fd(const char *str, int fd);
long				ft_atoi(const char *ptr_str);
void				free_double_str(char **str);
void				stack_free(t_node **str);
char				*ft_substr(char const *str, unsigned int index,
						size_t sub_max);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *st);
char				*ft_strdup(const char *str);
void				create_indexes(t_node **a);

// parsing :
void				full_args_check(char **av);

// push_swap :
// instructions :
t_node				*last_item(t_node *first_num);
int					node_size(t_node *list);
int					swap_top_nums(t_node **list);
int					push_top_nums(t_node **from_stack, t_node **go_to_stack);
int					rotating_nums(t_node **list);
int					down_rotating_nums(t_node **list);
int					sa(t_node **a);
int					sb(t_node **b);
int					ss(t_node **a, t_node **b);
int					pa(t_node **a, t_node **b);
int					pb(t_node **a, t_node **b);
int					ra(t_node **a);
int					rb(t_node **b);
int					rr(t_node **a, t_node **b);
int					rra(t_node **a);
int					rrb(t_node **b);
int					rrr(t_node **a, t_node **b);

// sorting
void				early_sort(t_node **a, t_node **b);
void				apply_radix(t_node **a, t_node **b);
int					node_size(t_node *list);
int					list_min_index(t_node **list, int min_num);
int					check_if_sorted(t_node **list);
void				limited_num_sort(t_node **a, t_node **b);
void				three_nums_sort(t_node **a);
void				four_nums_sort(t_node **a, t_node **b);
void				five_nums_sort(t_node **a, t_node **b);
void				three_sort_help(t_node *first_num, int index, t_node **a);

// stack init :
t_node				*last_item(t_node *first_num);
t_node				*new_node(int number);
void				add_node_to_stack(t_node **a, t_node *first_num);
char				*ft_strjoin(char const *s1, char const *s2);
int					how_far(t_node *a, int c_index);

#endif