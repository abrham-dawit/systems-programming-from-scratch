# Homework 4: Design Document

  * author: Abrham Dawit
  * date: November 1, 2024

## introduction
In this week homework, I will try to learn and write some short functions using stacks, linked lists and I/O to make a new-user text editor that I can even use to do my homeworks.

TODO(you): Even though I love C programming language, it is getting a bit complex every week and still, it's exciting. I Can't wait to learn more C stuff in the coming weeks.

## function 1: ll_text *append_text(ll_text *list, char *text)
In this function, I'm going to append a new code with specified text to the end of a linked list. To do this, I'm going to first create a new ll_text node. Then I'm going to copy the input text using strdup in order to store a separate instance. If the list is null, I'll return the new node as the head of the list. Otherwise, I'll traverse to the last node and link it to the new node.

## function 2: ll_text *insert_text(ll_text *list, char *text, int position)
In this function, I'm going to insert a new code with specified text at a given position in the list. To do this, I'm going to allocate a new node with the given text and insert it at the specified position. Then, I'm going to adjust the next pointers as needed.

## function 3: ll_text *delete_text(ll_text *list, int position)
In this function, I'm going to delete a node at a specified position. To do this, I'm going to remove the node at the specifed position from the list, then update links, and free the node's memory.

## function 4: ll_text *replace_text(ll_text *list, char *text, int position)
In this function, I'm going to replace the text of a node at a given position. To do this, I'm going to first replace the text in the node at positon by freeing its existing text and copying in the new text.

## function 5: ll_text *duplicate_ll_text(ll_text *list)
In this fuction, I'm going to create an entire copy of of the enitre linked list. To do this, I'm going to allocate new nodes and duplicate each string.

## function 6: int ll_text_length(ll_text *list)
In this function, I'm going to calculate the length of the linked list. To do this, I'm going to traverse the list, counting nodes to determine its length.

## function 7: ll_text_stack *push_duplicate(ll_text_stack *stack)
In this function, I'm going to add a copy of the current ll_text linked list to the top of the stack. To do this, I'm going to first duplicate the current top's ll_text, and then create a new stack node and set it as the stack's top.

## function 8: ll_text_stack *push_empty(ll_text_stack *stack)
In this function, I'm going to add an empty stack entry at the top of the stack. To do this, I'm going to first add a new stack node and initialize its text to null. Then, I'm going to set the new node as the new top of the stack.

## function 9: ll_text_stack *pop_stack(ll_text_stack *stack)
In this function, I'm going to remove and free the top entry in the stack. To do this, I'm going to first remove the top node of the stack, free its memory, and then, adjust the stack's top pointer to the next node.
