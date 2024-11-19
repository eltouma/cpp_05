/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:20:02 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/19 18:15:28 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm;

class ShrubberyCreationForm : public AForm
{
	std::string	_target;
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const ShrubberyCreationForm & obj);
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm & rhs);
	virtual ~ShrubberyCreationForm(void);
	virtual void	execute(Bureaucrat const &executor) const;

	class FailToOpenException : public std::exception
	{
	public:
		const char * what() const throw();
	};
};
