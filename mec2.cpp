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
    char* message;
    bool priority;
    char type;
    bool getpriority(data x);
};



struct node{
    
    char message;
    node *next;
};

bool data :: getpriority(data x)
{
    bool b=x.priority;
    return priority;
}

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
    
    char m1[30]="hey its sunny";
    char m2[30]="currents moving south 15km/h";
    data w;
    w.type ='w';    //represents  weather info
    w.message=m1; 
    w.priority=0;
    
    data c;
    w.type = 'c';       //represents current info
    w.message=m2;
    w.priority=0;
    
    int p=1;
    //int x=queues(w,q);
    
    return 0;
}


int queues (data info)
{
    queue w;
    queue c;
    
    char* mess=info.message;
    
    if(info.type == 'w') //then it is weather information
    {
        w.enqueue(*mess);
    }
    else
    {
        c.enqueue(*mess);
    }
        
    //cout << weather;
    return 1;
}



