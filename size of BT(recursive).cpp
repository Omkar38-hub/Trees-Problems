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
int sizeBT(struct Node *root)
{
	if(root==NULL)
	  return 0;
	else
	  return sizeBT(root->left)+sizeBT(root->right)+1;
}
int main()
{
	Node *root = newNode(10); 
    root->left = newNode(80); 
    root->right = newNode(70); 
    root->left->left = newNode(30); 
    root->left->right = newNode(40); 
    root->right->right = newNode(90); 
    cout<<"The size of Binary tree is "<<sizeBT(root);
    return 0;
}
//tc=O(n)
// auxillary Space=O(h)
