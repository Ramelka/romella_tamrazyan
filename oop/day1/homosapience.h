#ifndef HOMOSAPIENCE_H
#define HOMOSAPIENCE_H

#include <string>
#include "human.h"

enum Religion {
  Christianity = 1,
  Hinduism,
  Buddhism,
  Islam,
  Judaism
};

enum Race {
  Europoid,
  Austroloid,
  Negroid,
  Mongoloid
};

enum Nationality {
  Armenian,
  English,
  Russian,
  French,
  Spanish
};

class Homosapience:public Human {
  private:
      Religion _religion;
      Race _race;
      Nationality _nationality;

  public:
      Homosapience (const Human& human, Religion religion, Race race, Nationality nationality);

  Homosapience(const Homosapience&) = default;

  Religion getReligion() const;
  Race getRace() const;
  Nationality getNationality() const;
};


#endif
