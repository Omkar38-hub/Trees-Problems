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
void mirror(Node *root)
{
	if(root==NULL)
	   return;
	else
	{
		mirror(root->left);
		mirror(root->right);
		
		//swap left and right subtree
		
		Node *temp=root->left;
		root->left=root->right;
		root->right=temp;
	}
}
int main()
{
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	cout<<"Inorder Traversal of Initial tree \n";
	inorder(root);
	mirror(root);
	cout<<"\n\nInorder Traversal of mirror tree \n";
	inorder(root);
	return 0;
}





