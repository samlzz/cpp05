/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:28:02 by sliziard          #+#    #+#             */
/*   Updated: 2026/02/02 15:03:13 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// ============================================================================
// Construction / Destruction
// ============================================================================

Form::Form()
	: _name("default")
	, _signed(false)
	, _c_gradeToSign(Bureaucrat::c_lowerGrade)
	, _c_gradeToExecute(Bureaucrat::c_lowerGrade)
{}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name)
	, _signed(false)
	, _c_gradeToSign(gradeToSign)
	, _c_gradeToExecute(gradeToExecute)
{
	if (gradeToSign < Bureaucrat::c_higherGrade
		|| gradeToExecute < Bureaucrat::c_higherGrade)
		throw GradeTooHighException();

	if (gradeToSign > Bureaucrat::c_lowerGrade
		|| gradeToExecute > Bureaucrat::c_lowerGrade)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
	: _name(other._name)
	, _signed(other._signed)
	, _c_gradeToSign(other._c_gradeToSign)
	, _c_gradeToExecute(other._c_gradeToExecute)
{}

Form::~Form()
{}

// ============================================================================
// Operators
// ============================================================================

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_signed = other._signed;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << "Form \"" << f.getName() << "\""
		<< " [signed: " << (f.isSigned() ? "yes" : "no")
		<< ", grade to sign: " << f.getGradeToSign()
		<< ", grade to execute: " << f.getGradeToExecute()
		<< "]";
	return os;
}

// ============================================================================
// Methods
// ============================================================================

void	Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _c_gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

// ---- Getters ----
const std::string	&Form::getName() const			{ return _name; }
bool				Form::isSigned() const			{ return _signed; }
int					Form::getGradeToSign() const	{ return _c_gradeToSign; }
int					Form::getGradeToExecute() const	{ return _c_gradeToExecute; }

// ============================================================================
// Exceptions
// ============================================================================

const char	*Form::GradeTooHighException::what() const throw()
{
	return "FormException: grade too high";
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return "FormException: grade too low";
}
