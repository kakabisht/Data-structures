#include<iostream>
#include<stdio.h>
using namespace std;

struct node
{
    int key;
    struct node * left,*right;
};

struct node *newNode(int key)
{
    struct node *temp=new node;
    temp->key=key;
    temp->left=temp->right=NULL;
    return temp;
};

struct node *insert(struct node* root,int key){
    if(root==NULL)
        return newNode(key);
    if(key<root->key)
        root->left=insert(root->left,key);
    if(key<root->key)
        root->right=insert(root->right,key);

}

void inorder(struct node *root){
    if (root !=NULL)
    {
        inorder(root->left);
        cout<<root->key;
        inorder(root->right);
           
    }
}

struct node * search(struct node *root, int key){

    if((root==NULL) && (root->key ==key))
        return root;
    if(root->key >key)
        return search(root->left,key);
    
    return search(root->right,key);
}

struct node * minval(struct node *root){

    struct node * temp=root;
    while(temp->left !=NULL && temp)
        temp=temp->left ;
    return temp;
}

struct node * delnode(struct node *root,int key){
    if(root==NULL)
        return root;
    if(key<root->key)
        root->left=delnode(root->left,key);
    else if(key>root->key)
            root->right=delnode(root->right,key);
    else
    {
        if(root->left ==NULL )
        {
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        if( root->right==NULL)
        {
            struct node *temp=root->left;
            free(root);
            return temp;
        }

        struct node *temp=minval(root->right);
        root->key=temp->key;
        root->right=delnode(root->right, temp->key);
    }
    

}

int main(){

    struct node * root=NULL;
    root=insert(root,10);
    insert(root,2);
    insert(root,50);
    insert(root,1);
    insert(root,3);
    inorder(root);
    struct node* fetch=search(root,3);
    return 0;
}