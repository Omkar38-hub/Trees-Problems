// we can construct binary tree from (inorder-preorder or inorder-postorder)

// Never from preorder-postorder
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
void inOrder(Node *root)
{
	if(root==NULL)
	  return;
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}
int preIndex=0;
Node *btConstruction(int in[],int pre[],int initial,int end)
{
	if(initial>end)
	  return NULL;
	Node *root=new Node(pre[preIndex++]);
	int inIndex;
	for(int i=initial;i<=end;i++)
	{
		if(in[i]==root->data)
		{
			inIndex=i;
			break;
		}
	}
	root->left=btConstruction(in,pre,initial,inIndex-1);
	root->right=btConstruction(in,pre,inIndex+1,end);
	return root;
}
int main()
{
	
	int in[]={40,20,50,10,30,80,70,90}; //left-root-right
	int pre[]={10,20,40,50,30,70,80,90};  // root-left-right
	int n=sizeof(in)/sizeof(in[0]);
	Node *root=btConstruction(in,pre,0,n-1);
	inOrder(root);
	return 0;
}

//tc=O(n^2)
// auxillary Space=O(n)
