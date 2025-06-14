#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

// 3 bitni raboti:
// define the error/exception class
// throw (in the constructor)

#include <fstream>


class Book {
private:
    string title;
    string author;
    int year;
public:
    Book(const string &title = " ", const string &author = " ", int year = 0) {
        this->title = title;
        this->author = author;
        this->year = year;
    }

    friend ostream &operator<<(ostream &os, const Book &book) {
        os << book.title << "  " << book.author << "  " << book.year;
        return os;
    }

    // automatic generated operator ==, sporeduva dali se isti knigi
    bool operator==(const Book &rhs) const {
        return title == rhs.title &&
               author == rhs.author &&
               year == rhs.year;
    }

    bool operator!=(const Book &rhs) const {
        return !(rhs == *this);
    }

    const string &getAuthor() const {
        return author;
    }

};

class BookAlreadyExistsException {
private:
    Book b;
public:
    BookAlreadyExistsException(const Book &b) {
        this->b = b;
    }

    void message() {
        cout << "Book \"" << b << "/" "already exsist in the library" << endl;
    }

};


class Library {
private:
    string name;
    Book *books;
    int n;
public:
    // const so ime, a vo dinamicki alocirana niza treba da gi dodavame
    Library(const string &name = "") {
        this->name = name;
        n = 0;
        books = new Book[n];
    }

    // treba da ja vratime promenetata biblioteka, a dodavame knigi
    Library &operator+=(const Book &b) {

        for (int i = 0; i < n; i++) {
            if (books[i] == b) {
                throw BookAlreadyExistsException(b);
            }
        }

        Book *tmp = new Book[n + 1];
        for (int i = 0; i < n; i++) {
            tmp[i] = books[i];
        }
        tmp[n++] = b;

        delete[] books;
        books = tmp;

        return *this;
    }

    friend ostream &operator<<(ostream &os, const Library &library) {
        os << library.name << endl;

        for (int i = 0; i < library.n; i++) {
            os << library.books[i] << endl;
        }

        return os;
    }

    Book *getBooksByAuthor(string &author, int &numberFound) {

        numberFound = 0;
        for (int i = 0; i < n; i++) {
            if (books[i].getAuthor() == author) {
                numberFound++;
            }
        }

        Book *result = new Book[numberFound];
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (books[i].getAuthor() == author) {
                result[j++] = books[i];
            }
        }
        if (numberFound == 0) {
            return nullptr;
        } else {
            return result;
        }
    }

};

int main() {

    ifstream fin("C:\\Users\\eleni\\CLionProjects\\OOP\\input");

    string libraryName;             // FINKI library
    getline(fin, libraryName);

    Library library(libraryName);

    int n;
    fin >> n;           // 5
    fin.ignore(); // !!!

    string t, a;
    int year;

    for (int i = 0; i < n; i++) {
        getline(fin, t); // To kill a MockingBird
        getline(fin, a); // avtor
        fin >> year;    // 1998
        fin.ignore();

        //       cout << t << " " << a << " " << year << endl;
        Book b(t, a, year);

        try {
            library += b;
        } catch (BookAlreadyExistsException &e) {
            e.message();
        }
    }

    fin.close();


    ofstream ofs1("C:\\Users\\eleni\\CLionProjects\\OOP\\output");
    ofs1 << library << endl;
    ofs1.close();

    ofstream ofs2("C:\\Users\\eleni\\CLionProjects\\OOP\\output2");
    Book * result = library.getBooksByAuthor(a, n);

    if(result== nullptr){
        ofs2 << "None";
    }else {
        for (int i = 0; i < n; i++) {
            ofs2 << result[i] << endl;
        }
    }

    ofs2.close();

    return 0;
}
