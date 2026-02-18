/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 01:40:00 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/12 01:40:00 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <string>
#include <iostream>
#include <ostream>

#include "Bureaucrat.hpp"

class Form {

    private:
        const std::string name;
        const int gradeToSign;
        const int gradeToExecute;
        bool isSigned;

    public:
        Form(const std::string& name, int gradeToSign, int gradeToExecute);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

    // Getters

    const std::string getName() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    bool getIsSigned() const;

    // Setters
    void setName(const std::string name);
    void setGradeToSign(const int gradeToSign);
    void setGradeToExecute(const int gradeToExecute);
    void setIsSigned(bool isSigned);

    void beSigned(const Bureaucrat& bureaucrat);

    // Exceptions

    class GradeTooHighException : public std::exception {
        public :
            virtual const char* what() const throw() {
                return ("Cannot sign form. Grade too high!!");
            }
    };

    class GradeTooLowException : public std::exception {
        public :
            virtual const char* what() const throw() {
                return ("Cannot sign form. Grade too low!!");
            }
    };
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
