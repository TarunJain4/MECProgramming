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
    char *message;
    bool priority;
    char type;
    
    bool getpriority();
};

data :: getpriority()
{
    return priority;
}

struct node{
    
    char message;
    node *next;
};

class queue{
    private:
        node *front;
        node *back;
        
    public:
        
        queue();
        void enqueue(char p);
        int dequeue();
        void display();
};

queue :: queue()
{
    back = NULL;
    front =NULL;  
}

void queue :: enqueue(char message)
{
    node *temp= new node;
    temp ->message = message;
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
    char val;
    if(front == NULL){
        cout<<"\nQueue is Emtpty\n";
    }else{
        temp = front;
        val = temp ->message;
        front = front->next;
        cout<<"The data Dequeued is "<<temp->message;
        delete temp;
    }
    return val;
}

int queues (data info);
//data in information needs three values , type , priority and message
//the type is used to determine which queue information will go to
int main(int argc, char** argv) {
    
    data w;
    w.type ='w';    //represents  weather info
    w.message= "hey its sunny";
    w.priority=0;
    
    data c;
    w.type = 'c';       //represents current info
    w.message="currents moving south 15km/h";
    w.priority=0;
    
    int p=1;
    //int x=queues(w,q);
    
    return 0;
}
    queue w;
    queue c;

int queues (data info)
{

    
    if(info.type == 'w') //then it is weather information
    {
        w.enqueue(info.message);
    }
    else
    {
        c.enqueue(info.message);
    }
        
    //cout << weather;
    return 1;
}



