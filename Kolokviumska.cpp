#include <iostream>
#include <cstring>

using namespace std;

//vezbi stefan
// https://courses.finki.ukim.mk/mod/bigbluebuttonbn/view.php?id=145326#

// Kolokviumska zadaca - mal del nedoresen
// https://bbb-lb.finki.ukim.mk/playback/presentation/2.3/8b86aae906d25c9acd475b0b0fefd7034e7206de-1712225418645

// da se implementira modul za upravuvanje so vozacite i prevozite.
// Da se implementira klasa Vehicle vo koja se cuvaat inf. za:
// reg.br. na vozilo (niza 9 znaci), ime na vozac(dinamick.niza od znaci),
// lokacija kade se naoga voziloto momentalno(int), max broj na patnici za edno patuvanje(int)
// br. izvozeni km. na voziloto(decimalen br. inicijalno na nula).
// Za klasata da se implementiraat
// potrebnite const. op. =, metod za da funkc. resenieto, op. <<,
// op. == za sporedba na 2 vozila spored reg. br. na vozilo,
// op. += za zgolemuvanje na br. izvozeni km. za X km.
// Da se implementira klasa RideApp vo koja ke se cuvaat inf. za:
// ime na app(max 20 znaci), lista na vozila koi vozat preku ovaa app (dinam. niza)
// br na vozila (br. el. vo niza od vozaci - cel br, inicijalno e 0.
// Za klasata da se implementira potrebni const i metodi so cel da funkc. resenieto
// Dopolnitelno za klasata da se implementira:
// * op. += za dodavanje novo vozilo vo app, (edno vozilo smee samo ednas da figurira vo app,
// pa da ne se dozvoli dodavanje na vozilo so veke postoecki br. na reg.
// * metod void addRide(int area, int passenger, int distanceKm) za dodeluvanje na prevoz
// na vozilo koe e najblisku do reonot area i koe


class Vehicle {
    char id[9];
    char *driver;
    int location;
    int maxPassengers;
    double kms;     // ako e inicijalno na 0,
    // vo konstruktor nema da go ima, vo teloto go stavame na nula

    // si olesnuvame (skratuvame kod)
    void copy(const Vehicle &v) {
        strcpy(this->id, v.id);
        this->driver = new char[strlen(v.driver) + 1];
        strcpy(this->driver, v.driver);
        this->location = v.location;
        this->maxPassengers = v.maxPassengers;
        this->kms = 0;
    }

public:
    // 2 in 1 constructor
    Vehicle(char *id = "", char *driver = "", int location = 1, int maxPassengers = 2) {
        strcpy(this->id, id);
        this->driver = new char[strlen(driver) + 1];
        strcpy(this->driver, driver);
        this->location = location;
        this->maxPassengers = maxPassengers;
        this->kms = 0;
    }

    // copy constructor
    Vehicle(const Vehicle &v) {
        copy(v);
    }

    // operator = (shablonski)
    Vehicle &operator=(const Vehicle &v) {
        if (this != &v) {
            delete[] driver;
            copy(v);
        }
        return *this;
    }

    // destructor
    ~Vehicle() {
        delete[] driver;
    }

    //  operator <<
    friend ostream &operator<<(ostream &out, const Vehicle &v) {
        return out << "ID: " << v.id << " Driver's name: " << v.driver
                   << " Passenger capacity: " << v.maxPassengers << " Location: "
                   << v.location << " kms driven: " << v.kms;
    }

    bool operator==(const Vehicle &v) {
        return strcmp(this->id, v.id) == 0;
    }

    Vehicle &operator+=(double kms) {
        this->kms += kms;
        return *this;
    }

    // dodavame za olesnuvanje,
    // kako jas kako kola sum oddalecena od
    int distance(int area) {
        return abs(this->location - area);
    }

    friend class RideApp;

};

class RideApp {
    char name[21];
    Vehicle *vehicles;
    int n;

    void copy(const RideApp &app) {
        strcpy(this->name, app.name);
        this->n = app.n;
        vehicles = new Vehicle[app.n];
        for (int i = 0; i < n; i++) {
            vehicles[i] = app.vehicles[i];
        }

    }

public:
    // ne se testira copy const. i op. = pa nema potreba da se praj
    RideApp(char *name = "") {
        strcpy(this->name, name);
        vehicles = new Vehicle[0]; // nema elementi
        n = 0;
    }

