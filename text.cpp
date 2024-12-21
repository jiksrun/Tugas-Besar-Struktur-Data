#include "text.h"

void create_text(Text& text) {
	text.first = text.last = nullptr;
}


void create_cursor(Cursor& cursor) {
	cursor.current = cursor.next = nullptr;
}


adr create_elmText(infoType info) {
	adr newElm = new elmText;
	newElm->ch = info;
	newElm->next = newElm->prev = nullptr;
	return newElm;
}


void insertFirst(Text& text, adr p, Cursor& cursor) {
	if (!text.first) {
		text.first = text.last = p;
		cursor.current = p;
		cursor.next = p->next;
		return;
	}
	text.first->prev = p;
	p->next = text.first;
	text.first = p;
	cursor.current = p;
	cursor.next = p->next;
}


void insertLast(Text& text, adr p, Cursor& cursor) {
	if (!text.first) {
		text.first = text.last = p;
		cursor.current = p;
		cursor.next = p->next;
		return;
	}
	text.last->next = p;
	p->prev = text.last;
	text.last = p;
	cursor.current = p;
	cursor.next = p->next;
}


void insertAfter(Text& text, adr p, adr prec, Cursor& cursor) {
	if (!text.first) {
		text.first = text.last = p;
		cursor.current = p;
		cursor.next = p->next;
		return;
	}
	if (!prec->next) {
		insertLast(text, p, cursor);
		return;
	}
	p->next = prec->next;
	p->prev = prec;
	p->next->prev = p;
	prec->next = p;
	cursor.current = p;
	cursor.next = p->next;
}


void insertBefore(Text& text, adr p, adr prec, Cursor& cursor) {
	if (!text.first) {
		text.first = text.last = p;
		cursor.current = p;
		cursor.next = p->next;
		return;
	}
	if (!prec->prev) {
		insertFirst(text, p, cursor);
		return;
	}
	p->next = prec;
	p->prev = prec->prev;
	p->prev->next = p;
	prec->prev = p;

	cursor.current = p;
	cursor.next = p->next;
}


void deleteFirst(Text& text, adr p, Cursor& cursor) {
	if (!text.first) {
		p = nullptr;
		return;
	}
	if (text.first == text.last) {
		p = text.first;
		text.first = text.last = nullptr;
		cursor.current = cursor.next = nullptr;
		return;
	}
	/* p = text.first; */
	/* text.first = text.first->next; */
	/* p->next = text.first->prev = nullptr; */
	/* cursor.next = cursor.current; */
	/* cursor.current = cursor.current->prev; */
	cursor.current = text.first;
	cursor.next = text.first ? text.first->next : nullptr;
	p = text.first;
	text.first = text.first->next;
	text.first->prev = nullptr;
	p->next = nullptr;
}


void deleteLast(Text& text, adr p, Cursor& cursor) {
	if (!text.first) {
		p = nullptr;
		return;
	}
	if (text.first == text.last) {
		p = text.first;
		text.first = text.last = nullptr;
		cursor.current = cursor.next = nullptr;
		return;
	}
	cursor.current = cursor.current->prev;

	p = text.last;
	text.last = text.last->prev;
	p->prev = text.last->next = nullptr;

}


void deleteBefore(Text& text, adr p, adr prec, Cursor& cursor) {
    /* // Assumes: prec is cursor.current and a valid node in the list */

    /* // If the list is empty or prec is null, there's nothing to delete */
    /* if (!text.first || !prec) { */
    /*     p = nullptr; */
    /*     return; */
    /* } */

    /* // If prec is the first node, there's no node before it to delete */
    /* if (prec == text.first) { */
    /*     p = nullptr; */
    /*     return; */
    /* } */

    /* // Get the node before `prec` */
    /* p = prec->prev; */

    /* // If the node before `prec` is the first node */
    /* if (p == text.first) { */
    /*     text.first = prec; // Update the head of the list */
    /*     text.first->prev = nullptr; */
    /* } else { */
    /*     // Adjust the links of p's neighbors */
    /*     if (p->prev) { */
    /*         p->prev->next = prec; */
    /*     } */
    /*     prec->prev = p->prev; */
    /* } */

    /* // Disconnect p from the list */
    /* p->next = nullptr; */
    /* p->prev = nullptr; */

    /* // Update the cursor */
    /* if (cursor.current->prev == p) { */
    /*     cursor.current = cursor.current->prev; // Move cursor to the previous node */
    /* } */
    /* cursor.next = cursor.current->next; // Ensure cursor.next is updated */
	// kalau text kosong
	if (!text.first) {
		p = nullptr;
		return;
	}
	if (!prec) {
		p = nullptr;
		return;
	}
	// kalau text hanya punya satu elemen atau prec adalah elemen pertama
	if (!prec->prev) {
		p = nullptr;
		return;
	}
	// kalau elemen sebelum prec adalah elemen pertama
	if (prec->prev == text.first) {
		p = text.first;
		text.first = prec;
		p->next = prec->prev = nullptr;
		cursor.next = cursor.current;
		cursor.current = cursor.current->prev;
		return;
	}
	cursor.next = cursor.current;
	cursor.current = cursor.current->prev;
	p = prec->prev;
	prec->prev = p->prev;
	prec->prev->next = prec;
	p->next = p->prev = nullptr;

}



void printText(Text text, Cursor& cursor) {
	cout << "-----press ctrl+e to exit-----" << endl;

	if (text.first) {
		adr current = text.first;
		while (current) {
			cout << current->ch;
			if (current == cursor.current) {
				cout << '|';
			}
			current = current->next;
		}
	}
	/* cout << "\ncursor current: " << (cursor.current ? cursor.current->ch : 'x') << endl; */
	/* cout << "cursor next: " << (cursor.next ? cursor.next->ch : 'x') << endl; */
	cout << "\n\n\n----press ctrl+u/ctrl+r to undo/redo----" << endl;
}



