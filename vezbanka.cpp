#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void wtf() {
    ofstream fout("input.txt");
    string line;
    while (getline(cin, line)) {
        if (line == "----") break;
        fout << line << "\n";
    }
}

void rff(const string &path) {
    ifstream fin(path);
    string line;
    while (getline(fin, line)) {
        cout << line << "\n";
    }
}

class BankAccount {
    string br_smetka;
    string ime_sopstvenik;
    string tip_smetka;
    int saldo;
public:
    BankAccount(const string &brSmetka = "", const string &imeSopstvenik = " ", const string &tipSmetka = " ",
                int saldo = 0) {
        this->br_smetka = brSmetka;
        this->ime_sopstvenik = imeSopstvenik;
        this->tip_smetka = tipSmetka;
        this->saldo = saldo;
    }

    BankAccount(const BankAccount &cp) {
        this->br_smetka = cp.br_smetka;
        this->ime_sopstvenik = cp.ime_sopstvenik;
        this->tip_smetka = cp.tip_smetka;
        this->saldo = cp.saldo;
    }

    ~BankAccount() {}

    const string &getBrSmetka() const {
        return br_smetka;
    }

    const string &getImeSopstvenik() const {
        return ime_sopstvenik;
    }

    const string &getTipSmetka() const {
        return tip_smetka;
    }

    int getSaldo() const {
        return saldo;
    }

    friend istream &operator>>(istream &is, BankAccount &ba) {
        is >> ba.br_smetka >> ba.ime_sopstvenik >> ba.tip_smetka >> ba.saldo;
        return is;
    }

    friend ostream &operator<<(ostream &os, BankAccount &ba) {
        os << ba.br_smetka << ba.ime_sopstvenik << ba.tip_smetka << ba.saldo << endl;
        return os;
    }

    BankAccount &operator++() {
        saldo += 100;
        return *this;
    }
    //zosto return *this pravime na sekoe?

    // zosto ova da vraka kopija, ne moze kako ++ isto?
    BankAccount operator--(int) {
        BankAccount temp = *this;
        saldo -= 100;
        return temp;
    }


    //  Оператор += кој додава на салдото одреден број (int) vaka?
    BankAccount &operator+=(int number) {
        saldo += number;
        return *this;
    }

    void print(ofstream &out) {
        out << br_smetka << " " << ime_sopstvenik << " " << tip_smetka << " " << saldo << endl;
    }

};


class Bank {
    BankAccount *listaSmetki;
    int br_smetki;

public:

    Bank(BankAccount *listaSmetki = nullptr, int br_smetki = 0) {
        this->br_smetki = br_smetki;
        this->listaSmetki = new BankAccount[br_smetki];
        for (int i = 0; i < br_smetki; i++) {
            this->listaSmetki[i] = listaSmetki[i];
        }
    }

    Bank(const Bank &b) {
        this->br_smetki = b.br_smetki;
        this->listaSmetki = new BankAccount[b.br_smetki];
        for (int i = 0; i < br_smetki; i++) {
            this->listaSmetki[i] = b.listaSmetki[i];
        }
    }

    ~Bank() {
        delete[]listaSmetki;
    }

    Bank &operator=(const Bank &b) {
        if (this != &b) {
            delete[]listaSmetki;
            this->br_smetki = b.br_smetki;
            this->listaSmetki = new BankAccount[b.br_smetki];
            for (int i = 0; i < br_smetki; i++) {
                this->listaSmetki[i] = b.listaSmetki[i];
            }
        }
        return *this;
    }


    //KAKOOO
    Bank &operator+=(const BankAccount &ba) {

        BankAccount *temp = new BankAccount[br_smetki + 1];
        // kako sto stoi vo private: delot

        for (int i = 0; i < br_smetki; i++) {
            temp[i] = listaSmetki[i];
        }
        // kopirame starite

        // dodavame noviot
        temp[br_smetki] = ba;

        // ja briseme starata
        delete[]listaSmetki;
        listaSmetki = temp;

        return *this;

    }



    friend ostream &operator<<(ostream &os, const Bank &bank) {
        for (int i = 0; i < bank.br_smetki; i++) {
            os << bank.listaSmetki[i] << endl;
        }
        return os;
    }


};

int main() {
    wtf();

    Bank bank;
    //TODO ваш код
    //TODO прочитајте BankAccount објекти од input.txt (со operator>>) и додадете ги во `bank`

    ifstream in("input.txt");
    if (!in.is_open()) {
        cout << "Не може да се отвори input.txt" << endl;
        return 1;
    }

    string brSmetka, imeSopstvenik, tipSmetka;
    int saldo;


    while (in >> brSmetka >> imeSopstvenik >> tipSmetka >> saldo) {
        if (brSmetka == "----") {
            break;
        }
    }


    string searchNumber, filterType;
    cin >> searchNumber >> filterType;

    //TODO запишете во output1.txt: сите сметки (operator<< на bank)
    //TODO запишете во output2.txt:
    //   • резултат од bank[searchNumber].print(fout2) или порака при исклучок
    //   • резултат од bank.notOfType(filterType) (operator<<)

    cout << "All accounts:" << endl;
    rff("output1.txt");
    cout << "Search result for account " << searchNumber << ":" << endl;
    rff("output2.txt");

    return 0;
}
