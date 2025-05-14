#include <iostream>
#include <cstring>

using namespace std;

/*
Да се напише класа Datum во која ќе се чуваат ден, месец и година (цели броеви).
Да се напише класа Vraboten во која се чува име на вработениот (не повеќе од 20 знаци), плата и датум на раѓање (објект од класата Datum).
Да се напишат две функции кои како аргументи примаат низа од вработени и големина на низата. Едната функција го враќа вработениот со најголема плата, а другата функција го враќа најмладиот вработен во фирмата.
Во главната програма потребно е да се испечатат на екран податоците за најмалдиот и најплатениот вработен. Печатењето на вработениот да биде реализирано со посебна функција print() во рамките на класата Vraboten.
*/

class Date {
    int day;
    int month;
    int year;
public:

    // 2 in 1 constructor
    Date(int day = 1, int month = 1, int year = 2000) {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    // copy-constructor
    Date(const Date &d) {
        this->day = d.day;
        this->month = d.month;
        this->year = d.year;
    }

    ~Date() {}

    void print() {
        cout << day << "." << month << "." << year << endl;
    }

    // zemeno od AUD 1
    int compare(const Date &other) const {
        if (year != other.year)
            return year > other.year ? 1 : -1;
        if (month != other.month)
            return month > other.month ? 1 : -1;
        if (day != other.day)
            return day > other.day ? 1 : -1;
        return 0;
    }

};

class Employee {
    string name;
    int salary;
    Date DOB;
public:

    // default constructor
    Employee() {
        this->name = "Petko";
        this->salary = 10000;
    }

    // constructor w arguments
    Employee(const string &name, int salary, Date DOB) {
        this->name = name;
        this->salary = salary;
        this->DOB = DOB;
    }

    // copy-constructor --> samo za vezbanje
    Employee(const Employee &e) {
        this->name = e.name;
        this->salary = e.salary;
        this->DOB = e.DOB;
    }

    ~Employee() {}

    void print() {
        cout << name << " " << salary << " ";
        DOB.print();
    }

    friend Employee highestPayedEmployee(Employee *employees, int n);

    friend Employee youngestEmployee(Employee *employees, int n);

};

Employee highestPayedEmployee(Employee *employees, int n) {  // prima niza i golemina na niza
    Employee max = employees[0];    // pocetno go zemame prviot vraboten
    for (int i = 0; i < n; i++) {
        if (employees[i].salary > max.salary) {
            max = employees[i];
        }
    }
    return max;
}

// za da sporeduvame datumi-objekti, imame compare metod vo klasata Date
// youngest znaci najgolem datum, znaci max
Employee youngestEmployee(Employee *employees, int n) {
    Employee max = employees[0];
    for (int i = 0; i < n; i++) {
        if (employees[i].DOB.compare(max.DOB) > 0) {
            max = employees[i];
        }
    }
    return max;
}

int main() {

    // 10 pati se povikuva default constructor
    Employee employees[10];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        int salary;
        int day, month, year;
        cin >> name >> salary >> day >> month >> year;
        Date dob(day, month, year); // kreirame objekt DOB
        employees[i] = Employee(name, salary, dob); // kreirame objekt Employee
    }


    cout << "Highest payed employee: ";
    highestPayedEmployee(employees, n).print();

    cout << "Youngest payed employee: ";
    youngestEmployee(employees, n).print();

    // vnesuvame: broj vraboteni, ime plata den mesec godina

    return 0;
}
