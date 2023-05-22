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
//traversing by preorder 

// -1 is used for Null
void serialized(Node *root,vector<int>&v)
{
	if(root==NULL)
	{
		v.push_back(-1);
		return;
	}
	v.push_back(root->data);
	serialized(root->left,v);
	serialized(root->right,v);
}
Node *deseralized(vector<int>v,int &index)
{
	if(index==v.size())
	  return NULL;
	int val=v[index];
	index++;
	if(val==-1)
	   return NULL;
	Node *root=new Node(val);
	root->left=deseralized(v,index);
	root->right=deseralized(v,index);
	return root;
}
void inorder(Node *root)
{
	if(root==NULL)
	   return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int main()
{
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->right=new Node(60);
	vector<int>v;
	serialized(root,v);
	cout<<"the elements os serialized array is \n";
	for(auto x: v)
	   cout<<x<<" ";
	int index=0;
	Node *proot=deseralized(v,index);
	cout<<"\nInorder traversal of found tree ";
	inorder(proot);
	return 0;
}
