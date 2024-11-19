/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:03:29 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/19 23:58:37 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern::~Intern(void)
{
}

Intern::Intern(const Intern &obj)
{
	*this = obj;
}

Intern& Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	return (*this);
}

AForm*	Intern::shrubberyCreationForm(const std::string &target)
{
	std::cout << "Intern creates " << target << std::endl;
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::robotomyRequestForm(const std::string &target)
{
	std::cout << "Intern creates " << target << std::endl;
	return (new RobotomyRequestForm(target));
}

const char * Intern::InternException::what() const throw()
{
	return ", does'nt not exist";
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	AForm* (Intern::*display[2])(const std::string &target) =
	{
		&Intern::shrubberyCreationForm,
		&Intern::robotomyRequestForm
	};
	std::string formName[2] = 
	{
		"Subscription",
		"RobotomyRequestForm"
	};
	for (int i = 0; i < 2; i++)
	{
		if (formName[i] == name)
			return (this->*display[i])(target);
	}
	std::cerr << name;
	throw Intern::InternException();
}

