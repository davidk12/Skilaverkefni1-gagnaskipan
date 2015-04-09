#include <iostream>
#include "List.h"

int main()
{
    List myList;

    myList.headInsert(5);
    myList.headInsert(3);
    myList.headInsert(2);
    myList.headInsert(10);
    myList.headInsert(8);
    myList.headInsert(6);
    myList.headInsert(2);
    cout << "After inserting at the head:" << endl;
    cout << myList << endl;

    cout << "Length of list: " << myList.length() << endl;

    myList.remove(10);
    cout << "After removing item 10:" << endl;
    cout << myList << endl;
    myList.remove(2);
    cout << "After removing item 2:" << endl;
    cout << myList << endl;

    myList.reverse();
    cout << "After reversing the nodes:" << endl;
    cout << myList << endl;

    myList.removeAll();
    cout << "After removing the nodes:" << endl;
    cout << myList << endl;

    myList.endInsert(3);
    myList.endInsert(7);
    myList.endInsert(9);
    cout << "After inserting at the end:" << endl;
    cout << myList << endl;
    cout << "Length of list: " << myList.length() << endl;

    // At the end of this program the List destructor should be called automatically!
    return 0;
}

