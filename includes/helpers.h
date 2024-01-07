/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:09:08 by ijaija            #+#    #+#             */
/*   Updated: 2024/01/07 15:49:29 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include "./list_control.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(long long n, char format);
int		ft_printf(const char *mainstr, ...);
int		ft_putaddr(void *ptr);
int		ft_puthex(unsigned int n, char *base);
size_t	ft_numbase_len(unsigned long long n);
long	custom_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_putstr_fd(char *s, int fd);
void	fail_exit(void);
int		args_parsing(int *argc, char ***argv, int **args);
char	*get_next_line(int fd);
void	*freeing(char *str);
char	*line_fill(char *stock);
char	*custom_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char const *s);
char	*reading_input(void);
int		instructions_check(char *file);
char	**ft_split(char const *s, char c);
int		ft_strcmp(char *s1, char *s2);
void	rr(t_list *stack_a, t_list *stack_b, char *print);
void	rrx(t_list *stack_x, char *print);
void	rrr(t_list *stack_a, t_list *stack_b, char *print);
void	rx(t_list *stack_x, char *print);
void	sx(t_list *stack_x, char *print);
void	ss(t_list *stack_a, t_list *stack_b, char *print);
void	px(t_list *stack_x1, t_list *stack_x2, char *print);
void	processing_args(char **instructons, t_list *stack_a, t_list *stack_b);
int		check_ok_or_ko(t_list *stack_a, size_t n_args);
char	**str_arrays_join(char **dest, char **tmp);
void	printing(int *argv);
void	freeingx(char **argv);
int		check_sorted(t_list *stack_a, size_t n_args);
void	ft_putendl_fd(char *s, int fd);
void	sorting(t_list **stack_a, t_list **stack_b, int argc);
void	sort_tolati(t_list **stack_a);
t_list	*l_copy(t_list *list);
void	maymknch_sort(t_list **stack_a, t_list **stack_b, int argc);
void	list_indexing(t_list **stack_a, t_list **copy);
int		get_pos_target(t_list **s_a, int index_b, int target_i, int target_pos);
void	move_cost_init(t_list **stack_a, t_list **stack_b);
void	lowest_cost_move(t_list **stack_a, t_list **stack_b);
int		ft_abs(int n);
void	rev_rot_both(t_list **s_a, t_list **s_b, int *moves_a, int *moves_b);
void	rot_stack(t_list **stack, int *moves, char *s_rx, char *s_rrx);
void	rot_both(t_list **s_a, t_list **s_b, int *moves_a, int *moves_b);
void	fix_stack(t_list **stack_a, int argc);
void	list_init_pos(t_list **stack_a);

#endif