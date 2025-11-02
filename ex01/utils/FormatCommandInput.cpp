/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormatCommandInput.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:41:04 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/11/02 17:50:23 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Utils.hpp"

std::string formatCommandInput(const std::string& input)
{
    std::string formattedInput;
    
    for (size_t index = 0; index < input.length(); index++)
    {
        formattedInput += std::toupper(input[index]);
    }
    
    return formattedInput;
}