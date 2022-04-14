#include "programmer.h"

Programmer::Programmer(const Homosapience& homosapience, ProgrammingLanguage language) : Homosapience(homosapience) {
  _language = language;
}

ProgrammingLanguage Programmer::getLanguage() const {
  return _language;
}
