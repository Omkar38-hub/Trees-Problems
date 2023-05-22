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
int maxLevel=0;
void printView(struct Node *root,int level){
    if(root==NULL)
        return;
    if(maxLevel<level){
        cout<<root->data<<" ";
        maxLevel=level;
    }
    printView(root->left,level+1);
    printView(root->right,level+1);
}
void leftView(struct Node *root)
{
	printView(root,1);
}
int main()
{
	Node *root = newNode(10); 
    root->left = newNode(20); 
    root->right = newNode(30); 
    root->left->left = newNode(40); 
    root->left->right = newNode(50);
    root->right->right = newNode(60); 
    cout<<"The Left view of Binary tree is \n";
	leftView(root);
    return 0;
}
//tc=O(n)
// auxillary Space=O(h)
