#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Character {
public:
    virtual void attack() = 0;
    virtual string getInfo() = 0;
    virtual ~Character() = default;
};

class Warrior : public Character {
    string name;
public:
    Warrior(const string& n) : name(n) {}
    void attack() override {
        cout << name << " б'є мечем" << endl;
    }
    string getInfo() override {
        return "Warrior: " + name;
    }
};

class Mage : public Character {
    string name;
public:
    Mage(const string& n) : name(n) {}
    void attack() override {
        cout << name << " кидає закляття" << endl;
    }
    string getInfo() override {
        return "Mage: " + name;
    }
};

class Archer : public Character {
    string name;
public:
    Archer(const string& n) : name(n) {}
    void attack() override {
        cout << name << " стріляє з лука" << endl;
    }
    string getInfo() override {
        return "Archer: " + name;
    }
};

class Arena {
    vector<Character*> fighters;
public:
    ~Arena() {
        for (auto f : fighters) delete f;
    }

    void add(Character* c) {
        fighters.push_back(c);
    }

    void erase(int index) {
        if (index < 0 || index >= (int)fighters.size()) return;
        delete fighters[index];
        fighters.erase(fighters.begin() + index);
    }

    void show() const {
        for (size_t i = 0; i < fighters.size(); ++i) {
            cout << i << ": " << fighters[i]->getInfo() << endl;
        }
    }

    void attackAll() {
        for (auto f : fighters) f->attack();
    }

    Arena& operator+(Character* c) {
        add(c);
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Arena& a) {
        for (size_t i = 0; i < a.fighters.size(); ++i) {
            os << i << ": " << a.fighters[i]->getInfo() << endl;
        }
        return os;
    }
};

int main() {
    Arena arena;

    arena = arena + new Warrior("мечник");
    arena = arena + new Mage("гендальф");
    arena = arena + new Archer("лучник");

    cout << arena;

    arena.attackAll();

    return 0;
}
