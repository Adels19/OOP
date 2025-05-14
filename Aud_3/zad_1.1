#include <iostream>
#include <cstring>

using namespace std;

//Средба
//Да се дефинира класа Momche која содржи информации за име, презиме и години. За класата да се дефинираат конструктори, деструктор и метод за печатење на објектот на екран во формат:
//Momche: Ime Prezime Godini.
//Да се дефинира класа Devojche со истите атрибути и методи со разлика во форматот на печатење:
//Devojche: Ime prezime godini.
//Креирајте класа Sredba која содржи податоци за едно момче и едно девојче.
//Креирајте функција print() која ги печати податоците за момчето и девојчето во следниот формат:
//Sredba: Momche: Ime Prezime Godini Devojche: Ime Prezime Godini.
//Напишете функција daliSiOdgovaraat() која печати “Si odgovaraat” доколку разликата на нивните години е помала или еднаква на 5 или “Ne si odgovaraat” во спротивно.

class Boy {
    char fullName[100];
    int age;
public:

    // default constructor
    Boy() {
        strcpy(fullName, "Trajce");
        age = 18;
    }

    // constructor with arguments
    Boy(char *fullName, int age) {
        strcpy(this->fullName, fullName);
        this->age = age;
    }

    // destructor, do nothing
    ~Boy() {}

    // copy constructor
    Boy(const Boy &boy) {
        cout << "Copy constructor for boy is called." << endl;
        strcpy(this->fullName, boy.fullName);
        this->age = boy.age;
    }

    void print() {
        // Momche: Ime Prezime Godini
        cout << "Momche: " << fullName << " " << age << endl;
    }

    friend class Date;


};

class Girl {
    char fullName[100];
    int age;
public:

    // default constructor
    Girl() {
        strcpy(fullName, "Ana");
        age = 18;
    }

    // constructor with arguments
    Girl(char *fullName, int age) {
        strcpy(this->fullName, fullName);
        this->age = age;
    }

    // destructor, do nothing
    ~Girl() {}

    // copy constructor
    Girl(const Girl &girl) {
        cout << "Copy constructor for girl is called." << endl;
        strcpy(this->fullName, girl.fullName);
        this->age = girl.age;
    }

    void print() {
        // Devojche: Ime Prezime Godini
        cout << "Devojche: " << fullName << " " << age << endl;
    }
    friend class Date;

};

class Date {
    Boy boy;
    Girl girl;
public:
    Date() {} // default construcotr

    Date(const Boy &boy, const Girl &girl) {        // ako nema &, se povikuva implicitno a ne se praka po argumenti
        this->boy = boy;
        this->girl = girl;
    }

    // copy constructor
    Date(const Date &date) {
    //    cout << "Copy constructor is called." << endl;
        this->boy = date.boy;
        this->girl = date.girl;
    }

    void print() {
        cout << "Date between: ";
        boy.print();
        cout << " and ";
        girl.print();
    }

    void isMatch() {
        int diff = abs(boy.age - girl.age);
        if(diff<=5){
            cout << "Match" << endl;
        }else{
            cout << "Not a match. Swipe left." << endl;
        }
    }
};


int main() {

//    Boy boys[5]; // povikuva 5 pati default constructor

    Boy b; // default constructor
    Girl g;

    Date date(b, g);
    date.print();

    date.isMatch();

    // kako da go povikame copy constructor:
//    Boy b1(b); // eksplicitno
//    b1.print();




    return 0;
}
