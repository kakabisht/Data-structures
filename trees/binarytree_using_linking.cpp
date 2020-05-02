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


class BinaryTree : public Node
{   
    private:
    public: 
    Node *root,*temp;
    BinaryTree()//
    {
        root=NULL;
        temp=NULL;
    }
    void Create();
    void printMyTree( int );
    void recursivepreorder(Node *currentnode);
    void recursiveinorder(Node *currentnode);
    void recursivepostorder(Node *currentnode);
    void traversal(BinaryTree );
    void nonrecursivepreorder(Node *currentnode);
    void nonrecursiveinorder(Node *currentnode);
    void nonrecursivepostorder(Node *currentnode);
    int Isempty();
    int totalNodes(Node *);
    int leafNodes(Node *);

    void Insert(int );
    void Delete(int );
    void Search();
    void Reverse();
    Node * mirror(Node *);
    Node * copy( Node *);
};

void BinaryTree ::Create(){

    Node *newnode;
    int num;
    int k=0;
    do
    {
        cout<<"\n Enter the data :";
        cin>>num;
        newnode = new Node(num);
        if (root==NULL)
        {
            root=newnode;//It was empty 

        }
        else{
            
            temp=root;
            while (1)
            {
                char lorr;
                cout<<"Left or Right (l/r)"<<temp->data;
                cin>>lorr;
                if(lorr=='l'){
                    if (temp->left==NULL){
                        temp->left=newnode;
                        break;
                    }
                    else
                        temp=temp->left;//Until it finds an empty left node
                }
                if(lorr=='r'){
                    if(temp->right==NULL){
                        temp->right=newnode;
                        break;
                    }
                    else
                        temp=temp->right;//Until it finds an empty right node 
                }
            }
                   
        }
        cout<<"To continue press 0 , Else press anything";
        cin>>k; 
     
    } while (k==0);  
    
}

string BFSRecursive(Node *root,int level){
    if(root==NULL)return"-";
    if(level==1)return to_string(root->data);
    if(level >1)return BFSRecursive(root->left,level-1)+" "+BFSRecursive(root->right,level-1);

   cout<<"inside BFS recursive";
}

void BinaryTree ::recursivepreorder(Node *currentnode)
{
    if (currentnode != NULL){
        cout<<currentnode->data;//D
        recursivepreorder(currentnode->left);//L
        recursivepreorder(currentnode->right);//R
    }
    
}

void BinaryTree ::recursiveinorder(Node *currentnode)
{
    if (currentnode != NULL){
        recursiveinorder(currentnode->left);//L
        cout<<currentnode->data;//D
        recursiveinorder(currentnode->right);//R
    }
    
}

void BinaryTree ::recursivepostorder(Node *currentnode)
{
    if (currentnode != NULL){
        recursivepostorder(currentnode->left);//L
        recursivepostorder(currentnode->right);//R
        cout<<currentnode->data;//D
    }
    
}

void BinaryTree ::nonrecursivepreorder(Node *currentnode)
{
    temp=root;
    stack<Node *> s;
    cout<<"inorder traversal";
    while (1)
    {
       while (temp != NULL) {
				cout<<temp->data ;
				s.push(temp);
				temp = temp->left;
			}
			// check if Stack is emtpy, if yes, exit from everywhere
			if (s.empty()) {
				return;
			}
			// pop the element from the stack and go right to the tree
			temp = s.top();
            s.pop();
			temp = temp->right;   
    }
    
}

void BinaryTree ::nonrecursiveinorder(Node *currentnode)
{

    temp=root;
    stack<Node *> s;
    cout<<"inorder traversal";
    while (1)
    {
        while (temp!=NULL)
        {
            s.push(temp);
            temp=temp->left;
        }
        if (s.empty())
        {
           return;//Empty tree
        }
        temp=s.top();
        s.pop();

        cout<<temp->data;
        temp=temp->right;      
    }
    

}

void BinaryTree ::nonrecursivepostorder(Node *currentnode)
{
        temp=currentnode;
        stack<Node *> s1;
        stack<Node *> s2;
		s1.push(temp);
		while (s1.empty() == false) {
			// take out the root and insert into second stack.
			temp = s1.top();
            s1.pop();
			s2.push(temp);
			// now we have the root, push the left and right child of root into
			// the first stack.
			if(temp->left!=NULL){
				s1.push(temp->left);
			}
			if(temp->right!=NULL){
				s1.push(temp->right);
			}
		}
		//once the all node are traversed, take out the nodes from second stack and print it.
		cout<<"Preorder Traversal";
		while(s2.empty()==false){
		    cout<<s2.top();
            s2.pop();
		}	
    
}

void BinaryTree ::printMyTree( int height){
    cout<<"print my tree";
    for(int i=0;i<height+1;i++)
    {
        cout<<BFSRecursive(root,i)<<endl;
        cout<<"loop iter"<<i;
    }
        
}

