/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:33:01 by sliziard          #+#    #+#             */
/*   Updated: 2026/02/02 14:48:44 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

static inline void	title(const std::string &name)
{
	std::cout << "\n========== " << name << " ==========\n";
}

int	main(void)
{
	title("Construction");

	Bureaucrat	alice("Alice", 1);
	Bureaucrat	bob("Bob", 50);
	Bureaucrat	charlie("Charlie", 150);

	Form		topSecret("TopSecret", 10, 5);
	Form		internal("Internal", 50, 100);
	Form		publicForm("Public", 150, 150);

	std::cout << alice << '\n';
	std::cout << bob << '\n';
	std::cout << charlie << '\n';

	std::cout << topSecret << '\n';
	std::cout << internal << '\n';
	std::cout << publicForm << '\n';

	// -------------------------------------------------------------------------
	// Signing success cases
	// -------------------------------------------------------------------------
	title("Signing - success");

	alice.signForm(topSecret);
	bob.signForm(internal);
	charlie.signForm(publicForm);

	std::cout << topSecret << '\n';
	std::cout << internal << '\n';
	std::cout << publicForm << '\n';

	// -------------------------------------------------------------------------
	// Signing failure cases
	// -------------------------------------------------------------------------
	title("Signing - failure");

	bob.signForm(topSecret);
	charlie.signForm(internal);

	// -------------------------------------------------------------------------
	// Signing already signed form
	// -------------------------------------------------------------------------
	title("Signing already signed form");

	alice.signForm(topSecret);
	bob.signForm(internal);

	std::cout << topSecret << '\n';
	std::cout << internal << '\n';

	// -------------------------------------------------------------------------
	// Invalid form construction
	// -------------------------------------------------------------------------
	title("Invalid Form construction");

	try
	{
		Form invalidHigh("InvalidHigh", 0, 10);
		(void)invalidHigh;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << '\n';
	}

	try
	{
		Form invalidLow("InvalidLow", 200, 10);
		(void)invalidLow;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << '\n';
	}

	std::cout.flush();
	return 0;
}

