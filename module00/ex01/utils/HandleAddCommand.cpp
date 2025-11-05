/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HandleAddCommand.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 19:30:00 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/11/02 19:30:00 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../headers/Contact.hpp"
#include "../headers/PhoneBook.hpp"

void handleAddCommand(PhoneBook& phoneBook)
{
    Contact contact;
    contact.createContact();
    phoneBook.addContact(contact);
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Contact added successfully!" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
}
