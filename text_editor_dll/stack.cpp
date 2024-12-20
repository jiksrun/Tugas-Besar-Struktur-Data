#include "stack.h"

void resize(Stack& stack) {
	stack.capacity *= 2;
	adr* newItems = new adr[stack.capacity];

	for (int i = 0; i < stack.size; i++) {
		newItems[i] = stack.items[i];
	}
	delete[] stack.items;
	stack.items = newItems;
}


void push(Stack& stack, adr p) {
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
	stack.items[i++] = copy;
}


void pop(Stack& stack, adr& p) {
    if (stack.size == 0) {
        return;
    }

    p = stack.items[stack.size - 1];

    stack.items[--stack.size] = nullptr;
}


bool isEmpty(Stack& stack) {
	return stack.size == 0;
}




