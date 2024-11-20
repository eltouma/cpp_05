/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:13:21 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/20 12:53:29 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

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
			Bureaucrat("Benoît", 23),
		};

		PresidentialPardonForm	subscription("Subscription");
		ShrubberyCreationForm	home("Home");
		RobotomyRequestForm	bender("Bender");
		PresidentialPardonForm	birthCertificate("Birth certificate");
		ShrubberyCreationForm	garden("Garden");
		RobotomyRequestForm	walle("Walle");

		AForm	*forms[] = {
			&home,
			&subscription,
			&bender,
			&birthCertificate,
			&garden,
			&walle,
		};

		int	bLength;
		int	fLength;
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
						forms[k]->beSigned(bureaucrats[i]);
						bureaucrats[i].signAForm(*forms[k]);
						forms[k]->execute(bureaucrats[i]);
						bureaucrats[i].executeForm(*forms[k]);
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
