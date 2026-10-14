#include <stdio.h>
#include <stdlib.h>

void remove_newline(char *s, int maxsize) {
  for (int i = 0; i < maxsize && s[i]; i++) {
    if (s[i] == '\n') {
      s[i] = '\0';
      return;
    }
  }
}

int main(int argc, char *argv[]) {
  const int BUFSIZE = 80;
  char buffer[BUFSIZE];
  FILE *infile = NULL;

  if (argc != 2) {
    fprintf(stderr, "calculator needs exactly 1 argument, the input file\n");
    return 1;
  }
  infile = fopen(argv[1], "r");
  if (!infile) {
    fprintf(stderr, "input file %s not found\n", argv[1]);
    return 1;
  }

  // Your code should go here-ish. Feel free to change this loop as you need to.
  // IMPORTANT: your output should either be the single line "ERROR\n", or the
  // single number output.
 
  long crn = 0;  //crn stands for current running number
  long total_number = 0;
  char operation = '+';
  int  count = 1;

  while (fgets(buffer, BUFSIZE, infile)) {
    // TODO: implement the calculator.
    remove_newline(buffer, BUFSIZE);
    
    if ((count % 2) == 0) {
	 operation = *buffer;
	 
    } else {
	 crn = strtol (buffer, NULL, 10);
 	 
	 if (operation == '+') {
		 total_number += crn;
	 } else if (operation == '-') {
		 total_number -= crn;
	 } else if (operation == '*') {
		 total_number *= crn;
	 } else if (operation == '/') {
		if (crn == 0) {
		       printf("ERROR\n");
	       	       fclose(infile);
		       return 0;
		 }
		total_number /= crn;
	 }
   }
    count++;
 }
  
  printf("%ld\n", total_number);
  fclose(infile);
  return 0;

}
