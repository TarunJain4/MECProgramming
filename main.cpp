/* 
 * File:   main.cpp
 * Author: EricKamada
 *
 * Created on October 22, 2016, 6:31 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */

class data{
public:
    char weather;
    int priority;
    char type;
};

struct node{
    
    data info;
    node *next;
};



class queue{
//    char* weather; //need to make an linked list of pointers, each pointer will have weather information
    private:
        node *front;
        node *back;
        
    public:
        
        queue();
        void enqueue(int p);
        int dequeue();
        void display();
};

queue :: queue()
{
    back = NULL;
    front =NULL;  
}

void queue :: enqueue(int p)
{
    node *temp= new node;
    temp ->priority = p;
    temp -> next=NULL;
    if (front == NULL)
    {
        temp= front;
    }
    else { back->next= temp;}
    
    back = temp;
}

int queue :: dequeue(){
    
    node *temp = new node;
    int val;
    if(front == NULL){
        cout<<"\nQueue is Emtpty\n";
    }else{
        temp = front;
        val = temp ->priority;
        front = front->next;
        cout<<"The data Dequeued is "<<temp->priority;
        delete temp;
    }
    return val;
}

int queues (char* weather, char* current);
//data in information needs three values , type , priority and message
//the type is used to determine which queue information will go to
int main(int argc, char** argv) {
    char w[5]="bob";
    char q[5]="dan";
    int p=1;
    int x=queues(w,q);
    
    queue b;
    b.enqueue(0);
    int t=b.dequeue();
    cout <<t;
    return 0;
}

int queues (char* weather, char* current)
{
    
    cout << weather;
    return 1;
}



