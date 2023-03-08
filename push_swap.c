/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:30:06 by fcaetano          #+#    #+#             */
/*   Updated: 2022/10/06 13:17:26 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order(t_list **stack, t_list **aux, char cs)
{
	if (ft_lstsize(*stack) == 1)
		return ;
	if (ft_lstsize(*stack) == 2)
		order_2(stack, cs);
	else if (ft_lstsize(*stack) == 3)
		order_3(stack, cs);
	else if (ft_lstsize(*stack) == 4)
		order_4(stack, aux, cs);
	else if (ft_lstsize(*stack) == 5)
		order_5(stack, aux, cs);
	else
	{
		pivopb(stack, aux, ft_lstsize(*stack) / 2, ft_lstsize(*stack));
		pivo_ord(stack, aux);
	}
	print_moves(NULL);
}

int	porder(t_list **stack_a, t_list **stack_b, int ord)
{
	int	sz;

	sz = ft_lstsize(*stack_b);
	if (sz == 2)
		order_2(stack_b, 'b');
	else if (sz == 3)
		order_3(stack_b, 'b');
	else if (sz == 4)
		porder_4(stack_a, stack_b, ord);
	else if (sz == 5)
		porder_5(stack_a, stack_b, ord);
	if (ft_lstsize(*stack_b) != 0)
		push_ordered(stack_a, stack_b, ft_lstsize(*stack_b));
	return (ord + sz);
}

int	init_stack(int argc, char **argv, t_list **stack)
{
	if (check_entry(argv))
	{
		while (--argc > 0)
			ft_lstadd_front(stack, ft_lstnew(ft_atoi(argv[argc])));
		return (1);
	}
	else
		return (0);
}

void	free_all(char **argv, char *temp, int argc)
{
	free(temp);
	while (--argc >= 0)
		free(argv[argc]);
	free(argv);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*temp;

	if (argc > 1 && argv[1][0] != 0)
	{
		stack_b = NULL;
		temp = init_argv(argc, argv);
		argv = ft_split(temp, ' ');
		argc = 0;
		while (argv[argc])
			argc++;
		if (init_stack(argc, argv, &stack_a))
		{
			get_index(stack_a);
			if (!check(stack_a))
				order(&stack_a, &stack_b, 'a');
			ft_lstclear(&stack_a);
			ft_lstclear(&stack_b);
		}
		else
			write(2, "Error\n", 6);
		free_all(argv, temp, argc);
	}
	return (0);
}
