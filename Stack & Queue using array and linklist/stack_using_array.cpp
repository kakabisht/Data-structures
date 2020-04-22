#include<iostream>
#include<stdlib.h>

using namespace std;

int main() {
    int item, choice, i;
    int stack[10];
    int top = 0;//we start from the zero index ,
    int exit = 0;//for the do-while condition 

    cout << "\nStack using array ";
    do {
        cout << "\n1.Push \n2.Pop \n3.Display \nOthers to exit";
        cout << "\nEnter Your Choice : ";
        cin>>choice;
        switch (choice) {
            case 1:
                if (top == 10)
                    cout << "\n Stack is Full!";
                else {
                    cout << "\nEnter The Value to be pushed : ";
                    cin>>item;
                    cout << "\n Position : " << top << ", Pushed Value  :" << item;
                    stack[top++] = item;
                }
                break;
            case 2:
                if (top == 0)
                    cout << "\n Stack is Empty!";
                else {
                    --top;
                    cout << "\n Position : " << top << ", Popped Value  :" << stack[top];
                }
                break;
            case 3:
                cout << "\n Stack Size : " << top;
                for (i = (top - 1); i >= 0; i--)
                    cout << "\n Position : " << i << ", Value  :" << stack[i];
                break;
            default:
                exit = 1;
                break;
        }
    } while (exit==0);

    return 0;
}
