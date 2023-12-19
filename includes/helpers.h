/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:09:08 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/18 17:55:51 by ijaija           ###   ########.fr       */
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
void	ft_putstr_fd(char *s, int fd);
void	fail_exit(void);
int		args_parsing(int argc, char **argv, int *args);
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
void	rr(t_list *stack_a, t_list *stack_b);
void	rrx(t_list *stack_x);
void	rrr(t_list *stack_a, t_list *stack_b);
void	rx(t_list *stack_x);
void	sx(t_list *stack_x);
void	ss(t_list *stack_a, t_list *stack_b);
void	px(t_list *stack_x1, t_list *stack_x2);
void	processing_args(char **instructons, t_list *stack_a, t_list *stack_b);
void	check_ok_or_ko(t_list *stack_a, size_t n_args);

#endif