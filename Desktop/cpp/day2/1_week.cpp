#include <iostream>
using namespace std;

int main() {
    
    int weeknum;
    
    cout << "Please write a number of the week and I'll say the name of that day." << endl;
    cin >> weeknum;
    
    switch (weeknum) {
        case 1 :
	   cout << "The first day of week is Monday.";
	   break;
	case 2 :
	   cout << "The second day of week is Tuesday.";
           break;
	case 3 :
           cout << "The third day of week is Wednesday.";
           break;
	case 4 :
           cout << "The fourth day of week is Thursday.";
           break;
	case 5 :
           cout << "The fifth day of week is Friday.";
           break;
	case 6 :
           cout << "The sixth day of week is Saturday.";
           break;
	case 7 :
           cout << "The seventh day of week is Sunday.";
           break;
	default :
	   cout << "A week has only 7 days.";
	   break;
    }
    return 0;	    
}

