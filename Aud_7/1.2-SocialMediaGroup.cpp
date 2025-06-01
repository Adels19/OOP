#include <iostream>
#include <cstring>

using namespace std;

class User {
protected:
    string company;
    int level;
    string username;
public:

    // default-constructor
    User(string username = "AdelaElenin", string company = "VillaAdela", int level = 10) {
        this->username = username;
        this->company = company;
        this->level = level;
    }

    // copy-constructor
    User(const User &u) {
        this->username = u.username;
        this->company = u.company;
        this->level = u.level;
    }

    ~User() {}  // moze i ne mora

    void setUsername(const string &us) {
        this->username = us;
    }

    void setCompany(const string &comp) {
        this->company = comp;
    }

    void setLevel(int lv) {
        this->level = lv;
    }

    const string &getUsername() const {
        return username;
    }

    const string &getCompany() const {
        return company;
    }

    int getLevel() const {
        return level;
    }

    // vnesuvame korisnici
    friend istream &operator>>(istream &in, User &user) {
        in >> user.username >> user.company >> user.level;
        return in;
    }

    // pecatime korisnici
    friend ostream &operator<<(ostream &os, const User &user) {
        return os << user.username << " " << user.company << " " << user.level << endl;
    }
};

class Group {
protected:
    User *users;
    int size;
    string groupName;
public:

    // obicen constructor
    Group(const string &groupName) {
        this->size = 0;
        this->groupName = groupName;
        this->users = nullptr;
    }

    // copy constructor
    Group(const Group &gr) {
        this->size = gr.size;
        this->groupName = gr.groupName;

        this->users = new User[gr.size];

        for (int i = 0; i < gr.size; i++) {
            this->users[i] = gr.users[i];
        }
    }

    // poradi dinamicka alokacija, za deep copy (zlatna 3ka)
    Group &operator=(const Group &gr) {

        if (this != &gr) {

            // osloboduvame stara memorija
            delete[] users;

            // gi polnime novite vrednosti
            this->size = gr.size;
            this->groupName = gr.groupName;

            // dinamicka alokacija na nova memorija za *users
            this->users = new User[gr.size];
            for (int i = 0; i < gr.size; i++) {
                this->users[i] = gr.users[i];
            }
        }

        return *this;
    }

    // must za dinamicka alokacija
    ~Group() {
        delete[] users;
    }


    virtual void addMember(User &u) {

        // proverka dali postoi
        for (int i = 0; i < size; i++) {
            if (users[i].getUsername() == u.getUsername()) {
                cout << "User with username '" << u.getUsername() << "' already exists in the group." << endl;
                return;
            }
        }

        // kreiram nova niza so uste edno mesto za u
        User *temp = new User[size + 1];

        // gi dodavam starite elementi
        for (int i = 0; i < size; i++) {
            temp[i] = users[i];
        }

        // na posledno mesto go dodavam elementot u
        temp[size++] = u;

        // ja brisam starata niza
        delete[] users;

        // azuriranje na pokazuvacot na novata niza
        users = temp;
    }

    virtual double rating() const {

        double total = 0;
        double averageLevel = 0;
        for (int i = 0; i < size; i++) {
            total += users[i].getLevel();
        }

        averageLevel = total / size;

        return (10 - averageLevel) * size / 100.0;
    }

    // pecatenje informacii za grupata
    friend ostream &operator<<(ostream &out, const Group &g) {
        out << "Group: " << g.groupName << endl;
        out << "Members: " << g.size << endl;
        out << "Rating: " << g.rating() << endl;
        out << "Members list: " << endl;
        if (g.size == 0) {
            out << "EMPTY" << endl;
        } else {
            for (int i = 0; i < g.size; i++) {
                out << i + 1 << ". " << g.users[i] << endl;
            }
        }

        return out;
    }

};

class PrivateGroup : public Group {
public:
    static int capacity;    // maksimalen br na clenovi
    static const float coef;    // koef za presmetka na rejting


    // kreira objekt od PrivateGroup taka sto prima ime,
    // pa povikuva konstruktor od baznata klasa Group i go prosleduva so groupName
    PrivateGroup(const string &groupName)
            : Group(groupName) {}


    static void setCapacity(int c) {
        capacity = c;
    }

    static int getCapacity() {
        return capacity;
    }

    // se prepokriva metodata bidejkji ima nov nacin na smetanje so coef
    double rating() const {

        // za da ne delime so 0 - preventivno
        if (size == 0 || capacity == 0) return 0;


        double total = 0;
        double averageLevel = 0;
        for (int i = 0; i < size; i++) {
            total += users[i].getLevel();
        }

        averageLevel = total / size;


        return (10 - averageLevel) * ((double) size / capacity) * coef;
    }


};

// must ako se static
const float PrivateGroup::coef = 0.8f;
int PrivateGroup::capacity = 10;

int main() {

    cout << "INTEGRATION TEST" << endl;
    char name[50];
    int nGroups;
    cin >> nGroups;
    Group **groups = new Group *[nGroups];
    for (int i = 0; i < nGroups; i++) {
        int type;
        cin >> type;
        cin >> name;
        if (type == 1) { //normal group
            groups[i] = new Group(name);
        } else { //private group
            groups[i] = new PrivateGroup(name);
        }
        int nUsers;
        cin >> nUsers;
        for (int j = 0; j < nUsers; j++) {
            User u;
            cin >> u;

            groups[i]->addMember(u);

        }
    }

    cout << "BEFORE CHANGE OF PRIVATE GROUP COEFFICIENT" << endl;
    for (int i = 0; i < nGroups; ++i) {
        cout << *groups[i];
    }
    PrivateGroup::setCapacity(15);
    cout << "AFTER CHANGE OF PRIVATE GROUP COEFFICIENT" << endl;
    for (int i = 0; i < nGroups; ++i) {
        cout << *groups[i];
    }

}
