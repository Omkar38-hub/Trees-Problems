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

Node *LCA(Node *root,int n1,int n2)
{
	if(root==NULL)
	   return NULL;
	if(root->data==n1 || root->data==n2)
	   return root;
	Node *lca1=LCA(root->left,n1,n2);
	Node *lca2=LCA(root->right,n1,n2);
	if(lca1!=NULL && lca2!=NULL)
	  return root;
	if(lca1!=NULL)
	  return lca1;
	else
	  return lca2;
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
	int n1=20;
	int n2=80;
	Node *p=LCA (root,n1,n2);
	if(p==NULL)
	   cout<<"There is No common Ancestor\n";
	else
		cout<<"The Diamter of given of Binary Tree is "<<p->data<<"\n";
	return 0;
}

//tc=O(n)
// auxillary Space=O(h)
