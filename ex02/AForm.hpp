/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:59:51 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/19 17:49:38 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

#define CAN_SIGN 50
#define CAN_EXEC 100

class AForm
{
	const std::string	_name;
	bool	_signed;
	const int	_canSign;
	const int	_canExec;
public:
	AForm(void);
	AForm(const std::string name, const int canSign, const int canExec);
	AForm(const std::string name, const int canSign, const int canExec, const Bureaucrat &bureaucrat);
	AForm(const AForm &obj);
	AForm& operator=(const AForm &rhs);
	virtual ~AForm(void);
	const std::string &getName(void) const;
	const bool	&getSigned(void) const;
	const int	&getToSign(void) const;
	const int	&getToExec(void) const;
	void	beSigned(const Bureaucrat &bureaucrat);
	virtual void	execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException : public std::exception
	{
	public:
		const char * what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char * what() const throw();
	};

	class FormAlreadySignedException : public std::exception
	{
	public:
		const char * what() const throw();
	};

	class	FormNotSignedException : public std::exception
	{
	public:
		const char * what() const throw();
	};
};

std::ostream& operator<<(std::ostream &o_stream, const AForm &obj);
