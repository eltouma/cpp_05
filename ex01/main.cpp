/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:13:21 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/18 20:54:49 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try {
		Bureaucrat	bureaucrats[] =	{
			Bureaucrat("Jackson", 34),
			Bureaucrat("Jess", 8),
			Bureaucrat("Camille", 27),
			Bureaucrat("Géraldine", 14),
			Bureaucrat("Bastien", 24),
			Bureaucrat("Mehdi", 91),
			Bureaucrat("Antoine", 13),
			Bureaucrat("Benoît", 3),
		};
		Form	forms[] = {
			Form("Subscription", 10, 50),
			Form("Birth certificate", 55, 80),
			Form("Insurance", 10, 50),
			Form("Taxes", 10, 50),
			Form("Application", 10, 50),
		};
		int	bLength;
		int	fLength;

		Bureaucrat romeo("Roméo", 30);
		Form form("Comment", 14, 5, romeo);
		form.beSigned(romeo);
		romeo.signForm(form);

		bLength = sizeof(bureaucrats) / sizeof(bureaucrats[0]);
		fLength = sizeof(forms) / sizeof(forms[0]);
		for (int j = 0; j < 10; j++)
		{
			for (int i = 0; i < bLength; i++)
			{
				for (int k = 0; k < fLength; k++)
				{
					bureaucrats[i]++;
					try {
						forms[k].beSigned(bureaucrats[i]);
						bureaucrats[i].signForm(forms[k]);
						break ;
					}
					catch (const std::exception &customException)
					{
						std::cerr << customException.what() << std::endl;
					}
				}
			}
		}
	}
	catch (const std::exception &customException)
	{
		std::cerr << customException.what() << std::endl;
	}
}
