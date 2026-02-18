/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 01:40:00 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/12 01:40:00 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef AFORM_HPP
#define AFORM_HPP
#include <exception>
#include <string>
#include <iostream>
#include <ostream>
#include "Bureaucrat.hpp"
class AForm {
    private:
        const std::string name;
        const int gradeToSign;
        const int gradeToExecute;
        bool isSigned;
    public:
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();
        const std::string getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool getIsSigned() const;
        void beSigned(const Bureaucrat& bureaucrat);
        void execute(Bureaucrat const & executor) const;
        virtual void executeAction() const = 0;
        class GradeTooHighException : public std::exception {
            public :
                virtual const char* what() const throw() {
                    return ("Cannot process form. Grade too high!!");
                }
        };
        class GradeTooLowException : public std::exception {
            public :
                virtual const char* what() const throw() {
                    return ("Cannot process form. Grade too low!!");
                }
        };
        class FormNotSignedException : public std::exception {
            public :
                virtual const char* what() const throw() {
                    return ("Cannot execute form. Form is not signed!!");
                }
        };
};
std::ostream &operator<<(std::ostream &os, const AForm &form);
#endif
