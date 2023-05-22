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
int width(Node *root)
{
	queue<Node *>q;
	q.push(root);
	int mx=INT_MIN;
	while(!q.empty())
	{
		int count=q.size();
		mx=max(mx,count);
		for(int i=0;i<count;i++)
		{
			Node *temp=q.front();
			q.pop();
			if(temp->left)
			   q.push(temp->left);
			if(temp->right)
			   q.push(temp->right);
		}
	}
	return mx;
}
int main()
{
	
	Node *root=new Node(8);
	root->left=new Node(30);
	root->right=new Node(20);
	root->left->left=new Node(90);
	root->left->right=new Node(100);
	root->right->left=new Node(70);
	root->right->right=new Node(300);
	cout<<"The maximum width of binary tree is "<<width(root)<<"\n";
	return 0;
}

//tc=O(n)
// auxillary Space=O(w)
