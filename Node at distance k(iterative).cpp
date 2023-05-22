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

void printNode(struct Node *root,int k)
{
	queue<struct Node*>q;
	q.push(root);
	int i=0;
	while(!q.empty()&& i!=k)
	{
		int count=q.size();
		i++;
		for(int j=0;j<count;j++)
		{
				struct Node *temp=q.front();
				if(i==k)
				  cout<<temp->data<<" ";
				q.pop();
				if(temp->left)
				   q.push(temp->left);
				if(temp->right)
				   q.push(temp->right);
		}
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
    int k=3;
    cout<<"Node at distance "<<k<<" in Binary tree is \n";
    printNode(root,k);
    return 0;
}

//time complexity=O(n)
//Auxillary space=O(w)  (w is width of the tree)
