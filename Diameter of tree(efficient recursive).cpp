// Longest path between two leaf Node
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
int diameter(Node *root,int &res)
{
	if(root==NULL)
	    return 0;
	int lh=diameter(root->left,res);
	int rh=diameter(root->right,res);
	res=max(res,lh+rh+1);
	return 1+max(lh,rh);
}

int main()
{
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(60);
	root->left->left=new Node(30);
	root->left->right=new Node(80);
	root->left->left->left=new Node(40);
	root->left->left->right=new Node(50);
	root->left->left->left->left=new Node(60);
    root->left->right->right=new Node(90);
    root->left->right->right->right=new Node(18);
    int res=0;
	int p=diameter(root,res);
	cout<<"The Diamter of given of Binary Tree is "<<res<<"\n";
	return 0;
}

//tc=O(n)
// auxillary Space=O(h)
