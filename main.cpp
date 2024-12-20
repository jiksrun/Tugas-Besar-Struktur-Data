#include <cstdlib>
#include "text.h"
#include "get_char.h"
#include "editor.h"

int main() {
	Text text;
	Cursor cursor;

	create_text(text);
	create_cursor(cursor);

	Stack undo_stack;
	Stack redo_stack;

	char ch;

	while (true) {
		system("clear");
		printText(text, cursor);
		
		ch = getch();
		adr	p = create_elmText(ch);
		if (ch == 5) {
			break; 
		}

		if (ch == 27) {
			ch = getch();
			if (ch == '[') {
				ch = getch();
				if (ch == 'C') {
					moveCursorRight(cursor);
				} else if (ch == 'D') {
					moveCursorLeft(cursor);
				} else if (ch == 'A') {
					moveCursorUp(text, cursor);
				} else if (ch == 'B') {
					moveCursorDown(text, cursor);
				}
			}
		} else if (ch == 127) {
			push(undo_stack, text.first); 
			if (!cursor.next) {
				deleteLast(text, p, cursor);
			}
			else deleteBefore(text, p, cursor.current, cursor);

		} else if (ch == 21) { // ctrl+u
			if (!isEmpty(undo_stack)) {
				push(redo_stack, text.first); 
				pop(undo_stack, text.first);

				cursor.current=text.first;
				cursor.next=cursor.current->next;
			}
		} else {
			push(undo_stack, text.first); 
			if (!cursor.current) {
				insertFirst(text, p, cursor);
			} else if (!cursor.next) {
				insertLast(text, p, cursor);
			} else {
				insertAfter(text, p, cursor.current, cursor);
			}

		}

	}
	return 0;
}
