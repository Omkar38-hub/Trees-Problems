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
int printHeight(struct Node *root)
{
	if(root==NULL)
	   return 0;
	else
	  return max(printHeight(root->left),printHeight(root->right))+1;
}
int main()
{
	Node *root = newNode(5); 
    root->left = newNode(7); 
    root->right = newNode(9); 
    root->left->left = newNode(3); 
    root->left->right = newNode(2); 
    root->right->left = newNode(5); 
    root->right->right = newNode(4); 
    cout<<"Height of Binary tree is "<<printHeight(root)<<"\n";
    return 0;
}
