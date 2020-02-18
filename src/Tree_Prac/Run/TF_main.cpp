#include <iostream>
#include "../Nodes/TF_Tree.h"
 
 
int main()
{
	TF_TREE Car;
	TF* a = new TF(2, 2, 3, 4, 5, 6,"footprint");
	
	TF* b = new TF(3, 2, 3, 4, 5, 7, "chasis");
	a->insertTF(b);
	TF* c = new TF(4, 2, 3, 4, 5, 8, "wheel");
	b->insertTF(c);
	TF* d = new TF(5, 2, 3, 4, 5, 9, "joint");
	b->insertTF(d);
	
	Car.setTop(a);
	
	TF* k;
	k = Car.postorderSearch("footprint");
	
	Car.getAllParents("joint");
	Car.calPosition("joint");
}