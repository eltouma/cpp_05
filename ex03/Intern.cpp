/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:03:29 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/20 13:00:06 by eltouma          ###   ########.fr       */
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

AForm*	Intern::presidentialPardonForm(const std::string &target)
{
	std::cout << "Intern creates " << target << std::endl;
	return (new PresidentialPardonForm(target));
}

const char * Intern::InternException::what() const throw()
{
	return ", doesn't exist";
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	AForm* (Intern::*display[3])(const std::string &target) =
	{
		&Intern::shrubberyCreationForm,
		&Intern::robotomyRequestForm,
		&Intern::presidentialPardonForm
	};
	std::string formName[3] =
	{
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm",
	};
	for (int i = 0; i < 3; i++)
	{
		if (formName[i] == name)
			return (this->*display[i])(target);
	}
	std::cerr << name;
	throw Intern::InternException();
}

