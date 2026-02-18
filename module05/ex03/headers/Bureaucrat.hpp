/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 01:40:00 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/12 01:40:00 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <exception>
#include <string>
#include <iostream>
#include <ostream>
class AForm;
class Bureaucrat {
    protected:
        std::string name;
        int         grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        virtual ~Bureaucrat();
        std::string getName() const;
        int         getGrade() const;
        void    setName(std::string name);
        void    setGrade(int grade);
        void    incrementGrade();
        void    decrementGrade();
        void    signForm(AForm& form);
        void    executeForm(AForm const & form);
        class GradeTooHighException : public std::exception {
            public :
                virtual const char* what() const throw() {
                    return ("Access Denied. Grade too high!!");
                }
        };
        class GradeTooLowException : public std::exception {
            public :
                virtual const char* what() const throw() {
                    return ("Access Denied. Grade too low!!");
                }
        };
};
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
#endif
