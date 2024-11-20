/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:13:21 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/20 12:44:49 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	try {
		Bureaucrat	bureaucrats[] =	{
			Bureaucrat("Jackson", 84),
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

		Intern	a;
		Intern	b;
		Intern	c;
		Intern	d;
		Intern	e;
		Intern	f;

		AForm	*forms[] = {
			&subscription,
			&home,
			&bender,
			&birthCertificate,
			&garden,
			&walle,
		};

		Intern	*interns[] = {
			&a,
			&b,
			&c,
			&d,
			&e,
			&f,
		};

		AForm*	internCreation;
		int	bLength;
		int	fLength;
		int	iLength;

		bLength = sizeof(bureaucrats) / sizeof(bureaucrats[0]);
		fLength = sizeof(forms) / sizeof(forms[0]);
		iLength = sizeof(interns) / sizeof(interns[0]);

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < bLength; j++)
			{
				for (int k = 0; k < fLength && k < iLength; k++)
				{
					bureaucrats[j]++;
					try {
						forms[k]->beSigned(bureaucrats[j]);
						bureaucrats[j].signAForm(*forms[k]);
						forms[k]->execute(bureaucrats[j]);
						bureaucrats[j].executeForm(*forms[k]);
						internCreation = interns[j]->makeForm(forms[j]->getName(), subscription.getTarget());
						delete (internCreation);
						internCreation = interns[j]->makeForm(forms[j]->getName(), bender.getTarget());
						delete (internCreation);
						internCreation = interns[j]->makeForm(forms[j]->getName(), "testForm");
						delete (internCreation);
						internCreation = interns[j]->makeForm("Marie", garden.getTarget());
						delete (internCreation);
						internCreation = interns[j]->makeForm(forms[j]->getName(), home.getTarget());
						delete (internCreation);
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
