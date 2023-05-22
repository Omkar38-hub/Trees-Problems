// Longest path between two leaf Node
#include<bits/stdc++.h>	
using namespace std;
struct Node{
	int data;
	struct Node *left,*right;
	Node(int x)
	{
		data=x;
		left=right=NULL;
	}
};
int diamter(Node *root,unordered_map<Node *,int>&mp)
{
	if(root==NULL)
	    return 0;
	int d1=1+mp[root->left]+mp[root->right];
	int d2=diamter(root->left,mp);
	int d3=diamter(root->right,mp);
	return max(d1,max(d2,d3));
}
int height(Node *root,unordered_map<Node *,int>&mp)
{
	if(root==NULL)
	   return 0;
	else
	{
		int x=max(height(root->left,mp),height(root->right,mp))+1;
		mp[root]=x;
		return x;
	}
}
int main()
{
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(60);
	root->left->left=new Node(30);
	root->left->right=new Node(80);
	root->left->left->left=new Node(40);
	root->left->left->right=new Node(50);
	root->left->left->left->left=new Node(60);
    root->left->right->right=new Node(90);
    root->left->right->right->right=new Node(18);
    unordered_map<Node *,int>mp;
    int p=height(root,mp);
	cout<<"The Diamter of given of Binary Tree is "<<diamter(root,mp)<<"\n";
	return 0;
}

//tc=O(n)
// auxillary Space=O(n)
