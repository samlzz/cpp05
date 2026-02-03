/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:01:22 by sliziard          #+#    #+#             */
/*   Updated: 2026/02/03 17:11:30 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>

class AForm;

class Intern {

public:
	Intern();
	Intern(const Intern &other);
	~Intern();

	Intern &operator=(const Intern &other);

	AForm *makeForm(const std::string &formName, const std::string &target) const;

private:
	typedef AForm *(*t_formCreate)(const std::string &target);

	struct FormDescriptor
	{
		const char		*name;
		t_formCreate	builder;
	};

};

#endif