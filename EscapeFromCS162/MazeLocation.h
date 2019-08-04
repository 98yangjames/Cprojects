#ifndef MAZELOCATION_H
#define MAZELOCATION_H
#include <iostream>


class MazeLocation {

private:
  

public:
  virtual bool has_explorer() = 0;
  virtual void set_has_explorer(bool) = 0;
  virtual bool is_occupiable() = 0;
  virtual char get_display_character() = 0;
  virtual void set_has_ta(bool) = 0;
  virtual void set_has_programming_skill(bool) = 0;
  virtual bool get_has_programming_skill() = 0;
  virtual char display_programming() = 0;
  virtual void set_display_character(char) = 0;


};

#endif