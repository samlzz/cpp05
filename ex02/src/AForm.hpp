/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:28:10 by sliziard          #+#    #+#             */
/*   Updated: 2026/02/02 16:51:50 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <exception>
# include <ostream>
# include <stdint.h>

class Bureaucrat;

class AForm {

private:
	const std::string	_name;
	bool				_signed;
	const int			_c_gradeToSign;
	const int			_c_gradeToExecute;

public:
	AForm();
	AForm(const std::string &name, int32_t gradeToSign, int32_t gradeToExecute);
	AForm(const AForm &other);
	virtual ~AForm();

	AForm &operator=(const AForm &other);

	const std::string	&getName() const;
	bool				isSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;

	void				beSigned(const Bureaucrat &signer);
	void				execute(const Bureaucrat &executor) const;

protected:
	virtual void		executeAction() const = 0;

public:

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class NotSignedException : public std::exception {
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif
