#include "singleton.hpp"

int main() {

   Singleton *s = s->GetInstance();
   cout << s->GetValue() << endl;
   s->SetValue(200);
   cout << s->GetValue() << endl;

   return 0;
}