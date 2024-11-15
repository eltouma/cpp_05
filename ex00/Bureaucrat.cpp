/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:52:48 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/15 21:58:12 by eltouma          ###   ########.fr       */
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
	if (_grade > LOWEST)
		throw Bureaucrat::GradeTooLowException();
	if (_grade < HIGHEST)
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
	_grade -= 1;
	return (*this);
}

Bureaucrat Bureaucrat::operator++(int)
{
	Bureaucrat	tmp = *this;
	++*this;
	if (_grade < HIGHEST)
		throw Bureaucrat::GradeTooHighException();
	return (tmp);
}

Bureaucrat& Bureaucrat::operator--()
{
	_grade += 1;
	return (*this);
}

Bureaucrat Bureaucrat::operator--(int)
{
	Bureaucrat	tmp = *this;
	--*this;
	if (_grade > LOWEST)
		throw Bureaucrat::GradeTooLowException();
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

std::ostream& operator<<(std::ostream & o_stream, Bureaucrat const & instance)
{
	o_stream << instance.getName() << ", bureaucrat grade " << instance.getGrade() << "." << std::endl;
	return (o_stream);
}
