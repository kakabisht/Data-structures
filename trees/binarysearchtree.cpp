#include<iostream>
#include <stdlib.h>
#include<stack>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    
    Node()//default constructor
    {
        data=0;
        right=left=NULL;
    }

    Node(int n)//constructor
    {
        data=n;
        right=left=NULL;
    }
};


class BST : public Node
{   
    
    public: 
    Node *root,*temp;
    BST()
    {
        root=NULL;
        temp=NULL;
    }
    void Create();
    void Insert(int);
    Node* Search(Node*,int);
    Node * del( Node *,int );
    Node *delnode(Node * , int);
    Node *FindMin(Node *);
    bool printLevel(Node* , int );
    void levelOrderTraversal(Node* );


   
};

void BST::Create()
{

    Node *newnode;
    int num;
    int k=0;
    do
    {
        cout<<"\n Enter the data :";
        cin>>num;
        newnode = new Node(num);
        newnode->left=newnode->right=NULL;
        if (root==NULL)
        {
            root=newnode;//It was empty 

        }
        else{
            
            temp=root;
            while (1)
            {
                if(num<temp->data){
                    if (temp->left==NULL)
                    {
                        temp->left=newnode;
                        break;
                    }
                    else
                        temp=temp->left;
                }
                else
                {
                    if (temp->right==NULL)
                    {
                        temp->right=newnode;
                        break;
                    }
                    else
                        temp=temp->right;
                }
            
            }
                   
        }
        cout<<"To continue press 0 , Else press anything";
        cin>>k; 
     
    } while (k==0);  
}

void BST::Insert(int number){
    Node*newnode;
    newnode=new Node(number);
    if (root==NULL)
        root=newnode;
    else
    {
        temp=root;
        while(1)
        {
            if(number<temp->data){
                    if (temp->left==NULL)
                    {
                        temp->left=newnode;
                        break;
                    }
                    else
                        temp=temp->left;
            }
            else{
                    if (temp->right==NULL)
                    {
                        temp->right=newnode;
                        break;
                    }
                    else
                        temp=temp->right;
            }
        }
    }    
}

Node* BST::Search(Node * root,int val){

    if(root!=NULL)
    {
        if(root->data ==val)
            return root;
        if(val<root->data)
            return Search(root->left,val);
        if(val>root->data)
            return Search(root->right,val);
    }
    return NULL;
}

Node * BST:: FindMin(Node *root) {
   if (root == NULL) {
      return NULL; // or undefined.
   }
   if (root->left != NULL) {
      return FindMin(root->left); // left tree is smaller
   }
   return root;
}

 Node* BST::del( Node *root ,int data) {
  
  if (root == NULL) {
     return NULL;
  }
  if (data < root->data) {  // data is in the left sub tree.
      root->left = del(root->left,data);
  } 
  else if (data > root->data) { // data is in the right sub tree.
      root->right = del(root->right, data);
  } else {
     // case 1: no children
     if (root->left == NULL && root->right == NULL) {
        delete(root); // wipe out the memory, in C, use free function
        root = NULL;
     }
     // case 2: one child (right)
     else if (root->left == NULL) {
        Node *temp = root; // save current node as a backup
        root = root->right;
        delete temp;
     }
     // case 3: one child (left)
     else if (root->right == NULL) {
        Node *temp = root; // save current node as a backup
        root = root->left;
        delete temp;
     }
     // case 4: two children
     else {
        Node *temp = FindMin(root->right); // find minimal value of right sub tree
        root->data = temp->data; // duplicate the node
        root->right = del(root->right, temp->data); // delete the duplicate node
     }
  }
  return root; // parent node can update reference
}

bool BST :: printLevel(Node* root, int level)
{
    if (root == NULL)
        return false;

    if (level == 1)
    {
        cout << root->data<< " ";

        // return true if at-least one node is present at given level
        return true;
    }

    bool left = printLevel(root->left, level - 1);
    bool right = printLevel(root->right, level - 1);

    return left || right;
}

void BST ::levelOrderTraversal(Node* root)
{
    // start from level 1 -- till height of the tree
    int level = 1;

    // run till printLevel() returns false
    while (printLevel(root, level))
        level++;
}



int main()
{
    BST t;
    int k=0;
    cout<<"Welcome to Binary Tree Using Linking  by Hridyesh ";
    do
    {
        int ch;
        cout<<"Press \n 1.Create a Binary Search Tree \n 2.Display a Binary Search Tree \n 3.Inserting Element \n 5.Search an Element \n 6.Deleting Element  \n 7.To Quit \n";

        cin>>ch;
        int number;

        switch (ch)
        {
            case 1:
                    t.Create();
                    break;
           
            case 2:
                    t.levelOrderTraversal(t.root);
                    break;
                
            case 3:
                    break;
            
            case 4:
                    cout<<"Enter the number you want";
                    cin>>number;
                    t.Insert(number);
                    break;
            case 5:
                    cout<<"Enter the number you want";
                    cin>>number;
                    Node *ro=t.root;
                    t.Search(ro,number);
                    break;
            case 6:
                    cout<<"Enter the number you want";
                    cin>>number;
                    Node *ro=t.root;
                    t.delnode(ro,number);
                    break;
            case 7:
                    k=1;
                    break;

        }
      

    } while (k==0);
    return 0;
}
