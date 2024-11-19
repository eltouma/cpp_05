/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:20:02 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/19 02:23:22 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("Not forgiven")
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
{
	*this = obj;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

const char	*ShrubberyCreationForm::FormNotSignedException::what() const throw()
{
	return " not signed";
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
	{
		std::cout << this->getName();
		throw ShrubberyCreationForm::FormNotSignedException();
	}
	if (executor.getGrade() > this->getToExec()) 
		throw AForm::GradeTooLowException();
	std::cout << this->_target << " not forgiven by Zaphod Beeblebrox" << std::endl; 
}
