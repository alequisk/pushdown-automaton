#ifndef __GRAPH_LIB__
#define __GRAPH_LIB__

#include <string>
#include <vector>

struct Node {
  Node *parent = NULL;
  int state;
  std::string stackContent;
  std::string remainInput;
  bool isLeaf;

  std::vector<Node *> nodes;
};

Node *createNode(int state, std::string stackContent, std::string remainInput);

#endif