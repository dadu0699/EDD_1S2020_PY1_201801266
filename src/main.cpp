#include <iostream>
#include <cstdlib>

#include "Structures/CircularDoubleList/CircularDoubleList.h"
#include "Structures/DoubleList/DoubleList.h"
#include "Structures/Queue/Queue.h"
#include "Structures/SimpleList/SimpleList.h"

using namespace std;

int main() {
    cout << "\n----- Test Circular double List -----\n";
    CircularDoubleList<int> circularDoubleList;
    circularDoubleList.addNode(1);
    circularDoubleList.addNode(2);
    circularDoubleList.addNode(3);
    circularDoubleList.addNode(4);
    circularDoubleList.addNode(5);
    circularDoubleList.readStartNodes();
    circularDoubleList.readEndNodes();

    /*circularDoubleList.deleteSpecificNode(2);
    circularDoubleList.deleteSpecificNode(5);
    circularDoubleList.readStartNodes();
    circularDoubleList.readEndNodes();

    circularDoubleList.updateNode(3, 30);
    circularDoubleList.readStartNodes();*/

    cout << "\n----- Test Double List -----\n";
    DoubleList<int> doubleList;
    doubleList.addFirstNode(4);
    doubleList.addFirstNode(3);
    doubleList.addFirstNode(2);
    doubleList.addFirstNode(1);
    doubleList.readStartNodes();

    doubleList.addLastNode(5);
    doubleList.addLastNode(6);
    doubleList.addLastNode(7);
    doubleList.addLastNode(8);
    doubleList.readStartNodes();

    doubleList.updateNode(3, 30);
    doubleList.readStartNodes();

    doubleList.deleteFirstNode();
    doubleList.readStartNodes();

    doubleList.deleteLastNode();
    doubleList.readStartNodes();

    doubleList.deleteSpecificNode(5);
    doubleList.readStartNodes();
    doubleList.readEndNodes();

    cout << "\n----- Test Queue List -----\n";
    Queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);

    queue.pop();

    cout << "\n----- Test Simple List -----\n";
    SimpleList<int> simpleList;
    simpleList.addFirstNode(4);
    simpleList.addFirstNode(3);
    simpleList.addFirstNode(2);
    simpleList.addFirstNode(1);
    simpleList.readNodes();

    simpleList.addLastNode(5);
    simpleList.addLastNode(6);
    simpleList.addLastNode(7);
    simpleList.addLastNode(8);
    simpleList.readNodes();

    simpleList.updateNode(3, 30);
    simpleList.readNodes();

    simpleList.deleteFirstNode();
    simpleList.readNodes();

    simpleList.deleteLastNode();
    simpleList.readNodes();

    simpleList.deleteSpecificNode(5);
    simpleList.sortList();
    simpleList.readNodes();

    system("pause");
    return 0;
}
