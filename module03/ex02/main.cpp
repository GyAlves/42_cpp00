/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:40:00 by gyasminalve      #+#    #+#             */
/*   Updated: 2025/11/10 17:40:00 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ClapTrap.hpp"
#include "headers/ScavTrap.hpp"
#include "headers/FragTrap.hpp"
#include <iostream>

void printSeparator(const std::string &title)
{
    std::cout << "\n========== " << title << " ==========\n" << std::endl;
}

int main()
{
    printSeparator("TEST 1: FragTrap Construction/Destruction Chaining");
    {
        std::cout << "Creating FragTrap 'Fraggy':\n" << std::endl;
        FragTrap robot("Fraggy");
        std::cout << "\n--- FragTrap 'Fraggy' will be destroyed now ---\n" << std::endl;
    }

    printSeparator("TEST 2: FragTrap Basic Methods");
    {
        FragTrap bot("Destroyer");
        std::cout << std::endl;

        bot.attack("Target1");
        bot.takeDamage(40);
        bot.beRepaired(20);
        bot.highFivesGuys();
    }

    printSeparator("TEST 3: Comparing ClapTrap, ScavTrap, and FragTrap");
    {
        ClapTrap clap("Clappy");
        ScavTrap scav("Scavvy");
        FragTrap frag("Fraggy");
        std::cout << std::endl;

        std::cout << "ClapTrap attacks:" << std::endl;
        clap.attack("Enemy");

        std::cout << "\nScavTrap attacks:" << std::endl;
        scav.attack("Enemy");

        std::cout << "\nFragTrap attacks:" << std::endl;
        frag.attack("Enemy");

        std::cout << "\nSpecial abilities:" << std::endl;
        scav.guardGate();
        frag.highFivesGuys();
    }

    printSeparator("TEST 4: FragTrap Copy Constructor");
    {
        FragTrap original("Alpha");
        std::cout << "\nCreating copy of 'Alpha':\n" << std::endl;
        FragTrap copy(original);
        std::cout << std::endl;

        std::cout << "Original uses special ability:" << std::endl;
        original.highFivesGuys();

        std::cout << "\nCopy uses special ability:" << std::endl;
        copy.highFivesGuys();
    }

    printSeparator("TEST 5: FragTrap Assignment Operator");
    {
        FragTrap bot1("Beta");
        FragTrap bot2("Gamma");
        std::cout << std::endl;

        std::cout << "Before assignment:" << std::endl;
        bot1.highFivesGuys();
        bot2.highFivesGuys();

        std::cout << "\nAssigning Beta to Gamma:\n" << std::endl;
        bot2 = bot1;

        std::cout << "\nAfter assignment:" << std::endl;
        bot2.highFivesGuys();
    }

    printSeparator("TEST 6: FragTrap Default Constructor");
    {
        FragTrap anonymous;
        std::cout << std::endl;
        anonymous.attack("Enemy");
        anonymous.highFivesGuys();
    }

    printSeparator("TEST 7: FragTrap High-Five Party");
    {
        FragTrap bot1("Party1");
        FragTrap bot2("Party2");
        FragTrap bot3("Party3");
        std::cout << std::endl;

        std::cout << "High-five party begins!" << std::endl;
        bot1.highFivesGuys();
        bot2.highFivesGuys();
        bot3.highFivesGuys();
    }

    printSeparator("TEST 8: All Three Types Together");
    {
        ClapTrap clap("TeamClap");
        ScavTrap scav("TeamScav");
        FragTrap frag("TeamFrag");
        std::cout << std::endl;

        std::cout << "Team attacks:" << std::endl;
        clap.attack("Boss");
        scav.attack("Boss");
        frag.attack("Boss");

        std::cout << "\nTeam takes damage:" << std::endl;
        clap.takeDamage(5);
        scav.takeDamage(20);
        frag.takeDamage(30);

        std::cout << "\nTeam uses special abilities:" << std::endl;
        scav.guardGate();
        frag.highFivesGuys();
    }

    return 0;
}
