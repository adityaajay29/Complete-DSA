#include <iostream>
#include <vector>
using namespace std;

class Library
{
    string name;
    Location location;
    vector<BookItems> bookTypes;
};

class Location
{
    int pin;
    string city;
    string country;
};

class Book
{
    string title;
    int bookId;
    vector<Author> authors;
    BookTypes bookType;
};

class BookItems : public Book
{
    string barcode;
    int publicationDate;
    Rack bookRack;
    BookStatus bookStatus;
    int issueDate;
};

class Rack
{
    int rackID;
    int row;
    int col;
    string rowColDetails;
};

enum BookTypes{Science, Fiction, Arts, SocialSciences, Magazines, Coomerce, Law};

enum BookStatus{Issued, Available, Lost};

class Person
{
    string firstname;
    string lastname;
};

class Author : public Person
{
    BookTypes authorSpeaciality;
    vector<Book> booksPublished;
};

class LibraryMembers : public Person
{
    string ID;
    string phone;
    string email;
};

class Customer : public LibraryMembers
{
    int countBookIssued;
    int dateIssued;
    SearchBook search;
    BookIssueService bookIssueService;
};

class Librarian : public LibraryMembers
{
    SearchBook search;
    BookIssueService bookIssueService;
    public : 
    void issueBook(BookItems book);
    void deleteBook(BookItems book);
    void editBook(BookItems book);
};

class SearchBook
{   
    public : 
    vector<BookItems> getBooksByTypes(BookTypes book);
    vector<BookItems> getBooksByAuthor(Author author);
    vector<BookTypes> getBookByAuthorAndType(BookTypes book, Author author);
    vector<BookItems> getBookByPublicationDate(int date);
};

