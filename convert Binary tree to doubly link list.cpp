// Do not use extra space,Only use the space provided by the tree
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
void inorder(Node *root)
{
	if(root==NULL)
	  return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
Node *listView(Node *root)
{
	static Node* prev = NULL;
	if(root==NULL)
	   return root;
	Node *head=listView(root->left);
	if(prev==NULL)
	  head=root;
	else
	{
		root->left=prev;
		prev->right=root;
	}
	prev=root;
	listView(root->right);
	return head;
}
void print(Node *head)
{
	Node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->right;
	}
}
int main()
{
	
	Node *root=new Node(10);
	root->left=new Node(5);
	root->right=new Node(20);
	root->right->left=new Node(30);
	root->right->right=new Node(35);
	cout<<"Inorder traversal of Binary tree ";
	inorder(root);// also arranging nodes in Inorder traversal in link list
	cout<<"\nElements of doubly Link list ";
	Node *head=listView(root);
	print(head);
	return 0;
}

//tc=O(n)
// auxillary Space=O(h)
