#include "factoryMethod.hpp"

int main() {
    
    cout << "Launched with the Sea Logistics.\n";
    Logistics* logistics1 = new SeaLogistics();
    ClientCode(*logistics1);
    delete logistics1;

    cout << endl;

    cout << "Launched with the Road Logistics.\n";
    Logistics* logistics2 = new RoadLogistics();
    ClientCode(*logistics2);
    delete logistics2;

    cout << endl;

    return 0;
}