#include <iostream>
using namespace std;

class Coffee {
    public:
        virtual string Describe() const = 0;
        virtual ~Coffee() {}
};

class SimpleCoffee:public Coffee {
    public:
    string Describe() const override {
        return "Simple coffee ";
  }
};

class CoffeeDecorator:public Coffee {
    protected:
        Coffee *_coffee;
    public:
        CoffeeDecorator() {};
        CoffeeDecorator(Coffee *_coffee) {
            this->_coffee = _coffee;
        }
        string Describe() const override {
            return _coffee->Describe();
        }
};

class CaramelCoffee:public CoffeeDecorator {
    public:
        CaramelCoffee(Coffee *_coffee) {
            this->_coffee = _coffee;
        }
        string Describe() const override {
            return _coffee->Describe() + "with caramel";
        }
};

class VanillaCoffee:public CoffeeDecorator {
    public:
        VanillaCoffee(Coffee *_coffee) {
            this->_coffee = _coffee;
        }
        string Describe() const override {
            return _coffee->Describe() + "with vanilla";
        }
};
