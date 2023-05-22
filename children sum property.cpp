// sum of left child and right child of a node is equal to node value
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
bool childSum(Node *root)
{
	if(root==NULL)
	  return true;
	if(root->left==NULL && root->right==NULL)
	  return true;
	int sum=0;
	if(root->left)
	   sum+=root->left->data;
	if(root->right)
	   sum+=root->right->data;
	return (root->data==sum && childSum(root->left)&& childSum(root->right));
}
int main()
{
	
	Node *root=new Node(20);
	root->left=new Node(8);
	root->right=new Node(12);
	root->left->left=new Node(3);
	root->left->right=new Node(5);
	cout<<"Is the child Sum property satisfied by given BT?\n";
	if(childSum(root))
	    cout<<"YES\n";
	else
	    cout<<"NO\n";
}

//tc=O(n)
// auxillary Space=O(h)
