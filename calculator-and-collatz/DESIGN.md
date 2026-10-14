# Homework 2: Design Document

  * author: Abrham Dawit
  * date: October 18, 2024

## introduction
In this week homework, I will try to learn and write some short functions that deal with numbers, array of numbers and pointers in C programming.

TODO(you): I love C programming language! It is super fun!

## function 1: computing the next Collatz number
In this function, I'm going to compute the next collatz number based on a given input number that is either even or odd. For example, if the given input number is even, then it would return half the input number. Otherwise, if the given number is odd, it will return three times the given number, plus one. That's pretty much the formula of the Collatz number.

## function 2: counting Collatz steps to convergence
In this function, I'm going to repeatdly compute the next Collatz number, until I reach the value of 1. For example if the input given was already one, I need to return zero as it took me zero steps to converge. To write this function, I'm going to use iterative strategy with a while loop in order to implement the function.

## function 3: finding the maximum element of an array
In this function, I'm going to find the maximum element of an array using for loop in order to iterate over the array until I find the maximum value. So to start, I will store the first element as the initial maximum and then update it as it loops only if I find a greater element.

## function 4: summing all of the positive elements of an array
In this function, I'm going to calculate the sum of all positive elements in an array using for loop and if statement. To do this, I'm going to to iterate through each  array, checking if the element is positive or not. If it is, I am going to add it to the sum function. Then at the end, I'm going to return the sum total of the positive elements in the array.

## function 5: counting the negative numbers in an array
In this fuction, I'm going to count how many negative numbers there are in an array using for loop and if statement until I reach the end of the erray. To do this, I'm going to create a count variable and set it to zero. Then after that, everytime I found a negative number in the array, I'm going to increment the count variable and then return the count amount.

## the calculator program
The calculator program looks like this. First it reads each line of a filename that contains a series of numbers and arithmetic operators which will then be stored as a long. Then it reads the numbers and processes an arthimethic operations. After that, it updates the running total using the operator that it was using previously and prints it. Last but not least, when the program is running division and the number is 0, I have to immediatedly return an error message and terminate immediately.
