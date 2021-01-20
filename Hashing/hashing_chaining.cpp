#include<iostream>
#include <list>
using namespace std;
 
class Hash
{
    int buckets;    
    list<int> *table;// Pointer to an array containing buckets

    public:
        Hash(int V); 
        void insertItem(int x);// inserts a key into hash table    int no;

        
        void deleteItem(int key);// deletes a key from hash table

        int hashFunction(int x) {
             // hash function to map values to key
            return (x % buckets);
        }
 
        void displayHash();
};
 
Hash::Hash(int b)
{
    this->buckets = b;
    table = new list<int>[buckets];
}
 
void Hash::insertItem(int key)
{
    int index = hashFunction(key);
    table[index].push_back(key); 
}
 
void Hash::deleteItem(int key)
{
    // get the hash index of key
    int index = hashFunction(key);
    
    // find the key in (inex)th list
    list <int> :: iterator i;
    for (i = table[index].begin();
             i != table[index].end(); i++) {
      if (*i == key)
        break;
    }
    
    // if key is found in hash table, remove it
    if (i != table[index].end())
      table[index].erase(i);
}
 
// function to display hash table
void Hash::displayHash() {
    for (int i = 0; i < buckets; i++) {
      cout << i;
      for (auto x : table[i])
        cout << " --> " << x;
      cout << endl;
    }
}
 
int main()
{
    int size,no,choice;
    cout<<"Enter number of keys";
    cin>>size;
    int a[size];// array that contains keys to be mapped
    for(int i=0;i<size;i++)
        cin>>a[i];
    cout<<"\n";
    for(int i=0;i<size;i++)
        cout<<a[i]<<"\t";
    
    
    // insert the keys into the hash table
    Hash h(7);   // 7 is count of buckets in
                 // hash table
    for (int i = 0; i < size; i++) 
      h.insertItem(a[i]);  

    do{
		cout<<"Enter your choice\n";
		cout<<" 1-> Delete\n 2-> Display\n  0-> Exit\n";
        cin>>choice;
 
		switch(choice){
			case 1:
				cout<<"Enter number to be deleted";
                cin>>no;
                h.deleteItem(no);
				break;
			case 2:
				h.displayHash();
                break;
			default:
				cout<<"Enter correct choice\n";
				break;
		}
	}while(choice);
 
  return 0;
}