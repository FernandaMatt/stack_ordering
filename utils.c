/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:27:28 by fcaetano          #+#    #+#             */
/*   Updated: 2022/09/21 11:00:41 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos(t_list *stack, int index)
{
	int	pos;

	pos = 1;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

int	get_pivo(t_list *stack, int size)
{
	int	max_i;
	int	min_i;

	max_i = get_max_i(stack, size);
	min_i = get_min_i(stack, size);
	return (min_i + ((max_i - min_i) / 2));
}

int	dmid(t_list *stack, int index)
{
	int	dist;
	int	pos;

	pos = get_pos(stack, index);
	dist = pos - (ft_lstsize(stack) / 2) - 1;
	return (ft_abs(dist));
}

int	get_max_i(t_list *stack, int size)
{
	int	max_i;

	max_i = stack->index;
	while (--size)
	{
		stack = stack->next;
		if (stack->index > max_i)
			max_i = stack->index;
	}
	return (max_i);
}

int	get_min_i(t_list *stack, int size)
{
	int	min_i;

	min_i = stack->index;
	while (--size)
	{
		stack = stack->next;
		if (stack->index < min_i)
			min_i = stack->index;
	}
	return (min_i);
}
