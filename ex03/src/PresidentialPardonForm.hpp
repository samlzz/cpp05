/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:30:28 by sliziard          #+#    #+#             */
/*   Updated: 2026/02/02 16:33:46 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDON_FORM_HPP
# define PRESIDENTIALPARDON_FORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {

private:
	std::string _target;

protected:
	void executeAction() const;

public:
	PresidentialPardonForm(const std::string &target);
	~PresidentialPardonForm();
};

#endif

