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


class CircularList : public Node
{   
    private:
    Node *listptr,*temp;
    public: 
    CircularList()//
    {
        listptr=NULL;
        temp=NULL;
    }
    void Create();
    void Display();
    void Insert();
    void Delete();

};


void CircularList :: Create()//Same as Linked list
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
            {
                listptr = temp = newnode;
                newnode->next=listptr;
            }    
                
            else
            {
                temp -> next = newnode;//temp currently points towards current block
                newnode->next=listptr;
                temp = temp->next;
            }
        }
}

void CircularList:: Display()
{
    Node * temp = listptr ;         /*    temp points to first node*/
    while (temp->next != listptr) //iterate till it reaches last block
    {
         cout << temp->data << "--->";
         temp = temp->next;         /*    move temp to the next node */
    }
    cout<< "END"; 

}

void CircularList::Insert()
{
    int num,pos;
    cout<<"Enter number to input followed by position";
    cin>>num;
    cin>>pos;
                   
    Node *newnode= new Node (num);
    Node *temp=listptr;//value of head 
    if(pos==1)//first node 
    {
        while (temp->next!=listptr)//to reach last node
            temp=temp->next;
        newnode->next=listptr;
        listptr=newnode;
        temp->next=newnode; //link last to first 
    }
    else
    {
        for (int i = 1; i < pos-1 &&temp->next!=listptr; i++)//reaching till the location to insert ,
            temp=temp->next;
        newnode->next=temp->next;
        temp->next=newnode;
        
    }
    
}

void CircularList :: Delete()
{
    int pos;
    cout<<"Enter  position to delete" ;
    cin>>pos;
    Node *temp= listptr;
    Node *temp1=temp;

    if(pos == 1)
    {
        while (temp1->next!=listptr)
            temp1=temp1->next;
        listptr=listptr->next;
        delete temp;
        temp->next=listptr;
    }
    else
    {
        for (int i=1;i<pos-1 && temp->next !=listptr;i++)
            temp=temp->next;
        temp1=temp->next;
        temp->next=temp1->next;
        delete temp1;
    }
}

int main()
{
    CircularList cl;
    int k=0;
    cout<<"Welcome to Circular List by Hridyesh ";
    do
    {
        int ch;
        cout<<" \n 1.Create a CircularList \n 2.Display a CircularList \n 3.Inserting Elements \n 4.Deleting Elements \n Other key to exit  \n";

        cin>>ch;
        switch (ch)
        {
            case 1:
                    cl.Create();
                    break;
            case 2:
                    cl.Display();
                    break;
            case 3:   
                    cl.Insert();
                    break;
            case 4:
                    cl.Delete();
                    break;
            
            default:
                    k==1;
                    break;
        }
       
    } while (k==0);
    return 0;
}

