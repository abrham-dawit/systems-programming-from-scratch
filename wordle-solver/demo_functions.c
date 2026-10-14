// A nice place for you to mess with the functions, while you're developing.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "search_util.h"

int main(void) {
  char words[10][6] = {"stalk", "scrap", "shear", "batch", "motif",
                       "tense", "ultra", "vital", "ether", "nadir"};

  // make a dynamically-allocated vocabulary that you can mess with, including
  // freeing elements of it when necessary.
  char **vocabulary = calloc(10, sizeof(char *));
  for (int i = 0; i < 10; i++) {
    vocabulary[i] = strdup(words[i]);
  }
  size_t num_words = 10;

  // TODO(you): exercise all of your functions in here. Write some good test
  // cases!
 
  // Test 1: score_letter 
  printf("\n**** Test 1: score_letter ****\n");
  char test_letter = 't';
  int letter_score = score_letter(test_letter, vocabulary, num_words);
  printf("Letter '%c' occurs in %d words.\n", test_letter, letter_score);


  // Test 2: score_word
  printf("\n**** Test 2: score_word ****\n");
  int letter_scores[26] = {0};
  for (int i = 0; i < 26; i++) {
     	  letter_scores[i] = score_letter('a' + i, vocabulary, num_words);
  }
  char *test_word = "stalk";
  int word_score = score_word(test_word, letter_scores);
  printf("Score for the word '%s': %d\n", test_word, word_score);
 
 
  // Test 3: filter_vocabulary_gray
  printf("\n**** Test 3: filter_vocabulary_gray ****\n");
  char gray_letter = 't';
  size_t removed_gray = filter_vocabulary_gray(gray_letter, vocabulary, num_words);
  printf("Removed %zu words containing the letter '%c'. Remaining words:\n", removed_gray, gray_letter);
  for (size_t i = 0; i < num_words; i++) {
	  if (vocabulary[i] != NULL) {
		  printf("- %s\n", vocabulary[i]);
	  }
  }
  for (int i = 0; i < 10; i++) {
  	  free(vocabulary[i]);
  	  vocabulary[i] = strdup(words[i]);
  }


  // Test 4: filter_vocabulary_yellow
  printf("\n**** Test 4: filter_vocabulary_yellow ****\n");
  char yellow_letter = 'a';
  int yellow_position = 2;
  size_t removed_yellow = filter_vocabulary_yellow(yellow_letter, yellow_position, vocabulary, num_words);
  printf("Removed %zu words where letter '%c' is missing or at position %d. Remaining words:\n", removed_yellow, yellow_letter, yellow_position);
  for (size_t i = 0; i < num_words; i++) {
    	  if (vocabulary[i] != NULL) {
	  	  printf("- %s\n", vocabulary[i]);
	  }
  }
  for (int i = 0; i < 10; i++) {
	  free(vocabulary[i]);
	  vocabulary[i] = strdup(words[i]);
  }

    
  // Test 5: filter_vocabulary_green
  printf("\n**** Test 5: filter_vocabulary_green ****\n");
  char green_letter = 'e';
  int green_position = 4;
  size_t removed_green = filter_vocabulary_green(green_letter, green_position, vocabulary, num_words);
  printf("Removed %zu words where letter '%c' is not at position %d. Remaining words:\n", removed_green, green_letter, green_position);
  for (size_t i = 0; i < num_words; i++) {
    	  if (vocabulary[i] != NULL) {
	  	  printf("- %s\n", vocabulary[i]);
	  }
  }


  // ... OK we're done, clean up the vocabulary.
  free_vocabulary(vocabulary, num_words);

  return 0;
}
