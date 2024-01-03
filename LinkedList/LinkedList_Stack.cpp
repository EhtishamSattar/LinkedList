#include "LinkedList_Stack.h"
#include <iostream>
using namespace std;
LinkedList_Stack::LinkedList_Stack()
{
	top = nullptr;
}
bool LinkedList_Stack::push(int val)
{
	Nodee* temp = new Nodee;
	temp->data = val;
	temp->next = top;
	top = temp;
	return true;
}
bool LinkedList_Stack::pop(int& val)
{
	if (top == nullptr)
	{
		return false;
	}
	else
	{
		Nodee* curr = top;
		val = curr->data;
		curr = curr->next;
		top = curr;
		return true;
	}
}
void LinkedList_Stack::display()
{
	if (top == nullptr)
	{
		cout << "Stack is empty\n";
	}
	else {
		Nodee* cur = top;
		while (cur != nullptr)
		{
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << endl;
	}
}
