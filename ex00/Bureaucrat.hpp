/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:52:48 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/18 11:47:20 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

# define HIGHEST 1
# define LOWEST 150

class Bureaucrat
{
	const std::string _name;
	int	_grade;

	public:
	Bureaucrat(void);
	~Bureaucrat(void);
	Bureaucrat(const Bureaucrat& obj);
	Bureaucrat& operator=(const Bureaucrat& rhs);
	Bureaucrat(const std::string name, int grade);
	std::string const & getName() const;
	int const & getGrade() const;
	Bureaucrat& operator++(void);
	Bureaucrat operator++(int);
	Bureaucrat& operator--(void);
	Bureaucrat operator--(int);

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
};

std::ostream& operator<<(std::ostream & o_stream, Bureaucrat const & instance);
