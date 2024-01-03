#pragma once
#ifndef LINKEDLISTT_H
#define LINKEDLISTT_H

#include <iostream>
using namespace std;

class Linkedlistt;

class Node {
private:
	friend class Linkedlistt;
	int data;
	Node* next;
};
class Linkedlistt {
private:
	Node* head;
public:
	Linkedlistt();
	bool insertAtStart(int val);
	bool insertAtEnd(int val);
	bool search(int val);
	void display();
	bool removeFromStart(int &val);
	void displayReverse();
	int countNodes();
	int findSecondLastNode();
	void displayR(Node*node);
	Linkedlistt(const Linkedlistt& orig);

	~Linkedlistt();
};

#endif