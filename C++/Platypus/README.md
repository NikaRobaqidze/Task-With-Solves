# Class Platypus (Documentation)
## Installation
1) Download software environment which support C++ language. Click on [link](https://visualstudio.microsoft.com/downloads/) to download environment which I use (Microsoft studio 2019).
2) Create new C++ Empty project.
  	- Window application (console application).
  	- Create empty project. (At creating click on checkbox).
  	- Browse to path, where you want to create your project.
3) Download from this directory two file:
  	- Source.cpp
  	- Platypus.h
4) Move both file to your project "source files".
  	- Open using environment.
  	- On task bar mouse right click on "source files".
  	- Click on "Add items".
  	- Browse to path where both file have donwloaded.
  	- Select both file and click "Add".

# Documentation
Complex documentation with screens can see in "Documentation.docx" file.

## Libraries
  - iostream (For printing data on screen);
  - iomanip (To display the data in a beautiful format);
  - random (To select random numbers. To imitate the assumption.);

When creating a class by default the it's variables are assigned values by this way program does not automatically enter an invalid value (from buffer):
  - float weight (kg) A number taken at random from the interval, 0,1 <= n <= 9;
  - short age (month) A number taken at random from the interval, 0 <= n <= 11;
  - char name A randomly selected letter, including the letters A to Z;
  - char gender A randomly selected letter M (male) or F (female) with the same assumption;
  - bool alive true (live);
  - bool mutant false (No mutant);

## Private functions of the class:
  - checkWeight - The function returns nothing and you only call inside the class. The function checks the chances of Platypus death and outbreaks. The chance of death is equal to 10 times the weight of a duckling, i.e. a 5 kg duckling has a 50% chance of dying. If the platypus weighs 10 or more kilograms it dies (alive = false). The mutation assumption is 2%, or 1/50 is calculated by the following principle:
    - A random number is taken from the interval [1,50]. If this number is equal to 7 (there is no reason to choose a number) the platypus mutates (mutant = true). (The assumption that 1 <= n <= 50 taken is equal to 7 is 1/50, or 2%).

This function is called in the parametric and non-parametric age_me function.

## Public access functions of the class
  - A nonparametric constructor that creates a dead (alive = false) platypus.
  - A parametric constructor that takes as a parameter the sex, weight, age and name of the platypus. By silence the Platypus is alive and not a mutant.
  - print, constant because it does not change the value of variables in a class, a function that displays information about Platypus in a beautiful and easy-to-understand form and format.
  - The function is overloaded, it is set as a parameter for printing on screen, output stream (ostream), as well as the "<<" operator, for easy calling of the function.
  - age_me - a function that changes the age of the Platypus and is overloaded. It is initially checked whether the Platypus is alive. The checkWeight function will be called upon completion. In a nonparametric function, the number n is randomly selected from the interval 1 <= n <= 11, then the age of the platypus increases by n months. If the Platypus is dead a message appears on the screen.
    - The parameter age_me function performs the setter function. The function assigns a modulus (age = abs(age)) of the parameter passed to the Platypus because the age cannot be negative.
 
  - The class has three getter functions that are called in the fight function:
    - getWeight, return weight of Platypus.
    - getName, return name of Platypus.
    - getAlive, return status of alive of Platypus(Is it a live or not).

  - fight, A function that takes another Platypus as a parameter. It mimics the quarrel of the Platypus. The Platypus on which the fight function is called is calling Platypus. At fist is checking the memory address of both Platypus because the platypus cann't quarrel with itself. Also, whether the calling_platypus Platypus is alive, then the life of the Platypus who was summoned to the quarrel. Died Platypus cann't fight. In both case on screen appeared message. Next, (calling_platypus) the weight of the platypus is multiplied by the weight of second. A random number from the interval 1 <= n < 100. If the ratio of forces is greater than this randomly selected number calling_platypus - wins, otherwise the winner is second. The result of the fight is displayed on the screen.
  - eat, a function that increases the weight of the platypus. The function is overloaded. Initially, it is checked whether the Platypus is alive. In the nonparametric function, the number n is randomly selected from the interval 0,1 <= n < 5, then the weight of the duck card increases by n% of the current weight of the platypus. As soon as you gain weight, a message appears on the screen showing how much the duck weight has increased by %.
  - eat, function also takes weight as a parameter, as much as platypus weight should be increased, but this parameter should not be mistaken for the following interval: this parameter should be not less than 0.1% of platypus weight and more than 5% of its weight. In case where a user tries to eat a dead platypus message appeared on the screen.
  - hatch - The function mimics the hatching of a platipus. Its settings have silent values, it means, if the user does not enter the name and / or gender of the newly released Platypus, it will be saved automatically. Also, the newly hatched platypus is alive (alive = true), age (age = 0) 0 months and it is not mutant (mutant = false).
