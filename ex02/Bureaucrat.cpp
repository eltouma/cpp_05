/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:52:48 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/19 19:35:49 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp" 
#include "AForm.hpp" 

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
	return " grade too hight. Grade can't be higher than 1";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return " grade too low. Grade can't be higher than 150";
}

void	Bureaucrat::signAForm(const AForm& form) const
{

	if (this->_grade <= form.getToSign())
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	if (this->_grade > form.getToSign())
		std::cout << this->_name << " couldn't signed " << form.getName() << " because his grade is " << this->_grade << ". Only bureaucrats with a rank above " << form.getToSign() << " can sign the forms" << std::endl ;
}

void	Bureaucrat::executeForm(AForm const &form) const
{
	if (this->_grade <= form.getToExec())
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	if (this->_grade > form.getToExec())
		std::cout << this->_name << " couldn't executed " << form.getName() << " because his grade is " << this->_grade << ". Only bureaucrats with a rank above " << form.getToExec() << " can execute the forms" << std::endl ;
}
std::ostream& operator<<(std::ostream & o_stream, Bureaucrat const & instance)
{
	o_stream << instance.getName() << ", bureaucrat grade " << instance.getGrade() << "." << std::endl;
	return (o_stream);
}
