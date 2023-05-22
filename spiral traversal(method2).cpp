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
void spiral(Node *root)
{
	stack<Node *>s1;
	stack<Node *>s2;
	s1.push(root);
	while(!s1.empty()||!s2.empty())
	{
		while(!s1.empty())
		{
			Node *temp=s1.top();
			s1.pop();
			cout<<temp->data<<" ";
			if(temp->left)
			   s2.push(temp->left);
			if(temp->right)
			    s2.push(temp->right);
		}
		while(!s2.empty())
		{
			Node *temp=s2.top();
			s2.pop();
			cout<<temp->data<<" ";
			if(temp->right)
			    s1.push(temp->right);
			if(temp->left)
			   s1.push(temp->left);
		}
	}
}
int main()
{
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->left->left->left=new Node(8);
	root->left->left->right=new Node(9);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	root->right->left->left=new Node(10);

	cout<<"The spiral traversal of Binary Tree is ";
	spiral(root);
	return 0;
}

//tc=O(n)
// auxillary Space=O(w)
