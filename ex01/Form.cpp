/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:52:48 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/18 20:55:02 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp" 
#include "Bureaucrat.hpp" 

Form::Form(void) : _name("Form"), _signed(false), _canSign(CAN_SIGN), _canExec(CAN_EXEC)
{
}

Form::~Form(void)
{
}

Form::Form(const std::string name, const int canSign, const int canExec) : _name(name), _signed(false), _canSign(canSign), _canExec(canExec)
{
	if (_canExec < HIGHEST || _canSign < HIGHEST || _canExec > LOWEST || _canSign > LOWEST)
		std::cout << "Error: " << this->_name;
	if (_canExec < HIGHEST || _canSign < HIGHEST)
		throw Form::GradeTooHighException();
	if (_canExec > LOWEST || _canSign > LOWEST)
		throw Form::GradeTooLowException();
}

Form::Form(const std::string name, const int canSign, const int canExec, const Bureaucrat &bureaucrat) : _name(name), _signed(false), _canSign(canSign), _canExec(canExec)
{
	(void)bureaucrat;

	if (_canExec < HIGHEST || _canSign < HIGHEST || _canExec > LOWEST || _canSign > LOWEST)
		std::cout << "Error: " << this->_name;
	if (_canExec < HIGHEST || _canSign < HIGHEST)
		throw Form::GradeTooHighException();
	if (_canExec > LOWEST || _canSign > LOWEST)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& obj) : _signed(false), _canSign(10), _canExec(50)
{
	*this = obj;
}

Form& Form::operator=(const Form& rhs)
{
	if (this != &rhs)
		this->_signed = rhs.getSigned();
	return (*this);
}

std::string const & Form::getName(void) const
{
	return (this->_name);
}

bool const & Form::getSigned(void) const
{
	return (this->_signed);
}

int const & Form::getToSign(void) const
{
	return (this->_canSign);
}

int const & Form::getToExec(void) const
{
	return (this->_canExec);
}
const char * Form::GradeTooHighException::what() const throw()
{
	return ", one of the grade is too hight. Can't sign or execute the form";
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ", one of the grade is too low. Can't sign or execute the form";
}

const char * Form::FormAlreadySignedException::what() const throw()
{
	return "";
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{

	if (bureaucrat.getGrade() <= CAN_SIGN && this->getSigned())
	{
		std::cout << bureaucrat.getName() << " (grade: " << bureaucrat.getGrade() << "), could have signed " << this->_name << " but it's already signed";
		throw Form::FormAlreadySignedException();
	}
	if (bureaucrat.getGrade() <= CAN_SIGN)
		this->_signed = true;
	else
	{
		std::cout << "Error: " << bureaucrat.getName();
		throw Form::GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream & o_stream, Form const & instance)
{
	if (!instance.getSigned())
		o_stream << "Form: " << instance.getName() << ", status: not signed."<< std::endl;
	else
		o_stream << "Form: " << instance.getName() << ", status: signed." << std::endl;
	return (o_stream);
}
