/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:10:05 by sliziard          #+#    #+#             */
/*   Updated: 2026/02/02 16:33:22 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATION_FORM_HPP
# define SHRUBBERYCREATION_FORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

private:
	std::string _target;

protected:
	void executeAction() const;

public:
	ShrubberyCreationForm(const std::string &target);
	~ShrubberyCreationForm();
};

#endif