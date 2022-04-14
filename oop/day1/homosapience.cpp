#include <string>
#include "homosapience.h"

Homosapience::Homosapience (const Human& human, Religion religion, Race race, Nationality nationality) : Human(human) {
  _religion = religion;
  _race = race;
  _nationality = nationality;
}

Religion Homosapience::getReligion() const {
  return _religion;
}

Race Homosapience::getRace() const {
  return _race;
} 

Nationality Homosapience::getNationality() const {
  return _nationality;
} 


