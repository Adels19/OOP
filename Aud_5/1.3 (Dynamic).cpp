#include <iostream>
#include <cstring>

using namespace std;

// Aud_5-1.3 Dinamicki alocirana niza
// https://bbb-lb.finki.ukim.mk/playback/presentation/2.3/8b86aae906d25c9acd475b0b0fefd7034e7206de-1711624496101

// SVETO TROJSTVO ZA DINAMICKI NIZI: DEFAULT, COPY, OPERATOR=

class Array {
    int *content;  // dinamicki alocirana niza, osven znaci mora da ima golemina
    int size;
    int capacity;

    // za da ne se povtoruva podolu vo kodot moze vaka:
//    void copy(const Array &other){
//        this->capacity = other.capacity;
//        this->size = other.size;
//        content = new int[this->capacity];
//        for (int i = 0; i < this->size; i++) {
//            content[i] = other.content[i];
//        }
//    }
public:
    // na pocetok imam mesto za 10, koga ke ja napolnam,
    // 11tiot ne go sobira pa kapacitetot se zgolemuva duplo
    Array(int capacity = 10) {
        this->capacity = capacity;
        size = 0;   // momentalno prazna
        content = new int[capacity];
    }

    // MUST 2
    Array(const Array &other) {
        this->capacity = other.capacity;
        this->size = other.size;
        content = new int[this->capacity];
        for (int i = 0; i < this->size; i++) {
            content[i] = other.content[i];
        }
    }

    // MUST 3
    Array &operator=(const Array &other) {
        if (this != &other) {   // !self assignment
            // ova e se isto ko copy, samo prvo mora da se izbrisi
            delete [] content;
            this->capacity = other.capacity;
            this->size = other.size;
            content = new int[this->capacity];
            for (int i = 0; i < this->size; i++) {
                content[i] = other.content[i];
            }
        }
        return *this;
    }

    friend ostream &operator<<(ostream &out, const Array &a) {
        out << "Capacity: " << a.capacity << endl;
        out << "Size: " << a.size << endl;
        for (int i = 0; i < a.size; i++) {
            out << a.content[i] << " ";
        }
        out << endl;
        return out;
    }

    // da dodavame brojce vo nizata ako ima mesto,
    // ako nema ja zgolemuvame duplo
    Array &operator+=(int number) {
        if (number == capacity) {
            // cekor 1 se sozdava nova tmp niza so dupli kapacitet
            int *tmp = new int[2 * capacity];
            capacity *= 2;
            // cekor 2, so for se polni novata niza(se prefrluvaat)
            for (int i = 0; i < size; i++) {
                tmp[i] = content[i];
            }
            // cekor 3 se brisi memorijata od content da lebdi,
            // i neka pokazuva kon toa sto pokazuva tmp
            delete[] content;
            content = tmp;
        }
        // bezrazlika dali number < ili = ili > od capacity
        content[size] = number; // vo content od size go stavame number
        size++; // size se zgolemuva

        return *this;   // ja vraka modificirana niza
    }
};

int main() {

    Array a(3);
    cout << a;

    for (int i = 0; i < 14; i++) {
        a += i;
        cout << a;
    }


    return 0;
}
