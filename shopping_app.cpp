#include <bits/stdc++.h>
#include "queue1.h"
#include "stack1.h"
#include <windows.h>
#include <sstream>

using namespace std;

int search(int);
int display();
string check(int);

class Node{
    public:
    int ID;
    string proName;
    double preprice;
    int quantity;
    Node* next;

};

Node* head=NULL;

void beg(){
    system("cls");
    int id,quant;
    string name;
    double pre;
    Node* t=new Node();
    Node* p=head;

    cout<<"\t\tEnter product ID:-";
    cin>>id;
    t->ID=id;
    cout<<"\t\tEnter product name";
    cin>>name;
    t->proName=name;
    cout<<"\t\tEnter product price";
    cin>>pre;
    t->preprice=pre;
    cout<<"\t\tEnter product quantity";
    cin>>quant;
    t->quantity=quant;
    if(head==NULL){
        t->next=head;
        head=t;
    }
    else{
        while(p->next!=NULL){
            p=p->next;
            
        }
        p->next=t;
        t->next=NULL;
    }
    system("cls");
    cout<<"\n\n\t\t\t\tthis product is inserted\n\n\n";
}

int search(int id){
    int count=1;
    Node* p=head;
    while(p!=NULL){
        if(p->ID==id){
            break;
        }
        else{
            count++;
            p=p->next;
        }
    }
    return count;
}

int hashh(int x ,int mod){
    return x%mod;
}

