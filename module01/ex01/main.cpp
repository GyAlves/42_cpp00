/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 01:53:03 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/11/05 02:20:04 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Zombie.hpp"

int main()
{
    std::string zombie_name;
    int horde_size;

    std::cout << "Enter the name for the horde of zombies: ";
    std::getline(std::cin, zombie_name);
    
    std::cout << "Enter the number of zombies in the horde: ";
    std::cin >> horde_size;

    Zombie *horde = zombieHorde(horde_size, zombie_name);

    for (int counter = 0; counter < horde_size; counter++)
        horde[counter].announce();
    
    delete[] horde;
}