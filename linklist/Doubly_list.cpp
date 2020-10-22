#include <iostream>
#include <stdlib.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next,*prev;
    
    Node()//default constructor
    {
        data=0;
        next=NULL;
    }

    Node(int n)//constructor
    {
        data=n;
        prev=next=NULL;
    }
};


class DoublyList : public Node
{   
    private:
    Node *listptr,*temp;
    //ptr is used to point at the current node and temp is used for temporary usages such as iterations , data storage for a small time.
    public: 
    DoublyList()//
    {
        listptr=NULL;
        temp=NULL;
        //initializing the values to NULL , to avoid segmentation error
    }
    void Create();
    void Display();
    int Isempty();
    int len();
    void Insert(int );
    void Delete(int);
    void Search();
    void Reverse();
};


void DoublyList :: Create()
{
    int i, n;
    cout<<"\n How many nodes :";
    cin>>n;
    for(int i=0; i<n; i++)
        {
            int num;
            cout<<"\n Enter the data :";
            cin>>num;
            Node *newnode = new Node(num);
            if(listptr == NULL)
                listptr = temp = newnode;
            else
            {
                temp -> next = newnode;//temp currently points towards current block
                newnode->prev=temp;
                temp = temp->next;
            }
        }
}

int DoublyList :: Isempty()
{
    if(listptr == NULL)
        return 0;
    else
        return 1;
    
}

void DoublyList:: Display()
{
    Node * current_node = listptr ;         /*    temp points to first node*/
    if ( Isempty()==0 )
    {
            cout<<"List is empty";
    }
    else
    {
       cout<<"\n";
        while (current_node != NULL) //iterate till it reaches last block
        {
            cout << current_node->data << "--->";
            current_node = current_node->next;         /*    move temp to the next node */
        }
        cout<< "NULL"; 
        cout<<"\n";  
    }
}

Node *insert_in_begining(Node *lp,int pos){
    int ele;
    cout<<"\n Enter an element ";
    cin>>ele;
    Node *newnode = new Node(ele);
    newnode->next=lp;
    lp->prev=newnode;
    lp=newnode;
    return lp;
}

void insert_in_middle(Node *lp,int pos)
{
    Node *current_node=lp;
    int count=1;

    while (current_node->next!=NULL)
    {
        if(count==pos)
        {
            int ele;
            cout<<"\n Enter an element ";
            cin>>ele;
            Node *newnode = new Node(ele);
            newnode->next=current_node->next;
            current_node->next->prev=newnode;
            current_node->next=newnode;
            newnode->prev=current_node;
            break;
        }    
        else
            count+=1;
        
        current_node=current_node->next;
    }
    
}

void insert_in_end(Node *lp,int pos)
{
    Node *current_node=lp;
    while (current_node->next!=NULL)
        current_node=current_node->next;
    int ele;
    cout<<"\n Enter an element ";
    cin>>ele;
    Node *newnode = new Node(ele);
    newnode->next=NULL;
    current_node->next=newnode;
    newnode->prev=current_node;
}

void DoublyList::Insert(int size)
{
    int pos;
    cout<<"\n Enter position to enter an element in List \n";
    cin>>pos;
    if (pos==0)
    {
        listptr=insert_in_begining(listptr,pos);
    }
    if (pos==size)
    {
        insert_in_end(listptr,pos);
    }
    else
    {
        insert_in_middle(listptr,pos);
    }
    
}

int DoublyList ::len()
{
    int count=0;
    Node * current_node = listptr ;         /*    temp points to first node*/
    if ( Isempty()==0 )
    {
            cout<<"List is empty";
    }
    else
    {
        while (current_node != NULL)
        {
            count+=1;
            current_node = current_node->next;         /*    move temp to the next node */
        }
    }
    return count;
}
Node *delete_in_begining(Node *lp , int pos )
{
    if(lp==NULL)
        cout<<"\n List is Empty";
    else
    {
        Node *tempo=lp;
        lp=lp->next;
        free(tempo);
        return lp;
    }
}

void delete_in_end(Node *lp,int pos)
{
    if(lp==NULL)
        cout<<"\n List is Empty";
    else
    {
        Node *current_node=lp;
        while ((current_node->next)->next!=NULL)
            current_node=current_node->next;
        Node *tempo=current_node->next;
        current_node->next=NULL;
        free(tempo);
    }
}

void delete_in_middle(Node *lp,int pos)
{
    if(lp==NULL)
        cout<<"\n List is Empty";
    else
    {
        Node *current_node=lp;
        int count=1;

        while (current_node->next!=NULL)
        {
            if(count==pos)
            {
                Node *tempo;
                tempo->prev->next=tempo->next;
                tempo->next->prev=tempo->prev;
                free(tempo);
                break;
            }    
            else
                count+=1;
            
            current_node=current_node->next;
        }
          
    }
    
}

void DoublyList :: Delete(int size)
{
    int pos;
    cout<<"\n Enter position to delete an element in List \n";
    cin>>pos;
    if(pos==0)
    {
        listptr=delete_in_begining(listptr,pos);
    }
    if(pos==size)
    {
        delete_in_begining(listptr,pos);
    }
    else
        delete_in_middle(listptr,pos);
}
int main()
{
    DoublyList dl;
    int k=0;
    cout<<"Welcome to DoublyList by Hridyesh ";
    do
    {
        int ch;
        cout<<" \n 1.Create a DoublyList \n 2.Display a DoublyList \n 3.Inserting Elements \n 4.Deleting Elements \n Other key to exit  \n";

        cin>>ch;

        switch (ch)
        {
            case 1:
                    dl.Create();
                    break;
            case 2:
                    dl.Display();
                    break;
            case 3:
                    dl.Insert(dl.len());
                    break;
            case 4:
                    dl.Delete(dl.len());
                    break;
            default:
                    k=1;
                    break;
        }

    } while (k==0);
    return 0;
}

