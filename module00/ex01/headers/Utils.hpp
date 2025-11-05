/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:42:39 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/11/02 17:43:27 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include "PhoneBook.hpp"

std::string formatCommandInput(const std::string& input);
void handleAddCommand(PhoneBook& phoneBook);
void handleSearchCommand(PhoneBook& phoneBook);

#endif