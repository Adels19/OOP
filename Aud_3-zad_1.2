#include <iostream>
#include <cstring>
using namespace std;

//Да се дефинира класа Ekipa што содржи информации за име на екипата, година на формирање и градот од каде потекнува.
//Да се дефинира класа Natprevar што содржи информации за домаќин, гостин (објекти од класата Ekipa), голови кои ги постигнал домаќинот и голови кои ги постигнал гостинот.
//Да се дефинира посебна функција revans што како аргументи прима два константни (const) објекта од класата Natprevar и проверува дали едниот натпревар е реванш на другиот. Еден натпревар е реваш на друг ако гостинот и домаќинот од првиот натпревар се истите екипи со домаќинот и гостинот од вториот натпревар, соодветно.
//Да се дефинира функцијата duel која што како аргументи прима два константни (const) објекта од класата Natprevar. Ако едниот натпревар е реванш на другиот функцијата треба да ја врати екипата која е подобра во меѓусебниот дуел. Во спротивно, треба да испечати порака дека натпреварите не се совпаѓаат. Во случајот кога е нерешено функцијата враќа 0.

class Team {
    string name;
    int founding_year;
    string city;
public:
    // 2 in 1 constructor
    Team(string name = "", int founding_year = 1990, string city = "") {
        this->name = name;
        this->founding_year = founding_year;
        this->city = city;
    }

    // copy constructor
    Team(const Team &t) {
        this->name = t.name;
        this->founding_year = t.founding_year;
        this->city = t.city;
    }

    ~Team() {}   // destructor, nisto ne pravi

    // za da ni se olesna podolnata funkcija,
    // sporeduva dali timovite se isti
    bool isEqual(Team other) {
        return name == other.name;
    }

    string getName() {
        return name;
    }
};

class Game {
    Team homeTeam;
    Team awayTeam;
    int homeGoals;
    int awayGoals;
public:

    // za vakvi klasi sto sodrzat objekti najdobro e
    // poseben default constructor i poseben constructor so argumenti

    // default constructor
    Game() {
        this->homeGoals = 0;
        this->awayGoals = 0;
        // nema potreba za objektite zatoa sto imaat svoi default constr. pogore
    }

    // constructor so argumenti
    // Кога користиш const Team &, само се читаат постоечките објекти, без копирање.
    Game(const Team &homeTeam, const Team &awayTeam, int homeGoals, int awayGoals) {
        this->homeTeam = homeTeam;
        this->awayTeam = awayTeam;
        this->homeGoals = homeGoals;
        this->awayGoals = awayGoals;
    }

    ~Game() {}

    // bidejki e vo klasata, imame samo vtor argument, a prviot se podrazbira
    // za prviot objekt sto ja povikuva funkcijata
    bool isRematch(Game other) {
        // return vrakja true ili false --> namesto: return true; else return false;
        return (homeTeam.isEqual(other.awayTeam) && awayTeam.isEqual(other.homeTeam));
    }


    //
    Team duel(Game &other) {
        if (isRematch(other)) {
            int goalsOfFirstTeam = this->homeGoals + other.awayGoals;
            int goalsOfSecondTeam = this->awayGoals + other.homeGoals;

            if (goalsOfFirstTeam > goalsOfSecondTeam) {
                return this->homeTeam;
            } else if (goalsOfFirstTeam < goalsOfSecondTeam) {
                return other.homeTeam;
            } else {
                return Team();
            }
        }
    }

};

// ako funkcijata bese nadvor od klasata
// vo zagradata naveduvame dva argumenti za dva objekti sto sporeduvame
//bool isRematch(Game firstGame, Game lastGame){}

int main() {

    Team t1("Vardar", 1947, "Skopje");
    Team t2("Pelister",1945, "Bitola");

    // Прв натпревар: Vardar домаќин, Pelister гостин
    Game g1(t1, t2, 22, 21);  // Vardar 22 : 21 Pelister

    // Реванш натпревар: Pelister домаќин, Vardar гостин
    Game g2(t2, t1, 21, 22);  // Pelister 21 : 22 Vardar

    // Дуел помеѓу двата натпревари
    Team winner = g1.duel(g2);

    // Проверка дали е празен тим (односно нерешено или невалиден дуел)
    if (winner.isEqual(Team())) {
        cout << "Nereseno ili natprevarite ne se revans." << endl;
    } else {
        cout << "Pobednik vo duelot e: " << winner.getName() << endl;
    }

    // za da se pecati cel objekt, treba preoptovaruvanje na << da se napravi



    return 0;
}
