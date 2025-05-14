#include <iostream>
#include <cstring>

using namespace std;

// AUD 4
// https://bbb-lb.finki.ukim.mk/playback/presentation/2.3/740dc1184c44f2d100ce97a5038744c4cd34f22a-1648042101186
//Да се дефинира класа Ekipa што содржи информации за име на екипата, година на формирање и градот од каде потекнува.
//Да се дефинира класа Natprevar што содржи информации за домаќин, гостин (објекти од класата Ekipa), голови кои ги постигнал домаќинот и голови кои ги постигнал гостинот.
//Да се дефинира посебна функција revans што како аргументи прима два објекта од класата Natprevar и проверува дали едниот натпревар е реванш на другиот. Еден натпревар е реваш на друг ако гостинот и домаќинот од првиот натпревар се истите екипи со домаќинот и гостинот од вториот натпревар, соодветно.
//Да се дефинира функцијата duel која што како аргументи прима два објекта од класата Natprevar и ако едниот натпревар е ревашн на другиот функцијата треба да ја врати екипата која е подобра во меѓусебниот дуел. Во спротивно да испечати порака дека натпреварите не се совпаѓаат. Во случајот кога е нерешено функцијата враќа 0.


class Team {
    // dinamicki alocirani nizi
    char *name;
    char *stadium;
    char *city;

    // za da ne pisuvame vo copy constructor i operator =
    void copy(const Team &other) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->stadium = new char[strlen(other.stadium) + 1];
        strcpy(this->stadium, other.stadium);
        this->city = new char[strlen(other.city) + 1];
        strcpy(this->city, other.city);
    }

    void freeMemory() {
        delete[] name;
        delete[] stadium;
        delete[] city;
    }

public:

    // constructor with arguments and default
    Team(char *name = "", char *stadium = "", char *city = "") {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->stadium = new char[strlen(stadium) + 1];
        strcpy(this->stadium, stadium);
        this->city = new char[strlen(city) + 1];
        strcpy(this->city, city);
    }

    // copy-constructor
    Team(const Team &other) {
        copy(other);
    }

    //operator =
    Team &operator=(const Team &other) {
        if (this != &other) {
            freeMemory();
            copy(other);
        }
        return *this;
    }

    ~Team() {
        freeMemory();
    }

    void print() {
        cout << "Team name: " << name << ", which plays om stadium: " << stadium <<
             ", in the city: " << city << endl;
    }

};


int main() {
    int n;
    cin >> n;
    Team *teams = new Team[n]; // za da ne trosime memorija

    char name[100];
    char stadium[100];
    char city[100];
    for (int i = 0; i < n; i++) {
        cin >> name >> stadium >> city;
        teams[i] = Team(name, stadium, city); // bez operator =, tuka ke padne programata
    }

    for (int i = 0; i < n; i++) {
        teams[i].print();
    }

    return 0;
}
