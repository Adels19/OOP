#include <iostream>
#include <cstring>

using namespace std;

// 3 bitni raboti:
// define the error/exception class
// throw (in the constructor)
//


// possible errors
class EmbgLengthNotValidException {
private:
    string embg; // not valid embg
public:
    EmbgLengthNotValidException(const string &embg) : embg(embg) {

    }

    // message when this error happens
    void message() {
        cout << "EMBG " << embg << " must be 13 digits long" << endl;
    }
};

// another exception
class EmbgFormatNotValidException {
private:
    string embg;
public:

    EmbgFormatNotValidException(const string &embg) : embg(embg) {

    }

    // message when this error happens
    void message() {
        cout << "EMBG " << embg << " must contain only digits" << endl;
    }
};

class Citizen {
    string name;
    string embg;

public:
    Citizen(const string &name, const string &embg) {
        // koga preku objekt se praka parametar se proveruva
        if (embg.size() != 13) {
            throw EmbgLengthNotValidException(embg);
        }

        for (int i = 0; i < embg.length(); i++) {
            if (!isdigit(embg[i])) {
                throw EmbgFormatNotValidException(embg);
            }
        }

        this->name = name;
        this->embg = embg;
    }
};


int main() {

    string name;
    string embg;

    cin >> name >> embg;


    // goalkeeper to catch the exception

    try {
        Citizen(name, embg);
    } catch (EmbgLengthNotValidException &e){
        e.message();
    } catch (EmbgFormatNotValidException &e){
        e.message();
    }

    // ako e niza od objekti, so for ciklus kreirani, najdobar nacin za da se pecatat site
    // e da se stavi i--, n-- vo for-ot na krajot


    return 0;
}
