#include "../inc/Graph.h"

Node *createNode(int state, std::string stackContent, std::string remainInput) {
  Node *node = new Node();
  node->isLeaf = false;
  node->state = state;
  node->stackContent = stackContent;
  node->remainInput = remainInput;
  return node;
}
