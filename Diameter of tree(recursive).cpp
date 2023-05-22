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
int height(Node *root)
{
	if(root==NULL)
	   return 0;
	else
	   return max(height(root->left),height(root->right))+1;
}
int diamter(Node *root)
{
	if(root==NULL)
	    return 0;
	int d1=1+height(root->left)+height(root->right);
	int d2=diamter(root->left);
	int d3=diamter(root->right);
	return max(d1,max(d2,d3));
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

	cout<<"The Diamter of given of Binary Tree is "<<diamter(root)<<"\n";
	return 0;
}

//tc=O(n^2)
// auxillary Space=O(n)
