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

class Stack
{
    public:
    node*top,*bottom;
    Stack()
    {
        top=bottom=NULL;
    }
    void push (int n, int counter);
    void pop();
    int isEmpty();
    void Display(Stack s1);

};

void Stack ::push(int x,int counter)
{
    node * newnode= new node(x);
    newnode->next=top;
    top=newnode;
    if(counter==0)
    {
        bottom =newnode ;
        //value of bottomest node , it's not used but if you want to find the value of it then 
    }
}

int Stack ::isEmpty()
{
    return (top==NULL);
}

void Stack::pop()
{
    int n = top->data;
    node *temp=top;
    top=top->next;
    cout<<"value "<<n<<" is deleted ";
    free (temp);
}
void Stack::Display(Stack s1)
{

    node * current_node1=s1.top;
    while (current_node1!=NULL)
    {
        cout<<current_node1->data<<"\t";
        current_node1=current_node1->next;
    }

}

int main() {
   
    Stack s1;
    int exit=0;
    int counter=0;
    cout << "\nStack using Linklist ";
    do {
        int choice;
        cout << "\n1.Push \n2.Pop \n3.Display \n4.Bottom node value \n5.Others to exit";
        cout << "\nEnter Your Choice : ";
        cin>>choice;
        node * bottom_node=s1.bottom;

        switch (choice) {
            case 1:   
                int n;     
                cout << "\nEnter The Value to be pushed : ";
                cin>>n;
                cout<<"Pushed Value  :" << n;
                s1.push(n,counter);
                counter++;
                break;
            case 2:
                if (s1.isEmpty() == 1)
                    cout << "\n Stack is Empty!";
                else {
                    cout << ", Popped Value  :" ;
                    s1.pop();
                }
                break;
            case 3:
                s1.Display(s1);
                break;
            case 4:
                cout<<"bottom node "<<bottom_node->data;
                break;
            case 5:
                exit=1;
                break;
        }
    } while (exit==0);

    return 0;
}
