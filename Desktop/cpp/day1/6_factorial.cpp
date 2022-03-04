#include <iostream>

using namespace std;

int main () {
  
	int answer;
  	int sum;
  
  	cout << "Please enter a number " << endl;
  	cin >> answer;

  	sum = answer;
  
  	while (answer > 1) {
      	answer = answer - 1;
      	sum = sum * answer;
  	}

  	cout << sum << endl;
  	
	return 0;
}
