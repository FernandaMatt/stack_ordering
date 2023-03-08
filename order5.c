/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:02:55 by fcaetano          #+#    #+#             */
/*   Updated: 2022/09/14 14:50:16 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_2(t_list **stack, char c)
{
	if ((*stack)->content > ((*stack)->next)->content)
		swap(stack, c);
}

void	order_3_cases(t_list **stack, char c, int n)
{
	if (n == 0)
	{
		rotate(stack, c);
		swap(stack, c);
	}
	else if (n == 1)
	{
		swap(stack, c);
		rotate(stack, c);
	}
	else if (n == 2)
		reverse(stack, c);
	else if (n == 3)
		swap(stack, c);
	else
		rotate(stack, c);
}

void	order_3(t_list **stack, char c)
{
	t_list	*fst;
	t_list	*snd;
	t_list	*trd;

	fst = (*stack);
	snd = (*stack)->next;
	trd = ft_lstlast((*stack));
	if (fst->content < snd->content && snd->content < trd->content)
		;
	else if (fst->content > snd->content && snd->content > trd->content)
		order_3_cases(stack, c, 0);
	else if (fst->content < snd->content && snd->content > trd->content)
	{
		if (fst->content < trd->content)
			order_3_cases(stack, c, 1);
		else
			order_3_cases(stack, c, 2);
	}
	else if (fst->content < trd->content)
		order_3_cases(stack, c, 3);
	else
		order_3_cases(stack, c, 4);
}

void	order_4(t_list **stack, t_list **aux, char cs)
{
	char	ca;

	if (cs == 'a')
		ca = 'b';
	else
		ca = 'a';
	if (check(*stack))
		return ;
	to_index(stack, cs, get_min_i(*stack, ft_lstsize(*stack)));
	push(stack, aux, ca);
	order_3(stack, cs);
	push(aux, stack, cs);
}

void	order_5(t_list **stack, t_list **aux, char cs)
{
	int		min_i;
	char	ca;

	min_i = get_min_i(*stack, ft_lstsize(*stack));
	ca = 'a';
	if (cs == 'a')
		ca = 'b';
	if (dmid(*stack, min_i) >= dmid(*stack, min_i + 1))
	{
		if (push_min(stack, aux, min_i, cs))
			return ;
	}
	else
	{
		if (push_min(stack, aux, min_i + 1, cs))
			return ;
	}
	order_4(stack, aux, cs);
	push(aux, stack, cs);
	if (!check(*stack))
		swap(stack, cs);
}
