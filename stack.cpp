#include "stack.h"

void resize(Stack_text& stack) {
	stack.capacity *= 2;
	adr* newItems = new adr[stack.capacity];

	for (int i = 0; i < stack.size; i++) {
		newItems[i] = stack.items[i];
	}
	delete[] stack.items;
	stack.items = newItems;
}


void push(Stack_text& stack, adr p) {
	if (stack.size == stack.capacity) resize(stack);

	adr current = p;
	adr prev_current = p;

	adr copy = nullptr;
	adr* copied = &copy;

	int i = 0;

	while (current) {
		*copied = new elmText;
		(*copied)->ch = current->ch;
		current = current->next;
		copied = &((*copied)->next);
	}
	stack.items[stack.size++] = copy;
}


void pop(Stack_text& stack, adr& p) {
    if (stack.size == 0) {
        return;
    }

    p = stack.items[--stack.size];
}


bool isEmpty(Stack_text& stack) {
	return stack.size == 0;
}

/* void resize(Stack_cursor& stack) { */
/* 	stack.capacity *= 2; */
/* 	Cursor* newItems = new Cursor[stack.capacity]; */

/* 	for (int i = 0; i < stack.size; i++) { */
/* 		newItems[i] = stack.items[i]; */
/* 	} */
/* 	delete[] stack.items; */
/* 	stack.items = newItems; */
/* } */


/* void push(Stack_cursor& stack, Cursor p) { */
/* 	if (stack.size == stack.capacity) resize(stack); */

/* 	stack.items[stack.size++] = p; */
/* } */


/* void pop(Stack_cursor& stack, Cursor& p) { */
/*     if (stack.size == 0) { */
/*         return; */
/*     } */

/*     p = stack.items[--stack.size]; */
/* } */


/* bool isEmpty(Stack_cursor& stack) { */
/* 	return stack.size == 0; */
/* } */



