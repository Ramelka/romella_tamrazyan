#include "atoi.h"
#include <iostream>

using namespace std;

int own_atoi(char* x) {
  int result = 0;

  for (int i = 0; x[i] != '\0'; ++i) {
    result = result * 10 + x[i] - '\0';
  }

  return result;
}

