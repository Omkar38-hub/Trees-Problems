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
// Function to delete the given deepest node 
// (node) in binary tree 

void deleteDeepest(Node *root,Node *d_node)
{
	queue<Node*> q; 
    q.push(root); 

    // Do level order traversal until last node 
    Node* temp; 
    while(!q.empty()) 
    { 
        temp = q.front(); 
        q.pop(); 

        if (temp->right) 
        { 
            if (temp->right == d_node) 
            { 
                temp->right = NULL; 
                delete(d_node); 
                return; 
            } 
            else
                q.push(temp->right); 
        } 

        if (temp->left) 
        { 
            if (temp->left == d_node) 
            { 
                temp->left=NULL; 
                delete(d_node); 
                return; 
            } 
            else
                q.push(temp->left); 
        } 
    } 
}

// Function to delete element in binary tree 
void deleted(Node *root,int key)
{
	Node *key_node=NULL;
	if(root==NULL)
	{
		return;
	}
	queue<Node *>q;
	Node *temp;
	q.push(root);
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		if(temp->data==key)
		  key_node=temp;
		if(temp->left)
		   q.push(temp->left);
		if(temp->right)
		   q.push(temp->right);
	}
	int x=temp->data; //  the deepest rightmost node’s data 
	deleteDeepest(root,temp); //  delete deepest rightmost node’s data 
	key_node->data=x; // replace deepest data with deleted value
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
	int key=20;
	deleted(root,key);
	cout<<"\nNow Inorder traversal of Bt after deleting "<<key<<" is \n";
	inorder(root);
	key=10;
	deleted(root,key);
	cout<<"\nNow Inorder traversal of Bt after deleting "<<key<<" is \n";
	inorder(root);
	return 0;
}





