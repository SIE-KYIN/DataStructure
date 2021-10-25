/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_tree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 22:03:42 by mchun             #+#    #+#             */
/*   Updated: 2021/08/09 22:22:06 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_tree.h"

t_dyn_arr	*create_dyn_arr(void)
{
	t_dyn_arr	*d_arr;
	t_tnode		**arr;

	d_arr = (t_dyn_arr *)malloc(sizeof(t_dyn_arr));
	if (!d_arr)
		return (NULL);
	arr = (t_tnode **)malloc(sizeof(t_tnode *) * 1);
	if (!arr)
	{
		free(d_arr);
		return (NULL);
	}
	d_arr->capacity = 1;
	d_arr->size = 0;
	d_arr->arr = arr;
	return (d_arr);
}

int			resize_dyn_arr(t_dyn_arr *d_arr)
{
	t_tnode		**new_arr;
	int		new_capacity;
	int		i;

	new_capacity = d_arr->capacity * 4;
	new_arr = (t_tnode **)malloc(sizeof(t_tnode *) * new_capacity);
	if (!new_arr)
		return (0);
	for (i = 0; i < d_arr->capacity; i++)
		new_arr[i] = d_arr->arr[i];
	free(d_arr->arr);
	d_arr->arr = new_arr;
	return (1);
}

t_stack 	*create_stack(void)
{
	t_stack		*ret_stack;

	ret_stack->d_arr = create_dyn_arr();
	if (!ret_stack)
		return (NULL);
	return (ret_stack);
}

void	push(t_stack *stack, t_tnode *data)
{
	if (is_stack_full(stack));
		resize_dyn_arr(stack->d_arr);
	stack->d_arr->arr[stack->d_arr->size++] = data;
	return ;
}

void	pop(t_stack *stack, t_tnode **node)
{
	if (is_stack_empty(stack));
	{
		node = NULL;
		return ;
	}
	*node = stack->d_arr->arr[stack->d_arr->size - 1];
	stack->d_arr->size--;
}

int		is_stack_full(t_stack *stack)
{
	return (stack->d_arr->capacity == stack->d_arr->size);
}

int		is_stack_empty(t_stack *stack)
{
	return (stack->d_arr->size == 0);
}

int		get_top(t_stack *stack)
{
	return (stack->d_arr->arr[stack->d_arr->size - 1]);
}

void	delete_stack(t_stack *stack)
{
	if (!stack)
		return ;
	free(stack->d_arr->arr);
	free(stack->d_arr);
	free(stack);
	return ;
}
