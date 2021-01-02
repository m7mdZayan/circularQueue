#include <iostream>
#include <stdlib.h>
using namespace std;

class Queue{

    int * arr;
    int Size,rear,qfront;

public:

    Queue(int s = 5){
        this->Size = s;
        qfront = rear = -1;
        this->arr = new int[Size];
    }

    int isFull(){ return ( rear == Size - 1 && qfront == 0 || qfront == rear + 1 ); }

    int isEmpty(){ return (qfront == -1); }

    void enqueue(int d){
        if( this->isFull() ){
            cout << "Sorry! the queue is full" << endl;
            return;
        }
        else{
            if (qfront == -1){
                qfront = rear = 0;
            }
            else if (rear == Size - 1){
                rear = 0;
            }
            else{
                rear++;
            }
            arr[rear] = d;
        }
    }

    int dequeue( int & d ){
        if ( this->isEmpty() ){
            cout << "the queue is empty" << endl;
            return 0;
        }
        else{
            d=arr[qfront];
            if ( qfront == rear ) qfront = rear = -1;
            else if ( qfront == Size -1 ) qfront = 0;
            else { qfront++; }
            return 1;
        }
    }

    void display(){
        for (int i = 0; i < Size ; i++){
            cout << arr[i] <<endl;
        }
        cout << "front = " << qfront << "rear = " << rear << endl;
    }

    ~Queue(){
        delete[] arr;
        cout << "Destructor" << endl;
    }
};


int main()
{
    int Size = 0,d = 0,z = 0;
    char ch;
    cout << "please enter number of elements" << endl;
    cin>> Size;
    Queue q1(Size);


    do {
            cout << "Add('Enqueue') \nDequeue \nShowData \nExit \n" <<endl;
            cin >> ch;
        switch ( ch ){
        case 'a':
                cout << "enter the element" << endl;
                cin >> d;
                q1.enqueue(d);
                break;
        case 'd':
            {
                q1.dequeue(z);
                cout << "the deleted element = " << z <<endl;
                break;
            }
        case 's':
            {
                q1.display();
                break;
            }
        case 'e':
            {
                exit(0);
            }
        }

    } while ( ch != 'e' );


    return 0;
}
