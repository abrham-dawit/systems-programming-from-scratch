# Homework 2: Design Document

  * author: Abrham Dawit
  * date: October 25, 2024

## introduction
In this week homework, I will try to learn and write some short functions that deal with strings, arrays and function pointers in C programming using the idea of 'reduce' which was covered in class.

TODO(you): I love C programming language! It is getting very exciting and challenging every week.

## function 1: strings: is one string a suffix of the other?
In this function, I'm going to check if needle is a suffix of haystack, meaning it should match exacltly the last part of the haystack. To do this, I'm going to first calculate the length of both strings and compare needle to the end of haystack. Then, if needle is longer than haystack, I'll return false immediately. Otherwise, I'll compare the characters in reverse order from the end of both strings.

## function 2: strings: repeat a string n times
In this function, I'm going to create a new string that consists of n reptitions of the string s. To do this, I'm going to first allocate memory for (n * len(s) + 1) to hold the repeated string with a null terminator. Then, I'll use a loop to copy s into the new string n times. Finally, I'll return the pointer to the new string.

## function 3: strings: is this string a palindrome?
In this function, I'm going to check if a string is a palindrome. To do this, I'm going to first filter the string by removing all non-alphabetic characters including spaces and punctuations. Then I'm going to create a new version of s with only lowercase alphabetic characters. After that, I'm going to use two pointers to compare the start and end charachters, moving towards the center. Then if all charachters match, I'll return true. Otherwise, I'll return false.

## function 4: arrays: compute the dot product of two arrays
In this function, I'm going to calculate the dot product of two float arrays, which is the sum of pairwise products of corresponding elements. To do this, I'm going to create and initialize a variable sum to 0.0 first. Then, for each index i, I'm going to mulitply vec_a[i] by vec_b[i] and add this product to the cumulative sum variable. Finally, after looping through all the elements, I'll return the sum variable.

## function 5: reduce
In this fuction, I'm going to collect values in an array using a specified function. To do this, I'm going to create and initialize a variable called coll to 0. Then, I'm going to loop through nums, updating the collector variable coll by applying f to it and each element in turn. Finally, I'll return the final coll after processing all elements.

## function 6: finding the maximum element of an array with reduce
In this function, I'm going to find the maximum value of an array using reduce. To do this, I'm going to implement a helper function that returns the larger of two values. Then I'll use reduce with the helper function, the input array, and INT_MIN as the initial value to determine the maximum element.

## function 7: summing all of the positive elements of an array with reduce
In this function, I'm going to sum only the positive elements of an array using reduce. To do this, I'm going to create a helper function add_if_positive that adds val to the collector variable coll only if val is positive. Then, I'll pass the nums function, and an initial value of 0 to reduce to get the sum of only positive elements.
