#include "Linkedlist.h"

Linkedlistt::Linkedlistt()
{
	head = nullptr;
}
void Linkedlistt::display()
{
	if (head == nullptr)
		cout << "List is empty\n";
	else
	{
		Node* curr = head;
		while (curr != nullptr)
		{
			cout << curr->data << " ";
			curr = curr->next;
		}
	}
}
bool Linkedlistt::insertAtStart(int val)
{
	if (val == -1)
	{
		return false;
	}
	else
	{
		Node* temp = new Node;
		temp->data = val;
		temp->next = head;
		head = temp;
		return true;
	}
}
bool Linkedlistt::insertAtEnd(int val)
{
	if (val == -1)
	{
		return false;
	}
	else
	{
		Node* temp = new Node;
		temp->data = val;
		temp->next = nullptr;
		if (head == nullptr)
		{
			head = temp;
		}
		else
		{
			Node* curr = head;
			while (curr->next != nullptr)
			{
				curr = curr->next;
			}
			curr->next = temp;
		}
		return true;
	}
}
bool Linkedlistt::search(int key)
{
	Node* curr = head;
	while (curr != nullptr)
	{
		if (curr->data == key)
		{
			return true;

		}
		curr = curr->next;
	}
	return false;
}
bool Linkedlistt::removeFromStart(int& val)
{
	if (head == nullptr)
	{
		return false;
	}
	else
	{
		Node* curr = head;
		val = curr->data;
		head = curr->next;
		delete curr;
		return true;
	}
}
//bool Linkedlistt:: removeFromEnd(int&val)
//{
//	if(head==nullptr)
//	{
//		return false;
//	}
//	else
//	{
//		Node*curr=head;
//		Node* prev = nullptr;
//		while(curr->next!=nullptr)
//		{
//			prev = curr;
//			curr=curr->next;
//		}
//		val=curr->data;
//		prev->next = nullptr;
//		delete curr;
//		return true;
//	}
//}

void Linkedlistt::displayR(Node* node)
{
	if (node != nullptr)
	{
		displayR(node->next);
		cout << node->data << " ";

	}
}

int  Linkedlistt::findSecondLastNode()
{
	Node* temp = head;

	// If the list is empty or contains less
	// than 2 nodes
	if (temp == NULL || temp->next == NULL)
		return -1;

	// Traverse the linked list
	while (temp != NULL) {

		// Check if the current node  is the
		// second last node or not
		if (temp->next->next == NULL)
		{
			return temp->data;
		}
		// If not then move to the next node
		temp = temp->next;
	}
	return -1;
}

int Linkedlistt::countNodes()
{
	int count = 0;
	Node* curr = head;
	while (curr != nullptr)
	{
		curr = curr->next;
		count++;
	}
	return count;
}
void Linkedlistt::displayReverse()
{
	if (head == nullptr)
	{
		cout << "List is empty\n";
	}
	else
	{
		displayR(head);
		cout << endl;
	}

}
Linkedlistt::Linkedlistt(const Linkedlistt& orig) {
	cout << "copy constructor called\n";
	if (head == nullptr)
	{
		head = orig.head;
	}
	else {
		head = new Node;
		head->data = orig.head->data;
		Node* t1 = new Node;
		t1 = orig.head->next;
		Node *t2 = head;
		while (t1 != nullptr) {
			t2->next = new Node;
			t2 = t2->next;
			t2->data = t1->data;
			t1 = t1->next;
		}
		t2->next = nullptr;
	}

}

Linkedlistt:: ~Linkedlistt()
{
	Node* curr = head;
	while (curr != nullptr)
	{
		head = head->next;
		delete curr;
		curr = head;
	}
}