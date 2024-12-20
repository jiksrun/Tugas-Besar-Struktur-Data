#pragma once
#include <iostream>

using namespace std;

struct elmText;
typedef elmText* adr;
typedef char infoType;

struct elmText {
	infoType ch;
	adr next, prev;
};

struct Text {
	adr first, last;
};

struct Cursor {
	adr current, next;
};

void create_text(Text& text);
void create_cursor(Cursor& cursor);
adr create_elmText(infoType info);

void insertFirst(Text& text, adr p, Cursor& cursor);
void insertLast(Text& text, adr p, Cursor& cursor);
void insertAfter(Text& text, adr p, adr prec, Cursor& cursor);
void insertBefore(Text& text, adr p, adr prec, Cursor& cursor);

void deleteFirst(Text& text, adr p, Cursor& cursor);
void deleteLast(Text& text, adr p, Cursor& cursor);
void deleteBefore(Text& text, adr p, adr prec, Cursor& cursor);

void printText(Text text, Cursor& cursor);


