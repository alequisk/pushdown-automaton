#include <iostream>
#include <stack>

#include "inc/Transition.h"

#define endl '\n'
#define len(x) (int)(x.size())

using namespace std;

void receive_input();
void print_answer(bool status);
bool solve(int currentState, string toConsume, string stk);
bool run_automaton(int currentState, string toConsume, stack<char> myStack);

// Start here!
char initialCharOfStack;
string stringToCheck;
int qtdStates, qtdAlphabetOfInput, qtdAlphabetOfStack, qtdFinalStates, qtdTransitions, initialState;
vector<char> alphabetOfInput, alphabetOfStack;
stack<char> stackContent;
vector<int> finalStates;

Transition transitions;

int main() {
  receive_input();

  stackContent.push(initialCharOfStack);

  bool status = solve(initialState, stringToCheck, string(1, initialCharOfStack));
  cout << endl;

  print_answer(status);

  return 0;
}
void print_answer(bool status) {
  cout << (status ? "aceita" : "rejeita") << endl;
}

/**
 * function: receive_input
 * description: realize the input operation from problem
 **/
void receive_input() {
  cin >> qtdStates;

  cin >> qtdAlphabetOfInput;
  alphabetOfInput.resize(qtdAlphabetOfInput);

  for (char &caractere : alphabetOfInput) {
    cin >> caractere;
  }

  cin >> qtdAlphabetOfStack;
  alphabetOfStack.resize(qtdAlphabetOfStack);

  for (char &caractere : alphabetOfStack) {
    cin >> caractere;
  }

  cin >> initialState;
  cin >> initialCharOfStack;

  cin >> qtdFinalStates;
  finalStates.resize(qtdFinalStates);

  for (int &finalState : finalStates) {
    cin >> finalState;
  }

  cin >> qtdTransitions;

  transitions = Transition(qtdTransitions);

  transition_t transition;
  for (int i = 0; i < qtdTransitions; i++) {
    cin >> transition.currentState;
    cin >> transition.forwardState;
    cin >> transition.inputSymb;
    cin >> transition.stackTopSymb;
    cin >> transition.putString;

    transitions.insert(transition);
  }

  cin >> stringToCheck;
}

bool isFinal(int state) {
  bool isFinalState = false;
  for (int &x : finalStates)
    isFinalState = isFinalState || x == state;
  return isFinalState;
}

bool solve(int currentState, string toConsume, string stk) {
  cout << "(";  // delimiter of expression
  cout << currentState << ", " << (len(toConsume) ? toConsume : EPSILON) << ", " << (stk == "" ? EPSILON : stk);
  vector<transitionSpecs_t> nextTransitions = transitions.getNextStates(currentState, toConsume[0] ? toConsume[0] : EPSILON[0], stk[0]);

  bool answer = false;
  if (toConsume.empty())
    answer |= isFinal(currentState);

  for (transitionSpecs_t transition : nextTransitions) {
    cout << "; ";
    if (transition.inputSymb == EPSILON[0])  // dont consume the input string
    {
      if (transition.putString == EPSILON)  // imediate transition
      {
        answer |= solve(transition.forwardState, toConsume, stk.substr(1));
      } else {
        answer |= solve(transition.forwardState, toConsume, transition.putString + stk.substr(1));
      }
    } else {
      if (transition.putString == EPSILON)  // imediate transition
      {
        answer |= solve(transition.forwardState, len(toConsume) ? toConsume.substr(1) : toConsume, stk.substr(1));
      } else {
        answer |= solve(transition.forwardState, len(toConsume) ? toConsume.substr(1) : toConsume, transition.putString + stk.substr(1));
      }
    }
  }

  cout << ")";  // delimiter of expression
  return answer;
}