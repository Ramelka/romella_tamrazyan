#include <iostream>
using namespace std;

class Command {
    public:
        virtual ~Command() {};
        virtual void Execute() const = 0;
};

class SimpleCommand:public Command {
    private:
        string _pay_load;
    public:
        explicit SimpleCommand(string _pay_load) {
            this->_pay_load = _pay_load;
        }
        void Execute() const override {
            cout << "SimpleCommand: " << this->_pay_load << endl;
        }
};

class Receiver {
    public:
        void DoSomething(const string &a) {
            cout << "Receiver: Working on " << a << endl;
        }
        void DoSomethingElse(const string &b) {
            cout << "Receiver: Also working on " << b << endl;
        }
};

class ComplexCommand:public Command {
    private:
        Receiver *_receiver;
        string a;
        string b;
    public:
        ComplexCommand(Receiver *_receiver, string a, string b) {
            this->_receiver = _receiver;
            this->a = a;
            this->b = b;
        }
        void Execute() const override {
            cout << "ComplexCommand: ";
            this->_receiver->DoSomething(this->a);
            this->_receiver->DoSomethingElse(this->b);
        }
};

class Invoker {
    private:
        Command *_on_start_;
        Command *_on_finish_;
    public:
        ~Invoker() {
            delete _on_start_;
            delete _on_finish_;
        }
    void SetOnStart(Command *command) {
        this->_on_start_ = command;
    }
    void SetOnFinish(Command *command) {
        this->_on_finish_ = command;
    }
    void DoSomethingImportant() {
        cout << "Invoker: Do you want to do anything before I begin?\n";
        if (this->_on_start_) {
            this->_on_start_->Execute();
        }
        cout << "Invoker: Doing something really important...\n";
        cout << "Invoker: Do you want to do anything after I've finished?\n";
        if (this->_on_finish_) {
            this->_on_finish_->Execute();
        }
    }
};