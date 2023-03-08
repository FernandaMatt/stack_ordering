/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:59:55 by fcaetano          #+#    #+#             */
/*   Updated: 2022/10/06 08:59:58 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_index(t_list *stack)
{
	t_list	*head;
	t_list	*min;
	int		index;
	int		len;

	head = stack;
	len = ft_lstsize(stack);
	index = 0;
	while (index++ < len)
	{
		while (stack->index != 0)
			stack = stack->next;
		min = stack;
		while (stack)
		{
			if (stack->index == 0 && stack->content < min->content)
				min = stack;
			stack = stack->next;
		}
		min->index = index;
		stack = head;
	}
}

int	check_seq(t_list *stack, int ord)
{
	int	sz;

	if (!stack)
		return (0);
	sz = ft_lstsize(stack);
	if (get_max_i(stack, sz) - get_min_i(stack, sz) == sz -1)
	{
		while (stack)
		{
			if (stack->index == ord + 1)
				return (1);
			else
				stack = stack->next;
		}
	}
	return (0);
}

int	check(t_list *stack)
{
	while (stack->next)
	{
		if (stack->content > (stack->next)->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	check_rev(t_list *stack)
{
	while (stack->next)
	{
		if (stack->content < (stack->next)->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

char	*init_argv(int argc, char **argv)
{
	char	*temp;
	char	*ret;
	int		i;

	temp = NULL;
	ret = NULL;
	i = 0;
	while (i < argc)
	{
		if (ret)
		{
			temp = ret;
			ret = ft_strjoin(ret, " ");
			free(temp);
			temp = ret;
			ret = ft_strjoin(ret, argv[i]);
			free(temp);
		}
		else
			ret = ft_strjoin("./push_swap", " ");
		i++;
	}
	return (ret);
}
