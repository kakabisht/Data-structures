#include<iostream>
#include<queue>
using  namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
};

Node* createNode(int key){
    Node *node=new Node();
    node->key=key;
    node->left=NULL;
    node->right=NULL;
    return node;
}

Node *search(Node *root, int key){
    if(root==NULL)
        return NULL;
    queue < Node *>q;
    q.push(root);
    Node *out;
    while(!q.empty()){

    Node *temp=q.front();
       q.pop();
       if(temp->key=key){
            out=temp;cout<<"hit";
       }
       if(temp->left !=NULL){
           q.push(temp->left);
       }
       if(temp->right !=NULL){
           q.push(temp->left);
       }
       
    }
    return out;

}

void insert(Node **root, int key){

    if(*root ==NULL){
        cout<<"The root is null"<<endl;
        *root=createNode(key);
        return;
    }

    Node *nodetoinsert=createNode(key);
    queue<Node*>q;
    q.push(*root);

    while(! q.empty()){
        Node *temp=q.front();
        q.pop();

        if(temp->left==NULL){
            temp->left = nodetoinsert;

        }

        if(temp->right==NULL){
            temp->right = nodetoinsert;
            
        }
    }

}
void setExtremerighttoNUll(Node *root, Node *extremeright)
{
    queue <Node*> q;
    q.push(root);
    Node * temp;
    while(!q.empty()){
        temp=q.front();
        q.pop();
        if (temp->left ==extremeright){
            temp->left=NULL;
            return;
        }
        else{
            q.push(temp->left);
        }
        
        if (temp->right ==extremeright){
            cout<<"Found"<<endl;
            temp->right=NULL;
            return;
        }
        else{
            q.push(temp->right);
        }
        
    }

}   
void deleteNode(Node *root ,int key){
    Node *nodetodelete=search(root,key);
    queue <Node*> q;
    q.push(root);
    Node * temp;
    while(!q.empty()){
        temp=q.front();
        q.pop();
        if (temp->left!=NULL)
            q.push(temp->left);
        if (temp->right!=NULL)
            q.push(temp->right);
    }
    //We have to perform 3 steps
    int keyAtDeepestRIght=temp->key;
    setExtremerighttoNUll(root,temp);
    
    nodetodelete->key=keyAtDeepestRIght;
}
void DFT_inorder(Node *root){
    if(root==NULL)
        return ;
    DFT_inorder(root->left);
    cout<<root->key<<",";
    DFT_inorder(root->right);
}
void DFT_preorder(Node *root){
    if(root==NULL)
        return ;
    cout<<root->key<<",";
    DFT_preorder(root->left);
  
    DFT_preorder(root->right);
}
void DFT_postorder(Node *root){
    if(root==NULL)
        return ;
    DFT_postorder(root->left);
    DFT_postorder(root->right);
    cout<<root->key<<",";

}

void BFS(Node *root){
    queue<Node*> q;
    q.push(root);
    while (!q.empty()){
        Node * temp=q.front();
        q.pop();
        cout<<temp->key<<",";
        if(temp->left !=NULL)
            q.push(temp->left);
        
        if(temp->left !=NULL)
            q.push(temp->left);
        
    }
    

}

string BFSRecursive(Node *root,int level){
    if(root==NULL)return"-";
    if(level==1)return to_string(root->key);
    if(level >1)return BFSRecursive(root->left,level-1)+" "+BFSRecursive(root->right,level-1);
   
}

void printMyTree(Node *root , int height){

    for(int i=i;i<height+1;i++)
        cout<<BFSRecursive(root,i)<<endl;

}
int main(){
    Node *root=NULL;
    for(int i=1;i<=6;i++)
        insert(&root,i);
    cout<<root->key<<endl;
    cout<<root->left->key<<endl;
    cout<<root->right->key<<endl;
    cout<<root->left->left->key<<endl;
    cout<<root->left->right->key<<endl;
    cout<<root->right->left->key<<endl;
 //   cout<<root->right->right->key<<endl;
/*
    deleteNode(root,2);
     cout<<root->key<<endl;
    cout<<root->left->key<<endl;
    cout<<root->right->key<<endl;
    cout<<root->left->left->key<<endl;
    cout<<root->left->right->key<<endl;
    cout<<root->right->left<<endl;
   // cout<<root->right->right->key<<endl;
    */

    return 0;
}