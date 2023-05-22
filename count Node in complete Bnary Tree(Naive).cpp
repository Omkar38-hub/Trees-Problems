#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left,*right;
	Node(int x)
	{
		data=x;
		left=right=NULL;
	}
};
int count(Node *root)
{
	if(root==NULL)
	   return 0;
	else
	  return (1+count(root->left)+count(root->right));
}
int main()
{
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->left=new Node(60);
	cout<<"the number of nodes in given complete tree is  "<<count(root);
	return 0;
}
