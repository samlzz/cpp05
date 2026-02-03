/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:30:33 by sliziard          #+#    #+#             */
/*   Updated: 2026/02/02 16:30:54 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", 25, 5)
	, _target(target)
{}

PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::executeAction() const
{
	std::cout << _target
		<< " has been pardoned by Zaphod Beeblebrox"
		<< std::endl;
}

