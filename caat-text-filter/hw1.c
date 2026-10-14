#include "hw1.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

// For the value of Pi, please use M_PI, which is defined in math.h.
double area_of_disk(double radius) {
  // your code here
  double result = M_PI * radius * radius;

  return result;
}

double area_of_ring(double outer_radius, double inner_radius) {
  // your code here
  double result =
      M_PI * ((outer_radius * outer_radius) - (inner_radius * inner_radius));

  return result;
}

int bigger_minus_smaller(int a, int b) {
  // your code here
  if (a > b) {
    return a - b;
  } else {
    return b - a;
  }
}

bool value_in_range(int lower_bound, int x, int upper_bound) {
  // your code here
  if ((lower_bound <= x) && (x <= upper_bound)) {
    return true;
  } else {
    return false;
  }
}

int sum_of_greater_squares(int a, int b, int c) {
  // your code here
  a = a * a;
  b = b * b;
  c = c * c;

  int min_ab;
  if (a < b) {
    min_ab = a;
  } else {
    min_ab = b;
  }

  int min_abc;
  if (min_ab < c) {
    min_abc = min_ab;
  } else {
    min_abc = c;
  }

  return (a + b + c - min_abc);
}
