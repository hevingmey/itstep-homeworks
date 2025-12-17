#include "apartman.h"

int main() {
    Person p1("valeria", 30) ;
    
    Person p2("Mary", 28);
    
    Person p3("Vladyslsv", 40);

    Person flat1People[] = { p1, p2 };
    
    Person flat2People[] = { p3 };

    Apartment a1(1, 2, flat1People);
    
    Apartment a2(2, 1, flat2People);

    Apartment flatsArr[] = { a1, a2 };

    House h1("вул. Шевченка, 10", 2, flatsArr);

    h1.print();

    cout << "\n--- Копія будинку ---\n";
    House h2 = h1;
    h2.print();

    return 0;
}
