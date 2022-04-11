#include "human.h"
#include <iostream>

Human::Human(EyeColour _eye_colour, HairColour _hair_colour, Gender _gender, Human _father, Human _mother) 
{
  _eye_colour = _eye_colour;
  _hair_colour = _hair_colour;
  _gender = _gender;
  _father = _father;
  _mother = _mother;
}

