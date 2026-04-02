// Buoi2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Author {
    int id;
    char* name = new char[30];
    char* nationality = new char[30];
    friend istream& operator>>(istream& is, Author& author) {
        cout << "Enter author information:" << endl;
        cout << "\t+ Enter author ID: ";
        is >> author.id;
        cout << "\t+ Enter author name: ";
        is >> author.id;
        is.getline(author.name, 30);
        cout << "\t+ Enter author nationality: ";
        is.ignore();
        is.getline(author.nationality, 30);
        return is;
    }
};

struct Book {
    int id;
    char* name;
    char* nationality;
    double price;
    Author author;
        friend ostream& operator<<(ostream& os, const Book& book) {
        os << "\t+ ID: " << book.id << endl;
        os << "\t+ Name: " << book.name << endl;
        os << "\t+ Price: " << book.price << endl;
        os << "\t+ Author name: " << book.author.name << endl;
        return os;
    }
        friend istream& operator>>(istream& is, Book& book) {
            cout << "Enter book information:" << endl;
            cout << "\t+ Enter book ID: ";
            is >> book.id;
            cout << "\t+ Enter book name: ";
            is.ignore();
            is.getline(book.name, 50);
            cout << "\t+ Enter book price: ";
            is >> book.price;
            cin >> book.author;
            return is;
    }
};

void Show(const vector<Book>& books) {
    if(books.size() == 0) {
        cout << "No books available." << endl;
        return;
    }
    for (const auto& book : books) {
        cout << "Book information" << endl;
        cout << book;
    }
}



int main()
{
    vector<Book> books;
    do {
        system("cls");
        cout << "----------LIBRALY MANAGEMENT SYSTEM----------" << endl;
        cout << "1. Show all books" << endl;
        cout << "2. Add a new book" << endl;
        cout << "3. Update a book" << endl;
        cout << "4. Delete a book by id" << endl;
        cout << "5. Search for a book by name" << endl;
        cout << "6. Export to file" << endl;
        cout << "7. Import from file" << endl;
        cout << "0. Exit" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "Enter your choice: " << endl;
        int choice;
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "Show all books" << endl;
            Show(books);
            break;
        }
        case 2: {
            cout << "Add a new book" << endl;
            Book book;
            cin >> book;
            books.push_back(book);
            break;
        }
        case 3: {
            cout << "Update a book" << endl;
            int bookid;
            cout << "Enter book ID to update: ";
            cin >> bookId;


            Update(books, )
            break;
        }
        case 4: {
            cout << "Delete a book by id" << endl;
            break;
        }
        case 5: {
            cout << "Search for a book by name" << endl;
            break;
        }
        case 6: {
            cout << "Export to file" << endl;
            break;
        }
        case 7: {
            cout << "Import from file" << endl;
            break;
        }
        case 8: {
            cout << "Exit" << endl;
            break;
        }
        case 0: {
            return 0;
        }
        defaut: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    system("pause");
    } while (true);
}










// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
