#include "editor.h"

void moveCursorRight(Cursor& cursor) {
	if (cursor.current && cursor.next) {
		cursor.current = cursor.next;
		cursor.next = cursor.current->next;
	}
}


void moveCursorLeft(Cursor& cursor) {
	if (cursor.current && cursor.current->prev) {
		cursor.next = cursor.current;
		cursor.current = cursor.current->prev;
	}
}


void moveCursorUp(Text& text, Cursor& cursor) {
    if (!cursor.current || !cursor.current->prev || cursor.current->prev == text.first) {
        return; 
    }

    while (cursor.current && cursor.current->ch != '\n' && cursor.current->prev) {
        moveCursorLeft(cursor);
    }

    if (cursor.current) moveCursorLeft(cursor);

    adr temp = cursor.current;
    while (temp && temp->ch != '\n' && temp->prev != text.first) {
        temp = temp->prev;
    }

    if (temp) temp = temp->next;

    int horizontalPosition = 0;
    adr tempCursor = cursor.current;
    while (tempCursor && tempCursor->ch != '\n' && tempCursor->prev != text.first) {
        horizontalPosition++;
        tempCursor = tempCursor->prev;
    }

    int currentColumn = 1;
    while (currentColumn < horizontalPosition && temp && temp->next && temp->next->ch != '\n') {
        temp = temp->next;
        currentColumn++;
    }

    if (temp && temp->ch != '\n') {
        cursor.current = temp;
    }    
}


void moveCursorDown(Text& text, Cursor& cursor) {
    if (!cursor.current || !cursor.current->next || cursor.current->next == text.last) {
        return; 
    }

    while (cursor.current && cursor.current->ch != '\n' && cursor.current->next) {
        moveCursorRight(cursor);
    }

    if (cursor.current) moveCursorRight(cursor);

    adr temp = cursor.current;
    while (temp && temp->ch != '\n' && temp->next != text.last) {
        temp = temp->next;
    }

    if (temp) temp = temp->next;

    int horizontalPosition = 0;
    adr tempCursor = cursor.current;
    while (tempCursor && tempCursor->ch != '\n' && tempCursor->next != text.last) {
        horizontalPosition++;
        tempCursor = tempCursor->next;
    }

    int currentColumn = 1;
    while (currentColumn < horizontalPosition && temp && temp->prev && temp->prev->ch != '\n') {
        temp = temp->prev;
        currentColumn++;
    }

    if (temp && temp->ch != '\n') {
        cursor.current = temp;
    }
}

/* void save_cursor_state(Text& lines, Stack<Text>& undo_stack) { */
/*     cursor_stack.push(make_pair(row, col)); */
/* } */
