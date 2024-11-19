/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:52:48 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/19 02:21:02 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp" 
#include "Bureaucrat.hpp" 

AForm::AForm(void) : _name("AForm"), _signed(false), _canSign(CAN_SIGN), _canExec(CAN_EXEC)
{
}

AForm::~AForm(void)
{
}

AForm::AForm(const std::string name, const int canSign, const int canExec) : _name(name), _signed(false), _canSign(canSign), _canExec(canExec)
{
	if (_canExec < HIGHEST || _canSign < HIGHEST || _canExec > LOWEST || _canSign > LOWEST)
		std::cout << "Error: " << this->_name;
	if (_canExec < HIGHEST || _canSign < HIGHEST)
		throw AForm::GradeTooHighException();
	if (_canExec > LOWEST || _canSign > LOWEST)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const std::string name, const int canSign, const int canExec, const Bureaucrat &bureaucrat) : _name(name), _signed(false), _canSign(canSign), _canExec(canExec)
{
	(void)bureaucrat;

	if (_canExec < HIGHEST || _canSign < HIGHEST || _canExec > LOWEST || _canSign > LOWEST)
		std::cout << "Error: " << this->_name;
	if (_canExec < HIGHEST || _canSign < HIGHEST)
		throw AForm::GradeTooHighException();
	if (_canExec > LOWEST || _canSign > LOWEST)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& obj) : _signed(false), _canSign(10), _canExec(50)
{
	*this = obj;
}

AForm& AForm::operator=(const AForm& rhs)
{
	if (this != &rhs)
		this->_signed = rhs.getSigned();
	return (*this);
}

std::string const & AForm::getName(void) const
{
	return (this->_name);
}

bool const & AForm::getSigned(void) const
{
	return (this->_signed);
}

int const & AForm::getToSign(void) const
{
	return (this->_canSign);
}

int const & AForm::getToExec(void) const
{
	return (this->_canExec);
}
const char * AForm::GradeTooHighException::what() const throw()
{
	return ", one of the grade is too hight. Can't sign or execute the form";
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return ", one of the grade is too low. Can't sign or execute the form";
}

const char * AForm::FormAlreadySignedException::what() const throw()
{
	return "";
}

const char * AForm::FormNotSignedException::what() const throw()
{
	return " not signed";
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{

	if (bureaucrat.getGrade() <= CAN_SIGN && this->getSigned())
	{
		std::cout << bureaucrat.getName() << " (grade: " << bureaucrat.getGrade() << "), could have signed " << this->_name << " but it's already signed";
		throw AForm::FormAlreadySignedException();
	}
	if (bureaucrat.getGrade() <= CAN_SIGN)
		this->_signed = true;
	else
	{
		std::cout << "Error: " << bureaucrat.getName();
		throw AForm::GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream & o_stream, AForm const & instance)
{
	if (!instance.getSigned())
		o_stream << "AForm: " << instance.getName() << ", status: not signed."<< std::endl;
	else
		o_stream << "AForm: " << instance.getName() << ", status: signed." << std::endl;
	return (o_stream);
}
