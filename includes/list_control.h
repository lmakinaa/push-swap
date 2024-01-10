/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_control.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:36:50 by ijaija            #+#    #+#             */
/*   Updated: 2024/01/10 11:41:37 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_CONTROL_H
# define LIST_CONTROL_H

# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				move_cost_a;
	int				move_cost_b;
	int				index;
	int				pos;
	int				pos_target;
	struct s_node	*next;
}			t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
}				t_list;

t_list	*c_list(void);
t_node	*c_node(int value);
int		l_display(t_list *list);
void	l_addfront(t_list *list, t_node *node);
void	l_addback(t_list *list, t_node *node);
void	l_addafter(t_list *list, t_node *node1, t_node *node2);
void	l_addbefore(t_list *list, t_node *node1, t_node *node2);
void	l_free(t_list **list);
void	l_delnode(t_list *list, t_node *node);
size_t	l_len(t_list *list);
t_list	*array_to_list(int *array, int len);

#endif