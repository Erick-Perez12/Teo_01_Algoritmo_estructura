#include <iostream>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

int main() {
	LinkedList<int> l1,l2;
	l1.pushFront(2);
	l1.InsertTail(4);
	l1.InsertTail(5);
	l1.InsertTail(11);
	l1.SortedInserter(3);
	l1.Insertk(10,4);
	
	
	l2.InsertTail(11);
	l2.InsertTail(12);
	l2.InsertTail(13);
	cout << l1 << endl;
	l1.Ordenado();
	cout<<"Minimo: "<<l1.Minimum()<<endl;

	cout << l1 + l2<<endl;

	
}