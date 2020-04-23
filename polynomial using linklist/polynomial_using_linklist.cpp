#include <iostream>
#include <stdlib.h>
using namespace std;

class PolyNode
{
    public:
    float coef;
    int exp;
    PolyNode * next; 
    PolyNode() // constructor        
    {    
        coef = 0; 
        exp = 0; 
        next=NULL; 
    }
    PolyNode(double c, int e) // constructor        
    {    
        coef = c; 
        exp = e; 
        next=NULL; 
    }
};

class Linkedlist : public PolyNode
{
    PolyNode *listptr,*temp;
    public:
    Linkedlist()//
    {
        listptr=NULL;
        temp=NULL;
        //initializing the values to NULL , to avoid segmentation error
    }
    int Isempty();
    void Create();
    void Create(int num, int pow);
    void Addpolly( Linkedlist l1, Linkedlist l2,Linkedlist l3);
    void Display();
    void DeletePolly(Linkedlist &l1,Linkedlist &l2);
    
};
int Linkedlist :: Isempty()
{
    if(listptr == NULL)
        return 0;
    else
        return 1;
    
}

void Linkedlist :: Create()
{
	int n, i, num, pow;
	cout << "Enter number of terms: ";
	cin >> n;
	for(i=0;i<n;i++){
		cout << "Please enter coeffecient and power  with a space: ";
		cin >> num;
		cin >> pow;
	    PolyNode *newnode = new PolyNode(num,pow);
	    if(listptr == NULL)
	        listptr = temp = newnode;
	    else
	    {
	        temp -> next = newnode;//temp currently points towards current block
	        temp = temp->next;
	    }
	}
}

void Linkedlist :: Create(int num, int pow)
{
    PolyNode *newnode = new PolyNode(num,pow);
    if(listptr == NULL)
        listptr = temp = newnode;
    else
    {
        temp -> next = newnode;//temp currently points towards current block
        temp = temp->next;
    }
}

void Linkedlist :: Display()
{
    PolyNode * current_node = listptr ;         /*    temp points to first node*/
    if ( Isempty()==0 )
    {
            cout<<"List is empty";
    }
    else
    {
       cout<<"\n";
        while (current_node->next != NULL) //iterate till it reaches last block
        {
            cout << current_node->coef <<"x^"<<current_node->exp<< " + ";
            current_node = current_node->next;         /*    move temp to the next node */
        }
        cout << current_node->coef <<"x^"<<current_node->exp<< "\n";
    }

}
void Linkedlist::Addpolly(Linkedlist lk1, Linkedlist lk2,Linkedlist lk3)
{
    PolyNode * current_node1=lk1.listptr;
    PolyNode * current_node2=lk2.listptr;

    //copy elements of first Polynode
    while (current_node1!=NULL)
    {
    	lk3.Create(current_node1->coef, current_node1->exp);
        current_node1=current_node1->next;        
    }
    //copy elements of second Polynode
    while (current_node2!=NULL)
    {
    	lk3.Create(current_node2->coef, current_node2->exp);
        current_node2=current_node2->next;
    }
	lk3.Display();
    PolyNode * c3_1=lk3.listptr;
	while(c3_1!=NULL){
	    PolyNode * c3_2_prev=c3_1;
	    PolyNode * c3_2=c3_1->next;
		while(c3_2!=NULL){
			if(c3_1->exp == c3_2->exp){
				c3_1->coef += c3_2->coef;  
				c3_2_prev->next = c3_2->next;
			}else{
				c3_2_prev=c3_2;
			}
			c3_2=c3_2->next;
		}
		c3_1=c3_1->next;
	}
	lk3.Display();
}

int main()
{
    Linkedlist lk1,lk2,lk3;
    int k=0;
    cout<<"Welcome to Polynomial Using Linklist by Hridyesh ";
    do
    {
        int ch;
        cout<<"Press \n 1.Create  Polynomial's \n 2.Add Polynomials \n 3.Display polynomial's \n 4.To close  \n";

        cin>>ch;

        switch (ch)
        {
            case 1:
                    lk1.Create();
                    lk2.Create();
                    break;
            case 2:
                    lk3.Addpolly(lk1,lk2,lk3);
					lk3.Display();
                    break;
            case 3:
                    lk1.Display();
                    lk2.Display();
                    break;
            case 4:
                    k==1;
                    break;
            default:
                    cout<<"enter correct choice";
                    break;
        }

    } while (k==0);
    return 0;
}