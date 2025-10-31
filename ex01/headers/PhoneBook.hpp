/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:07:29 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/10/31 11:50:53 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int     contactCount;
        
    public:
        PhoneBook();
        ~PhoneBook();

        // Setters
        void setContactCount(int count);

        // Getters
        int getContactCount() const;

        void addContact(const Contact& contact);
        void displayContacts() const;
};

#endif