#include<iostream>
using namespace std;

int size=0;

class node{

    public:
     int data;
     node* next;

     node(int data){
         this->data = data;
     }
};

void removeloop(node* slow, node* fast){
    int c=0;
    node* prev = fast;
    while(slow != fast){

        slow = slow->next;
        prev = fast;
        fast = fast->next;
        c++;
    }
    cout<<c <<endl;

    cout<<fast->data<<endl;
    prev->next = NULL;
}

bool detectcycle(node* n){
     node* fast= n;
     node* slow = n;
     bool res = false;

     while(fast != NULL && fast->next != NULL){
         slow= slow->next;
         fast = fast->next->next;
         
         if(fast == slow){
             removeloop(n, fast) ; // when they meet at first put the sp to the head of the list
                     // do this in the remove fun  and move the fp in the loop only
             res= true;
             return res;
         }
     }
        return res;
} 

 void displaynode(node* n){
   for(node* temp =n; temp != NULL; temp = temp->next){
       cout<<temp->data <<" -> ";
   }
   cout<<endl;
 }  

     

int main(){
node* n1 = new node(1);
node* n2 = new node(2);
node* n3 = new node(3);
node* n4 = new node(4);
node* n5 = new node(5);
node* n6 = new node(6);
node* n7 = new node(7);
node* n8 = new node(8);
node* n9 = new node(9);
node* n10 = new node(10);

n1->next = n2;
n2->next = n3;
n3->next = n4;
n4->next = n5;
n5->next = n6;
n6->next = n7;
n7->next = n8;
n8->next = n9;
n9->next = n10;
n10->next = n5;

// displaynode(n1);
bool res = detectcycle(n1);
cout<<res;
displaynode(n1);

}