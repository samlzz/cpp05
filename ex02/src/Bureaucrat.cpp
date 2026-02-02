/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:37:25 by sliziard          #+#    #+#             */
/*   Updated: 2026/02/02 16:46:12 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include <string>

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// ============================================================================
// Static variables
// ============================================================================

const int32_t Bureaucrat::c_higherGrade = 1;
const int32_t Bureaucrat::c_lowerGrade = 150;

// ============================================================================
// Construction / Destruction
// ============================================================================

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

Bureaucrat::~Bureaucrat()
{
#ifdef PRINT_CALLER
	std::cout << "Bureaucrat destructor called" << std::endl;
#endif
}

// ============================================================================
// Operators
// ============================================================================

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

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}

// ============================================================================
// Methods
// ============================================================================

void	Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << _c_name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _c_name << " couldn't sign "
			<< f.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
		std::cout << _c_name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _c_name << " couldn't execute "
			<< form.getName() << " because " << e.what() << std::endl;
	}
}

// ---- Getters ----
const std::string	&Bureaucrat::getName(void) const	{ return _c_name; }
int32_t				Bureaucrat::getGrade(void) const	{ return _grade; }

// ============================================================================
// Exceptions
// ============================================================================

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "BureaucratException: grade too high";
}
const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "BureaucratException: grade too low";
}
