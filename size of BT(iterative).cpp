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
	queue<struct Node*>q;
	q.push(root);
	int count=0;
	while(!q.empty())
	{
		int cnt=q.size();
		count+=q.size();
		for(int i=0;i<cnt;i++){
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
// auxillary Space=O(w)
