/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:28:18 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/06 03:03:53 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ValidateInput.hpp"
#include "headers/FileReader.hpp"
#include "headers/ReplaceContent.hpp"
#include "headers/FileWriter.hpp"

int main(int argc,  char *argv[])
{
    std::string result;
    std::string fileContent;
    std::string filename;
    std::string s1;
    std::string s2;

    if (!parseAndValidateArgs(argc, argv, filename, s1, s2))
        return (1);
        
    fileContent = readFileContent(filename);
    if (fileContent == "")
        return (1);
    
    if (s2.empty())
    {
        std::cout << "The replacement string is empty. No changes made to the file." << std::endl;
        return (0);
    }
    
    result = replaceContent(fileContent, s1, s2);

    if (!writeFileContent(filename, result))
        return (1);

    return (0);
}