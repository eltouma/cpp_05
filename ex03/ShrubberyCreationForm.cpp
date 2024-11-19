/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:20:02 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/19 19:18:14 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("School 42")
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm("ShrubberyCreationForm", 145, 137)
{
	*this = obj;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

const char * ShrubberyCreationForm::FailToOpenException::what() const throw()
{
	return ", failed to open.";
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string	outfileName = this->_target + "_shrubbery";

	if (!this->getSigned())
	{
		std::cout << this->getName();
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > this->getToExec()) 
	{
		std::cout << this->getName();
		throw AForm::GradeTooLowException();
	}
	std::ofstream asciiTree(outfileName.c_str(), std::ios::out);
	if (!asciiTree.is_open())
	{
		std::cerr << "Error. " << outfileName;
		throw ShrubberyCreationForm::FailToOpenException();
	}
	asciiTree << "ASCII trees";
	asciiTree.close();
}
