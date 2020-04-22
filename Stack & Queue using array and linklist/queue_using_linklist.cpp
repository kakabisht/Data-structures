#include<iostream>
#include<stdlib.h>

using namespace std;

class node 
{
    public:
    int data;
    node* next;
    node(int n)
    {
        data=n;
        next=NULL;
    }

};

class Queue
{
    public:
    node*front,*rear;
    Queue()
    {
        front=rear=NULL;
    }
    void enque (int n);
    void deque();
    int isEmpty();
    void Display(Queue q1);

};

int Queue ::isEmpty()
{
    return (front==NULL);
}


void Queue :: enque(int x)
{
    node * newnode= new node(x);
    if(isEmpty()!=0)
        front=rear=newnode;
    else
    {
        rear->next=newnode;
        rear=newnode;    
    }
}


void Queue::deque()
{
    int n = front->data;
    node *temp=front;
    front=front->next;
    cout<<"value "<<n<<" is deleted ";
    free (temp);
    if(front==NULL)
        rear=front;
}
void Queue::Display(Queue q1)
{

    node * current_node1=q1.front;
    while (current_node1!=NULL)
    {
        cout<<current_node1->data<<"\t";
        current_node1=current_node1->next;
    }

}

int main() {
   
    Queue q1;
    int exit=0;
    int counter=0;
    cout << "\nStack using Linklist ";
    do {
        int choice;
        cout << "\n1.Enque \n2.Deque \n3.Display \n4.First and rear node value \n5.Others to exit";
        cout << "\nEnter Your Choice : ";
        cin>>choice;
        node * rear_node=q1.rear;
        node * front_node=q1.front;
        
        switch (choice) {
            case 1:   
                int n;     
                cout << "\nEnter The Value to be pushed : ";
                cin>>n;
                cout<<"Pushed Value  :" << n;
                q1.enque(n);
                break;
            case 2:
                if (q1.isEmpty() == 1)
                    cout << "\n Queue is Empty!";
                else {
                    cout << ", Popped Value  :" ;
                    q1.deque();
                }
                break;
            case 3:
                q1.Display(q1);
                break;
            case 4:
              
                cout<<"rear node "<<rear_node->data;
                cout<<"front node "<<front_node->data;
                break;
            case 5:
                exit=1;
                break;
        }
    } while (exit==0);

    return 0;
}