    // no pravime za da vezbame
    RideApp(const RideApp &app) {
        copy(app);
    }

    ~RideApp() {
        delete[] vehicles;
    }

    RideApp &operator+=(const Vehicle &other) {
        for (int i = 0; i < n; i++) {
            if (vehicles[i] == other) {
                return *this;
            }
        }
        Vehicle *tmp = new Vehicle[n + 1]; // se povikuva default cons. od Vehicle
        for (int i = 0; i < n; i++) {
            tmp[i] = vehicles[i];   // se povikuva operator = od Vehicle
        }
        tmp[n++] = other;   // op. = od Vehicle
        delete[]vehicles;
        vehicles = tmp;
        return *this;
    }

    friend ostream &operator<<(ostream &os, const RideApp &app) {
        os << app.name;
        if (app.n == 0) {
            os << "EMPTY" << endl;
        }

        for (int i = 0; i < app.n; i++) {
            os << app.vehicles[i] << endl;
        }
        return os;
    }


    // barame so funkc. distance, najbliska + dovolen kapacitet
    void addRide(int area, int passenegers, int kms) {
        bool first = true;
        //Vehicle closestVehicle; // ova e kopija na voizlo
        int idx = -1;
        int minDistance;

        for (int i = 0; i < n; i++) {
            if (vehicles[i].maxPassengers >= passenegers) {
                if (first) {    // ako e first
                    first = false;
                    idx = i;
                    minDistance = vehicles[i].distance(area);
                } else {
                    if (vehicles[i].distance(area) < minDistance) {
                        idx = i;
                        minDistance = vehicles[i].distance(area);
                    }
                }
            }
        }
        vehicles[idx] += kms;
        vehicles[idx].location = area;
    }
};

int main() {

    int testCase;
    cin >> testCase;
    if (testCase == 1) {
        cout << "CONSTRUCTOR Vehicle" << endl;
        Vehicle vehicle("NE1234SA", "Stefan", 5, 4);
        cout << vehicle << endl;
        cout << "CONSTRUCTOR Vehicle OK" << endl;
    } else if (testCase == 2) {
        cout << "COPY-CONSTRUCTOR Vehicle" << endl;
        Vehicle vehicle = Vehicle("NE1234SA", "Stefan", 5, 4);
        cout << vehicle << endl;
        cout << "COPY-CONSTRUCTOR Vehicle OK" << endl;
    } else if (testCase == 3) {
        cout << "DEFAULT CONSTRUCTOR AND OPERATOR = Vehicle" << endl;
        Vehicle vehicle;
        Vehicle vehicle2("NE1234SA", "Stefan", 5, 4);
        vehicle = vehicle2;
        cout << vehicle << endl;
        cout << "DEFAULT CONSTRUCTOR AND OPERATOR = Vehicle OK" << endl;
    } else if (testCase == 4) {
        cout << "CONSTRUCTOR RideApp" << endl;
        char appName[50];
        cin >> appName;
        RideApp app(appName);
        cout << app;
        cout << "CONSTRUCTOR RideApp OK" << endl;
    } else if (testCase == 5) {
        cout << "RideApp signUpVehicle test" << endl;
        char appName[50];
        cin >> appName;
        RideApp app(appName);
        int n;
        cin >> n;
        char ID[9];
        char name[20];
        int location;
        int capacity;
        for (int i = 0; i < n; i++) {
            cin >> ID >> name >> location >> capacity;
            app += Vehicle(ID, name, location, capacity);
        }
        cout << app;
    } else if (testCase == 6) {
        cout << "RideApp addRide test" << endl;
        char appName[50];
        cin >> appName;
        RideApp app(appName);
        int n;
        cin >> n;
        char ID[6];
        char name[20];
        int location;
        int capacity;
        for (int i = 0; i < n; i++) {
            cin >> ID >> name >> location >> capacity;
            app += Vehicle(ID, name, location, capacity);
        }
        cin >> n;
        for (int i = 0; i < n; i++) {
            int area, passengers, kms;
            cin >> area >> passengers >> kms;
            app.addRide(area, passengers, kms);
        }
        cout << app;
    }
    return 0;
}
