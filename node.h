// Copyright 2018 <Author>

#ifndef NODE_H_
#define NODE_H_

class Node {
 public:
  explicit Node(char data);
  char GetData();
  Node* InsertPreviousNode(char data);
  Node* InsertNextNode(char data);
  Node* GetPreviousNode();
  Node* GetNextNode();
  bool ErasePreviousNode();
  bool EraseNextNode();
private:
	char m_data;
	Node *m_next;
	Node *m_prev;
};

#endif  // NODE_H_
