#ifndef HUMAN_H
#define HUMAN_H

enum Gender {
  male = 1,
  female = 2
};
enum EyeColour {
  brown = 1,
  black,
  blue,
  green,
  grey,
  hazel,
  red
};
enum HairColour {
  Black = 1,
  Brown,
  White,
  Blonde,
  Red
};

class Human {
  private:
      int _birth_date;
      Gender _gender;
      EyeColour _eye_colour;
      HairColour _hair_colour;  
      Human _father;
      Human _mother;
      int _health_level;
      int _mental_health;
      void Think();
      void Digestion();
  public:
      void Breath();
      void Walk();
      bool Eat(Food _food);
      void Drink(Drink _drink);
      Human(EyeColour _eye_colour, HairColour _hair_colour, Gender _gender, Human _father, Human _mother);
};

#endif
