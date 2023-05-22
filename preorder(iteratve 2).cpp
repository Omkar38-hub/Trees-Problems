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

void Preorder(Node *root)
{
	if(root==NULL)
	   return;
	stack<Node *>s;
	Node *curr=root;
	while(curr!=NULL || !s.empty())
	{
		while(curr!=NULL)
		{
			cout<<curr->data<<" ";
			s.push(curr);
			curr=curr->left;
		}
		curr=s.top();
		s.pop();
		curr=curr->right;
	}
}

int main()
{
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->left->left=new Node(60);
	root->right->right=new Node(50);
	root->right->right->left=new Node(70);
	root->right->right->right=new Node(80);
	cout<<"the preorder traverssal of tree is ";
	Preorder(root);
	return 0;
}

//tc=O(n)
// auxillary Space=O(h)
