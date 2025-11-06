/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReader.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 01:37:23 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/11/06 02:11:06 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/FileReader.hpp"

std::string readFileContent(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    std::string content;
    std::string line;

    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return "";
    }

    while(std::getline(file, line))
    {
        content += line;
        if (!file.eof())
            content += "\n";
    }

    file.close();
    return content;
}