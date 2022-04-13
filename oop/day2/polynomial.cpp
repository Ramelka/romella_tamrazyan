#include "polynomial.h"
#include <iostream>

using namespace std;

void Polynomial::Add() {
  if (_degree1 > _degree2) {
      for (int i = 0; i <= _degree1; i++) {
          if (i <= _degree2) {
              arr3[i] = arr1[i] + arr2[i];
          } else {
              arr3[i] = arr2[i];
          }
      }  
  } else if (_degree1 < _degree2) {
      for (int i = 0; i <= _degree2; i++) {
          if (i <= _degree1)  {
              arr3[i] = arr1[i] + arr2[i];
          } else {
              arr3[i] = arr1[i];
          }
       } 
  } else if (_degree1 = _degree2) {
      for (int i = 0; i <= _degree2; i++) {
          arr3[i] = arr1[i] + arr2[i];
      } 
  }
} 

void Polynomial::Subtract() {
  if (_degree1 > _degree2) {
      for (int i = 0; i <= _degree1; i++) {
          if (i <= _degree2) {
              arr3[i] = arr1[i] - arr2[i];
          } else {
              arr3[i] = arr2[i];
          }
      }  
  } else if (_degree1 < _degree2) {
      for (int i = 0; i <= _degree2; i++) {
          if (i <= _degree1)  {
              arr3[i] = arr1[i] - arr2[i];
          } else {
              arr3[i] = arr1[i];
          }
      } 
       
  } else if (_degree1 = _degree2) {
      for (int i = 0; i <= _degree2; i++) {
          if (arr1[i] - arr2[i] != 0) {
              arr3[i] = arr1[i] - arr2[i];
          }
      } 
  }
}    

void Polynomial::Multiply() {
  if (_degree1 > _degree2) {
      for (int i = 0; i <= _degree1; i++) {
          if (i <= _degree2) {
              arr3[i] = arr1[i] + arr2[i];
          } else {
              arr3[i] = arr2[i];
          }
      }   
  } else if (_degree1 < _degree2) {
      for (int i = 0; i <= _degree2; i++) {
          if (i <= _degree1)  {
              arr3[i] = arr1[i] + arr2[i];
          } else {
              arr3[i] = arr1[i];
          }
       }
  } else if (_degree1 = _degree2) {
      for (int i = 0; i <= _degree2; i++) {
          arr3[i] = arr1[i] + arr2[i];
      }   
  }
} 


