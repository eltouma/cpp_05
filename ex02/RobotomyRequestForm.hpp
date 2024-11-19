/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:20:02 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/19 18:17:17 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm;

class RobotomyRequestForm : public AForm
{
	std::string	_target;
	static	int	_index;
public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const RobotomyRequestForm & obj);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm& operator=(const RobotomyRequestForm & rhs);
	virtual ~RobotomyRequestForm(void);
	virtual void	execute(Bureaucrat const &executor) const;
};
