#include <iostream>
#include <vector>
 
using namespace std;
class TF
{
	vector<TF*> Node;
	string name;
	int x, y, z, r, p, yaw;
	TF* parent;
public:
	TF(int xval = 0, int yval = 0, int zval = 0, int rval = 0,
		int pval = 0, int yawval = 0, string Nodename = "") : x(xval), y(yval), z(zval),
		r(rval), p(pval), yaw(yawval), Node(0) ,name(Nodename), parent(NULL){ }
	//셋터
	void setPose(int i, int j, int k)
	{x = i, y = j, z = k;}
	void setRpy(int i, int j, int k)
	{r = i, p = j, yaw = k;}
	void setParent(TF* n) { parent = n; }
	//겟터
	int getx() { return x; }
	int gety() { return y; }
	int getz() { return z; }
	int getr() { return r; }
	int getp() { return p; }
	int getyaw() { return yaw; }
	vector<TF*> getDesc() { return Node; }
	string getName() { return name; }
	TF* getParent() { return parent; }
	
	
	// 새로운 TF 삽입
	void insertTF(TF* n)
	{
		if (n != NULL)
		{
			Node.push_back(n);
			n->setParent(this);
		}
	}
	//풋터
	void display()
	{
		cout << "x,y,z,r,p,y = " << x<< y<< z << r << p << yaw << endl;
		cout << "part name is " << name << endl;
		if (getParent()!= NULL)
			cout << "My parent is " << getParent()->getName() << endl;

	else cout << "I'm the top of tree" << endl;
	}
};