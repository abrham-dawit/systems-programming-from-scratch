# Homework 6: Design Document

  * author: Abrham Dawit
  * date: November 25, 2024

## introduction
In this week homework, I will try to learn and write some short functions using strings, searching, and pointers to make a solver for the popular word-guessing game wordle, building on my previous work from last week.

TODO(you): Even though I love C programming language, it is getting a bit complex every week and still, it's exciting. I Can't wait to learn more C stuff in the coming weeks.

## function 1: score_letter
In this function, I'm going to calculate the number of words in the vocabulary that contain a specified letter. To do this, I'm going to loop through the vocabulary array and check if the letter exists in each word. Then if it does, I'll increment a counter before finally returning the total count.

## function 2: score_word
In this function, I'm going to calculate the score of a given word based on the letter scores provided in the letter_scores array. Then, I will loop through each unique letter in the word(avoiding duplicates), and add its score from letter_scores to a cumulative total before finally returning the total score of the word.

## function 3: filter_vocabulary_gray
In this function, I'm going to filter the vocabulary by removing words that contain a specified letter, as the letter is not in the secret word. To implement it, I will iterate through the vocabulary array, checking if the letter exists in each word. If the letter is found, I will free the word's memory, set the pointer to NULL, and increment a counter for the number of words removed before finally returning the total count of removed words.

## function 4: filter_vocabulary_yellow
In this function, I'm going to filter the vocabulary by removing words that either do not contain the specified letter or contain it at the specified position. Then, I will iterate through the vocabulary array and check these conditions for each word. If a word fails the conditions, I will free its memory, set its pointer to NULL, and increment the counter for removed words before finally returning the number of filtered words. 

## function 5: filter_vocabulary_green
In this function, I'm going to filter the vocabulary by removing words that do not have the specified letter in the specified position. To do this, I'm going to iterate through the vocabulary array and check if the letter at the specified position matches the given letter. If not, I will free the memory of the word, set its pointer to NULL, and increment the counter for removed words before finally returning the number of filtered words.
