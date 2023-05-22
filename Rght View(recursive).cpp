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
void rightView(Node *root,int level,int &maxlevel)
{
	if(root==NULL)
	  return;
	if(maxlevel<level)
	{
		cout<<root->data<<" ";
		maxlevel=level;
	}
	rightView(root->right,level+1,maxlevel);
	rightView(root->left,level+1,maxlevel);
	
}

int main()
{
	Node *root=new Node(50);
	root->left=new Node(20);
	root->right=new Node(100);
	root->left->left=new Node(10);
	root->left->right=new Node(40);
	root->right->left=new Node(70);
	root->right->right=new Node(120);
	root->right->left->left=new Node(60);
	root->right->left->right=new Node(80);
	cout<<"The Rght View of given Binary Tree is \n";
	int maxlevel=0;
	rightView(root,1,maxlevel);
	return 0;
}