void BinaryTree::traversal(BinaryTree t){
    int choice_traversal;
    int choice_recornot;
    cout<<"We have 2 types  of traversal ,choose \n1.Recursive \n2.Non Recursive ";
    cin>>choice_recornot;
    if (choice_recornot==1)
    {
        cout<<"There are 3 types of traversals , choose \n1.Preorder \n2.Inorder \n3.Postorder";
        cin>>choice_traversal;
        if (choice_traversal==1)
        {
            cout<<"Preorder Traversal";
            t.recursivepreorder(root);

        }
        if (choice_traversal==2)
        {
            cout<<"Inorder Traversal";
            t.recursiveinorder(root);

        }
        if (choice_traversal==3)
        {
            cout<<"Postorder Traversal";
            t.recursivepostorder(root);
        }
        
    }
    if (choice_recornot==2)
    {
        cout<<"There are 3 types of traversals , choose \n1.Preorder \n2.Inorder \n3.Postorder";
        cin>>choice_traversal;
        if (choice_traversal==1)
        {
            cout<<"Preorder Traversal";
            t.nonrecursivepreorder(root);

        }
        if (choice_traversal==2)
        {
            cout<<"Inorder Traversal";
            t.nonrecursiveinorder(root);

        }
        if (choice_traversal==3)
        {
            cout<<"Postorder Traversal";
            t.nonrecursivepostorder(root);
        }
        
    }
    
}

void BinaryTree::Insert(int number){

    Node *newnode=new Node(number);
    if (root==NULL)
        root=newnode;
    else
    {
        temp=root;

        while(1){
            char lorr;
            cout<<"Left or Right (l/r) "<<temp->data;
            cin>>lorr;
            if(lorr=='l'){
                if (temp->left==NULL)
                {
                    temp=temp->left;break;
                }
                else
                    temp=temp->left;
           
            }
            if(lorr=='r'){
                if (temp->right==NULL)
                {
                    temp=temp->right;break;
                }
                else
                    temp=temp->right;
           
            }
        
        }
    }
}

int BinaryTree::totalNodes(Node *root){

    int static count=0;
    if (root!=NULL)
    {
        count++;
        totalNodes(root->left);
        totalNodes(root->right);
    }
    return count;
}

int BinaryTree::leafNodes(Node * root){
    int static countleaf=0;
    if(root==NULL)
        return countleaf;
    if(root->left ==NULL &&root->right ==NULL)
        return ++countleaf;
    leafNodes(root->left);
    leafNodes(root->right);
}

Node * BinaryTree :: copy(Node *root){
    if(root == NULL)
        return NULL;
    /* create a copy of root node */
    Node* newNode = new Node(root->data);
    /* Recursively create clone of left and right sub tree */
    newNode->left = copy(root->left);
    newNode->right = copy(root->right);
    /* Return root of cloned tree */
    return newNode;
}
 
Node * BinaryTree :: mirror(Node *root){   
    if(root == NULL)
        return NULL;
    /* create a copy of root node */
    Node* newNode = new Node(root->data);
    /* Recursively create mirror of left and right sub tree */
    newNode->left = mirror(root->right);
    newNode->right = mirror(root->left);
    /* Return root of mirror tree */
    return newNode;
}

int main()
{
    BinaryTree t;
    BinaryTree t2;
    int k=0;
    cout<<"Welcome to Binary Tree Using Linking  by Hridyesh ";
    do
    {
        int ch;
        cout<<"Press \n 1.Create a Binary Tree \n 2.Display a Binary Tree \n 3.Traverse Binary Tree \n 4.Inserting Element \n 5.Copy data from one tree to another \n 6.Counting total number of nodes \n 7.Counting leaf nodes \n 8.Mirror of binary tree \n 9.To Quit \n";

        cin>>ch;

        switch (ch)
        {
            case 1:
                    t.Create();
                    break;
            case 2:    

                    int height;
                    cout<<"Enter the height of the Display you want";
                    cin>>height;
                    t.printMyTree( height);
                    break;
                
            case 3:
                    t.traversal(t);
                    break;
            
            case 4:
                    int number;
                    cout<<"Enter the height of the Display you want";
                    cin>>number;
                    t.Insert(number);
                    break;

            case 5:
                    t2.root=t.copy(t.root);
                    t2.traversal(t2);
                    break;
        
            case 6:
                    cout<<"total nodes ="<<t.totalNodes(t.root);
                    break;
            case 7:
                    cout<<"Leaf nodes ="<<t.leafNodes(t.root);
                    break;

            case 8:
                    t2.root=t.mirror(t.root);
                    t2.traversal(t2);
                    break;
            case 9:
                    k=1;
                    break;
            default:
                    break;
        }

    } while (k==0);
    return 0;
}

