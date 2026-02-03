/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:00:00 by sliziard          #+#    #+#             */
/*   Updated: 2026/02/03 17:24:56 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

static inline void	title(const std::string &s)
{
	std::cout << "\n========== " << s << " ==========\n";
}

int	main(void)
{
	std::srand(std::time(NULL));

	title("Setup");

	Intern		intern;
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	employee("Employee", 50);

	std::cout << boss << std::endl;
	std::cout << employee << std::endl;

	// -------------------------------------------------------------------------
	// Valid form creation
	// -------------------------------------------------------------------------
	title("Valid form creation");

	AForm *f1 = intern.makeForm("shrubbery creation", "home");
	AForm *f2 = intern.makeForm("robotomy request", "Bender");
	AForm *f3 = intern.makeForm("presidential pardon", "Ford Prefect");

	if (f1) std::cout << *f1 << std::endl;
	if (f2) std::cout << *f2 << std::endl;
	if (f3) std::cout << *f3 << std::endl;

	// -------------------------------------------------------------------------
	// Form creation
	// -------------------------------------------------------------------------

	title("Invalid form creation");

	AForm *invalid = intern.makeForm("coffee request", "kitchen");
	if (!invalid)
		std::cout << "Invalid form correctly not created" << std::endl;
	else
		std::cout << "Error: invalid form was created" << std::endl;


	title("Signing and execution");

	if (f1)
	{
		employee.signForm(*f1);
		boss.executeForm(*f1);
	}

	if (f2)
	{
		employee.signForm(*f2);
		boss.executeForm(*f2);
	}

	if (f3)
	{
		employee.signForm(*f3);
		boss.signForm(*f3);
		boss.executeForm(*f3);
	}

	delete f1;
	delete f2;
	delete f3;
	return 0;
}

