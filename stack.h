#pragma once

#include <iostream>
#include "text.h"

using namespace std;

struct Stack {
	int capacity;
	int size;
	adr* items;
	Stack() : capacity(1), size(0), items(new adr[capacity]) {}
};

void resize(Stack& stack);

void push(Stack& stack, adr p);
void pop(Stack& stack, adr& p);
bool isEmpty(Stack& stack);

