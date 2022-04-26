// Copyright (c) 2022 Hertz All rights reserved.
//
// Created by: Hertz Antonella
// Created on: Apr, 26, 2022.
// This program generates a random number, compares
// it to the user number and keeps looping until
// they guess it right.

#include <iostream>
#include <random>

int main() {
    // Generates random number
    int randomNumber;
    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 9);  // [0,100]
    randomNumber = idist(rgen);
    // std::cout << randomNumber << std::endl;

    // declare variable
    int loop_counter = 0;
    int userNum;
    std::string userNumString;


    while (true) {
        // Ask the user to guess any number from 0 to 10
        std::cout << "Enter a number between 0 and 10: ";
        std::cin >> userNumString;
        std::cout << std::endl;

        // convert from string to int
       try {
         userNum = std::stoi(userNumString);

           // range
            if (userNum >= 0 && userNum <= 10) {
        // compare if userNumis equal to randomNumber.
                if (userNum == randomNumber) {
                    std::cout << std::endl;
                    std::cout << " correct, cogrates";
                    std::cout << std::endl;
                    break;
              } else {
                    std::cout << " Incorrect. Please try again.\n";
                    std::cout << std::endl;
                    loop_counter = loop_counter + 1;
                    std::cout << std::endl;
                }
          } else {
               std::cout << "Please enter a number from 0 to 10.\n";
           }
        // handling any possible errors.
     } catch (std::invalid_argument) {
            std::cout << "Invalid input, Please enter numbers(1,2,3..)\n";
       }
    }
}
