# Homework 5: Design Document

  * author: Abrham Dawit
  * date: November 18, 2024

## introduction
In this week homework, I will try to learn and write some short functions using strings, searching, words and I/O to make my own version of wordle, a word-guessing game that has become popular in the last few years.

TODO(you): Even though I love C programming language, it is getting a bit complex every week and still, it's exciting. I Can't wait to learn more C stuff in the coming weeks.

## function 1: score_guess
In this function, I'm going to compare the guessed word with the secret word and fill the result array with 'x','y', or 'g' based on the criteria given. This result string uses 'x', 'y', and 'g' to indicate correct letters, letters in the wrong position, and incorrect letters. To implement this, I'm going to compare each letter of the guess to the secret word, tracking matches and marking the result string. Also, in this function I will make it return true if the guess exactly matches the secret word and false otherwise.

## function 2: valid_guess
In this function, I'm going to check if the player's 5-letter guess is a valid word. To do this, I'm going to check if the given 5-letter word exists in the vocabulary array. Then, I'm going to iterate through the vocabulary and use strcmp to compare the guess against each word, returning true if a match is found, otherwise false.

## function 3: load_vocabulary
In this function, I'm going to read a list of 5-letter words form a specified file and store them in a dynamically allocated array of strings. To do this, I'm going to utilize fopen() to open the file, strdup() to copy words into the array, and realloc() to resize the array as more words are read.

## function 4: free_vocabulary
In this function, I'm going to free the memory allocated for the vocabulary. To do this, I'm going to iterate through the array, freeing the memory for each word using free(), and finally free the vocabulary array itself.
