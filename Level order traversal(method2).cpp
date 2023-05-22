#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node *left,*right;
};

Node* newNode(int data) 
{ 
    Node *temp = new Node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
int height(struct Node *root)
{
	if(root==NULL)
	  return 0;
	else
	  return max(height(root->left),height(root->right))+1;
}
void Klevel(struct Node *root,int k,int i)
{
	if(root==NULL)
	  return;
	if(i==k)
	  cout<<root->data<<" ";
	else
	{
		Klevel(root->left,k,i+1);
		Klevel(root->right,k,i+1);
	}
}
void levelOrder(struct Node *root,int h)
{
	for(int k=1;k<=h;k++)
	  Klevel(root,k,1);//print nodes of level k of binary Tree
}
int main()
{
	Node *root = newNode(10); 
    root->left = newNode(20); 
    root->right = newNode(30); 
    root->left->left = newNode(8); 
    root->left->right = newNode(7); 
    root->right->right = newNode(6); 
    root->left->right->right = newNode(15); 
    root->left->right->left = newNode(9); 
    cout<<"The level order Traversal of Binary tree is \n";
    int h=height(root);//height of binary Tree
    levelOrder(root,h);
    return 0;
}
//tc=O(h*n)
// auxillary Space=O(n)
