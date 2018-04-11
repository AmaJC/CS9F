#include "CLLNode.cpp"
#include <iostream>
using namespace std;

int main()
{
    const int N = 8;
    const int K = 2;

    CLLNode *list = new CLLNode(0); // sentinel
    for (int j = N; j > 0; j--)
    {
        CLLNode *newGuy = new CLLNode(j);
        list->insert(newGuy);
        // TODO: You fill this in
    }
    list->print();

    while (!list->lengthIsOne())
    {
        for (int j = 0; j < K; j++)
        {
            list = list->next();
        }

        // TODO: You fill this in
    }
    cout << "Only one person remains: ";
    list->print();

    return 0;
}
