#include <iostream>
#include <string>
#include <fstream>

using namespace std;

char lower(char letter) {
    if (letter >= 'A' && letter <= 'Z') {
        return letter + ('a' - 'A');
    }
    return letter;
}
string to_lower(string word) {
    string result = "";
    for (int i = 0; word[i] != '\0'; i++) {
        result += lower(word[i]);
    }
    return result;
}

string higher (string word) {
	word[0] -= ('a' - 'A'); 
    for (int i = 0; i < word.length(); i++) {
    	 if (word[i] == '_') {
	     word[i + 1] -= ('a' - 'A'); 
	 }
    }
    return word;
}

string stou (string word) {
   for (int i = 0; i < word.length(); i++) {
        if (word[i] == ' ') {
	    word[i] -= ' ';
 	    word[i] += '_';		 
	}
   }
   return word;
}

string utos (string word) {
   for (int i = 0; i < word.length(); i++) {
        if (word[i] == '_') {
  	    word[i] -= '_';
	    word[i] += ' ';		 
        }
   }
   return word;
}
int main() {
  ifstream file;
  file.open("hotels.txt");
  string info;
  int x = 0;
  while(!file.eof()){
        file >> info;
	x++;
  }
  file.close();
  x /= 16;
  string all[x][16];
  ifstream base;
  base.open("hotels.txt");
  for (int i = 0; i < x; i++) {
     for (int j = 0; j < 16; j++) {
          base >> all[i][j];
     }
  }

  char answ;
do{

  string city = ""; 
  cout << "\n\n\n\t\t\t\t\t\t\t\tWelcome to American Booking Agency <R/A>\n\n\n";
  cout << "\t\t\t\t\t\t\t\t      --> City list <--\n\n";
  string city_name[x];

  for (int i = 0; i < x; i++) {
     if (all[i + 1][0] != all[i][0]) {
  	city_name[i] = all[i][0];
     } else {
     	city_name[i] = "null";
     }	
  }

  for (int i = 0; i < x; i++) {
     if (city_name[i] != "null")
  	cout << "\t\t\t\t\t\t\t\t\t| " << utos(higher(city_name[i])) << endl;
  }

  cout << endl;
  int hotel_index[x], y = 0;

  while (1) {  
    cout << "\t\t\t     In which city do you want to book a hotel? > "; getline(cin, city);
    cout << endl;
    city = to_lower(city);
    city = stou(city);

    for (int i = 0; i < x; i++) {
    	 if (city == all[i][0]){
	     hotel_index[y] = i;
	     y++;
 	 }
    }
    if (y != 0) {
        break;
    } else {
        cout << "\t\t\t     Sorry, but there is no such city in our list\n\n";

    } 
  }
  cout << "\t\t\t\t\t\t\t\t--> List of hotels in "<< utos(higher(city)) << " <--" << endl; 
 
  for (int i = 0; i < y; i++) {
       cout <<"\t\t\t\t\t\t\t\t\t| " << utos(higher(all[hotel_index[i]][1])) << "  ";
      
       for (int j = 0; j < stoi(all[hotel_index[i]][15]); j++){
            cout << '*';	
       }
	cout << "\n";
  }

  cout << "\n";
  string name, command;
  int index = 0;

  do{	
point1:
	cout << "\t\t\t\tWhich hotel would you like to stay in?  > "; getline(cin, name);
	cout << endl;
	name = stou(to_lower(name));
	
	for (int i = 0; i < y; i++) {	
	    if (name == all[hotel_index[i]][1]){
	        index = hotel_index[i];
	        name = utos(higher(name));     
	        cout << "\t\t\t\t\t\t\t\t" << name << " hotel includes" << endl;
		
		if (all[index][2] != "0") {
		    cout << "\t\t\t\t\t\t\t\t ~ Single room > costs $" << all[index][3] << " per day \n";
		}
		if (all[index][4] != "0") {
		    cout << "\t\t\t\t\t\t\t\t ~ Double room > costs $" << all[index][5] << " per day \n";
		}
		if (all[index][6] != "0") {
		    cout << "\t\t\t\t\t\t\t\t ~ Triple room > costs $" << all[index][7] << " per day \n";
		}
		if (all[index][8] != "0") {
		    cout << "\t\t\t\t\t\t\t\t ~ Luxe room   > costs $" << all[index][9] << " per day \n";
		}
		if (all[index][10] != "no") {
		    cout << "\t\t\t\t\t\t\t\t ~ Swiming pool \n";
		}
		if (all[index][11] != "no") {
		    cout << "\t\t\t\t\t\t\t\t ~ Spa \n";
		}
		if (all[index][12] != "no") {
		    cout << "\t\t\t\t\t\t\t\t ~ Fitness room \n";
		}
		if (all[index][13] != "no") {
		    cout << "\t\t\t\t\t\t\t\t ~ Restaurant \n";
		}
		if (all[index][14] != "no") {
		    cout << "\t\t\t\t\t\t\t\t ~ Parking \n";
		}
	        break;
	     }
	     int num = 0;
	     
	     for (int i = 0; i < y; i++) {
		     
	        if (stou(to_lower(name)) != all[hotel_index[i]][1]){
		    num++;
		} 
    		if (num == y) {		
	     	    cout << "\t\t\t\tThere is no hotel with that name in our list.\n";
		    goto point1;
		}
	     }
	     
	}
	cout << "\n\t\t\t\t\t Are you satisfied with the proposed conditions of the hotel? \n\t\t\t\t\t If not, choose another hotel.(yes/no)  > "; getline(cin, command);  
  
  }
  while(command != "yes");
 
  string room;
  int day, money, c = 0;
point2:
  cout << endl << "\t\t\t\t\t\t Which room do you prefer?  > ";
  cin >> room;
  cin.ignore(1);
  cout << endl;
  room = to_lower(room);
  if (room == "single" || room == "double" || room == "triple" || room == "luxe") {
      int num = 0, num1;
     
      if (c != 4) {
          if (room == "single") {
               num += stoi(all[index][2]);
	       num1 = num;
               
	       if (num != 0) {
	     	   num--;
	     	   all[index][2] = to_string(num);
	     	   cout << "\t\t\t\t\t How many days will you stay in our hotel?  > ";
	     	   cin >> day;
	     	   money = day * stoi(all[index][3]);
	       } else {
		   if (num1 == 0) {
		        cout << "\n\t\t\t\t\t\tOur hotel does not have this type of room.\n";
			c++;
		        goto point2;	 
		   } else {    
		      	cout << "\t\t\t\t\t I'm sorry, but the single rooms are all occupied.\n\t\t\t\t\t You can choose a different type of room. > ";
	     	      	c++;
	     	      	goto point2;
                  }
	       }
      	  }
     	  if (room == "double") {
              num += stoi(all[index][4]);
	      num1 = num;
              if (num != 0) {
	     	  num--;
	          all[index][4] = to_string(num);
	      	  cout << "\t\t\t\t\t How many days will you stay in our hotel?  > ";
	     	  cin >> day;
	     	  money = day * stoi(all[index][5]);
              } else {
		   if (num1 == 0) {
		        cout << "\n\t\t\t\t\t\tOur hotel does not have this type of room.\n";
			c++;
		        goto point2;	
		   } else { 
              	 	cout << "\t\t\t\t\t I'm sorry, but the double rooms are all occupied.\n\t\t\t\t\t You can choose a different type of room. > ";
	     	 	c++;
	     	  	goto point2;
                   }
	      }
          }
          if (room == "triple") {
              num += stoi(all[index][6]);
	      num1 = num;
              if (num != 0) {
	     	  num--;
	    	  all[index][6] = to_string(num);
	     	  cout << "\t\t\t\t\t How many days will you stay in our hotel?  > ";
	     	  cin >> day;
	     	  money = day * stoi(all[index][7]);
              } else {
		   if (num1 == 0) {
		        cout << "\n\t\t\t\t\t\tOur hotel does not have this type of room.\n";
			c++;
		        goto point2;	
		   } else { 
                  	cout << "\t\t\t\t\t I'm sorry, but the triple rooms are all occupied.\n\t\t\t\t\t You can choose a different type of room. > ";
	    	  	c++;
	     	  	goto point2;
                   }
	      }
     	  }
          if (room == "luxe") {
              num += stoi(all[index][8]);
	      num1 = num;
              if (num != 0) {
	     	  num--;
	    	  all[index][8] = to_string(num);
	     	  cout << "\t\t\t\t\t How many days will you stay in our hotel?  > ";
	     	  cin >> day;
	     	  money = day * stoi(all[index][9]);
              } else {
		   if (num1 == 0) {
		        cout << "\n\t\t\t\t\t\tOur hotel does not have this type of room.\n";
			c++;
		        goto point2;	
		   } else { 
                  	cout << "\t\t\t\t\t I'm sorry, but the luxe rooms are all occupied.\n\t\t\t\t\t You can choose a different type of room. > ";
	     	  	c++;
	     	  	goto point2;
              	   }
	      }
          }

     cout << "\n\n\t\t\t\t\t\t\t Ok, we have accepted your order.\n\n\t\t\t\t\t\t\t Your stay in our hotel will cost $" << money << ".\n";
     cout << "\n\n\t\t\t\t\t\t\t Thank you for using our services.\n";

     cout << "\n\n\n_________________________________________________________________________________________________________________________________________________________________________________\n\n\n";
    
     cout << "\n\t\t\t\t\t\t\t To register the next client, enter y/n. > ";
     cin >> answ;
     cin.ignore(1);
    
     cout << "\n\n\n_________________________________________________________________________________________________________________________________________________________________________________\n\n\n";
    
     } else {
         cout << "\n\n\t\t\t\t\t\t\tI'm sorry, but there are no more rooms available in our hotel. \n";
     }
  } else {
      cout << "\n\t\t\t\t\t\tOur hotel does not have this type of room.\n";
	      goto point2;
  }
}
while (answ != 'n');

return 0;
} 
