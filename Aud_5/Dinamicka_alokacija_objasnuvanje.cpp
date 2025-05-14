#include <iostream>
#include <cstring>

using namespace std;

// AUD 4
// https://bbb-lb.finki.ukim.mk/playback/presentation/2.3/740dc1184c44f2d100ce97a5038744c4cd34f22a-1648042101186

class String {
private:
    // char cptr[100] --> zaludno potrosena memorija
    char *content;       // dynamically allocated array of characters
public:
    // za dinamicka alokacija
    // Ubavo bi bilo da ima: default constructor, constructor w arguments
    // MUST: copy-constructor,  destructor, operator =

    String(char *content = "") { // 2 in 1 constructor
        // 1. allocate memory for this -> cptr
        this->content = new char[strlen(content) + 1]; // +1 za null
        // 2. copy content
        strcpy(this->content, content);
    }

    // 1st part (copy constructor)
    String(const String &other) {
        this->content = new char[strlen(other.content) + 1];
        strcpy(this->content, other.content);
    }

    // 2nd part (destructor)
    ~String() {
        delete[] content;
    }

    // 3rd part (operator =)
    String &operator=(const String &s) {
        if(this==&s){   // prevent self-assignment
            delete [] content;
            this->content = new char[strlen(s.content) + 1];
            strcpy(this->content, s.content);
        }
        return *this;
    }

};

int main() {

    

    return 0;
}
