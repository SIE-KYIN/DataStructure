/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_tree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:13:40 by mchun             #+#    #+#             */
/*   Updated: 2021/08/09 22:23:08 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_TREE_H
# define B_TREE_H

# include <stdio.h>
# include <limits.h>

typedef struct s_tnode
{
	int				data;
	struct s_tnode	*left;
	struct s_tnode	*right;
}				t_tnode;

typedef struct	s_dyn_arr{
	t_tnode	**arr;
	int		size;
	int		capacity;
}				t_dyn_arr;

typedef struct	s_stack{
	t_dyn_arr	*d_arr;
}				t_stack;

t_dyn_arr	*create_dyn_arr(void);
int			resize_dyn_arr(t_dyn_arr *d_arr);

t_stack	*create_stack(void);
void	push(t_stack *stack, t_tnode *data);
void	pop(t_stack *stack, t_tnode **data);
int		is_stack_full(t_stack *stack);
int		is_stack_empty(t_stack *stack);
int		get_top(t_stack *stack);
void	delete_stack(t_stack *stack);

#endif
