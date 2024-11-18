/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:13:21 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/18 10:43:41 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try {
		Bureaucrat	bureaucrats[] =	{
			Bureaucrat("Jackson", 99),
			Bureaucrat("Jess", 8),
			Bureaucrat("Camille", 57),
			Bureaucrat("Géraldine", 91),
			Bureaucrat("Bastien", 24),
			Bureaucrat("Mehdi", 149),
			Bureaucrat("Antoine", 13),
			Bureaucrat("Benoît", 3),
		};
		int	length = sizeof(bureaucrats) / sizeof(bureaucrats[0]);
		for (int j = 0; j < 10; j++)
		{
			for (int i = 0; i < length; i++)
			{
				{
				//	bureaucrats[i]--;
					bureaucrats[i]++;
					std::cout << bureaucrats[i];
				}
			}
		}
	}
	catch (const std::exception &customException)
	{
		std::cerr << customException.what() << std::endl;
	}
}
