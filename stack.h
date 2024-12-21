#pragma once

#include <iostream>
#include "text.h"

using namespace std;

struct Stack_text {
	int capacity;
	int size;
	adr* items;
	Stack_text() : capacity(1), size(0), items(new adr[capacity]) {}
};

/* struct Stack_cursor { */
/* 	int capacity; */
/* 	int size; */
/* 	Cursor* items; */
/* 	Stack_cursor() : capacity(1), size(0), items(new Cursor[capacity]) {} */
/* }; */

void resize(Stack_text& stack);
void push(Stack_text& stack, adr p);
void pop(Stack_text& stack, adr& p);
bool isEmpty(Stack_text& stack);

/* void resize(Stack_cursor& stack); */
/* void push(Stack_cursor& stack, Cursor p); */
/* void pop(Stack_cursor& stack, Cursor& p); */
/* bool isEmpty(Stack_cursor& stack); */

