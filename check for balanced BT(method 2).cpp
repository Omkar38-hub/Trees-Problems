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
bool isBalanced(Node *root)
{
	if(root==NULL)
	   return 0;
	int lh=isBalanced(root->left);
	if(lh==-1)
	  return -1;
	int rh=isBalanced(root->right);
	if(rh==-1)
	   return -1;
	if(abs(rh-lh)>1)
	   return -1;
	return (max(lh,rh)+1);
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

//tc=O(n)
// auxillary Space=O(n)
