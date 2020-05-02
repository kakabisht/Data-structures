#include <iostream>
#include <stdlib.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    
    Node()//default constructor
    {
        data=0;
        next=NULL;
    }

    Node(int n)//constructor
    {
        data=n;
        next=NULL;
    }
};


class LinkedList : public Node
{   
    private:
    Node *listptr,*temp;
    //ptr is used to point at the current node and temp is used for temporary usages such as iterations , data storage for a small time.
    public: 
    LinkedList()//
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


void LinkedList :: Create()
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
                temp = temp->next;
            }
        }
}

int LinkedList :: Isempty()
{
    if(listptr == NULL)
        return 0;
    else
        return 1;
    
}

void LinkedList:: Display()
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
            current_node->next=newnode;
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
}

void LinkedList::Insert(int size)
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

int LinkedList ::len()
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
                tempo=current_node->next;
                current_node->next=current_node->next->next;
                free(tempo);
                break;
            }    
            else
                count+=1;
            
            current_node=current_node->next;
        }
          
    }
    
}

void delete_by_value(Node *lp, int val){
    int find=0;
    Node *current_node=lp;
     while (current_node->next!=NULL)
    {
        if (current_node->next->data==val)
        {
            Node *tempo;
            tempo==current_node->next;
            current_node->next=current_node->next->next;
            free(tempo);
            find=1;
        }
        current_node=current_node->next;

    }
    if(find ==0)
        cout<<"\n Value Not present";

}

void LinkedList :: Delete(int size)
{
    int ch;
    cout<<"You want to delete an element on the \n 1.basis of position \n 2.value ";
    cin>>ch;
    if (ch==1)
    {
        int pos;
        cout<<"\n Enter position to delete an element in List \n";
        cin>>pos;
        if (pos==0)
        {
            listptr=delete_in_begining(listptr,pos);
        }
        if (pos==size)
        {
            delete_in_begining(listptr,pos);
        }
        else
            delete_in_middle(listptr,pos);
    }
    if (ch==2)
    {
        int val;
        cout<<"\n Enter value to delete  in List \n";
        cin>>val;
        delete_by_value(listptr,val);
        
    }
}

void LinkedList :: Search()
{
    int val;
    cout<<"\n Enter  element to search  in List \n";
    cin>>val;
    int find=0;
    int count=0;
    Node *current_node=listptr;
    while (current_node->next!=NULL)
    {
        if (current_node->data==val)
        {
            find=1;
            break;
        }
        count+=1;
        current_node=current_node->next;

    }
    if(find ==1)
        cout<<"\n Value present at "<<count;
    else
        cout<<"\n Value not present";
}
void LinkedList ::Reverse(){
    Node * forward, *curr, *back; 
    forward    = listptr; 
    curr =    NULL;
    back=NULL;
    while ( forward != NULL )
    {    
        back = curr;
        curr = forward;
        forward = forward->next;
        curr-> next = back;
    }
     listptr= curr;
}
int main()
{
    LinkedList lk;
    int k=0;
    cout<<"Welcome to Linked List by Hridyesh ";
    do
    {
        int ch;
        cout<<"Press \n 1.Create a Linklist \n 2.Display a Linklist \n 3.Length of LinkList \n 4.Inserting Elements \n 5.Deleting Elements \n 6.Search Value \n 7.Reverse the list \n";

        cin>>ch;

        switch (ch)
        {
            case 1:
                    lk.Create();
                    break;
            case 2:
                    lk.Display();
                    break;
            case 3:
                    cout<<"Length of Link List is"<<lk.len();
                    break;
            case 4:
                    lk.Insert(lk.len());
                    break;
            case 5:
                    lk.Delete(lk.len());
                    break;
            case 6:
                    lk.Search();
                    break;
            case 7:
                    lk.Reverse();
                    break;

            default:
                    break;
        }
        cout<<"\n To continue press 0 \n";
        cin>>k;  

    } while (k==0);
    return 0;
}

