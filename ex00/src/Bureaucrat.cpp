/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:37:25 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/24 16:10:27 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include <string>
#include "Bureaucrat.hpp"

const int32_t Bureaucrat::c_higherGrade = 1;
const int32_t Bureaucrat::c_lowerGrade = 150;

// *Constructors
Bureaucrat::Bureaucrat(): _c_name("anonym"), _grade(c_lowerGrade)
{
#ifdef PRINT_CALLER
	std::cout << "Bureaucrat default constructor called" << std::endl;
#endif
}

Bureaucrat::Bureaucrat(const std::string &name, int32_t grade): _c_name(name), _grade(grade)
{
#ifdef PRINT_CALLER
	std::cout << "Bureaucrat parameters constructor called" << std::endl;
#endif
	if (grade < c_higherGrade)
		throw GradeTooHighException();
	else if (grade > c_lowerGrade)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _c_name(other._c_name), _grade(other._grade)
{
#ifdef PRINT_CALLER
	std::cout << "Bureaucrat copy constructor called" << std::endl;
#endif
}
// *Destructor
Bureaucrat::~Bureaucrat()
{
#ifdef PRINT_CALLER
	std::cout << "Bureaucrat destructor called" << std::endl;
#endif
}

// *Operators

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
#ifdef PRINT_CALLER
	std::cout << "Bureaucrat assignment operator called" << std::endl;
#endif
	if (this != &other)
	{
		_grade = other._grade;
	}
	return *this;
}


//* Methods

// --- Getters ---
const std::string	&Bureaucrat::getName(void) const
{
	return _c_name;
}
int32_t				Bureaucrat::getGrade(void) const
{
	return _grade;
}

Bureaucrat	&Bureaucrat::operator++(void)
{
	if (_grade <= c_higherGrade)
		throw GradeTooHighException();
	_grade--;
	return (*this);
}
Bureaucrat	Bureaucrat::operator++(int)
{
	Bureaucrat	save(*this);

	if (_grade <= c_higherGrade)
		throw GradeTooHighException();
	_grade--;
	return (save);
}

Bureaucrat	&Bureaucrat::operator--(void)
{
	if (_grade >= c_lowerGrade)
		throw GradeTooLowException();
	_grade++;
	return (*this);
}
Bureaucrat	Bureaucrat::operator--(int)
{
	Bureaucrat	save(*this);

	if (_grade >= c_lowerGrade)
		throw GradeTooLowException();
	_grade++;
	return (save);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "BureaucratException: grade too high";
}
const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "BureaucratException: grade too low";
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}