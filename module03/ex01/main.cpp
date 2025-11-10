/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:37:46 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/10 17:14:16 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ClapTrap.hpp"
#include "headers/ScavTrap.hpp"
#include <iostream>

void printSeparator(const std::string &title)
{
    std::cout << "\n========== " << title << " ==========\n" << std::endl;
}

int main()
{
    printSeparator("Constructor and Destructor Test");
    {
        std::cout << "Creating ScavTrap:\n" << std::endl;
        ScavTrap warrior("Scavy");
        std::cout << "\n--- ScavTrap Scavy will be destroyed now ---\n" << std::endl;
    }

    printSeparator("ScavTrap Functionality Test");
    {
        ScavTrap guard("Guardian");
        std::cout << std::endl;

        guard.attack("Hell Knight");
        guard.takeDamage(30);
        guard.beRepaired(20);
        guard.guardGate();
    }

    printSeparator("ScavTrap and ClapTrap attack Test");
    {
        ClapTrap clappy("Clappy");
        ScavTrap scavvy("Scavvy");
        std::cout << std::endl;

        clappy.attack("Cerberus");
        scavvy.attack("Night Demon");
    }

    printSeparator("Scavy Energy Depletion Test");
    {
        ScavTrap scavTrap("Scavy");
        std::cout << std::endl;

        for (int i = 0; i < 3; i++)
        {
            std::cout << "Attack #" << i + 1 << ":" << std::endl;
            scavTrap.attack("hell dog");
        }
    }
    
    return (0);
}
