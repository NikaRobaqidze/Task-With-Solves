## Introduction
Mr. Burns cares about almost nothing ... just himself and his money. Thus, when a radioactive substance leaked from its power plant, it claimed the lives of several species of wildlife. He was very concerned about how the public perceived this, as public opinion would affect his income, rumors surfaced around the Springfield nuclear power plant. One of them was concern about possible cases of mutation in Springfield's rare river duckweed. In the wild, after a little over 50, the word "extinction" was heard. Thus, to stop the media, Mr. Burns seized 30 of them to analyze for signs of mutation. He found that the mutation rate is 2% every month, but when a mutation occurs, it causes the duck cards to become sterile and unable to reproduce. From the available information, he wants to create computer simulations that the press loves very much. This is where your homework begins!
##Specifications
In this task you will create a class called platypus. Below, we describe what defines platypus. You will also create a main function in which you will create platypus type objects to test the functionality defined by your new user. By the way, this type of master is called a driver because it is only used to test something (new). In this driver, you will create enough objects of your new type (s) to adequately test their functions. How you manage to do this is up to you.

Platypus class must contains the following
## Member data (variables)
  - float  weight;
  - short age (months);
  - char name (initial);
  - char gender;
  - bool alive (live or die);
  - bool mutant (mutant or not);
 
 ## Member functions
  - A default constructor that creates a dead duck card.
  - A parameter constructor that assigns values to determine the values of the object's gender, weight, age, and name variables, and by default the object must be alive and not mutant.
  - Function print that displays information about the duck card in a beautiful and easy-to-understand form and format.
  - Function age_me which returns nothing but changes the age of the object. It should provide a 2% chance that the object might become a mutant. Each time the age_me function is called, the object has a chance to die and this chance is equal to 10 times the weight of the duck card, ie a 5 kg duck card has a 50% chance of dying. The probability of death of Ikhniskarta of 10 and more kilograms is 100%.
  - A fight function that takes another Platypus as a parameter. Which fights the duck card on which the function is called (calling_platypus) against another that is passed as a parameter (other_platypus). The winner is determined by the "fight ratio" (calling_platypus weight / other_platypus weight) * 50. A random number from 1 to 100 is taken. If the power ratio is greater than this random number calling_platypus wins, otherwise the winner is second.
  - The eat function increases the weight of the duck card by 0.1% - 5.0% of its current weight.
  - A hatch function that assigns the newborn Platypus the following parameters alive = true, mutant = false, and age = 0. Sex 'm' or 'f' with equal probability. Weight randomly from 0.1 to 1.0 kg. The name can be defined by the user or the name can be any randomly selected character (character chosen randomly).
## Notice
Think very carefully about how to use the functions listed above when writing them. There are definitely circumstances when some function should not be performed. For example, a dead duckling eats nothing.

## Testing of class
You need to test your Platypus class thoroughly in your driver program. You must call all member functions in it. You need to display on the screen what it is doing and what is happening as a result of these changes, what is happening to the corresponding object (Duck Card / Platypus). The combat function will require two platforms: one to which you have to call the combat function and the other to pass as a parameter to this function.

Adequacy in the use of constants will be evaluated: Function parameters that do not change the function must be declared using const (note the design of the Time class). Consider declaring the mutation parameter constant, if it is changed later, the code will be easier to convert ... In addition, member shifts must be accompanied by corresponding gethers and setters.
