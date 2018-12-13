//implementation of Paragraph

#include <iostream>
#include <string>
#include <vector>

#include "Paragraph.h"

Paragraph::Paragraph()
{
    text = "";
}
void Paragraph::setText(string p) // Put (or replace) the text in a paragraph
{
    text = p;
}
bool Paragraph::search(string word) // Search this paragraph for this word.
{
    if (text.find(word)!=string::npos)
        return true;
    else
        return false;
}
void Paragraph::display() // Display this paragraph
{
    cout << text;
}

