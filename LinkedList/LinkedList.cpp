// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedList.h"
#include "LinkedList_Stack.h"

int main()
{
    std::cout << "Hello World!\n";
    Linkedlistt li;
    int j = 10;
    while (j > 0)
    {
        li.insertAtStart(j);
        j-=2;
    }
    li.display();
    cout << endl;
    Linkedlistt li2;
    li2.insertAtEnd(1000);
    li2.insertAtEnd(500);
    li2.insertAtEnd(250);
    li2.insertAtEnd(125);
    li2.display();
    cout << "\nCount of li1 items are " << li.countNodes();
    cout << "\nCount of li2 items are " << li2.countNodes();
    cout << endl;
    // search li2
    if (li2.search(500))
    {
        cout << "500 is present in li2\n";
    }
    else {
        cout << "500 is not found in li2\n";
    }

    //search li
    if (li.search(99))
    {
        cout << "99 is present in li\n";
    }
    else {
        cout << "99 is not found in li\n";
    }
    
    int valToRemove = 0;
    li2.removeFromStart(valToRemove);
    cout << valToRemove << endl;

    cout << "List li2 after removing from start";
    li2.display();
    cout << endl;
    li.displayReverse();
    cout << endl;
    li2.displayReverse();
    cout << endl;
    cout<<li.findSecondLastNode();
    cout << endl << endl;
    Linkedlistt li3 = li;
    li3.display();
    cout << endl;
    cout << "\t\tLinkedList_Stack\n\n";
    LinkedList_Stack ls1;
    ls1.push(5);
    ls1.push(10);
    ls1.push(15);
    ls1.push(20);
    ls1.display();
    int a = 0;
    ls1.pop(a);
    cout << a << "is Poped from stack\n";
    ls1.display();


}

