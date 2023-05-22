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
	stack<int>s;
	bool reverse=false;
	queue<Node *>q;
	q.push(root);
	while(!q.empty())
	{
		int count=q.size();
		for(int i=0;i<count;i++)
		{
			Node *temp=q.front();
			q.pop();
			if(reverse)
			   s.push(temp->data);
			else
			   cout<<temp->data<<" ";
			if(temp->left)
			   q.push(temp->left);
			if(temp->right)
			   q.push(temp->right);
		}
		if(reverse)
		{
			while(!s.empty())
			{
				cout<<s.top()<<" ";
				s.pop();
			}
		}
		reverse=!reverse;
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
