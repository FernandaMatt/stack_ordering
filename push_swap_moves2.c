/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:41:21 by fcaetano          #+#    #+#             */
/*   Updated: 2022/09/19 15:42:55 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_index(t_list **stack, char c, int index)
{
	if (get_pos(*stack, index) <= (ft_lstsize(*stack) / 2))
	{
		while ((*stack)->index != index)
			rotate(stack, c);
	}
	else
	{
		while ((*stack)->index != index)
			reverse(stack, c);
	}
}

void	push_ordered(t_list **stack_a, t_list **stack_b, int stacksize)
{
	while (stacksize--)
	{	
		push(stack_b, stack_a, 'a');
		rotate(stack_a, 'a');
	}
}

int	push_revord(t_list **stack_a, t_list **stack_b, int stacksz, int ord)
{
	int	mv;

	mv = stacksz;
	while (mv--)
		push(stack_b, stack_a, 'a');
	mv = stacksz;
	while (mv--)
		rotate(stack_a, 'a');
	return (ord + stacksz);
}

int	push_nextn(t_list **stack_a, t_list **stack_b, int ord)
{
	while (!check(*stack_a) || ft_lstsize(*stack_b) != 0)
	{
		if ((*stack_a)->index == ord + 1)
		{
			rotate(stack_a, 'a');
			ord++;
		}
		else if ((*stack_a)->index == ord + 2
			&& ((*stack_a)->next)->index == ord + 1)
		{
			swap(stack_a, 'a');
			rotate(stack_a, 'a');
			rotate(stack_a, 'a');
			ord += 2;
		}
		else
			push(stack_a, stack_b, 'b');
		if (check_seq(*stack_b, ord))
			break ;
	}
	return (ord);
}

int	push_min(t_list **stack, t_list **aux, int min_i, char cs)
{
	char	ca;

	ca = 'a';
	if (cs == 'a')
		ca = 'b';
	to_index(stack, cs, min_i);
	if (check(*stack))
		return (1);
	push(stack, aux, ca);
	return (0);
}
