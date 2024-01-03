#pragma once
#ifndef LINKEDLIST_STACK_H
#define LINKEDLIST_STACK_H
#include<iostream>
using namespace std;
class LinkedList_Stack;
class Nodee
{
private:
	friend class LinkedList_Stack;
	int data;
	Nodee* next;
};
class LinkedList_Stack
{
private:
	Nodee* top;
public:
	LinkedList_Stack();
	bool push(int val);
	bool pop(int& val);
	void display();
};

#endif 