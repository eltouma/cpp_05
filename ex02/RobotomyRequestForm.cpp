/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:20:02 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/19 19:17:49 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

int RobotomyRequestForm::_index = 0;

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("John")
{
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm("RobotomyRequestForm", 72, 45)
{
	*this = obj;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
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
	std::cout << "Drilling noises" << std::endl;
	if (!this->_index)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Error. Robotomy failed for " << this->_target << std::endl;
	this->_index = !this->_index;
}
