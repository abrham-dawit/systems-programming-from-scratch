#include <stdio.h>

// Finish this program. You'll almost certainly want to use a loop of some
// kind, getchar() and putchar(). Remember that the output of getchar() is the
// symbol EOF when you get to the end of the input.

int main(void) {
  char c;
  while ((c = getchar()) != EOF) {
    putchar(c);

    if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' ||
        c == 'o' || c == 'O' || c == 'u' || c == 'U') {
      putchar(c);
    }
  }
  return 0;
}
