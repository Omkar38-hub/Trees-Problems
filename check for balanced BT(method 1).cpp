// difference between the height of left subtree and right subtree should not be greater than 1
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
	  return (max(height(root->left),height(root->right))+1);
}
bool isBalanced(Node *root)
{
	if(root==NULL)
	   return true;
	int lh=height(root->left);
	int rh=height(root->right);
	return ((abs(lh-rh)<=1) && isBalanced(root->left) && isBalanced(root->right));
}
int main()
{
	
	Node *root=new Node(30);
	root->left=new Node(40);
	root->right=new Node(80);
	root->left->left=new Node(50);
	root->left->right=new Node(70);
	root->left->right->left=new Node(20);
	root->left->right->right=new Node(10);
	root->right->left=new Node(5);
	cout<<"Is the given binary tree is balanced?\n";
	if(isBalanced(root))
	    cout<<"YES\n";
	else
	    cout<<"NO\n";
}

//tc=O(n^2)
// auxillary Space=O(n)
