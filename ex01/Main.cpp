/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:07:34 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/10/31 12:00:02 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "headers/Contact.hpp"
#include "headers/PhoneBook.hpp"

int main(void)
{
    Contact contact;
    PhoneBook phoneBook;
    
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    std::cout << "Enter First Name: ";
    std::getline(std::cin, firstName);
    contact.setFirstName(firstName);

    std::cout << "Enter Last Name: ";
    std::getline(std::cin, lastName);
    contact.setLastName(lastName);

    std::cout << "Enter Nickname: ";
    std::getline(std::cin, nickname);
    contact.setNickname(nickname);

    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phoneNumber);
    contact.setPhoneNumber(phoneNumber);
    
    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, darkestSecret);
    contact.setDarkestSecret(darkestSecret);

    phoneBook.addContact(contact);
    phoneBook.displayContacts();

    return (0);
}