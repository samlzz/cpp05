/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:04:34 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/24 16:13:30 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main(void)
{
	try
	{
		Bureaucrat a("Alice", 2);
		Bureaucrat b("Bob", 149);

		std::cout << a << std::endl;
		std::cout << b << std::endl;

		++a;
		std::cout << a << std::endl;

		--b;
		std::cout << b << std::endl;

		--b; // sould throw an execption
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		//Bureaucrat	toHigh("Charlie", 0);
		Bureaucrat	toLow("Delta", 200);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "GradeTooLowException caught: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "GradeTooHighException caught: " << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Generic exception caught: " << e.what() << std::endl;
	}
	return 0;
}

