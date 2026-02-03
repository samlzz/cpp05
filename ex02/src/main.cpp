/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:02:10 by sliziard          #+#    #+#             */
/*   Updated: 2026/02/03 16:38:12 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#ifndef ROBOTOMY_TRY_COUNT
# define ROBOTOMY_TRY_COUNT	5
#endif

static inline void	title(const std::string &name)
{
	std::cout << "\n========== " << name << " ==========\n";
}

int	main(void)
{
	std::srand(std::time(0));

	title("Bureaucrats");

	Bureaucrat	president("President", 1);
	Bureaucrat	manager("Manager", 50);
	Bureaucrat	intern("Intern", 150);

	std::cout << president << std::endl;
	std::cout << manager << std::endl;
	std::cout << intern << std::endl;

	title("Forms creation");

	AForm	*shrub = new ShrubberyCreationForm("home");
	AForm	*robot = new RobotomyRequestForm("Bender");
	AForm	*pardon = new PresidentialPardonForm("Ford Prefect");

	std::cout << *shrub << std::endl;
	std::cout << *robot << std::endl;
	std::cout << *pardon << std::endl;

	// -------------------------------------------------------------------------
	// Execute before signing
	// -------------------------------------------------------------------------
	title("Execute before signing");

	president.executeForm(*shrub);
	president.executeForm(*robot);
	president.executeForm(*pardon);

	// -------------------------------------------------------------------------
	// Signing tests (fail then success)
	// -------------------------------------------------------------------------
	title("Signing forms");

	intern.signForm(*shrub);
	intern.signForm(*robot);
	manager.signForm(*pardon);
	std::cout << '\n';

	manager.signForm(*shrub);
	manager.signForm(*robot);
	president.signForm(*pardon);
	std::cout << '\n';

	std::cout << *shrub << std::endl;
	std::cout << *robot << std::endl;
	std::cout << *pardon << std::endl;

	// -------------------------------------------------------------------------
	// Executions tests
	// -------------------------------------------------------------------------
	title("Execute with insufficient grade");

	manager.executeForm(*pardon);
	intern.executeForm(*shrub);

	title("Successful executions");

	president.executeForm(*shrub);
	president.executeForm(*robot);
	president.executeForm(*pardon);

	title("Robotomy randomness");
	for (size_t i = 0; i < ROBOTOMY_TRY_COUNT; ++i)
		president.executeForm(*robot);

	delete shrub;
	delete robot;
	delete pardon;
	return 0;
}

