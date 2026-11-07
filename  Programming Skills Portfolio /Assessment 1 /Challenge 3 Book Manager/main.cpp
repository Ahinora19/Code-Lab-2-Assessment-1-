
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

// A class representing one book
class Book {
public:
    string title, author, id;
    int pages;
    bool available;

    void display() const {
        cout << "\nID: " << id
             << "\nTitle: " << title
             << "\nAuthor: " << author
             << "\nPages: " << pages
             << "\nAvailable: " << (available ? "Yes" : "No")
             << "\n";
    }
};

// Load books from the text file
vector<Book> loadBooks() {
    vector<Book> books;
    ifstream file("bookData.txt");

    if (!file) {
        cout << "Error: Cannot open bookData.txt\n";
        return books;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Book book;
        string pages, status;

        getline(ss, book.title, ',');
        getline(ss, book.author, ',');
        getline(ss, pages, ',');
        getline(ss, book.id, ',');
        getline(ss, status);

        try {
            book.pages = stoi(pages);
            book.available = (status == "true");
            books.push_back(book);
        }
        catch (...) {
            cout << "Skipping invalid book record.\n";
        }
    }
    return books;
}

// Display all books
void showAllBooks(const vector<Book>& books) {
    for (const Book& book : books) {
        book.display();
    }
}

// Find a book by its ID
void findBook(const vector<Book>& books) {
    string id;
    cout << "Enter book ID: ";
    cin >> id;

    for (const Book& book : books) {
        if (book.id == id) {
            book.display();
            return;
        }
    }
    cout << "Book not found.\n";
}

int main() {
    vector<Book> books = loadBooks();

    if (books.empty()) {
        cout << "No books loaded. Exiting.\n";
        return 1;
    }

    int choice = 0;

    while (choice != 3) {
        cout << "\n===== BOOK MANAGER =====\n";
        cout << "1. View all books\n";
        cout << "2. Find book by ID\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input.\n";
            break;
        }

        if (choice == 1) {
            showAllBooks(books);
        }
        else if (choice == 2) {
            findBook(books);
        }
        else if (choice == 3) {
            cout << "Goodbye!\n";
        }
        else {
            cout << "Please choose 1, 2 or 3.\n";
        }
    }
    return 0;
}
