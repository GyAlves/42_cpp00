/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 01:40:00 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/12 01:40:00 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Animal.hpp"
#include "headers/Dog.hpp"
#include "headers/Cat.hpp"
#include "headers/WrongAnimal.hpp"
#include "headers/WrongCat.hpp"

void printSeparator(const std::string& title)
{
    std::cout << "\n==========================================" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "==========================================" << std::endl;
}

int main()
{
    printSeparator("TEST 1: Basic test from subject");
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); // will output the cat sound!
        j->makeSound();
        meta->makeSound();

        delete meta;
        delete j;
        delete i;
    }

    printSeparator("TEST 2: Testing WrongAnimal (without virtual)");
    {
        const WrongAnimal* wrongMeta = new WrongAnimal();
        const WrongAnimal* wrongCat = new WrongCat();

        std::cout << wrongCat->getType() << " " << std::endl;
        wrongCat->makeSound(); // will output WrongAnimal sound! (WRONG!)
        wrongMeta->makeSound();

        delete wrongMeta;
        delete wrongCat;
    }

    printSeparator("TEST 3: Direct object instantiation");
    {
        Animal animal;
        Dog dog;
        Cat cat;

        std::cout << "\nCalling makeSound on each:" << std::endl;
        animal.makeSound();
        dog.makeSound();
        cat.makeSound();

        std::cout << "\nTypes:" << std::endl;
        std::cout << "Animal type: " << animal.getType() << std::endl;
        std::cout << "Dog type: " << dog.getType() << std::endl;
        std::cout << "Cat type: " << cat.getType() << std::endl;
    }

    printSeparator("TEST 4: Copy constructor tests");
    {
        Dog originalDog;
        std::cout << "\nCreating copy of Dog:" << std::endl;
        Dog copiedDog(originalDog);

        std::cout << "\nOriginal Dog sound: ";
        originalDog.makeSound();
        std::cout << "Copied Dog sound: ";
        copiedDog.makeSound();
    }

    printSeparator("TEST 5: Assignment operator tests");
    {
        Cat cat1;
        Cat cat2;

        std::cout << "\nAssigning cat1 to cat2:" << std::endl;
        cat2 = cat1;

        std::cout << "\ncat1 sound: ";
        cat1.makeSound();
        std::cout << "cat2 sound: ";
        cat2.makeSound();
    }

    printSeparator("TEST 6: Array of Animals (polymorphism)");
    {
        const Animal* animals[4];

        std::cout << "Creating array of animals:" << std::endl;
        animals[0] = new Dog();
        animals[1] = new Cat();
        animals[2] = new Dog();
        animals[3] = new Cat();

        std::cout << "\nTesting polymorphism:" << std::endl;
        for (int i = 0; i < 4; i++)
        {
            std::cout << "Animal[" << i << "] type: " << animals[i]->getType() << " - Sound: ";
            animals[i]->makeSound();
        }

        std::cout << "\nDeleting animals:" << std::endl;
        for (int i = 0; i < 4; i++)
        {
            delete animals[i];
        }
    }

    printSeparator("TEST 7: Destructor order test");
    {
        std::cout << "Creating Animal pointer to Dog:" << std::endl;
        Animal* dog = new Dog();
        std::cout << "\nDeleting through Animal pointer:" << std::endl;
        delete dog;

        std::cout << "\nNote: Without virtual destructor, only Animal destructor would be called!" << std::endl;
    }

    printSeparator("TEST 8: Wrong vs Right comparison");
    {
        std::cout << "RIGHT WAY (with virtual):" << std::endl;
        const Animal* rightCat = new Cat();
        std::cout << "Type: " << rightCat->getType() << " - Sound: ";
        rightCat->makeSound();
        delete rightCat;

        std::cout << "\nWRONG WAY (without virtual):" << std::endl;
        const WrongAnimal* wrongCat = new WrongCat();
        std::cout << "Type: " << wrongCat->getType() << " - Sound: ";
        wrongCat->makeSound();
        delete wrongCat;
    }

    printSeparator("END OF TESTS");

    return 0;
}
