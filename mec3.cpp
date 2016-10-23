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

//the type value is used to determine which queue information will go to

class data{         //data has three values , information type , priority and message to be broadcast
public:
    char* message;      // this is what will be queued and eventually broadcast out
    bool priority;      // this determines if the message is urgent or not
    char type;          // the information can in regards to weather ('w') or current ('w')
    bool getpriority(data x); // method used to get the priority of the selected data class
};



struct node{    // queue will be implemented using linked lists
    
    char message;
    node *next;
};

bool data :: getpriority(data x)    // returns priority of data class x
{
    bool b=x.priority;
    return priority;
}

// queue was implemented following the template found in the link below
// http://code.runnable.com/U5n_ei3uhWBxOqiT/queue-implementation-using-linked-list-for-c%2B%2B

class queue{
    private:
        node *front;
        node *back;
        
    public:
        
        queue();
        void enqueue(char p);
        int dequeue();
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

int queues (data info, queue w, queue c); //initialization for queue

int main() {
    
    // data values w and c are test variables used to verify code worked as expected
    
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
    
    
    queue weather;
    queue current;
    
    
    int p=1;
    int x=queues(w, weather,current);
    
    return 0;
}

int queues (data info, queue w, queue c)  //one queue for weather and one queue for current
{

    
    char* mess=info.message;
    
    if(info.type == 'w') //type is used here to determine which queue message will be inserted into
    {
        w.enqueue(*mess); 
    }
                // queues will fill up with messages to be sent 
    else
    {
        c.enqueue(*mess);
    }
    
    return info.priority; // the priority of the info will be returned
}



