/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:59:51 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/18 18:17:36 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

#define CAN_SIGN 50
#define CAN_EXEC 100

class Form
{
	const std::string	_name;
	bool	_signed;
	const int	_canSign;
	const int	_canExec;
public:
	Form(void);
	Form(const std::string name, const int canSign, const int canExec);
	Form(const std::string name, const int canSign, const int canExec, const Bureaucrat &bureaucrat);
	Form(const Form &obj);
	Form& operator=(const Form &rhs);
	~Form(void);
	const std::string &getName(void) const;
	const bool	&getSigned(void) const;
	const int	&getToSign(void) const;
	const int	&getToExec(void) const;
	void	beSigned(const Bureaucrat &bureaucrat);

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
};

std::ostream& operator<<(std::ostream &o_stream, const Form &obj);
