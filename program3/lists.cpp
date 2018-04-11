#include "lists.h"
#include <iostream>
#include <cassert>
using namespace std;

/**
 * Delete the node and all nodes accessible through it.
 * Precondition: this != 0.
 */
ListNode::~ListNode()
{
    cout << "Deleting node with value " << myValue << endl;
    ListNode *p = this;
    if (not p) {
        return;
    } else {
        delete p->myNext;
    }
    p = NULL;
}

/**
 * Print the list.
 */
void ListNode::print() const
{
    for (const ListNode *list = this; list; list = list->rest())
    {
        cout << list->first() << " ";
    }
    cout << endl;
}