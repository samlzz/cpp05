/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:28:02 by sliziard          #+#    #+#             */
/*   Updated: 2026/02/02 16:52:15 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// ============================================================================
// Construction / Destruction
// ============================================================================

AForm::AForm()
	: _name("default")
	, _signed(false)
	, _c_gradeToSign(Bureaucrat::c_lowerGrade)
	, _c_gradeToExecute(Bureaucrat::c_lowerGrade)
{}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
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

AForm::AForm(const AForm &other)
	: _name(other._name)
	, _signed(other._signed)
	, _c_gradeToSign(other._c_gradeToSign)
	, _c_gradeToExecute(other._c_gradeToExecute)
{}

AForm::~AForm()
{}

// ============================================================================
// Operators
// ============================================================================

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		_signed = other._signed;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
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

void	AForm::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() > _c_gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

void	AForm::execute(const Bureaucrat &executor) const
{
	if (!_signed)
		throw NotSignedException();
	if (executor.getGrade() > _c_gradeToExecute)
		throw GradeTooLowException();
	executeAction();
}

// ---- Getters ----
const std::string	&AForm::getName() const				{ return _name; }
bool				AForm::isSigned() const				{ return _signed; }
int					AForm::getGradeToSign() const		{ return _c_gradeToSign; }
int					AForm::getGradeToExecute() const	{ return _c_gradeToExecute; }

// ============================================================================
// Exceptions
// ============================================================================

const char	*AForm::GradeTooHighException::what() const throw()
{
	return "AFormException: grade too high";
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return "AFormException: grade too low";
}

const char	*AForm::NotSignedException::what() const throw()
{
	return "AFormException: form not signed";
}