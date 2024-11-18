/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:52:48 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/18 19:42:42 by eltouma          ###   ########.fr       */
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
	if (_canExec < HIGHEST || _canSign < HIGHEST)
		throw Form::GradeTooHighException();
	if (_canExec > LOWEST || _canSign > LOWEST)
		throw Form::GradeTooLowException();
}

Form::Form(const std::string name, const int canSign, const int canExec, const Bureaucrat &bureaucrat) : _name(name), _signed(false), _canSign(canSign), _canExec(canExec)
{
	if (_canExec < HIGHEST || _canSign < HIGHEST)
		throw Form::GradeTooHighException();
	if (_canExec > LOWEST || _canSign > LOWEST)
		throw Form::GradeTooLowException();
	if (bureaucrat.getGrade() < HIGHEST)
		throw Form::GradeTooHighException();
	if (bureaucrat.getGrade() > LOWEST)
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
	return "Error\nOne of the grade is too hight. Can't sign or execute the form";
}

const char * Form::GradeTooLowException::what() const throw()
{
	//return "Error\nOne of the grade is too low. Can't sign or execute the form";
	return " can't sign or execute the form";
}

const char * Form::FormAlreadySignedException::what() const throw()
{
	//return "Error\nForm already signed";
	return "";
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{

//	std::cout << "On rentre dans " << __func__ << " this->_signed est à " << this->getSigned() << "\n";
	if (bureaucrat.getGrade() <= CAN_SIGN && this->getSigned())
//	if (this->_signed == true)
	{
//		std::cout << "this->_signed est deja true, le bureaucrate " << bureaucrat.getName() << " ne peut pas signer un doncument deja signé\n";
		std::cout << bureaucrat.getName() << " (grade: " << bureaucrat.getGrade() << "), could have signed " << this->_name << " but it's already signed";
//		std::cout << "\t" << bureaucrat.getName() << " form " << this->_name << " _signed: " << _signed << "\n";
		throw Form::FormAlreadySignedException();
	}
	if (bureaucrat.getGrade() <= CAN_SIGN)
	{
//		std::cout << "Le bureaucrate " << bureaucrat.getName() << " peut signer le formulaire " << this->_name << ", il met this->_signed a true\n";
		this->_signed = true;
//		std::cout << "On sort de " << __func__ << " this->_signed est à " << this->getSigned() << "\n";
//		std::cout << "\t" << bureaucrat.getName() << " form " << this->_name << " _signed: " << _signed << "\n";
	}
/*
	else if (this->_signed == true)
	{
		
		std::cout << bureaucrat.getName() << " form " << this->_name << " -signed: " << _signed << "\n";
		throw Form::FormAlreadySignedException();
	}
*/
	else
	{
		std::cout << "Error\nOne of the grade is too low. " << bureaucrat.getName();
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
