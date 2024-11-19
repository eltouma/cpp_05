/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:52:48 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/19 16:38:09 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp" 


Bureaucrat::Bureaucrat(void) : _name("John"), _grade(LOWEST)
{
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if (this->_grade > LOWEST || this->_grade < HIGHEST)
		std::cout << "Error: " << this->_name;
	if (this->_grade > LOWEST)
		throw Bureaucrat::GradeTooLowException();
	if (this->_grade < HIGHEST)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
{
	*this = obj;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
		this->_grade = rhs.getGrade();
	return (*this);
}

Bureaucrat& Bureaucrat::operator++()
{
	this->_grade -= 1;
	return (*this);
}

Bureaucrat Bureaucrat::operator++(int)
{
	if (this->_grade <= HIGHEST)
	{
		std::cout << "Error: " << this->_name;
		throw Bureaucrat::GradeTooHighException();
	}
	Bureaucrat	tmp = *this;
	++*this;
	return (tmp);
}

Bureaucrat& Bureaucrat::operator--()
{
	this->_grade += 1;
	return (*this);
}

Bureaucrat Bureaucrat::operator--(int)
{
	if (this->_grade >= LOWEST)
	{
		std::cout << "Error: " << this->_name;
		throw Bureaucrat::GradeTooLowException();
	}
	Bureaucrat	tmp = *this;
	--*this;
	return (tmp);
}
std::string const & Bureaucrat::getName(void) const
{
	return (this->_name);
}

int const & Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ", grade too hight. Grade can't be higher than 1";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ", grade too low. Grade can't be lower than 150";
}

std::ostream& operator<<(std::ostream & o_stream, Bureaucrat const & instance)
{
	o_stream << instance.getName() << ", bureaucrat grade " << instance.getGrade() << "." << std::endl;
	return (o_stream);
}
