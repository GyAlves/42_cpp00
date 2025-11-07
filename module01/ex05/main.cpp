/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 01:19:43 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/11/07 01:19:44 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Harl.hpp"
#include <iostream>
#include <string>

int main(void)
{
    Harl harl;
    std::string level;

    std::cout << "Enter complaint level: ";
    std::cin >> level;

    harl.complain(level);

    return 0;
}
