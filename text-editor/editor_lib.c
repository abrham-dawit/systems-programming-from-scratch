#include "editor_lib.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Functions about ll_text...
// append a line: add to the end of the linked list
ll_text *append_text(ll_text *list, char *text) {
  
  ll_text *new_node = malloc(sizeof(ll_text));
  if (!new_node) {
	  return NULL;
  }
  new_node->text = strdup(text);
  new_node->next = NULL;
  if (list == NULL) {
  	  return new_node;
  }
  ll_text* current = list;
  while (current->next != NULL) {
	  current = current->next;
  }
  current->next = new_node;
  return list;
}

void save_to_file(ll_text *list, const char *filename) {
  FILE *outfile = fopen(filename, "w");
  for (ll_text *here = list; here; here = here->next) {
    fprintf(outfile, "%s\n", here->text);
  }
  fclose(outfile);
}

int ll_text_length(ll_text *list) {
  int length = 0;
  ll_text *current = list;

  while (current != NULL) {
	  length++;
	  current = current->next;
  }

  return length;
}

// insert a specific line: add to specific place in the linked list; this is the
// new entry at the specified line
ll_text *insert_text(ll_text *list, char *text, int position) {

  ll_text *new_node = malloc(sizeof(ll_text));
  new_node->text = strdup(text);
  new_node->next = NULL;
  
  if (position == 0) {
	 new_node->next = list;
	 return new_node;
  }
  
  ll_text *current = list;
  for (int i = 0; i < position - 1; i++) {
	 current = current->next;
  }
  
  new_node->next = current->next;
  current->next = new_node;
  return list;
}

// delete a specific line: delete the ith entry in the linked list and return
// the new front of the linked list.
ll_text *delete_text(ll_text *list, int position) {
 	
  if (position == 0) {
      ll_text *temp = list;
      list = list->next;
      free(temp->text);
      free(temp);
      return list;
    }

  ll_text *current = list;
  for (int i = 0; i < position - 1; i++) {
      current = current->next;
  }

  ll_text *temp = current->next;
  current->next = temp->next;
  free(temp->text);
  free(temp);
 
  return list;
}

// replace a line: go to the specific entry, free the text that's there, replace
// it with a copy of the specified text.
ll_text *replace_text(ll_text *list, char *text, int position) {
   
  ll_text *current = list;
  for (int i = 0; i < position; i++) {
      current = current->next;
  }

  free(current->text);
  current->text = strdup(text);

  return list;
}

// duplicate a list. Returns a copy of the list, including newly copied versions
// of all of the strings.
ll_text *duplicate_ll_text(ll_text *list) {

  if (list == NULL) {
	 return NULL;
  }

  ll_text *new_list = malloc(sizeof(ll_text));
  new_list->text = strdup(list->text);
  new_list->next = NULL;

  ll_text *current = list->next;
  ll_text *new_current = new_list;

  while (current != NULL) {
      ll_text *new_node = malloc(sizeof(ll_text));
      new_node->text = strdup(current->text);
      new_node->next = NULL;
      new_current->next = new_node;

      new_current = new_node;
      current = current->next;
  }
  return new_list;
}

// functions about the state stack...
ll_text_stack *load_from_file(const char *filename) {
  ll_text *lines = NULL;
  ll_text_stack *stack = calloc(1, sizeof(ll_text_stack));
  char buf[1024];
  FILE *infile = fopen(filename, "r");
  while (fgets(buf, 1024, infile)) {
    chomp(buf);
    lines = append_text(lines, buf);
  }
  stack->lines = lines;
  return stack;
}

ll_text_stack *new_stack_empty_text(void) {
  ll_text_stack *stack = calloc(1, sizeof(ll_text_stack));
  stack->lines = NULL;
  return stack;
}

// Push a new state onto the stack that's an exact copy of the state currently
// at the top.
ll_text_stack *push_duplicate(ll_text_stack *stack) {

  ll_text *duplicated_lines = duplicate_ll_text(stack->lines);

  ll_text_stack *new_stack = malloc(sizeof(ll_text_stack));
  if (!new_stack) {
	  return NULL;
  }
  new_stack->lines = duplicated_lines;

  new_stack->next = stack;

  return new_stack;
}

// Push a new entry onto the stack that has an empty ll_text at the top.
ll_text_stack *push_empty(ll_text_stack *stack) {

  ll_text_stack *new_stack = malloc(sizeof(ll_text_stack));
  if (!new_stack) {
  	return NULL;
  }

  new_stack->lines = NULL;

  new_stack->next = stack;

  return new_stack;
}

// undo, removing the most recent state
// this has to free all the memory associated with that state
ll_text_stack *pop_stack(ll_text_stack *stack) {
  if (stack == NULL) {
	return NULL;
  }
  ll_text_stack* top_node = stack;
  stack = stack->next;

  ll_text* current = top_node->lines;
  while(current != NULL) {
	  current = delete_text(current, 0);
  }
  free(top_node);
  return stack;

} 

// Find the first newline in the input and replace it with \0
void chomp(char *s) {
  for (int i = 0; s[i]; i++) {
    if (s[i] == '\n' || s[i] == '\r') {
      // Check for \r in case we're on Windows or a very old Mac??
      // Look, I won't stop you from doing CSE 13s on a Mac from 2001 or prior.
      s[i] = '\0';
      break;
    }
  }
}
