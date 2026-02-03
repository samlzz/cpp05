/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:02:31 by sliziard          #+#    #+#             */
/*   Updated: 2026/02/03 17:13:10 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include <iostream>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// ============================================================================
// Canonical form
// ============================================================================

Intern::Intern() {}
Intern::Intern(const Intern &other) { (void)other; }
Intern::~Intern() {}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

// ============================================================================
// Factory helpers
// ============================================================================

static AForm *createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

static AForm *createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

static AForm *createPresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

// ============================================================================
// makeForm
// ============================================================================

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
	static const FormDescriptor forms[] = {
		{"shrubbery creation", &createShrubbery},
		{"robotomy request", &createRobotomy},
		{"presidential pardon", &createPresidential}
	};

	for (size_t i = 0; i < (sizeof(forms) / sizeof(forms[0])); ++i)
	{
		if (formName == forms[i].name)
		{
			AForm *f = forms[i].builder(target);
			std::cout << "Intern creates " << formName << std::endl;
			return f;
		}
	}
	std::cout << "Intern cannot create \"" << formName << "\": unknown form" << std::endl;
	return 0;
}

