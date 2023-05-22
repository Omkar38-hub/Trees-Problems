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
	queue<struct Node*>q;
	q.push(root);
	int count=0;
	while(!q.empty())
	{
		int cnt=q.size();
		count++;
		for(int i=0;i<cnt;i++)
		{
			struct Node *temp=q.front();
			q.pop();
			if(temp->left)
			   q.push(temp->left);
			if(temp->right)
			   q.push(temp->right);
		}
	}
	return count;
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
