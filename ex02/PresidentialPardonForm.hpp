/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:20:02 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/19 02:49:55 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
	std::string	_target;
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(const PresidentialPardonForm & obj);
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm& operator=(const PresidentialPardonForm & rhs);
	~PresidentialPardonForm(void);
	void	execute(Bureaucrat const &executor) const;
};
