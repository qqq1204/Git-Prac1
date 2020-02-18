#include <iostream>
#include "TF_Node.h"
 
class TF_TREE
{
	TF *top;
public:
	TF_TREE() { top = NULL; }
	void setTop(TF* c) { top = c; }
	TF* postorderSearch(string name) { return postorderSearch(top, name); }
	TF* postorderSearch(TF* node, string name) {
		if (node != NULL)
		{
			TF* tmp= NULL;
			if (node->getName() != name)
			{	
				tmp = postorderSearchVector(node->getDesc(), name);
				return tmp;
			}
			else {	return node;}
		}
	}
	TF* postorderSearchVector(vector<TF*> nodearr, string name)
	{
 
		if (!nodearr.empty())
			for (int i = 0; i < nodearr.size(); i++)
			{
				if (nodearr[i]->getName() == name)
					return nodearr[i];
				else{
					TF* tmp = postorderSearch(nodearr[i], name);
					if (tmp != NULL) { return tmp; }
					continue;
				}
			}
		else return NULL;
	}
	void removeTF(string name)
	{
		postorderSearch(name)->getDesc().clear();
		delete postorderSearch(name);
	}
	vector<TF*> getAllParents(string name)
	{
		vector<TF*> Parents;
		TF* targetTF = postorderSearch(name);
		while (targetTF->getParent() != NULL)
		{
			Parents.insert(Parents.begin(), targetTF->getParent());
			targetTF = targetTF->getParent();	
		}
		for (int i = 0; i < Parents.size(); i++)
			cout << Parents[i]->getName() << endl;
		return Parents;
	}
	void calPosition(string name)
	{	
		int tmpx = 0; int tmpy = 0; int tmpz = 0;
		vector<TF*> ParentsGroup = getAllParents(name);
		for (int i = 0; i < ParentsGroup.size(); i++)
		{
			tmpx += ParentsGroup[i]->getx();
			tmpy += ParentsGroup[i]->gety(); 
			tmpz += ParentsGroup[i]->getz();
		}
		tmpx += postorderSearch(name)->getx();
		tmpy += postorderSearch(name)->gety();
		tmpz += postorderSearch(name)->getz();
		
		cout << "x, y, z " << tmpx<<" " << tmpy << " " << tmpz << endl;
	}
	void calQuaternion(string name)
	{
 
	}
};