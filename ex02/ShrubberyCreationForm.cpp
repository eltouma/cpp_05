/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:20:02 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/20 12:52:51 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("School 42")
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm("ShrubberyCreationForm", 145, 137)
{
	*this = obj;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

const char * ShrubberyCreationForm::FailToOpenException::what() const throw()
{
	return ", failed to open.";
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string	outfileName = this->_target + "_shrubbery";

	if (!this->getSigned())
	{
		std::cout << this->getName();
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > this->getToExec()) 
	{
		std::cout << this->getName();
		throw AForm::GradeTooLowException();
	}
	std::ofstream asciiTree(outfileName.c_str(), std::ios::out);
	if (!asciiTree.is_open())
	{
		std::cerr << "Error. " << outfileName;
		throw ShrubberyCreationForm::FailToOpenException();
	}
	asciiTree << "\n            .        +          .      .          ."
		"\n     .            _        .                    ."
		"\n  ,              /;-._,-.____        ,-----.__"
		"\n ((        .    (_:#::_.:::. `-._   /:, /-._, `._,"
		"\n  `                 i   _|`'=:_::.`.);  i __/ /"
		"\n                      ,    `./  i:. `.   )==-'  ."
		"\n    .      ., ,-=-.  ,i, +#./`   i:.  / /           ."
		"\n.           i/:/`-' , ,i '` ` `   ): , /_  -o"
		"\n       .    /:+- - + +- : :- + + -:'  /(o-) i)     ."
		"\n  .      ,=':  i    ` `/` ' , , ,:' `'--'.--'---._/`7"
		"\n   `.   (    i: i,-._` ` + 'i, ,'   _,--._,---':.__/"
		"\n              i:  `  X` _| _,i/'   .-'"
		"\n.               ':._:`i____  /:'  /      .           ."
		"\n                    i::.  :i/:'  /              +"
		"\n   .                 `.:.  /:'  }      ."
		"\n           .           ):_(:;   i           ."
		"\n                      /:. _/ ,  |"
		"\n                   . (|::.     ,`                  ."
		"\n     .                |::.    {i"
		"\n                      |::.i  i `."
		"\n                      |:::(i    |"
		"\n              O       |:::/{ }  |                  (o"
		"\n               )  ___/#i::`/ (O '==._____   O, (O  /`"
		"\n          ~~~w/w~'~~,i` `:/,-(~`'~~~~~~~~'~o~i~/~w|/~"
		"\ndew   ~~~~~~~~~~~~~~~~~~~~~~~iiW~~~~~~~~~~~~i|/~~" <<std::endl;
	asciiTree.close();
}
