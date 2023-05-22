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
 // Do level order traversal until we find 
    // an empty place. 
void insert(Node *root,int key)
{
	if(root==NULL)
	{
		root=new Node(key);
		return;
	}
	queue<Node *>q;
	q.push(root);
	while(!q.empty())
	{
		Node *temp=q.front();
		q.pop();
		if(!temp->left)
		{
			temp->left=new Node(key);
			break;
		}
		else
		   q.push(temp->left);
		if(!temp->right)
		{
			temp->right=new Node(key);
			break;
		}
		else
		   q.push(temp->right);
	}
}
int main()
{
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->right=new Node(60);
	cout<<"Inorder Traversal of Initial tree \n";
	inorder(root);
	int key=12;
	insert(root,key);
	cout<<"\nNow Inorder traversal of Bt after Inserting "<<key<<" is \n";
	inorder(root);
	key=24;
	insert(root,key);
	cout<<"\nNow Inorder traversal of Bt after Inserting "<<key<<" is \n";
	inorder(root);
	return 0;
}
