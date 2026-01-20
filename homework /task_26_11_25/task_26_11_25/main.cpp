#include <iostream>
#include <map>

using namespace std;

class Car
{
private:
    string name;
    int price;

public:
    Car()
    {
        name = "";
        price = 0;
    }

    Car(string n, int p)
    {
        name = n;
        price = p;
    }

    string getName() const
    {
        return name;
    }

    int getPrice() const
    {
        return price;
    }

    void setName(string n)
    {
        name = n;
    }

    void setPrice(int p)
    {
        price = p;
    }

    void showInfo() const
    {
        cout << name << " - " << price << "$" << endl;
    }
};

class AutoSalon
{
private:
    map<string, Car> cars;

public:
    void addCar(const Car& car)
    {
        cars[car.getName()] = car;
        cout << "додано\n";
    }

    void removeCar(const string& name)
    {
        if (cars.count(name) == 0)
        {
            cout << "нема такого авто\n";
            return;
        }

        cars.erase(name);
        cout << "видалено\n";
    }

    void showAll() const
    {
        if (cars.empty())
        {
            cout << "список порожній\n";
            return;
        }

        for (pair<const string, Car> p : cars)
        {
            cout << p.first << " - " << p.second.getPrice() << "$" << endl;
        }
    }

    void findCar(const string& name) const
    {
        if (cars.count(name) == 0)
        {
            cout << "не знайдено\n";
            return;
        }

        cout << name << " - " << cars.at(name).getPrice() << "$" << endl;
    }
};

int main()
{
    AutoSalon salon;

    while (true)
    {
        cout << "\n1 - додати\n2 - видалити\n3 - показати всі\n4 - знайти\n0 - вийти\n";
        cout << "вибір: ";

        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 0)
        {
            break;
        }

        if (choice == 1)
        {
            string name;
            int price;

            cout << "назва: ";
            getline(cin, name);

            cout << "ціна: ";
            cin >> price;
            cin.ignore();

            Car car(name, price);
            salon.addCar(car);
        }
        else if (choice == 2)
        {
            string name;
            cout << "назва для видалення: ";
            getline(cin, name);

            salon.removeCar(name);
        }
        else if (choice == 3)
        {
            salon.showAll();
        }
        else if (choice == 4)
        {
            string name;
            cout << "назва для пошуку: ";
            getline(cin, name);

            salon.findCar(name);
        }
        else
        {
            cout << "невірний вибір\n";
        }
    }

    return 0;
}
