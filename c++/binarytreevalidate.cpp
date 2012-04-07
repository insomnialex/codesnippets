#include <iostream>
#include <string>

using namespace std;

class Node{
	
    private:
	    int value;
		Node* left;
		Node* right;

    public:
		Node()
		{
			value = NULL;
		}
		Node(int val)
		{
			value = val;
			left = new Node();
			right = new Node();
		}
	    int GetValue(){return value;}
		Node GetLeftChild(){if(left == 0) return 0; else return *left;}
		Node GetRightChild(){if(right == 0) return 0; else return *right;}
		void AttachLeftChild(Node* node){left = node;}
		void AttachRightChild(Node* node){right = node;}
};

bool validBooleanTree(Node node, int min, int max)
{
	if(node.GetValue() == NULL)
		return true;
	if(node.GetValue() > min && node.GetValue() < max)
	{
		//cout << min << " < " << node.GetValue() << " < " << max << endl;		
		if(!validBooleanTree(node.GetLeftChild(), min, node.GetValue()))
			return false;
		if(!validBooleanTree(node.GetRightChild(), node.GetValue(), max))
			return false;
		return true;
	}
	return false;
}

int main(int argc, char* argv[])
{	
    // graphical representation of the binary tree 
    // to be created
	//      5
	//   3     7
	//       6   9
	
	//top node
	Node* a = new Node(5);
	//left child node
	Node* b = new Node(3);
	a->AttachLeftChild(b);
	//right child node
	Node* c = new Node(7);
	a->AttachRightChild(c);	
	//left child node of right child node
	Node* d = new Node(6);
	c->AttachLeftChild(d);	
	//right child node of right child node
	Node* e = new Node(9);
	c->AttachRightChild(e);
	
	string valid = "true";
	bool validTree = validBooleanTree(*a, -999999, 999999);
	if(!validTree)
	{
		valid = "false";
	}
	cout << "valid binary tree? ";
	cout << valid;

	return 0;
}