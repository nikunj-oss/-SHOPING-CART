#include <bits/stdc++.h>
using namespace std;
class Node1{
    public:
        string cname;
        Node1* link;

};

Node1* front=NULL;
Node1* rear=NULL;

bool isempty(){
    if(front==NULL && rear==NULL){
        return true;

    }
    else{
        return false;

    }
}

void enqueue(string name){
    Node1* temp=new Node1();
    temp->cname=name;
    temp->link=NULL;

    if(front==NULL){
        front=temp;
        rear=temp;
    }
    else{
        rear->link=temp;
        rear=temp;
    }
}

void dequeue(){
    if(isempty()){
        cout<<"queue is empty\n";
    }
    else{
        if(front==rear){
            free(front);
            front=rear=NULL;
        }
        else{
            Node1* ptr=front;
            front=front->link;
            free(ptr);
        }
    }
}

void showfront(){
    if(isempty()){
        cout<<"queue is empty";
    }
    else{
        cout<<"element at front is "<<front->cname<<endl;
    }
}

void qdisplay(){
    if(isempty()){
        cout<<"queue is empty\n";
    }
    else{
        Node1* temp=front;
        while(temp!=NULL){
            cout<<"\t"<<temp->cname<<"\t"<<endl;
            temp=temp->link;
        }
    }
}
