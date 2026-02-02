/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:00:27 by sliziard          #+#    #+#             */
/*   Updated: 2026/02/02 14:19:35 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <ostream>
# include <stdint.h>
# include <string>

// ============================================================================
// Forward declaration
// ============================================================================

class Form;

// ============================================================================
// Bureaucrat class
// ============================================================================

class Bureaucrat {

private:
	const std::string	_c_name;
	int32_t				_grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string &name, int32_t grade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();

	Bureaucrat&	operator=(const Bureaucrat& other);
	Bureaucrat	&operator++(void);
	Bureaucrat	&operator--(void);
	Bureaucrat	operator++(int);
	Bureaucrat	operator--(int);

	const std::string	&getName(void) const;
	int32_t				getGrade(void) const;

	void				signForm(Form &f);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char*	what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char*	what() const throw();
	};

	static const int32_t	c_higherGrade;
	static const int32_t	c_lowerGrade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif
