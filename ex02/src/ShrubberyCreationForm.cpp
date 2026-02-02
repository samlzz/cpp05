/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:10:02 by sliziard          #+#    #+#             */
/*   Updated: 2026/02/02 16:40:52 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137)
	, _target(target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::executeAction() const
{
	std::string		fileName(_target + "_shrubbery");
	std::ofstream	ofs(fileName.c_str());

	ofs <<
		"     ccee88oo\n"
		"  C8O8O8Q8PoOb o8oo\n"
		" dOB69QO8PdUOpugoO9bD\n"
		"CgggbU8OU qOp qOdoUOdcb\n"
		"    6OuU  /p u gcoUodpP\n"
		"      \\\\//  /douUP\n"
		"        \\\\////\n"
		"         |||/\\\n"
		"         |||\\/\n"
		"         |||||\n"
		"   .....//||||\\...." << std::endl;
}
