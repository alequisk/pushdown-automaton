#ifndef __TRANSITION_LIB__
#define __TRANSITION_LIB__

#include "Constants.h"

class Transition {
 public:
  Transition();
  Transition(int quantity);
  void insert(transition_t transition);
  std::vector<transitionSpecs_t> getNextStates(int q, char toConsume, char stackChar);

 private:
  int N;
  std::vector<std::vector<transitionSpecs_t>> transitions;
  transitionSpecs_t transitionToSpec(transition_t transition);
};

#endif