/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 01:40:00 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/12 23:10:49 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal {

    protected:
        std::string type;

    public:

        AAnimal();
        AAnimal(const AAnimal &other);
        AAnimal &operator=(const AAnimal &other);
        virtual ~AAnimal();

        virtual void        makeSound() const = 0;
        virtual std::string getType() const;
};

#endif
