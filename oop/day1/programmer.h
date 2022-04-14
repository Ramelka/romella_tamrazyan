#ifndef PROGRAMMER_H
#define PROGRAMMER_H

#include "homosapience.h"

enum ProgrammingLanguage {
  CPP = 1,
  C,
  Python,
  JAVA,
  JS
};

class Programmer:public Homosapience {
  private:
      ProgrammingLanguage _language;
  public:
      Programmer(const Homosapience& homosapience, ProgrammingLanguage language);

  Programmer(const Programmer&) = default;

  ProgrammingLanguage getLanguage() const;
};
#endif
