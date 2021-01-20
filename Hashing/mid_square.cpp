#include <iostream>
using namespace std;

long getHash(int x){
   
    long long key = x;
//     Using the current time to form a key
    key = key * key;
    key = key / 10000;
    key = key % 100000000;
    return key;
}
int main(){
    cout<<"Enter Value of X : ";
    int x; cin>>x;
    cout << "Hash Address : " << getHash(x) << endl;
    return 0;
}