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
void printNode(struct Node *root,int k,int i)
{
	if(root==NULL)
	   return;
	if(i==k)
	  cout<<root->data<<" ";
	else
	{
		printNode(root->left,k,i+1);
		printNode(root->right,k,i+1);
	}
}
int main()
{
	Node *root = newNode(10); 
    root->left = newNode(20); 
    root->right = newNode(30); 
    root->left->left = newNode(40); 
    root->left->right = newNode(50); 
    root->right->right = newNode(70); 
    root->right->right->right = newNode(80); 
    int k=2;
    cout<<"Node at distance "<<k<<" in Binary tree is \n";
    printNode(root,k,1);
    return 0;
}
//time complexity=O(n)
//Auxillary space=O(h)  (w is width of the tree)
