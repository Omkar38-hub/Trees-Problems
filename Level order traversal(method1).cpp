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
void levelOrder(struct Node *root)
{
	queue<struct Node*>q;
	q.push(root);
	while(!q.empty())
	{
		struct Node *temp=q.front();
		q.pop();
		cout<<temp->data<<" ";
		if(temp->left)
		   q.push(temp->left);
		if(temp->right)
		   q.push(temp->right);
	}
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
    levelOrder(root);
    return 0;
}
//tc=O(n)
// auxillary Space=O(w)
