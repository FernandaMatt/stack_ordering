/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:20:20 by fcaetano          #+#    #+#             */
/*   Updated: 2022/09/28 17:01:26 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pivo_ord(t_list **stack_a, t_list **stack_b)
{
	int	ord;

	ord = 0;
	while (!check(*stack_a) || ft_lstsize(*stack_b) != 0)
	{
		if (!check(*stack_a) && ft_lstsize(*stack_b) == 0)
				ord = push_nextn(stack_a, stack_b, ord);
		if (ft_lstsize(*stack_b) > 5)
			ord = pivopa(stack_b, stack_a, ft_lstsize(*stack_b), ord);
		else if (ft_lstsize(*stack_b))
		{
			if (check_rev(*stack_b))
				ord = push_revord(stack_a, stack_b, ft_lstsize(*stack_b), ord);
			else
				ord = porder(stack_a, stack_b, ord);
		}
	}
}

void	pivopb(t_list **stack_a, t_list **stack_b, int ipivo, int stacksz)
{
	while (stacksz--)
	{
		if ((*stack_a)->index <= ipivo)
			push(stack_a, stack_b, 'b');
		else
			rotate(stack_a, 'a');
	}
}

int	pivopa(t_list **stack_b, t_list **stack_a, int stacksz, int ord)
{
	int			ipivo;

	ipivo = get_pivo(*stack_b, stacksz);
	while (stacksz--)
	{
		if ((*stack_b)->index == ord + 1)
		{
			push(stack_b, stack_a, 'a');
			rotate(stack_a, 'a');
			ord++;
		}
		else if ((*stack_b)->index > ipivo)
			push(stack_b, stack_a, 'a');
		else
			rotate(stack_b, 'b');
	}
	return (ord);
}

void	porder_4(t_list **stack_a, t_list **stack_b, int ord)
{
	int		n;

	n = 4;
	push(stack_b, stack_a, 'a');
	order_3(stack_b, 'b');
	while (n--)
	{
		if ((*stack_b) && (*stack_b)->index == ord + 1)
		{
			push(stack_b, stack_a, 'a');
			rotate(stack_a, 'a');
		}
		else
			rotate(stack_a, 'a');
		ord++;
	}
}

void	porder_5(t_list **stack_a, t_list **stack_b, int ord)
{
	int		n;

	n = 5;
	push(stack_b, stack_a, 'a');
	push(stack_b, stack_a, 'a');
	order_3(stack_b, 'b');
	while (n--)
	{
		if ((*stack_b) && (*stack_b)->index == ord + 1)
		{
			push(stack_b, stack_a, 'a');
			rotate(stack_a, 'a');
		}
		else if ((*stack_a)->index == ord + 1)
			rotate(stack_a, 'a');
		else
		{
			swap(stack_a, 'a');
			rotate(stack_a, 'a');
		}
		ord++;
	}
}
