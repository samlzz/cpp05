/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:32:43 by sliziard          #+#    #+#             */
/*   Updated: 2026/02/02 16:33:30 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUEST_FORM_HPP
# define ROBOTOMYREQUEST_FORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {

private:
	std::string _target;

protected:
	void executeAction() const;

public:
	RobotomyRequestForm(const std::string &target);
	~RobotomyRequestForm();
};

#endif