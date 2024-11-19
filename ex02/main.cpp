/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:13:21 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/19 02:35:21 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	try {
		Bureaucrat	bureaucrats[] =	{
			Bureaucrat("Jackson", 4),
			Bureaucrat("Jess", 8),
			Bureaucrat("Camille", 27),
			Bureaucrat("Géraldine", 14),
			Bureaucrat("Bastien", 24),
			Bureaucrat("Mehdi", 91),
			Bureaucrat("Antoine", 13),
			Bureaucrat("Benoît", 3),
		};
		PresidentialPardonForm	forms[] = {
			PresidentialPardonForm("Subscription"),
			PresidentialPardonForm("Birth certificate"),
			PresidentialPardonForm("Insurance"),
			PresidentialPardonForm("Taxes"),
			PresidentialPardonForm("Application"),
		};
/*
		AForm	forms[] = {
			AForm("Subscription", 10, 50),
			AForm("Birth certificate", 55, 80),
			AForm("Insurance", 10, 50),
			AForm("Taxes", 10, 50),
			AForm("Application", 10, 50),
		};
*/
		int	bLength;
		int	fLength;
//		Bureaucrat romeo("Roméo", 30);
	//	PresidentialPardonForm test;
//		test.execute(romeo);
//		Bureaucrat romeo("Roméo", 30);
//		AForm form("Comment", 14, 5, romeo);
//		form.beSigned(romeo);
//		romeo.signAForm(form);

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
						bureaucrats[i].signAForm(forms[k]);
						//bureaucrats[i]++;
						forms[k].execute(bureaucrats[i]);
						//bureaucrats[i].signAForm(forms[k]);
						bureaucrats[i]++;
				//		std::cout << bureaucrats[i];
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
