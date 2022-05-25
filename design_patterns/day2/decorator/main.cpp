#include "decorator.hpp"

int main() {

    Coffee *simple = new SimpleCoffee();
    cout << simple->Describe() << endl;

    Coffee *caramelCoffee = new CaramelCoffee(simple);
    Coffee *vanillaCoffee = new VanillaCoffee(simple);
    cout << caramelCoffee->Describe() << endl;
    cout << vanillaCoffee->Describe() << endl;

    delete simple;
    delete caramelCoffee;
    delete vanillaCoffee;

  return 0;
}