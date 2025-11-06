/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ValidateInput.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:00:53 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/06 02:15:48 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ValidateInput.hpp"

bool parseAndValidateArgs(int argc, char *argv[], std::string& filename, std::string& s1, std::string& s2)
{
    if (argc != 4)
    {
        std::cout << "Usage: " << argv[0] << " <filename>.txt <string1> <string2>" << std::endl;
        return (false);
    }

    filename = argv[1];
    s1 = argv[2];
    s2 = argv[3];

    if (filename.empty())
    {
        std::cout << "Error: filename cannot be empty" << std::endl;
        return (false);
    }
    if (s1.empty())
    {
        std::cout << "Error: search string (s1) cannot be empty" << std::endl;
        return (false);
    }
    return (true);
}
