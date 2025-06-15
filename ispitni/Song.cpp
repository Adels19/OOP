#include <iostream>
#include <cstring>
#include <fstream>


using namespace std;

class NotValidInput {
public:
    void message() {
        cout << "Trying to delete from an empty list!" << endl;
    }
};

class Song {
private:
    string naslov;
    string avtor;
    string izveduvac;
    int vremetraenje;
public:

    Song(const string &naslov = "", const string &avtor = "", const string &izveduvac = "",
         const int vremetraenje = 0) {
        this->naslov = naslov;
        this->avtor = avtor;
        this->izveduvac = izveduvac;
        this->vremetraenje = vremetraenje;
    }

    Song(const Song &cp) {
        this->naslov = cp.naslov;
        this->avtor = cp.avtor;
        this->izveduvac = cp.izveduvac;
        this->vremetraenje = cp.vremetraenje;
    }

    void setNaslov(const string &n) {
        this->naslov = n;
    }

    void setAvtor(const string &a) {
        this->avtor = a;
    }

    void setIzveduvac(const string &i) {
        this->izveduvac = i;
    }

    void setVremetraenje(int v) {
        this->vremetraenje = v;
    }

    const string &getNaslov() const {
        return naslov;
    }

    const string &getAvtor() const {
        return avtor;
    }

    const string &getIzveduvac() const {
        return izveduvac;
    }

    int getVremetraenje() const {
        return vremetraenje;
    }

    friend istream &operator>>(istream &in, Song &song) {
        getline(in, song.naslov);
        getline(in, song.avtor);
        getline(in, song.izveduvac);
        in >> song.vremetraenje;
        return in;
    }

    void print(ofstream &out) {
        out << "Song title: " << naslov << ", Author: " << avtor << ", Interpreted by: " << izveduvac << ", "
            << vremetraenje << " sek." << endl;
    }

    friend class Festival;
};

class Festival {
private:
    string imeFestival;
    string grad;
    string datum;
    Song *songs;
    int n;
public:

    Festival(const string &imeFestival = "", const string &grad = "", const string &datum = "", Song *songs = nullptr,
             int n = 0) {

        this->imeFestival = imeFestival;
        this->grad = grad;
        this->datum = datum;

        this->n = n;
        this->songs = new Song[n];
        for (int i = 0; i < n; i++) {
            this->songs[i] = songs[i];
        }
    }

    Festival(const Festival &cp) {
        this->imeFestival = cp.imeFestival;
        this->grad = cp.grad;
        this->datum = cp.datum;

        this->n = cp.n;
        this->songs = new Song[cp.n];
        for (int i = 0; i < cp.n; i++) {
            this->songs[i] = cp.songs[i];
        }
    }

    Festival &operator=(const Festival &cp) {

        if (this != &cp) {

            delete[]songs;

            this->imeFestival = cp.imeFestival;
            this->grad = cp.grad;
            this->datum = cp.datum;
            this->n = cp.n;

            songs = new Song[n];
            for (int i = 0; i < cp.n; i++) {
                songs[i] = cp.songs[i];
            }

        }

        return *this;
    }

    ~Festival() {
        delete[]songs;
    }

    Festival &operator-=(const Song &s) {

        int newSize = 0;

        if (n == 0) {
            throw NotValidInput();
        }

// Го копира само она што не е еднакво на дадената песна
// → значи сите исти се отстрануваат.

        for (int i = 0; i < n; i++) {
            if (!(songs[i].getNaslov() == s.getNaslov() &&
                  songs[i].getAvtor() == s.getAvtor() &&
                  songs[i].getIzveduvac() == s.getIzveduvac() &&
                  songs[i].getVremetraenje() == s.getVremetraenje())) {
                newSize++;
            }
        }

        if (newSize == n)return *this;

        Song *tmp = new Song[newSize];
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (!(songs[i].getNaslov() == s.getNaslov() &&
                  songs[i].getAvtor() == s.getAvtor() &&
                  songs[i].getIzveduvac() == s.getIzveduvac() &&
                  songs[i].getVremetraenje() == s.getVremetraenje())) {
                tmp[j++] = songs[i];
            }
        }

        delete[]songs;
        songs = tmp;
        n = newSize;

        return *this;
    }

    //Festival: Ohridski Trubaduri - Ohrid, 30/08/2024
    void print(ofstream &out) {
        out << "Festival: " << imeFestival << " - " << grad << ", " << datum << endl;

        for (int i = 0; i < n; i++) {
            songs[i].print(out);
        }

    }

    friend istream &operator>>(istream &is, Festival &f) {
        is >> f.imeFestival >> f.grad >> f.datum >> f.n;
        for (int i = 0; i < f.n; i++) {
            is >> f.songs[i];
        }
        return is;
    }

    Festival notFromAuthor(const string &author) {

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (songs[i].getAvtor() != author) {
                count++;
            }
        }

        Song *filtered = new Song[count];
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (songs[i].getAvtor() != author) {
                filtered[j++] = songs[i];
            }
        }

        Festival f(imeFestival, grad, datum, filtered, count);
        delete[] filtered;
        return f;
    }


};


void wtf() {
    ofstream fout("vlezna.txt");
    string line;
    while (getline(std::cin, line)) {
        if (line == "----") {
            break;
        }
        fout << line << endl;
    }
}

void rff(string path) {
    ifstream fin(path);
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
}


int main() {

    wtf();

    Festival festival;
    //TODO your code here
    //TODO Read the data from the file and store them in `festival`
    ifstream fin("vlezna.txt");
    if (!fin.is_open()) {
        return -1;
    }

    string imeFestival;
    string grad;
    string datum;
    int n;

    getline(fin, imeFestival);   //Ohridski Trubaduri
    getline(fin, grad);          //Ohrid
    getline(fin, datum);         //30/08/2024
    fin >> n;                   //2
    fin.ignore();


    Song *songs = new Song[n];
    for (int i = 0; i < n; i++) {
        fin >> songs[i];
        fin.ignore();
    }

    festival = Festival(imeFestival, grad, datum, songs, n);


    delete[] songs;


    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE NEXT COMMENT
    string author;
    getline(cin, author);
    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE PREVIOUS COMMENT


    Song toDelete;
    try {
        festival -= toDelete;
    }catch(NotValidInput &e){
        e.message();
    }
    //TODO Save the results in the files izlezna1.txt and izlezna2.txt after this line

    ofstream fout1("izlezna1.txt");
    ofstream fout2("izlezna2.txt");

    festival.print(fout1);
    Festival filtered = festival.notFromAuthor(author);
    filtered.print(fout2);

    //DO NOT MODIFY THE CODE BELLOW

    cout << "All the data for the festival:" << endl;
    rff("izlezna1.txt");
    cout << "Songs NOT from the author " << author << ": " << endl;
    rff("izlezna2.txt");


    return 0;
}
