/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:37:46 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/10 17:30:46 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ClapTrap.hpp"
#include <iostream>

void printSeparator(const std::string &title)
{
    std::cout << "\n========== " << title << " ==========\n" << std::endl;
}

int main()
{
    printSeparator("Constructor and Destructor Test");
    {
        ClapTrap warrior("Clappy");
        std::cout << "\n--- Clappy will be destroyed now ---\n" << std::endl;
    }

    printSeparator("ClapTrap Functionality Test");
    {
        ClapTrap clap("clappy");
        std::cout << std::endl;

        clap.attack("bread zombie");
        clap.takeDamage(5);
        clap.beRepaired(3);
    }

    printSeparator("Copy Constructor Test");
    {
        ClapTrap walker("White Walker");
        std::cout << "\nCreating copy of White Walker:\n" << std::endl;
        ClapTrap walkerCopy(walker);
        std::cout << std::endl;

        walker.attack("Jon Snow");
        walkerCopy.attack("Daenerys Targaryen");
    }

    printSeparator("Assignment Operator Test");
    {
        ClapTrap robot1("Beta");
        ClapTrap robot2("Gamma");
        std::cout << std::endl;

        std::cout << "Before assignment:" << std::endl;
        robot1.attack("Enemy1");
        robot2.attack("Enemy2");

        std::cout << "\nAssigning Beta to Gamma:\n" << std::endl;
        robot2 = robot1;

        std::cout << "\nAfter assignment, Gamma attacks:" << std::endl;
        robot2.attack("Enemy3");
    }

    printSeparator("Default Constructor Test");
    {
        ClapTrap nameless;
        std::cout << std::endl;
        nameless.attack("Zombie Dog");
    }

    printSeparator("Clappy Fight Simulation Test");
    {
        ClapTrap fighter("ClappyIronFirst");
        std::cout << std::endl;

        fighter.attack("ZappySwasnson");
        fighter.takeDamage(8);
        fighter.beRepaired(5);
        fighter.attack("ZappySwasnson");
        fighter.takeDamage(10);
    }

    return 0;
}