void delPro(){
    system("cls");
    display();
    int id;
    Node* curr=head;
    Node* prev=head;

    cout<<"\n\nEnter ID to delete that product:\n\n";
    cin>>id;


    if(head==NULL){
        system("cls");
        cout<<"List is empty"<<endl;


    }
    int pos=0;
    int count=display();
    pos=search(id);
    if(pos<=count){
        while(curr->ID!=id){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        system("cls");
        cout<<"\n<<item is deleted>>\n";

    }
    else{
        cout<<"\n<<Not Found>>\n\n";
    }

}

void modify(){
    int id;
    double pre;
    string pname;

    int nid;
    int nq;

    if(head==NULL){
        system("cls");
        cout<<"List is empty"<<endl;

    }
    else{
        display();
        cout<<"\n\nEnter ID to modify product name and its price:\n";

    }
    cin>>id;
    Node* curr=head;
    int pos=0;
    int count=display();
    pos=search(id);


    if(pos<=count){
        while(curr->ID!=id){
            curr=curr->next;
        }
        cout<<"\nOld ID : "<<curr->ID<<endl;
        cout<<"\nOld Name : "<<curr->proName<<endl;
        cout<<"\nOld Price : "<<curr->preprice<<endl;
        cout<<"\nOld Quantity : "<<curr->quantity<<endl;

        cout<<endl<<endl;
        cout<<"Enter new ID:";
		cin>>nid;
		curr->ID=nid;
		cout<<"Enter new Name:";
		cin>>pname;
		curr->proName=pname;
		cout<<"Enter new Price:";
		cin>>pre;
		curr->preprice=pre;
		cout<<"Enter new Quantity:";
		cin>>nq;
		curr->quantity=nq;

    }
    else{
        cout<<id<<"is <<Not Found>>\n\n";

    }
}



int display(){
    system("cls");
    int c=0;
    Node* p=head;
    cout<<"Existing products are:\n";
	cout<<"ID\t\tProduct Name\t\tPrice\t\tQuantity\n";
    cout<<"===============================================\n";
    while(p!=NULL){
        cout<<p->ID<<"\t\t"<<p->proName<<"\t\t\t"<<p->preprice<<"\t\t\t"<<check(p->quantity)<<"\n";
        p=p->next;
        c=c+1;
    }
    cout<<"\nTotal products in our store is:"<<c<<"\n\n\n";
    return c;  

}

string check(int quant){
    int a=quant;
    stringstream ss;
    ss<<a;
    string quantity=ss.str();
    if(quant<=0){
        return "out of stock!";
    }
    else{
        return quantity;
    }

}

void buy(){
    system("cls");
    display();
    string products[20];
    int pay=0,no,c=0,price,id,i=1;
    if(head==NULL){
        cout<<"\n<<<<There is no items to buy>>>>\n\n";
    }
    else{
        cout<<"how many items you wanna buy!\n";
        cin>>no;
        int count=display();
        while(i<=no){
            Node* curr=head;
            int quant,cho;  a:
            cout<<"Enter id of the item that you wannna buy:";
            int id,pos=0;
            cin>>id;
            if(id==-1){
                system("cls");
                return;

            }
            pos=search(id);
            if(pos<=count){
                while(curr->ID!=id){
                    curr=curr->next;

                }
                cout<<"how many quantities you want";
                cin>>quant;
                if(curr->quantity<quant){
                    cout<<"\n\n\t\t\t----The Quantity You Entered is not available---"<<endl;
                    cout<<"\n\t\t\t-----(Press -1 for Back to Main Menu)------"<<endl;
                    goto a;
                }

                products[c]=curr->proName;
                c++;

                pay+=curr->preprice*quant;
                i++;
            }
            else{
                cout<<"\n<<<<<<<<<This item is not available in our store at this time>>>>\n\n";

            }


        }
        string customer;
        cout<<"\n\t\tEnter your Name:";
        cin>>customer;
        enqueue(customer);
        system("cls");
        cout<<"\n\n\n\n\t\t\tyou have bought : ";
        for(int i=0;i<no;i++){
            cout<<products[i]<<",";
        }
        price=pay*(0.90);
        cout<<"\n\n Orignal Price : "<<pay;
        cout<<"\n with 10% discount: "<<price<<"\nThank you! for the shopping\n\n";
    }
}

void administrator(){
    system("cls");
    int ch;
    do{
        cout<<"\t\t============================================"<<endl;
        cout<<"\t\t|          Administator Portal              |"<<endl;
        cout<<"\t\t============================================"<<endl;

        cout<<"\t\t     Enter 1 for ADD a new product    "<<endl;
        cout<<"\t\t     Enter 2 to display all products   "<<endl;
        cout<<"\t\t     Enter 3 for MODIFY Existing product"<<endl;
        cout<<"\t\t     Enter 4 for Delete a particular product item"<<endl;
        cout<<"\t\t     Enter 5 for Customers List "<<endl;
        cout<<"\t\t     Enter 6 for Dequeue customer"<<endl;
        cout<<"\t\t     Enter 7 for Generate hash"<<endl;
        cout<<"\t\t     Enter 0 for Main Menu"<<endl;

        cout<<"\nEnter your choice>>>";
        cin>>ch;
        switch(ch){
            case 1:
                beg();
                break;
            case 2:
                system("cls");
                display();
                break;

            case 3:
                modify();
                system("cls");
                break;

            case 4:
                delPro();
                cout<<"\n-------Product is Deleted-------\n";
                break;

            case 5:
                system("cls");
                cout<<"|============CUSTOMERS NAMES LIST==============|"<<endl;
                qdisplay();
                break;

            case 6:
                system("cls");
                cout<<"|============CUSTOMERS NAMES LIST==============|"<<endl;
                dequeue();
                qdisplay();
                break;

            case 7:
                int x,n;
                cout << "Enter element to generate hash = ";
                cin >> x;  cout<<"Of total list number : "; cin>>n;
                cout << "Hash of " << x << " is = " << hashh(x,n);
                break;

            default:
                system("cls");
        }



    }
    while(ch!=0);
}

int main(){
    for(int i=0;i<=51;i++)
     {
     	push(i);
	 }

     int ch;
     while(ch!=3){
        cout<<"\n\t\t|--------<Main Menu>-----------|";
        cout<<"\n\n";
        cout<<"\t\t 1)Administator of Market\n";
        cout<<"\t\t 2)Customer               \n";
        cout<<"\t\t 3)Exit                    \n";

        cout<<"\nEnter your choice>>>";
        cin>>ch;
        switch (ch)
        {
        case 1:
            administrator();
            break;
        case 2:
            cout<<endl<<endl;
            spop();
            system("pause");
            buy();
            break;
        case 3:
            cout<<"\n\n\t\t\t\t\tThank You\t\t\t\t";
            break;
        
        default:
            break;
        }
     }
     return 0;
}