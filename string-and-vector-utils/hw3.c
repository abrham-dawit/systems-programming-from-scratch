/*
 * All of your code for hw3 goes in here. Your goal is to finish these
 * functions.
 */

#include "hw3.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool str_suffix(char *haystack, char *needle) {
  int len_haystack = strlen(haystack);
  int len_needle = strlen(needle);

  if (len_needle > len_haystack) {
	  return false;
  }
  for  (int i = len_needle - 1; i >= 0; i--) {
 	int j = i + len_haystack - len_needle;
       	if (haystack[j] != needle[i]) {
		return false;
	}
  }
  return true;
}

char *str_repeat(char *s, int n) {
  int len_s = strlen(s);
  int out_len = len_s * n + 1;
  char *out = malloc(out_len);
  out[out_len - 1] = '\0';
 
  for (int i = 0; i < n; i++) {
	 strcpy(out + (len_s) * i, s);
  }
 
  return out;

}

bool char_is_valid(char c) {
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

char to_lowercase(char c) {
	if (c >= 'A' && c <= 'Z') {
		return c + ('a' - 'A');
	}
	return c;
}

bool str_is_palindrome(char *s) {
  int left = 0;
  int right = strlen(s) - 1;

   while (left < right) {
	while (!char_is_valid(s[left])) {
		left++;
	}
	while (!char_is_valid(s[right])) {
		right--;
	}
	if (to_lowercase(s[left]) != to_lowercase(s[right])) {
		return false;
	}
   	left++;
	right--;
   }
   return true;
}

float dot_product(float *vec_a, float *vec_b, int length) {
  float sum = 0.0;
  for (int i = 0; i < length; i++) {
	  sum += vec_a[i] * vec_b[i];
  }
  return sum;
}

int reduce(int *nums, int length, int (*f)(int, int), int initial) {
  int coll = initial;                 // coll stands for collector
  for (int i = 0; i < length; i++) {
	  coll = f(coll, nums[i]);
  }
  return coll;
}

// These two functions will end up as a *single call to reduce*, but you'll have
// to write a new helper function for each of them. Those helper functions will
// be quite short though!

int max_helper(int x, int y) {
  if (x > y) {
	  return x;
  } else {
	  return y;
  }
}

int maximum_with_reduce(int *nums, int length) {
  return reduce(nums, length, max_helper, INT_MIN);
}

int add_if_positive (int coll, int val) {
  if (val > 0) {
	return coll + val;
  } else {
	return coll;
  }
}

int sum_positive_with_reduce(int *nums, int length) {
   return reduce(nums, length, add_if_positive, 0);
}

