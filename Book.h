// book
#include "Paragraph.h"
#ifndef BOOK_H
#define BOOK_H

using namespace std;

class Book 
{
private:
    string title;
    vector <Paragraph> paragraphs;
public:
    Book();
    void setTitle(string title); // Set the title of this book
    string getTitle(); // Get the title
    int countMatches(string word); // Return the number if time word appears in a Book
    void add(Paragraph p); // add a paragraph to the end of the book;
    void clear(); // Clear the contents and title of it hAME           
    void displayMatches(string word); // Display all paragraphs with word in it        
};

#endif /* BOOK_H */

