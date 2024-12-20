#pragma once

#include "text.h"
#include "stack.h"

void moveCursorRight(Cursor& cursor);
void moveCursorLeft(Cursor& cursor);
void moveCursorUp(Text& text, Cursor& cursor);
void moveCursorDown(Text& text, Cursor& cursor);

