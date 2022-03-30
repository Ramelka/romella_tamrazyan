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

  cout << "===========================================\n";
  string filter = "";
  cout << "				Enter the filter you want to search a car by:\n";
  cout << "		--Brand--Price--Mileage--Engine size--Transmission box--Colour--\n";
  getline(cin, filter);
  
  if (filter == "Brand") {
      string brand_info = "";
      cout << "Enter a car brand: ";
      getline (cin, brand_info);
      for (int i = 0; i < 7; i++) {
	      if (brand_info == info[i].car) {
              func(info[i]);
          }
	  } 
  }

  if (filter == "Price") {
      double price_info;
	  cout << "Enter price: ";
      cin >> price_info;
      for (int i = 0; i < 7; i++) {
          if (price_info == info[i].price) {
              func(info[i]);
		  }
	  }
  }

  if (filter == "Mileage") {
      double mileage_info;
      cout << "Enter mileage: ";
      cin >> mileage_info;
      for (int i = 0; i < 7; i++) {
          if (mileage_info == info[i].mileage) {
              func(info[i]);
          }
	  }
  }

  if (filter == "Engine size") {
      double engine_info;
      cout << "Enter engine size: ";
      cin >> engine_info;
      for (int i = 0; i < 7; i++) {
          if (engine_info == info[i].engine_size) {
              func(info[i]);
          }
	  }
  }

  if (filter == "Transmission box") {
      string transbox_info = "";
      cout << "Enter engine size: ";
      cin >> transbox_info;
      for (int i = 0; i < 7; i++) {
          if (transbox_info == info[i].transmission_box) {
              func(info[i]);
          }
      }
  }

  if (filter == "Colour") {
      string colour_info = "";
      cout << "Enter colour: ";
      cin >> colour_info;
      for (int i = 0; i < 7; i++) {
          if (colour_info == info[i].colour) {
              func(info[i]);
          }
      }
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
