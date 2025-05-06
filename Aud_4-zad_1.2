#include <iostream>
#include <cstring>

using namespace std;

// AUD 4
// https://bbb-lb.finki.ukim.mk/playback/presentation/2.3/740dc1184c44f2d100ce97a5038744c4cd34f22a-1648042101186
/*Да се напише класа Array за работа со еднодимензионални полиња од целобројни елементи. За полето се чуваат информации за неговиот вкупен капцитет, тековниот број на елементи. Резервацијата на меморијата да се врши динамички. Во класата да се имплементираат следните функции:
add за додавање нови броеви во полето и притоа ако е исполнет капацитетот на полето (низата) да се зголеми за 100%.
change која има два целобројни аргументи А и В и ги заменува сите броеви А од полето во В.
deleteAll која ги брише сите појавувања на целоброниот аргумент во полето, а притоа капацитетот да не се промени.
print за печатење на елементите од полето.
Да се тестира класата во main функција
 */

class LibraryMember;

class Library;

class Book {
    string name;
    string author;
    bool available;
public:
    // default
    Book() {
        this->name = "Hajdi";
        this->author = "Johana Luis";
        this->available = true;
    }

    Book(string name, string author, bool available) {
        this->name = name;
        this->author = author;
        this->available = available;
    }

    Book(const Book &b) {
        this->name = b.name;
        this->author = b.author;
        this->available = b.available;
    }

    ~Book() {}

    friend class Library;

    friend void checkOutBook(LibraryMember &member, Library &library, int index);


};

class Library {
    string name;
    Book *books;
    int number;
public:

    Library() {
        this->name = "Braka Miladinovci";
        this->number = 0;
        this->books=new Book[30]; // alociram memorija
    }

    Library(const string &name, Book *books, int number) {
        this->name = name;
        this->number = number;
        this->books = new Book[30];
        for (int i = 0; i < number; ++i) {
            this->books[i] = books[i];
        }
    }

    ~Library() {
        delete [] books;
    }

    friend void checkOutBook(LibraryMember &member, Library &library, int index);

    void addBook(Book book){
        if (number < 30) {
            books[number++] = book;
        } else {
            cout << "Library is full." << endl;
        }
    }

    void print() {
        cout << "Library: " << name << endl;
        for (int i = 0; i < number; i++) {
            cout << books[i].name << " " << books[i].author << " " << books[i].available << endl;
        }
    }

};

class LibraryMember {
    string name;
    int ind;
public:
    LibraryMember() {
        this->name = "";
        this->ind = 0;
    }

    LibraryMember(string name, int ind) {
        this->name = name;
        this->ind = ind;
    }

    ~LibraryMember() {}

    friend void checkOutBook(LibraryMember &member, Library &library, int index);

};

void checkOutBook(LibraryMember &member, Library &library, int index) {
    if (library.books[index].available) {
        cout << member.name << "ID: " << member.ind << " checks out " <<
             library.books[index].name << endl;
        library.books[index].available = false;
    } else {
        cout << "Sorry " << library.books[index].name << " is not available." << endl;
    }
}


int main() {
    Library l1;
    int n;
    cout << "Enter the number of books" << endl;
    cin >> n;
    char name[30], author[30];
    bool availability;
    for (int i = 0; i < n; i++) {
        cin >> name >> author >> availability;
        Book b = Book(name, author, availability);
        l1.addBook(b);
    }
    l1.print();
    LibraryMember m1("Marko", 9541);
    int index;
    cin >> index;
    checkOutBook(m1, l1, index);
    return 0;
}
