/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:12:28 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/08 16:47:52 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
    
    private:
        //
    
    public:
    
        ScavTrap(std::string name);
        ~ScavTrap();

        void attack(const std::string &target);
        
        voidGuardGate();       
};

#endif