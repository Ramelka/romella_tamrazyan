#include "command.hpp"

int main() {

    Invoker *invoker = new Invoker;
    invoker->SetOnStart(new SimpleCommand("Say Hi!"));
    Receiver *receiver = new Receiver;
    invoker->SetOnFinish(new ComplexCommand(receiver, "sending email", "saving report"));
    invoker->DoSomethingImportant();

    delete invoker;
    delete receiver;

    return 0;
}