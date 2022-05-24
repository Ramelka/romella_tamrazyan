#include <iostream>
using namespace std;

class Chair {
    public:
        virtual ~Chair() {};
        virtual unsigned int GetPrice() const = 0;
};

class ArtDecoChair:public Chair {
    public:
        unsigned int GetPrice() const override {
            return 100;
        }
};

class VictorianChair:public Chair {
    public:
        unsigned int GetPrice() const override {
            return 200;
        }
};

class ModernChair:public Chair {
    public:
        unsigned int GetPrice() const override {
            return 500;
        }
};

class Sofa {
    public:
        virtual ~Sofa() {};
        virtual unsigned int GetPrice() const = 0;
};

class ArtDecoSofa:public Sofa {
    public:
        unsigned int GetPrice() const override {
            return 1000;
        }
};

class VictorianSofa:public Sofa {
    public:
        unsigned int GetPrice() const override {
            return 1200 ;
        }
};

class ModernSofa:public Sofa {
    public:
        unsigned int GetPrice() const override {
            return 1500;
        }
};

class CoffeeTable {
    public:
        virtual ~CoffeeTable() {};
        virtual unsigned int GetPrice() const = 0;
};

class ArtDecoCoffeeTable:public CoffeeTable {
    public:
        unsigned int GetPrice() const override {
            return 1500;
        }
};

class VictorianCoffeeTable:public CoffeeTable {
    public:
        unsigned int GetPrice() const override {
            return 1700 ;
        }
};

class ModernCoffeeTable:public CoffeeTable {
    public:
        unsigned int GetPrice() const override {
            return 2000;
        }
};

class Furniture {
    public:
        virtual Chair *CreateChair() const = 0;
        virtual Sofa *CreateSofa() const = 0;
        virtual CoffeeTable *CreateCoffeeTable() const = 0;
};

class Furniture1:public Furniture {
    public:
        Chair *CreateChair() const override {
            return new ArtDecoChair();
        }
        Sofa *CreateSofa() const override {
            return new ArtDecoSofa();
        }
        CoffeeTable *CreateCoffeeTable() const override {
            return new ArtDecoCoffeeTable();
        }
};

class Furniture2:public Furniture {
    public:
        Chair *CreateChair() const override {
            return new VictorianChair();
        }
        Sofa *CreateSofa() const override {
            return new VictorianSofa();
        }
        CoffeeTable *CreateCoffeeTable() const override {
            return new VictorianCoffeeTable();
        }
};

class Furniture3:public Furniture {
    public:
        Chair *CreateChair() const override {
            return new ModernChair();
        }
        Sofa *CreateSofa() const override {
            return new ModernSofa();
        }
        CoffeeTable *CreateCoffeeTable() const override {
            return new ModernCoffeeTable();
        }
};

void ClientCode(const Furniture &furniture) {
    const Chair *chair = furniture.CreateChair();
    const Sofa *sofa = furniture.CreateSofa();
    const CoffeeTable *coffee_table = furniture.CreateCoffeeTable();
 
    cout << "The price of a chair: " << chair->GetPrice() << endl;
    cout << "The price of a sofa: " << sofa->GetPrice() << endl;
    cout << "The price of a coffee table: " << coffee_table->GetPrice() << endl;
    
    delete chair;
    delete sofa;
    delete coffee_table;
}