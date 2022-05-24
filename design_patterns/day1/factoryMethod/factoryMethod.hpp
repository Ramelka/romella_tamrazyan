#include <iostream>
using namespace std;

class Transport {
    public:
        virtual ~Transport() {}
        virtual string Operation() const = 0;
};

class Ship:public Transport {
    public:
        string Operation() const override {
            return "{Result of the Ship}";
        }
};

class Truck:public Transport {
    public:
        string Operation() const override {
            return "{Result of the Truck}";
        }
};

class Logistics {
    public:
        virtual ~Logistics(){};
        virtual Transport* FactoryMethod() const = 0;
        string SomeOperation() const {
            Transport* Transport = this->FactoryMethod();
            string result = "The same creator's code has just worked with " + Transport->Operation();
            delete Transport;
            return result;
        }
};

class SeaLogistics:public Logistics {
    public:
        Transport* FactoryMethod() const override {
            return new Ship();
        }
};

class RoadLogistics:public Logistics {
    public:
        Transport* FactoryMethod() const override {
            return new Truck();
        }
};

void ClientCode(const Logistics& logistics) {
    cout << "I'm not aware of the creator's class, but it still works.\n";
    cout << logistics.SomeOperation() << endl;
}
