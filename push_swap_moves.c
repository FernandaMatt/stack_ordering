/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:11:17 by fcaetano          #+#    #+#             */
/*   Updated: 2022/09/14 13:58:55 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_moves(char *mv)
{
	static char	*prev_mv;

	if ((!ft_strcmp(prev_mv, "sa") && !ft_strcmp(mv, "sb"))
		|| (!ft_strcmp(prev_mv, "sb") && !ft_strcmp(mv, "sa")))
	{
		ft_printf("ss\n");
		mv = NULL;
	}
	else if ((!ft_strcmp(prev_mv, "ra") && !ft_strcmp(mv, "rb"))
		|| (!ft_strcmp(prev_mv, "rb") && !ft_strcmp(mv, "ra")))
	{
		ft_printf("rr\n");
		mv = NULL;
	}
	else if ((!ft_strcmp(prev_mv, "rra") && !ft_strcmp(mv, "rrb"))
		|| (!ft_strcmp(prev_mv, "rrb") && !ft_strcmp(mv, "rra")))
	{
		ft_printf("rrr\n");
		mv = NULL;
	}
	else if (prev_mv)
		ft_printf("%s\n", prev_mv);
	prev_mv = mv;
}

void	swap(t_list **stack, char c)
{
	t_list	*temp;

	if (ft_lstsize((*stack)) > 1)
	{
		temp = (*stack);
		(*stack) = (*stack)->next;
		temp->next = (*stack)->next;
		(*stack)->next = temp;
		if (c == 'a')
			print_moves("sa");
		else
			print_moves("sb");
	}
}

void	push(t_list **from, t_list **to, char c)
{
	t_list	*temp;

	if (ft_lstsize((*from)) > 0)
	{
		temp = (*from);
		(*from) = (*from)->next;
		temp->next = NULL;
		ft_lstadd_front(to, temp);
		if (c == 'a')
			print_moves("pa");
		else
			print_moves("pb");
	}
}

void	rotate(t_list **stack, char c)
{
	t_list	*temp;

	if (ft_lstsize((*stack)) > 1)
	{
		temp = (*stack);
		(*stack) = (*stack)->next;
		temp->next = NULL;
		ft_lstadd_back(stack, temp);
		if (c == 'a')
			print_moves("ra");
		else
			print_moves("rb");
	}
}

void	reverse(t_list **stack, char c)
{
	t_list	*head;
	t_list	*last;
	int		size;

	if (ft_lstsize((*stack)) > 1)
	{
		size = ft_lstsize((*stack));
		head = (*stack);
		last = ft_lstlast((*stack));
		while (--size > 1)
			(*stack) = (*stack)->next;
		(*stack)->next = NULL;
		last->next = head;
		(*stack) = last;
		if (c == 'a')
			print_moves("rra");
		else
			print_moves("rrb");
	}
}
