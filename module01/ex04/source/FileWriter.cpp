/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileWriter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 02:59:00 by gyasminalve      #+#    #+#             */
/*   Updated: 2025/11/06 02:59:00 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/FileWriter.hpp"

bool writeFileContent(const std::string& filename, const std::string& content)
{
    std::string outputFile = filename + ".replace";
    std::ofstream file(outputFile.c_str());

    if (!file.is_open())
    {
        std::cerr << "Error: could not create file " << outputFile << std::endl;
        return (false);
    }

    file << content;
    file.close();

    if (file.fail())
    {
        std::cerr << "Error: failed to write to file " << outputFile << std::endl;
        return (false);
    }

    return (true);
}
