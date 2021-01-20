#include<stdio.h>
#include<iostream>
#include<limits.h>
// defining Min and Max values of INT
 
using namespace std;
 
void insert(int ary[],int hFn, int size){
    int element,pos,n=0;
 
	cout<<"Enter key element to insert\n";
    cin>>element;
 
	pos = element%hFn;
 
	while(ary[pos]!= INT_MIN) {  // INT_MIN and INT_MAX indicates that cell is empty. So if cell is empty loop will break and goto bottom of the loop to insert element
		if(ary[pos]== INT_MAX)
            break;
		pos = (pos+1)%hFn;
		n++;
		if(n==size)
		break;      // If table is full we should break, if not check this, loop will go to infinite loop.
	}
 
	if(n==size)
        cout<<"Hash table was full of elements \n";
	else
        ary[pos] = element;    //Inserting element
}
 
void del(int ary[],int hFn,int size){
	/*
	very careful observation required while deleting. To understand code of this delete function see the note at end of the program
	*/
	int element,n=0,pos;
 
	cout<<"Enter element to delete\n";
    cin>>element;
 
	pos = element%hFn;
 
	while(n++ != size){
		if(ary[pos]==INT_MIN){
			cout<<"Element not found in hash table\n";
			break;
		}
		else if(ary[pos]==element){
			ary[pos]=INT_MAX;
			cout<<"Element deleted\n\n";
			break;
		}
		else{
			pos = (pos+1) % hFn;
		}
	}
	if(--n==size)
        cout<<"Element not found in hash table\n";
}
 
void search(int ary[],int hFn,int size){
	int element,pos,n=0;
 
	cout<<"Enter element to delete\n";
    cin>>element;
 
	pos = element%hFn;
 
	while(n++ != size){
		if(ary[pos]==element){
			cout<<"Element found at index %d\n"<<pos;
			break;
		}
		else
            if(ary[pos]==INT_MAX ||ary[pos]!=INT_MIN)
                pos = (pos+1) %hFn;
	}
	if(--n==size) cout<<"Element not found in hash table\n";
}
 
void display(int ary[],int size){
	int i;
 
	cout<<"Index\tValue\n";
 
	for(i=0;i<size;i++)
        cout<<i<<"\t"<<ary[i]<<"\n";
}
int main(){
	int size,hFn,i,choice;
 
	cout<<"Enter size of hash table\n";
    cin>>size;
 
	int ary[size];
 
	cout<<"Enter hash function [mod hFn ]\n";
    cin>>hFn;
 
	for(i=0;i<size;i++)
        ary[i]=INT_MIN; //Assigning INT_MIN indicates that cell is empty
 
	do{
		cout<<"Enter your choice\n";
		cout<<" 1-> Insert\n 2-> Delete\n 3-> Display\n 4-> Searching\n 0-> Exit\n";
        cin>>choice;
 
		switch(choice){
			case 1:
				insert(ary,hFn,size);
				break;
			case 2:
				del(ary,hFn,size);
				break;
			case 3:
				display(ary,size);
				break;
			case 4:
				search(ary,hFn,size);
				break;
			default:
				cout<<"Enter correct choice\n";
				break;
		}
	}while(choice);
 
	return 0;
}