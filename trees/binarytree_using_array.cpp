#include<iostream>
#include<math.h>
using namespace std;
void input(int binarytree[],int size){
     for (int i = 0; i < size; i++)
    {
        if (i==0)
        {
            cout<<"\nenter value of root node";
            cin>>binarytree[i];
        }
        else if (i%2!=0)
        {
            cout<<"left node";
            cin>>binarytree[i];
        }
        else if (i%2==0)
        {
            cout<<"right node";
            cin>>binarytree[i];
        }
        

    } 
}
void insert(int binarytree[],int size){
    int pos;
    cout<<"enter the position to enter info in";
    cin>>pos;
     for (int i = 0; i < size; i++)
    {
        if (i==pos){
            cout<<"enter the new value at pos"<<pos;
            cin>>binarytree[i];
        }
    }

}
void del(int binarytree[],int size){
    int pos;
    cout<<"enter the position to delete info in";
    cin>>pos;
     for (int i = 0; i < size; i++)
    {
        if (i==pos){
            cout<<"at pos"<<pos;
            binarytree[i]=0;
        }
    }

}
void display(int binarytree[], int size){
     for (int i = 0; i < size; i++)
    {
        if (i==0){
            cout<<"\tRoot"<<binarytree[i];
        }
        if(i==1){
            cout<<"\tleft node"<<binarytree[i];
        }
        else if(i%2==0 && i>0){
            cout<<"\tright node"<<binarytree[i];
        }
        else if(i%2!=0 ){
            cout<<"\nbelonging to parent "<<binarytree[i-2];
            cout<<"\tleft node"<<binarytree[i];
        }
       
        
    }
} 
int main(){
    cout<<"Do read the condtion's for the random access to any node for further classification";
    cout<<"\nenter depth of tree you want ";
    int k;
    cin>>k;
    int size =pow(2,k)-1;
    int binarytree[ ] = { 0 };  // results in [0, 0, 0, 0, 0]
    display(binarytree,size);
    input(binarytree,size);

    int ch=0,choice=0;
    do
    {
        cout<<"\nOptions for binary tree are \n1.Insert \n2.Delete \n3.Display \n4.To exit";
        cin>>choice;
        switch (choice)
        {
        case 1:
            insert(binarytree,size);
            break;
        case 2 :
            del(binarytree,size);
            break;
        case 3:
            display(binarytree,size);
            break;
        case 4:
            ch=1;
            break;
        default:
            cout<<"\nEnter correct value";
            break;
        }
    } while (ch!=0);
    
    
}