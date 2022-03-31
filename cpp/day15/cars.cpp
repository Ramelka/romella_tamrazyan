#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

struct details {
  string car = "";
  string model = "";
  double price;
  double mileage;
  double engine_size ;
  string transmission_box = "";
  string colour = "";
};

struct features {
  string car = "";
  string model = "";
  double min_price;
  double max_price;
  double min_mileage;
  double max_mileage;
  double engine_size;
  string transmission_box = "";
  string colour = "";
  string l = "-";
}input;

void func(details i);

int main() {

  ifstream f;
  f.open("cars.txt");

  struct details info[7];
  string data = "";
  string s[7];

  int i = 0, j = 0;
  while (!f.eof()) {
      f >> data;
      s[i] = data;
      i++;

      if (i == 7) {
          info[j].car = s[0];
          info[j].model = s[1];
          info[j].price = stod(s[2]);
          info[j].mileage = stod(s[3]);
          info[j].engine_size = stod(s[4]);
          info[j].transmission_box = s[5];
          info[j].colour = s[6];
          i = 0;
          j++;
       }
  }

  f.close();
//  struct features input[9];
  cout << "============================================================================\n";
  cout << "             Enter the filters to search a car by or enter '-'>:\n";
  cout << "     --Brand--Price--Mileage--Engine size--Transmission box--Colour--\n";
  cout << "============================================================================\n";
  cout << "Brand: "; cin >> input.car;
  cout << "Min price: "; cin >> input.min_price;
  cout << "Max price: "; cin >> input.max_price;
  cout << "Min mileage: "; cin >> input.min_mileage;
  cout << "Max mileage: "; cin >> input.max_mileage;
  cout << "Engine size: "; cin >> input.engine_size;
  cout << "Transmission box: "; cin >> input.transmission_box;
  cout << "Colour: "; cin >> input.colour;
 // string l = "-";
  for (int i = 0; i < 7; i++) {
      if (info[i].car != input.car && input.car != input.l ) {
          continue;
      }
      /*if ((info[i].price < input.min_price || info[i].price > input.max_price) && input.min_price != input.l) {
          continue;
      }
      if ((info[i].mileage < input.min_mileage || info[i].mileage > input.max_mileage) && input.min_mileage != input.l) {
          continue;
      }
      if (info[i].engine_size != input.engine_size && input.engine_size != l) {
          continue;
      }*/
      if (info[i].transmission_box != input.transmission_box && input.transmission_box != input.l) {
          continue;
      }
      if (info[i].colour != input.colour && input.colour != input.l) {
          continue;
      }
       func(info[i]);
  }

  return 0;
}

void func(details i) {
  cout << "Brand            ---> " << i.car << endl;
  cout << "Model            ---> " << i.model << endl;
  cout << "Price            ---> " << i.price << " $" << endl;
  cout << "Mileage          ---> " << i.mileage << endl;
  cout << "Engine size      ---> " << i.engine_size << endl;
  cout << "Transmission box ---> " << i.transmission_box << endl;
  cout << "Colour           ---> " << i.colour << endl;
}

