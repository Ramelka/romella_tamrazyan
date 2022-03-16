#include "atoi.h"

int own_atoi(char* x) {
  int result = 0;
	
  int j = 0;

  if (x[0] == '-') {
    j = 1;
  }

  for (int i = j; x[i] != '\0'; i++) {
    result = result * 10 + x[i] - '0';
  }

  if (x[0] == '-') {
    return -result;
  }

  return result;
}

