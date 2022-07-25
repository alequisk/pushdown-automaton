#ifndef __CONSTANTS_LIB__
#define __CONSTANTS_LIB__

#include <string>
#include <vector>

#define EPSILON "e"

struct transition_t {
  int currentState;
  int forwardState;
  char inputSymb;
  char stackTopSymb;
  std::string putString;
};

struct transitionSpecs_t {
  int forwardState;
  char inputSymb;
  char stackTopSymb;
  std::string putString;
};

#endif