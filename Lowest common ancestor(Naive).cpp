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
bool path(Node *root,vector<Node *>&p,int n)
{
	if(root==NULL)
	  return false;
	p.push_back(root);
	if(root->data==n)
	  return true;
	if(path(root->left,p,n)||path(root->right,p,n))
	  return true;
	p.pop_back();
	return false;
}
Node *LCA(Node *root,int n1,int n2)
{
	vector<Node *>p1,p2; // paths for the both node
	if(path(root,p1,n1)==false || path(root,p2,n2)==false)
	   return NULL;
	for(int i=0;i<p1.size()-1 && i<p2.size()-1;i++)
	{
		if(p1[i+1]!=p2[i+1])
		  return p1[i];
	}
	return NULL;
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
	int n1=70;
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
