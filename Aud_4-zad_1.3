#include <iostream>
#include <cstring>

using namespace std;

// Aud_4-zad_1.3
// https://bbb-lb.finki.ukim.mk/playback/presentation/2.3/740dc1184c44f2d100ce97a5038744c4cd34f22a-1648042101186
/*Да се напише класа Student која треба да чува информации за името на студентот, број на индекс и просек. Да се дефинираат статички членови кои ќе даваат информации за бројот на студенти и вкупниот просек. Да се имплементираат статички функции кои ќе го враќаат вкупниот просек и бројот на студенти. Секогаш кога ќе се креира објект, статичките членови треба да се ажурираат.
Во главната програма да се внесат информации за n студенти, да се испечати список со сите студенти и вредностите од статичките членови.
 */

class Student {
    string name;
    string index;
    float GPA;
    // tuka definirame staticki clenovi
    static int totalStudents;
    static float totalGPA;
public:

    // default constructor
    Student() {
        this->name = "";
        this->index = "";
        this->GPA = 0.0;
    }

    // constructor w arguments
    Student(const string &name, string index, float GPA) {
        this->name = name;
        this->index = index;
        this->GPA = GPA;
        totalGPA += GPA;
        totalStudents++;
    }

    static int getTotalStudents() {
        return totalStudents;
    }

    static float getAverageGPA() {
        return totalGPA / totalStudents;
    }

    void print() {
        cout << index << " " << name << " " << GPA << endl;
    }

    ~Student() {}

};

// definirame staticki clenovi koi ne pripagaat na konkreten objekt
// tuku na samata klasa
int Student::totalStudents = 0;
float Student::totalGPA = 0.0;

int main() {

    int n;
    cout << "Enter number of students" << endl;
    cin >> n;
    Student students[n];
    string name, id;
    float gpa;

    for (int i = 0; i < n; i++) {
        cin >> name >> id >> gpa;
        students[i] = Student(name, id, gpa);
    }

    for (int i = 0; i < n; i++) {
        students[i].print();
    }

    cout << "Total students: " << Student::getTotalStudents() << endl;
    cout << "Total average: " << Student::getAverageGPA() << endl;

    return 0;
}
