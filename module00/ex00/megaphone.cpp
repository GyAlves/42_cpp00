/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 20:11:56 by galves-a          #+#    #+#             */
/*   Updated: 2025/10/28 21:36:09 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
    std::string input;
    
    if (argc < 2)
    {
        std::cout << " * LOUD AND UNBEARABLE FEEDBACK NOISE * " << std::endl;
        return (0);
    }

    for (int counter = 1; counter < argc; counter++)
    {
        std::string parameter;
        
        parameter = argv[counter];

        for (size_t index = 0; index < parameter.length(); index++)
            parameter[index] = std::toupper(parameter[index]);
        
        std::cout << parameter;
    }
    
    std::cout << std::endl;
    
    return (0);
}