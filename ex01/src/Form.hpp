/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:28:10 by sliziard          #+#    #+#             */
/*   Updated: 2026/02/02 14:29:12 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <exception>
# include <ostream>
# include <stdint.h>

class Bureaucrat;

class Form {

private:
	const std::string	_name;
	bool				_signed;
	const int			_c_gradeToSign;
	const int			_c_gradeToExecute;

public:
	Form();
	Form(const std::string &name, int32_t gradeToSign, int32_t gradeToExecute);
	Form(const Form &other);
	~Form();

	Form &operator=(const Form &other);

	const std::string	&getName() const;
	bool				isSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;

	void				beSigned(const Bureaucrat &b);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif

