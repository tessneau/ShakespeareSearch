//paragraph

#ifndef PARAGRAPH_H
#define PARAGRAPH_H

using namespace std;

class Paragraph 
{
private:
    string text;
    
public:
    Paragraph();
    void setText(string p); // Put (or replace) the text in a paragraph
    bool search(string word); // Search this paragraph for this word.
    void display(); // Display this paragraph
};

#endif /* PARAGRAPH_H */

