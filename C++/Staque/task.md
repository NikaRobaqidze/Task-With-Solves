## Programming assignment  “Staque”

Create a data structure "Staque" that can only store integers. The working principle is as follows:
  1) If the number is even, you add to the top of Staque.
  2) If the number is odd, you add to the bottom of Staque.
  3) If you are trying to delete a number, you must either delete it from the beginning or from the end, but you must follow the rule LIFO (Last In First Out).

Write C ++ code to develop such a structure and use the link list to implement it.

Example of what the interface should look like (note this is just an example - it can be added / beautified):
  - Enter the numbers in the stack in the following order 1, 3, 2, 4, 6, 8 , 9 ;
  - Display its contents: For the numbered numbers, the stack should look like this: (top) 8 6 4 2 1 3 9 (bottom)
  - Delete 2 even and one even number and remove the remaining elements, because deleting is always based on the LIFO rule, the first number you have to delete will be 8 and then 6 and then 9, so you have to leave: (top) 4 2 1 3 (bottom).
  - Test the program on add / delete operations for a minimum of 3 different number sequences and the corresponding different types of deletions.

(Note that maybe we say delete 2 numbers and do not specify odd or even, or say there are not so many odd and / or even numbers - consider other scenarios to deal with possible errors).

You must have 2 files for one structure and the other to test it.

As in the previous assignments you should upload the code and the corresponding review of the completed assignment with its screens.
