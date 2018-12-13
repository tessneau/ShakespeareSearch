//implementation of Book

#include <iostream>
#include <string>
#include <vector>

#include "Paragraph.h"
#include "Book.h"

Book::Book()
{
    title = "";
    paragraphs.clear();
}
void Book::setTitle(string Title) // Set the title of this book
{
    title = Title;
}
string Book::getTitle() // Get the title
{
    return title;
}
int Book::countMatches(string word) // Return the number of times word appears in a Book
{
    int count(0);
    
    for (int i=0; i < paragraphs.size(); i++)
    {
        if(paragraphs[i].search(word))
            count++;
    }
    return count;
}
void Book::add(Paragraph p) // add a paragraph to the end of the book;
{
    paragraphs.push_back(p);
}
void Book::clear() // Clear the contents and title of a Book;    
{
    paragraphs.clear();
    title ="";
}
void Book::displayMatches(string word)// Display all paragraphs with word in it 
{
    for (int i=0; i < paragraphs.size(); i++)
    {
        if(paragraphs[i].search(word))
        {
            paragraphs[i].display();
            cout <<"\n-------------------------------------------\n";
        }
    }
}

