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

void topView(Node *root,int hd)
{
	map<int,int>mp;
	queue<pair<Node *,int>>q;
	q.push(make_pair(root,hd));
	while(!q.empty())
	{
		Node *temp=q.front().first;
		hd=q.front().second;
		if(mp.count(hd)==0)
		   mp[hd]=temp->data;
		if(temp->left)
		    q.push(make_pair(temp->left,hd-1));
	    if(temp->right)
	       q.push(make_pair(temp->right,hd+1));
	    q.pop();
	}
	for(auto i=mp.begin();i!=mp.end();i++) 
    { 
        cout<<i->second<<" "; 
    }   
}
int main()
{
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	cout<<"The top View of given Binary Tree is \n";
	topView(root,0);
	return 0;
}





