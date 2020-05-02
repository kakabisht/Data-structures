#include<iostream>
#include<math.h>
#define capacity 10
using namespace std;

class Tree{
    public :
    int A[capacity];
    int currentSize;
    Tree();
    int getLeft(int);
    int getRight(int);
    int getParent(int);
    bool isEmpty();
    int searchkey(int );
    void deletekey( );
    void insertkey(int);
    void printTree();

};


Tree::Tree(){
    currentSize=0;
}
int Tree::getLeft(int index){
    return 2*index+1;
}
int Tree::getRight(int index){
    return 2*index+2;
} 
int Tree::getParent(int index){
    return (2*index-1)/2;
}
bool Tree::isEmpty(){

    if(currentSize==0)
        return true;
    else 
        false;
}
int Tree::searchkey(int key){
    for (int i=0;i<currentSize;i++){
        if(A[i]==key)
            return i;
    }
    return-1;
}

void Tree::deletekey(){
    if(currentSize ==0 )
        return;
    currentSize--;

}

void Tree::insertkey(int key){

    if (currentSize==capacity){
        cout<<"full";
    }
    A[currentSize]=key;
    currentSize++;
}

void Tree::printTree(){
    for(int i=0;i<currentSize;i++){
        cout<<A[i]<<",";
    }
}

int main(){
    Tree T;
    for (int i = 0; i < capacity; i++)
    {
        T.insertkey(i);
    }
    T.printTree();
    T.deletekey();
    cout<<"\n";
    T.printTree();
    cout<<"enter value to be searched"<<endl;
    int val;
    cin>>val;
    T.searchkey(val);

    
}