//File Name: health.cpp 
//Author: Tess Neau
//Email Address: neaut@kenyon.edu
//Assignment Number: Final Project - Shakespeare
//Description: This program reads in the complete works of Shakespeare 
//             and organizes it by books to allow for word searches amongst 
//             the books.
//Last changed: Monday December 12th 2016

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Book.h"
#include "Paragraph.h"

using namespace std;

string readParagraph(istream& is)
// Precondition: the argument "is" is a string type stream
// Postcondition: series of lines of string text under the format of a paragraph are returned
{
    string line;
    string paragraph;
    int lineNum = 0;

    //scan for the next paragraph
    do 
    {
        getline(is, line);
    } while (line.length() ==  0 && !is.eof());

    // return nothing if eof
    if (is.eof()) 
    {
        return "";
    }
    // Get the next paragraph
    do 
    {
        // Only put a newline after first line
        if (lineNum++ > 0) 
        {
            paragraph += "\n";
        }
        paragraph += line;
        getline(is, line);
    } while (line.length() > 0 && !is.eof());

    return paragraph;
}

int main()
{
    string filename = "Shakespeare.txt";
    ifstream ssfile;
    
    //Open the file
    ssfile.open("Shakespeare.txt");

    vector <Book> Books; // Our main vector which will contain all Shakespeare books.
    Book tempB; // A temporary "carrier" of each Book into the vector Books as Books[i] (1< i< 38)
    string P; // A platform to use the readParagraph function with the Shakespeare file
    Paragraph tempP; // A temporary "carrier" of P into tempB
    
    cout << "Welcome to the Shakespeare word lookup program!\n"
         << "Number of books: 38" << endl;
    
    int j(1);// numerator of Books for UI
    
    // BOOK READER
    for (int i=0; i < 38; i++)
    {   
        int count(-1); // count number of lines in paragraph
        
        // goes through Shakespeare.txt until a Book is attained
        while(!ssfile.eof() && P.find("BOOK: ") == string::npos)
            P = readParagraph(ssfile);
        
        // title of the Book is saved into tempB
        tempB.setTitle(P.substr(5,P.length()-5));
        
        // goes through and saves the Book into tempB
        while(!ssfile.eof() && P != "THE END")
        {
            P = readParagraph(ssfile);
            tempP.setText(P);
            tempB.add(tempP);
            count++; //lines are counted
        }
        //tempB is copied into the vector Books and then cleared for the next one
        Books.push_back(tempB);
        tempB.clear();

        cout << j << ". " << Books[i].getTitle()<< "(" << count << ")" << endl;
        j++;
    }
    
    // WORD SEARCHER
    string searchWord;
    int searchNumber;
    
    //repeats word choice process if user enter 0 for searchNumber
    do
    {
        cout <<"\nEnter a word to search for: ";
        cin >> searchWord;

        j=1;
        // shows number of matches in each Books[i] for UI 
        for (int i=0; i < 38; i++)
        {
            cout << j << ". " << Books[i].getTitle()<< " has " << Books[i].countMatches(searchWord) << " matches.\n";
            j++;
        }
        // displays paragraphs containing searchWord for UI (repeats until number not valid (between 1 and 38)
        do
        {
            cout << "\nTo display the paragraphs containing \"" << searchWord 
                 << "\" enter the number of the book, 0 to search for another word, any other number to exit: ";
            cin >> searchNumber;
            if (searchNumber < 1 || searchNumber > 38)
                break;
            cout << "\nParagraphs from " << Books[searchNumber-1].getTitle() 
                 << " containing the word " << searchWord << endl;
            Books[searchNumber-1].displayMatches(searchWord);
            
        }while (searchNumber > 0 && searchNumber < 39);
        
    }while (searchNumber == 0);

    cout << "\nLeaving so soon? Hope to see you again, bye! \n";
    
    return 0;
}