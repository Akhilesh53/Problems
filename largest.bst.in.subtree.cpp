#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};


// vector will be like {min,max,size}
vector<int> dfs(Node* root){
    if(!root){
        return {INT_MAX,INT_MIN,0};
    }

    if( !root->left && !root->right){
        return {root->data,root->data,1};
    }

    vector<int>left = dfs(root->left);
    vector<int>right = dfs(root->right);

    // if left subtree max vlaue is less than root and right subtree min value is greater than root
    // then we can say that this is a BST
    if(left[1] < root->data && right[0] > root->data){
        return {min(left[0],root->data),max(right[1],root->data),left[2]+right[2]+1};
    }
    return {INT_MIN,INT_MAX,max(left[2],right[2])};
}

int largestBST(Node *root)
{
    if (!root)
        return 0;
   
   vector<int>ans =  dfs(root);
   return ans[2];
}