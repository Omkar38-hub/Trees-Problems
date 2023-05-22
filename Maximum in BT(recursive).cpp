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
int maxElement(struct Node *root)
{
	if(root==NULL)
	  return INT_MIN;
	else
	  return max(root->data,max(maxElement(root->left),maxElement(root->right)));
}
int main()
{
	Node *root = newNode(10); 
    root->left = newNode(30); 
    root->right = newNode(40); 
    root->left->left = newNode(80); 
    root->left->left->right = newNode(70); 
    root->right->left = newNode(60); 
    root->right->right = newNode(20); 
    cout<<"The maximum element of Binary tree is "<<maxElement(root);
    return 0;
}
//tc=O(n)
// auxillary Space=O(h)
