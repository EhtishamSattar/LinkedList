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

//const LinkedList& LinkedList::operator=(const LinkedList& rhs)
//{
//	if (this == &rhs)
//	{
//		return *this;
//	}
//	else
//	{
//		if (rhs.head == nullptr)
//		{
//			head == nullptr;
//		}
//		else
//		{
//			Node* temp = head;    //memory which is allocated earlier is free now,now list is empty
//			while (temp != nullptr)
//			{
//				head = head->next;
//				delete temp;
//				temp = head;
//			}
//			head = new Node;
//			head->data = (rhs.head)->data;
//			Node* t1 = (rhs.head)->next;
//			Node* t2 = head;
//			while (t1 != nullptr)
//			{
//				t2->next = new Node; //allocate new node
//				t2 = t2->next;  //transfer it to next
//				t2->data = t1->data;
//				t1 = t1->next;
//			}
//			t2->next = nullptr;
//		}
//		return *this;
//	}
//}
//bool  LinkedList::uniqueSortedInsert(int val)
//{
//	Node* curr = head, * prev = nullptr;
//	while (curr != nullptr && curr->data <= val)
//	{
//		prev = curr;
//		curr = curr->next;
//	}
//	if (prev->data == val)
//	{
//		return false;
//	}
//	else
//	{
//		Node* temp = new Node;
//		temp->data = val;
//		if (prev == nullptr)
//		{
//			temp->next = head;
//			head = temp;
//		}
//		else
//		{
//			temp->next = curr;
//			prev->next = temp;
//			return true;
//		}
//	}
//}
//
//int  LinkedList::findSecondLastNode()
//{
//	Node* temp = head;
//
//	// If the list is empty or contains less
//	// than 2 nodes
//	if (temp == NULL || temp->next == NULL)
//		return -1;
//
//	// Traverse the linked list
//	while (temp != NULL) {
//
//		// Check if the current node  is the
//		// second last node or not
//		if (temp->next->next == NULL)
//		{
//			return temp->data;
//		}
//		// If not then move to the next node
//		temp = temp->next;
//	}
//}
////---------------------------lab-8-----------------//
//int LinkedList::countNodes()
//{
//	int count = 0;
//	Node* curr = head;
//	while (curr != nullptr)
//	{
//		curr = curr->next;
//		count++;
//	}
//	return count;
//}
//bool  LinkedList::removeKthNode(int k, int& val)
//{
//	int count2 = 0, totalCount = countNodes();
//
//	if (totalCount < k)
//	{
//		return false;
//	}
//	else
//	{
//		Node* curr = head;
//		Node* prev = nullptr;
//		while (curr != nullptr && k - 1 != count2)
//		{
//			prev = curr;
//			curr = curr->next;
//			count2++;
//		}
//		if (curr == head)
//		{
//			val = curr->data;
//			head = head->next;
//		}
//		else
//		{
//			val = curr->data;
//			prev->next = curr->next;
//		}
//		delete curr;
//		curr = nullptr;
//		return true;
//	}
//}
//
//void LinkedList::combine(LinkedList& list1, LinkedList& list2)
//{
//	if (list1.head == nullptr && list2.head == nullptr)
//	{
//		head = nullptr;
//	}
//	else if (list1.head == nullptr)
//	{
//		head = list2.head;
//		list2.head = nullptr;
//
//	}
//	else if (list2.head == nullptr)
//	{
//		head = list1.head;
//		list1.head = nullptr;
//	}
//	else
//	{
//		Node* temp = nullptr;
//		head = list1.head;
//		temp = head;
//		while (temp->next != nullptr)
//		{
//			temp = temp->next;
//		}
//		temp->next = list2.head;
//		list2.head = nullptr;
//		list1.head = nullptr;
//	}
//}
//void LinkedList::shuffleMerge(LinkedList& list1, LinkedList& list2)
//{
//	Node* curr1 = list1.head;
//	Node* curr2 = list2.head;
//	Node* next1 = nullptr;
//	Node* next2 = nullptr;
//	head = curr1;
//	while (curr1 != nullptr && curr2 != nullptr)
//	{
//		next1 = curr1->next;
//		curr1->next = curr2;
//		next2 = curr2->next;
//		curr2->next = next1;
//		curr1 = next1;
//		curr2 = next2;
//
//	}
//	list1.head = nullptr;
//	list2.head = nullptr;
//	next1 = nullptr;
//	next2 = nullptr;
//
//}
//
////bool  LinkedList::removeKthNode(int k, int& val)
////{
////	int count2 = 0, totalCount = countNodes();
////
////	if (k > totalCount)
////	{
////		return false;
////	}
////	else
////	{
////		Node* curr = head;
////		Node* prev = nullptr;
////		for (int i = 1; i < k; i++)
////		{
////			prev = curr;
////			curr = curr->next;
////		}
////		if (curr == nullptr)
////		{
////			return false;
////		}
////		else if (curr == head)
////		{
////			val = curr->data;
////			head = head->next;
////		}
////		else
////		{
////			val = curr->data;
////			prev->next = curr->next;
////
////		}
////		delete curr;
////		curr = nullptr;
////		return true;
////	}
////}
//bool  LinkedList::removeKthNodeFromEnd(int k, int& val)
//{
//	Node* curr = head;
//	Node* prev = nullptr;
//	int size = countNodes();
//	if (k > size || curr == NULL)
//	{
//		return false;
//	}
//	else
//	{
//		for (int i = 1; i < size - k + 1; i++)
//		{
//			prev = curr;
//			curr = curr->next;
//		}
//		if (curr == head)
//		{
//			val = curr->data;
//			head = head->next;
//		}
//		else
//		{
//			val = curr->data;
//			prev->next = curr->next;
//		}
//		delete curr;
//		curr = nullptr;
//		return true;
//
//	}
//}
//
////-------------------------------------------------------------//
//
////Task#04
//bool  LinkedList::removeLastNode(int& val)
//{
//	if (head == nullptr)
//	{
//		return false;
//	}
//	else
//	{
//		if (head->next == nullptr)
//		{
//			val = head->data;
//			delete head;
//			head = nullptr;
//			return true;
//		}
//		else
//		{
//			Node* curr = head;
//			Node* prev = nullptr;
//			while (curr->next != nullptr)
//			{
//				prev = curr;
//				curr = curr->next;
//			}
//			val = curr->data;
//			prev->next = curr->next; //prev->next=nullptr
//			delete curr;
//			curr = nullptr;
//			return true;
//		}
//	}
//}
//bool  LinkedList::removeSecondLastNode(int& val)
//{
//	Node* curr = head;
//	Node* prev = nullptr;
//
//	// If the list is empty or contains less
//	// than 2 nodes
//	if (curr == NULL || curr->next == NULL)
//		return false;
//	else
//	{
//		if (head->next->next == NULL)
//		{
//			val = curr->data;
//			head = head->next;
//		}
//		else
//		{
//			// Traverse the linked list
//			while (curr->next->next != NULL)
//			{
//				prev = curr;
//				curr = curr->next; 			// If not then move to the next node
//			}
//			val = curr->data;
//			prev->next = curr->next;
//		}
//		delete curr;
//		curr = nullptr;
//		return true;
//	}
//}
////Task-5
//int LinkedList::findMax()
//{
//	if (head == nullptr)
//	{
//		return -999;
//	}
//	else
//	{
//		Node* curr = head;
//		int max = curr->data;
//		curr = curr->next;
//		while (curr != nullptr)
//		{
//			if (curr->data > max)
//			{
//				max = curr->data;
//			}
//			curr = curr->next;
//		}
//		return max;
//	}
//}
////int LinkedList::findMin()
////{
////	if (head == nullptr) {
////		return 999;
////	}
////	else
////	{
////		Node* curr = head;
////		int min = curr->data;
////		curr = curr->next; //next element of curr is stored in curr to compare with previous  element
////		while (curr != nullptr)
////		{
////			if (curr->data < min)
////			{
////				min = curr->data;
////			}
////			curr = curr->next;
////		}
////		return min;
////	}
////}
//int LinkedList::findMin()
//{
//	return findMin(head);
//}
//int  LinkedList::countEvens()
//{
//	return countEvens(head);
//}
//
/////-----------------------------LAB-9---------------------///
//int LinkedList::removeAll(int val)
//{
//	int count = 0;
//	Node* curr = head;
//	Node* prev = nullptr;
//	while (curr != nullptr)
//	{
//		if (curr->data == val)
//		{
//			if (curr == head)
//			{
//				head = head->next;
//				count++;
//				prev = nullptr;
//				curr = head;  //curr = curr->next;
//			}
//			else
//			{
//				prev->next = curr->next;
//				delete curr;
//				curr = prev->next;
//				count++;
//			}
//		}
//		else
//		{
//			prev = curr;
//			curr = curr->next;
//		}
//	}
//	prev = nullptr;
//	return count;
//}
//int LinkedList::removeEverySecondNode()
//{
//	int count = 1, countReturn = 0;
//	Node* curr = head;
//	Node* prev = nullptr;
//	while (curr != nullptr)
//	{
//		if (count % 2 == 0)
//		{
//			prev->next = curr->next;
//			delete curr;
//			curr = nullptr;
//			curr = prev->next;
//			countReturn++;
//		}
//		else
//		{
//			prev = curr;
//			curr = curr->next;
//		}
//		count++;
//	}
//	prev = nullptr;
//	return countReturn;
//}