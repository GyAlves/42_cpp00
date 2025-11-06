/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceContent.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 02:29:06 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/11/06 02:59:17 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ReplaceContent.hpp"

std::string replaceContent(const std::string &content, const std::string &s1, const std::string &s2)
{
    std::string modifiedContent = "";
    size_t      pos = 0;
    size_t      found;

    while((found = content.find(s1, pos)) != std::string::npos)
    {
        modifiedContent += content.substr(pos, found - pos);
        modifiedContent += s2;

        pos = found + s1.length();
    }

    modifiedContent += content.substr(pos);
    return (modifiedContent);
}