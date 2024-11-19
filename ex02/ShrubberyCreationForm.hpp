/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:20:02 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/19 01:52:14 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm;

class ShrubberyCreationForm : public AForm
{
	std::string	_target;
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const ShrubberyCreationForm & obj);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm & rhs);
	~ShrubberyCreationForm(void);
	void	execute(Bureaucrat const &executor) const;

	class	FormNotSignedException : public std::exception
	{
	public:
		const char * what() const throw();
	};
};
