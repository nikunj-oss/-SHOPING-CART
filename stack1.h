#include <bits/stdc++.h>
using namespace std;

class stack1{
    public:
    int data;
    stack1* link;
};

stack1* top;


void push(int data){
    stack1* temp;
    temp=new stack1();
    if(!temp){
        cout<<"\nheap overflow";
        exit(1);
    }
    temp->data=data;
    temp->link=top;
    top=temp;
}

int isEmpty(){
    return top==NULL;
}

int peek(){
    if(!isEmpty()){
        return top->data;

    }
    else{
        exit(1);
    }
}


void spop(){
    stack1* temp;
    if (top == NULL) { 
		cout << "\nStack Underflow" << endl; 
		exit(1); 
	} 
    else{
        temp=top;
        top=top->link;
        temp->link=NULL;

        free(temp);
    }
        cout<<"Your Trolli No is :"<<top->data<<endl; 
    	cout<<"                  ___"<<endl;
	    cout<<"                 /  |"<<endl;
	    cout<<"  ______________/   --"<<endl;
	    cout<<" |___/__ /___/_|     "<<endl;     
	    cout<<" |__/___/___/__|     "<<endl;     
	    cout<<" |_/___/___/___|     "<<endl;     
	    cout<<"    _______/         "<<endl;
	    cout<<"     O   O           "<<endl;
}

void sdisplay(){
    stack1* temp;
    if(top==NULL){
        cout<<"\nstack underflow";
        exit(1);
    }
    else{
        temp=top;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->link;
        }
    }
}


