#include "../inc/Transition.h"

#include <assert.h>

Transition::Transition() {}

Transition::Transition(int quantity) {
  assert(quantity > 0);
  N = quantity;
  transitions.assign(quantity, std::vector<transitionSpecs_t>());
}

void Transition::insert(transition_t transition) {
  assert(transition.currentState < N && transition.forwardState < N);
  transitions[transition.currentState].push_back(transitionToSpec(transition));
}

transitionSpecs_t Transition::transitionToSpec(transition_t transition) {
  transitionSpecs_t statement;
  statement.forwardState = transition.forwardState;
  statement.inputSymb = transition.inputSymb;
  statement.stackTopSymb = transition.stackTopSymb;
  statement.putString = transition.putString;
  return statement;
}

std::vector<transitionSpecs_t> Transition::getNextStates(int q, char toConsume, char stackChar) {
  assert(q < N);
  std::vector<transitionSpecs_t> transitionStates = std::vector<transitionSpecs_t>();
  for (transitionSpecs_t transition : this->transitions[q]) {
    if ((transition.inputSymb == EPSILON[0] || transition.inputSymb == toConsume) && transition.stackTopSymb == stackChar) {
      transitionStates.push_back(transition);
    }
  }
  return transitionStates;
}