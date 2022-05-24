#include <iostream>
using namespace std;

class Singleton {
    private:
        Singleton();
        int value;
        static Singleton *instance;
    public:
        static Singleton *GetInstance();
        int GetValue();
        void SetValue(int);
};

Singleton::Singleton() {
    value = 0;
}

Singleton *Singleton::instance = 0;

Singleton *Singleton::GetInstance() {
    if (instance == 0) {
        instance = new Singleton();
    }
    return instance;
}

int Singleton::GetValue() {
    return this->value;
}

void Singleton::SetValue(int value) {
    this->value = value;
}