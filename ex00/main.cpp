/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:13:21 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/15 21:58:34 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try {
		Bureaucrat	bureaucrat;
		Bureaucrat	jackson("Jackson", 99);

		std::cout << bureaucrat;
		bureaucrat++;
		std::cout << bureaucrat;
		std::cout << jackson;
		jackson++;
		std::cout << jackson;
		jackson++;
		std::cout << jackson;
	}
	catch (const std::exception &customException)
	{
		std::cerr << customException.what() << std::endl;
	}
}
