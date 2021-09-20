# include<bits/stdc++.h>
using namespace std;
struct node
{
    node*left;
    node*right;
    int data;
    node(int data)
    {
        this->data = data;
        left =NULL;
        right=NULL;
    }
};
node*LCA(node*root,int n1,int n2)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==n1 || root->data==n2)
    {
        return root;
    }
    node*left = LCA(root->left,n1,n2);
    node*right = LCA(root->right,n1,n2);
    if(left==NULL && right==NULL)
    {
        return NULL;
    }
    if(left!=NULL && right!=NULL)
    {
        return root;
    }
    if(left!=NULL)
    {
        return LCA(root->left,n1,n2);
    }
    return LCA(root->right,n1,n2);
}
int calculate_dis(node*root,int n,int dis)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->data==n)
    {
        return 0;
    }
    int left = calculate_dis(root->left,n,dis+1);
    int right = calculate_dis(root->right,n,dis+1);
    if(left!=-1)
    {
        dis = left;
        return (root->left,n,dis+1);
    }
    dis=right;
    return (root->right,n,dis+1);
}
int connecting_func(node*root,int n1,int n2)
{
    node*result = LCA(root,n1,n2);
    int d1 = calculate_dis(result,n1,0);
    int d2 = calculate_dis(result,n2,0);
    return d1+d2;
}
int main()
{
    node*root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left =new node(6);
    root->right->right =  new node(7);
    cout<<connecting_func(root,2,3);

}