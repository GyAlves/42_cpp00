/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:08:45 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/05 20:15:08 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {
    
    private:
        std::string type;
        
    public:
    
        Weapon(std::string type);
        Weapon();
        ~Weapon();

        // Setters
        void    setType(std::string type);

        // Getters
        const std::string& getType() const;
};

#endif