/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:03:46 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/20 12:11:03 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class	AForm;

class	Intern
{
public:
	Intern(void);
	~Intern(void);
	Intern(const Intern &obj);
	Intern& operator=(const Intern &rhs);
	AForm*	shrubberyCreationForm(const std::string &target);
	AForm*	robotomyRequestForm(const std::string &target);
	AForm*	presidentialPardonForm(const std::string &target);
	AForm*	makeForm(std::string name, std::string target);

	class InternException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

