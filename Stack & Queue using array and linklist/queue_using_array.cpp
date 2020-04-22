#include <iostream>
#include<stdlib.h>


using namespace std;

int main() {
    int item, choice, i;
    int queue[10];
    int rear = 0;///rear index of queue
    int front = 0;//front index of queue 
    int exit = 0;

    cout << "\n Queue using array";
    do {
        cout << "\n1.Insert \n2.Remove \n3.Display \nOthers to exit";
        cout << "\nEnter Your Choice : ";
        cin>>choice;
        switch (choice) {
            case 1:
                if (rear == 10)
                    cout << "\nQueue Reached Max!!";
                else {
                    cout << "\nEnter The Value to be Insert : ";
                    cin>>item;
                    cout << "\nPosition : " << rear + 1 << " , Insert Value  : " << item;
                    queue[rear++] = item;
                }
                break;
            case 2:
                if (front == rear)
                    cout << "\n## Queue is Empty!";
                else {
                    cout << "\nPosition : " << front << " , Remove Value  :" << queue[front];
                    front++;
                }
                break;
            case 3:
                cout << "\nQueue Size : " << (rear - front);
                for (i = front; i < rear; i++)
                    cout << "\nPosition : " << i << " , Value  : " << queue[i];
                break;
            default:
                exit = 1;
                break;
        }
    } while (exit!=0);

    return 0;
}