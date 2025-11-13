/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 02:00:00 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/12 23:11:43 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/AAnimal.hpp"
#include "headers/Dog.hpp"
#include "headers/Cat.hpp"
#include "headers/Brain.hpp"

void printSeparator(const std::string& title)
{
    std::cout << "\n==========================================" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "==========================================" << std::endl;
}

int main()
{
    printSeparator("TEST 1: Basic test from subject (no memory leaks)");
    {
        const AAnimal* j = new Dog();
        const AAnimal* i = new Cat();

        delete j; // should not create a memory leak
        delete i;
    }

    printSeparator("TEST 2: Array of Animals (half Dogs, half Cats)");
    {
        const int size = 10;
        AAnimal* animals[size];

        std::cout << "\nCreating array of animals:" << std::endl;
        for (int idx = 0; idx < size; idx++)
        {
            if (idx < size / 2)
                animals[idx] = new Dog();
            else
                animals[idx] = new Cat();
        }

        std::cout << "\nTesting sounds:" << std::endl;
        for (int idx = 0; idx < size; idx++)
        {
            std::cout << "Animal[" << idx << "] (" << animals[idx]->getType() << "): ";
            animals[idx]->makeSound();
        }

        std::cout << "\nDeleting all animals:" << std::endl;
        for (int idx = 0; idx < size; idx++)
        {
            delete animals[idx];
        }
    }

    printSeparator("TEST 3: Deep copy test with Dog (copy constructor)");
    {
        std::cout << "Creating original dog:" << std::endl;
        Dog originalDog;

        std::cout << "\nSetting ideas in original dog's brain:" << std::endl;
        originalDog.getBrain()->setIdea(0, "Chase the ball");
        originalDog.getBrain()->setIdea(1, "Eat food");
        originalDog.getBrain()->setIdea(2, "Sleep on couch");

        std::cout << "\nCreating copy of dog (deep copy):" << std::endl;
        Dog copiedDog(originalDog);

        std::cout << "\nOriginal dog's ideas:" << std::endl;
        for (int i = 0; i < 3; i++)
            std::cout << "  Idea " << i << ": " << originalDog.getBrain()->getIdea(i) << std::endl;

        std::cout << "\nCopied dog's ideas:" << std::endl;
        for (int i = 0; i < 3; i++)
            std::cout << "  Idea " << i << ": " << copiedDog.getBrain()->getIdea(i) << std::endl;

        std::cout << "\nModifying original dog's ideas:" << std::endl;
        originalDog.getBrain()->setIdea(0, "MODIFIED IDEA");

        std::cout << "\nOriginal dog's idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
        std::cout << "Copied dog's idea 0: " << copiedDog.getBrain()->getIdea(0) << std::endl;

        if (originalDog.getBrain()->getIdea(0) != copiedDog.getBrain()->getIdea(0))
            std::cout << "\n✓ Deep copy works! Ideas are independent." << std::endl;
        else
            std::cout << "\n✗ SHALLOW COPY DETECTED! This is wrong!" << std::endl;

        std::cout << "\nBrain addresses:" << std::endl;
        std::cout << "  Original dog's brain: " << originalDog.getBrain() << std::endl;
        std::cout << "  Copied dog's brain: " << copiedDog.getBrain() << std::endl;

        if (originalDog.getBrain() != copiedDog.getBrain())
            std::cout << "✓ Different Brain objects (deep copy)" << std::endl;
        else
            std::cout << "✗ Same Brain object (shallow copy - WRONG!)" << std::endl;
    }

    printSeparator("TEST 4: Deep copy test with Cat (assignment operator)");
    {
        std::cout << "Creating two cats:" << std::endl;
        Cat cat1;
        Cat cat2;

        std::cout << "\nSetting ideas in cat1's brain:" << std::endl;
        cat1.getBrain()->setIdea(0, "Hunt mice");
        cat1.getBrain()->setIdea(1, "Climb tree");

        std::cout << "\nSetting ideas in cat2's brain:" << std::endl;
        cat2.getBrain()->setIdea(0, "Scratch furniture");
        cat2.getBrain()->setIdea(1, "Ignore humans");

        std::cout << "\nBefore assignment:" << std::endl;
        std::cout << "  cat1 idea 0: " << cat1.getBrain()->getIdea(0) << std::endl;
        std::cout << "  cat2 idea 0: " << cat2.getBrain()->getIdea(0) << std::endl;

        std::cout << "\nAssigning cat1 to cat2 (deep copy):" << std::endl;
        cat2 = cat1;

        std::cout << "\nAfter assignment:" << std::endl;
        std::cout << "  cat1 idea 0: " << cat1.getBrain()->getIdea(0) << std::endl;
        std::cout << "  cat2 idea 0: " << cat2.getBrain()->getIdea(0) << std::endl;

        std::cout << "\nModifying cat1's ideas:" << std::endl;
        cat1.getBrain()->setIdea(0, "MODIFIED CAT IDEA");

        std::cout << "\nAfter modification:" << std::endl;
        std::cout << "  cat1 idea 0: " << cat1.getBrain()->getIdea(0) << std::endl;
        std::cout << "  cat2 idea 0: " << cat2.getBrain()->getIdea(0) << std::endl;

        if (cat1.getBrain()->getIdea(0) != cat2.getBrain()->getIdea(0))
            std::cout << "\n✓ Deep copy works with assignment operator!" << std::endl;
        else
            std::cout << "\n✗ SHALLOW COPY DETECTED with assignment operator!" << std::endl;

        std::cout << "\nBrain addresses:" << std::endl;
        std::cout << "  cat1's brain: " << cat1.getBrain() << std::endl;
        std::cout << "  cat2's brain: " << cat2.getBrain() << std::endl;

        if (cat1.getBrain() != cat2.getBrain())
            std::cout << "✓ Different Brain objects (deep copy)" << std::endl;
        else
            std::cout << "✗ Same Brain object (shallow copy - WRONG!)" << std::endl;
    }

    printSeparator("TEST 5: Self-assignment test");
    {
        std::cout << "Creating dog:" << std::endl;
        Dog dog;
        dog.getBrain()->setIdea(0, "Original idea");

        std::cout << "\nSelf-assigning through reference (avoiding compiler warning):" << std::endl;
        Dog& dogRef = dog;
        dog = dogRef;

        std::cout << "\nIdea after self-assignment: " << dog.getBrain()->getIdea(0) << std::endl;
        std::cout << "✓ Self-assignment handled correctly (no crash, no memory leak)" << std::endl;
    }

    printSeparator("TEST 6: Polymorphism with Brain");
    {
        std::cout << "Creating Animal pointers to Dog and Cat:" << std::endl;
        AAnimal* dog = new Dog();
        AAnimal* cat = new Cat();

        std::cout << "\nDeleting through Animal pointers:" << std::endl;
        delete dog; // Brain should be deleted properly
        delete cat; // Brain should be deleted properly

        std::cout << "\n✓ Virtual destructors ensure Brain is deleted" << std::endl;
    }

    printSeparator("TEST 7: Testing all 100 ideas");
    {
        std::cout << "Creating dog and filling all 100 ideas:" << std::endl;
        Dog dog;

        for (int i = 0; i < 100; i++)
        {
            std::string idea = "Idea number ";
            idea += (char)('0' + (i / 10));
            idea += (char)('0' + (i % 10));
            dog.getBrain()->setIdea(i, idea);
        }

        std::cout << "\nFirst 5 ideas:" << std::endl;
        for (int i = 0; i < 5; i++)
            std::cout << "  " << dog.getBrain()->getIdea(i) << std::endl;

        std::cout << "\nLast 5 ideas:" << std::endl;
        for (int i = 95; i < 100; i++)
            std::cout << "  " << dog.getBrain()->getIdea(i) << std::endl;

        std::cout << "\n✓ All 100 ideas can be stored and retrieved" << std::endl;
    }

    printSeparator("END OF TESTS");
    std::cout << "\nRun with valgrind to verify no memory leaks!" << std::endl;
    std::cout << "valgrind --leak-check=full ./Brain" << std::endl;

    return 0;
}
