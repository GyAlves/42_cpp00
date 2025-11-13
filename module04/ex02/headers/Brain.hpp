/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 02:00:00 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/12 02:00:00 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {

    private:
        std::string ideas[100];

    public:

        Brain();
        Brain(const Brain &other);
        Brain &operator=(const Brain &other);
        ~Brain();

        std::string getIdea(int index) const;
        void        setIdea(int index, const std::string &idea);
};

#endif
