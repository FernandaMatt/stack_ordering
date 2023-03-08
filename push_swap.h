/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaetano <fernandacunha@id.uff.br>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:41:32 by fcaetano          #+#    #+#             */
/*   Updated: 2022/09/21 11:01:09 by fcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

void	print_moves(char *mv);
void	swap(t_list **stack, char c);
void	push(t_list **from, t_list **to, char c);
void	to_index(t_list **stack, char c, int index);
void	rotate(t_list **stack, char c);
void	reverse(t_list **stack, char c);
void	order(t_list **stack, t_list **aux, char cs);
int		porder(t_list **stack_a, t_list **stack_b, int ord);
void	order_3(t_list **stack, char c);
void	order_3_cases(t_list **stack, char c, int n);
void	order_2(t_list **stack, char c);
void	order_4(t_list **stack_a, t_list **stack_b, char cs);
void	porder_4(t_list **stack_a, t_list **stack_b, int ord);
void	porder_5(t_list **stack_a, t_list **stack_b, int ord);
void	order_5(t_list **stack_a, t_list **stack_b, char cs);
int		pivopa(t_list **stack_a, t_list **stack_b, int stacksz, int ord);
void	pivopb(t_list **stack_a, t_list **stack_b, int vpivo, int stacksz);
int		push_min(t_list **stack, t_list **aux, int min_i, char cs);
void	pivo_ord(t_list **stack_a, t_list **stack_b);
void	push_ordered(t_list **stack_a, t_list **stack_b, int stacksz);
int		push_revord(t_list **stack_a, t_list **stack_b, int stacksz, int ord);
int		push_nextn(t_list **stack_a, t_list **stack_b, int ord);
char	*init_argv(int argc, char **argv);
int		init_stack(int argc, char **argv, t_list **stack);
int		check(t_list *stack);
int		check_rev(t_list *stack);
int		check_seq(t_list *stack, int ord);
void	get_index(t_list *stack);
int		get_pos(t_list *stack, int index);
int		get_max_i(t_list *stack, int size);
int		get_min_i(t_list *stack, int size);
int		get_pivo(t_list *stack, int size);
int		dmid(t_list *stack, int index);
int		check_entry(char **entry);

#endif
