/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:52:48 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/18 14:20:29 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp" 
#include "Form.hpp" 

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
	if (_grade <= HIGHEST)
		throw Bureaucrat::GradeTooHighException();
	Bureaucrat	tmp = *this;
	++*this;
	return (tmp);
}

Bureaucrat& Bureaucrat::operator--()
{
	_grade += 1;
	return (*this);
}

Bureaucrat Bureaucrat::operator--(int)
{
	if (_grade >= LOWEST)
		throw Bureaucrat::GradeTooLowException();
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
	return "Error\nGrade too hight. Grade can't be higher than 1";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Error\nGrade too low. Grade can't be higher than 150";
}

void	Bureaucrat::signForm(const Form& form)
{
	if (this->_grade <= CAN_SIGN)
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	if (this->_grade > CAN_SIGN)
		std::cout << this->_name << " couldn't signed " << form.getName() << " because his grade is " << this->_grade << ". Only bureaucrats with a rank above " << CAN_SIGN << " can sign the forms" << std::endl ;
}

std::ostream& operator<<(std::ostream & o_stream, Bureaucrat const & instance)
{
	o_stream << instance.getName() << ", bureaucrat grade " << instance.getGrade() << "." << std::endl;
	return (o_stream);
}