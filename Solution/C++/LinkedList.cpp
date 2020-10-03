#include<bits/stdc++.h>

using namespace std;

typedef uintptr_t ut;

class Linkedlist {
    class Node{
        public:
          int data;
          Node *next;
    };

    Node* head;
    Node* tail;
    int size ;
    Node* rdrleft; // used as the left for reverse data rec 
    Node* pallin_left; // used to check pallindrome
    Node* fleft; // used for fold left
    // unordered_set <int> seen; // container for storing elements for remove duplicates (unsorted)

     Node* midnode(Node* sp, Node* ep){

       Node* fast = sp;
       Node* slow = sp;

       while(fast != ep && fast->next !=ep){
            slow = slow->next;
            fast= fast->next->next;
       }
       return slow;
   }

    Linkedlist* mergesort(Node * sp, Node* ep){
        // sp = this->head;
        // ep = this->tail;

        // base - mergetwosortedlists
        if(sp == ep){
            Linkedlist* br = new Linkedlist();
            br->addlast(sp->data);
            return br;
        }

        Node* mid = midnode(sp, ep);
        Linkedlist* fhsorted = mergesort(sp, mid);
        Linkedlist* shsorted = mergesort(mid->next, ep);

        Linkedlist* msr = new Linkedlist();
        msr->mergetwosortedlists(*fhsorted, *shsorted);

        return msr;


      /*
        Linkedlist* l3 = new Linkedlist();
        Linkedlist* l4 = new Linkedlist();
        Node* l3temp = l3->head;

        Node* mid = this->midnode(sp, ep); // this will get the mid of the this list

        mergesort(sp, mid);
        if(sp->data > mid->data){
            l3->addlast(sp->data);
            l3->addlast(mid->data);
            l3temp = l3temp->next;
        }
        else{
            l3->addlast(mid->data);
            l3->addlast(sp->data);
            l3temp = l3temp->next;
        }

        mergesort(mid->next, ep);
        if(mid->next->data > ep->data){
            l3->addlast(mid->next->data);
            l3->addlast(ep->data);
            l3temp = l3temp->next;
        }
        else{
            l3->addlast(ep->data);
            l3->addlast(mid->next->data); 
            l3temp = l3temp->next;
        }
      return l3;
      */
    }

  
   Node* midnodemy(Node* sp,  Node* ep){
       // sp - start pointer, ep - end pointer
       // this function will return mid element

       //fast pointer - fp will move by with multiple of 2 and sow pointer will move by 1 at a time 
    Node* rNode=NULL;
     if(size%2 == 0){
         for(int i=0; i<size; i++){
             sp = sp->next->next;
             ep = ep->next;

             if(sp == NULL || sp->next==NULL ){
                 rNode= ep;
                 break;
             }
         } 
     }
     else{
         for(int i=0; i<size; i++){
             sp= sp->next->next;
             ep = ep->next;

             if(sp == NULL || sp->next==NULL ){
                     rNode= ep;
                 break;
             }
         }
     }

     return rNode;
     
   }
    

    void fold(Node* right, int floor){ // 10-20-30-40-50-60-70  ---> 10-70-20-60-30-50-40
        if(right == NULL){
            return;
        }

         fold(right->next, floor+1);
  
        if(floor> size/2){     // for odd list 
            right->next = fleft->next;   // fleft = 10 , temp = 20
            fleft->next = right;       // 10-70
            fleft = right->next;        // 10-70-20
        }
        else if(floor==size/2){
             tail = right;
             tail->next = NULL;
            }
        
    }

    void foldP(Node** left, Node* right, int floor){  // using pointer to pointer via left
        if(right == NULL){
            return;
        }

        foldP(left, right->next, floor+1);
          
        if(floor>size/2){
            
            right->next = (*left)->next;
            (*left)->next = right;
            (*left)=right->next;
        }
        else if(floor == size/2){
            tail = right;
            tail->next = NULL;
        }
    }

    void unfold(Node* t1){
        if(t1->next == NULL){
            head = tail = t1;
            return;
        }
        else if(t1->next->next == NULL){
            head = t1;
            tail = t1->next;
            return;
        }

        Node* t2 = t1->next;
          unfold(t1->next->next);
        
        

        t1->next = head;
        tail->next=t2;
        head=t1;
        tail=t2;
        tail->next = NULL;
    }

    bool pallindrome(Node* right, int floor){
        if(right == NULL){
            return true;
        }
        
            bool ans = pallindrome(right->next, floor +1);
        
        if ( ans == false){
            return false;
        }
        if(floor>= size/2){

            int temp = pallin_left->data;
            if(temp == right->data){
                return true;
            }
            else{
                return false;
            }
        }
        return true;
    }

    void rdr(Node* right, int floor){
        if(right == NULL){
            return;
        }

        rdr(right->next, floor+1 );

        if(floor>= size/2){ // we'll make the swap till the mid only
           int temp = rdrleft->data;
           rdrleft->data = right->data;
           right->data = temp;

           rdrleft = rdrleft->next;

        }
    }

    void rpr(Node* node){  // pointer reverse recursively
        
        // Node* first = node;
        // Node* rest = first->next;

        // if(first->next == NULL){
        //     return;
        // }
        // if(rest->next == NULL){
        //     return;
        // }
        

        // rpr(rest);
        // first->next->next = first;

        // first->next = NULL;

        // node = rest;

        if(node == tail){
            return;
        }
        rpr(node->next);
        node->next->next = node;
    }

    void displayrev(Node* node){  // displaying the data reverse without actually reversing it
        
        if(node == NULL){
            return;
        }
        displayrev(node->next);
        cout<<node->data<<"->";
    }

    void handleAddSizeWhen0(int data){
        Node* nn= new Node();
        nn->data = data;
        nn->next = NULL;

        head = tail = nn;

        size =1;
    }

    int handleremovalwhensize1(){
        int temp = head->data;
        delete head;

        head = tail = NULL;
        size= 0;

        return temp;
        // cout<<temp;
    }

    Node* getnodeat(int idx){
        Node* temp =head;
        for(int i=0; i<idx; i++){
            temp = temp->next;   /// going to an certain index -- > mention as idx
        }
        return temp;
    }

    bool ispallin(Node** left, Node* right)
    {
        /* stop recursion when right becomes NULL */
        if(right == NULL) 
        return true;

        /* If sub-list is not palindrome then no need to
        check for current left and right, return false */
        bool ans = ispallin(left , right->next);

        if(ans == false) 
        return false;

        // checking if the values matched  /* Check values at current left and right */
        bool isp = (right->data == (*left)->data);

        // move left to the next node
        *left = (*left)->next;

        return isp;
    }




    public:
      
       Linkedlist(){   ///  constructor
           head = tail = NULL;
           size =0;
       }

       ~Linkedlist(){  // destructor

           Node* temp = head;

           for(int i=0; i<size; i++){
               Node* rem = temp ;
               temp = temp->next;
               delete rem;
           }
       }

       void clear(Linkedlist* l){
           l->head = NULL;
           l->tail = NULL;
           l->size = 0;
       }

       void addfirst(int data){
           if(size == 0){
               handleAddSizeWhen0(data);
            }
        else{

            //space allocation
            Node* nn = new Node();
            nn->data = data;   // created node get the data
            nn->next = NULL;    // initially it is having null in the next

            nn->next = head;  // as we're nn is pointing to the next as head in the front

            head = nn;
            size++;
        }
       }

       void displayrev(){
           displayrev(head);
       }

       void addlast(int data){
              if(size == 0){
               handleAddSizeWhen0(data);
            }
        else{

            //space allocation
            Node* nn = new Node();
            nn->data = data;
            nn->next = NULL;

            tail->next = nn;

            tail = nn;
            size++;
        }
       }

       int getfirst(){

          if(size==0){   // no node present
              return -1;
          }
          else{
              return head->data;
          }
       }

       void display(){

           Node* temp = head;
           for(int i=0; i<size; i++){
                  cout<< temp->data<<"->";
                  temp = temp->next;
           }
           cout<<endl;
       }

       bool isempty( ){
           return size == 0;
       }

       int getlast(){
           if(size== 0){
               return -1;
           }
           else{
               return tail->data;
           }
       }

       int removefirst(){

           if(size == 0){
               return -1;
           }
           else if(size == 1){
               return handleremovalwhensize1();
           }
           else{
           int temp = head->data;
           Node* second = head->next;

           delete head;

           head= second;
           size--;

           return temp;
           }  
       }

       int removelast(){
            if(size == 0){
               return -1;
           }
           else if(size == 1){
            //    cout<<handleremovalwhensize1();
               return handleremovalwhensize1();
           }
           else{
           Node* temp = getnodeat(size-1);
           temp->next = NULL;

           int s= tail->data;

           delete tail;

           tail = temp;
           size--;
           return s;
           } 
       }

       int removeatidx(int idx){
           if(idx == 0){
               return removefirst();
           }
           else if(idx == size-1){
               return removelast();
           }
           else{
               Node* nm1 = getnodeat(idx-1);
               Node* n = nm1->next;
               Node* np1 = n->next;

               int temp = n->data;

               nm1->next = np1;
               size--;
               delete n;
               return temp;
               
           }
       }

       int getat(int idx){
           if(idx<0 || idx>=size ){
               cout<<"idx out of bound";
               return -1;
           }
           else{
               Node* temp = getnodeat(idx);
               return temp->data;
           }
       }

       void addatidx(int idx, int data){
           if(idx == 0){
               addfirst(data);
           }
           else if(idx == size){
               addlast(data);
           }
           else{
               Node* nm1 = getnodeat(idx -1);
               Node* np1 = nm1->next;

               Node* n = new Node();
               n->data = data;

               nm1->next = n;
               n->next = np1;
               size++;
           }
       }

       void reversepointeri()
       {
           Node* cur = head;
           Node* prev = NULL;
           Node* nex = NULL;

           while(cur != NULL)
           {
               // store currents's next val in nex
               nex = cur->next;

               //change direction of pointer
               cur->next = prev;

               // move prev and cur by 1 step
               prev = cur;
               cur = nex;
           }
           head = prev;
       }

    //    void reversepointeri(){  // reverse pointer iteratively
    //        Node* cur = head;
    //        Node* nex = head->next;
    //        Node* prev = NULL;

    //        while(cur->next != NULL){
               
    //            cur->next = prev;

    //            prev = cur;
    //            cur= nex;

    //            if(nex!= NULL){
    //            nex = nex->next;
    //        }
    //        }
           
    //        Node* temp = head;
    //        head = tail;
    //        tail = temp;
    //        tail->next = NULL;
    //    }

       void reversedatai(){   // reverse data iteratively

        int li = 0;
        int ri = size-1;

        while(li<ri){
            Node* left = getnodeat(li);
            Node* right = getnodeat(ri);

            int t = left->data;
            left->data = right->data;
            right->data= t;
            
            li++;
            ri--;
        }
       }
   
    //    void reverserec(){
           
    //        rpr(head);

    //    }

    int getsize(){
        
        // cout<<size;
        return size;
    }


       void revpointrec(){ // reversing the list recursively by pointer
           rpr(head);

           Node* temp = head;
           head = tail;
           tail = temp ;
           tail->next = NULL;
       }

       void revdatarec(){  // reversing the list recursively by data
           
           rdrleft = head;
           rdr(head, 0);
       }

       void revusing2pointersnxor()  // reversing the LL using 2 pointers and using bitwise operand
       {
           Node *prev = NULL;
           Node* cur = head; // cur is pointing to the same memmory address as head
           // here we used ut which is a uintptr_t ---> this coverts a pointer to a int and then an int  to a pointer which helped us in using bitwise operand...

           while(cur != NULL)
           {
               cur =(Node*)( ((ut)prev ^ (ut)cur ^ (ut)cur->next) ^ (ut)(cur->next = prev) ^ (ut)(prev = cur));
           }
           head = prev;
       }
      
      bool isplalin(){
         pallin_left = head;
         return pallindrome(head, 0);
      }


      // this is working pallindrome 
      // working as a wrapper function over ispallin()
        bool pallin()
        {
            //  ispallin(&head, head) ---> is wrong as on passing this the changes will be made on original head
            // O(N) time complexity and  O(n) if Function Call Stack size is considered, otherwise O(1).
            Node* left = head;
            Node* right = head;
            ispallin(&left, right);
        }

      void foldpub(){
          fleft = head;
          fold(head, 0);
      }

      void foldP(){
          Node* left = head;
          Node* right = head;
          foldP(&left, right, 0);
      }

      void unfoldpublic(){
          Node* t1= head;
          unfold(t1);
      }

      void removeduplicates(){
          Linkedlist nl;
          
          while(this->size > 0){
              int temp = this->removefirst();

              if(nl.size == 0 || nl.tail->data != temp){
                  nl.addlast(temp);
              }
          }

        //   clear(&nl); // by doing this here our nl will cleared and will not have anything to show

          this->head = nl.head;
          this->tail = nl.tail;
          this->size = nl.size;

          clear(&nl);  // here nl will be safe and will not store garbage too
      }

    //   void removedup_hash() // removing duplicates using unordered set (hashing)
    //   {
    //       // prepare a hash to store seen values
    //       unordered_set <int> seen;

    //       // pick elements one by one
    //       Node* cur = head;
    //       Node* prev = NULL;

    //       while(cur != NULL)
    //       {
    //           // if current value is seen
    //           if(seen.find(cur->data) != seen.end())
    //           {
    //               // if duplicate is found ----> 
    //               prev->next = cur->next;
    //               delete(cur);
    //           }
    //           else
    //           {
    //               //if duplicate is not found
    //               /// 1) insert the unseen data in set
    //               // 2) move prev
    //               seen.insert(cur->data);
    //               prev = cur;
    //           }
    //           // move cur using prev
    //           cur = prev->next; 
    //       }
    //      unordered_set<int> :: iterator itr;
    //      for(itr = seen.begin() ; itr != seen.end(); itr++)
    //         {
    //             cout<<*itr<<"->";
    //         }
    //   }

    void oddeven(){

        Linkedlist odd;
        Linkedlist even;
        
        while(this->size>0){

            int temp = this->removefirst();

            if(temp%2!=0){
              odd.addlast(temp);
            }
            else{
                even.addlast(temp);
            }
        }

        if(odd.size == 0){
            this->head = even.head;
            this->tail = even.tail;
            this->size = even.size;
        }
        else if(even.size == 0){
            this->head = odd.head;
            this->tail = odd.tail;
            this->size = odd.size;
        }
        else{
            odd.tail->next = even.head;
            this->head = odd.head;
            this->tail = even.tail;
            this->size = odd.size + even.size;
        }
        
        clear(&odd);
        clear(&even);
    }

    void kreverse(int k){
        Linkedlist acc;

        while(this->size >0){
        
            Linkedlist temp;
            for(int i=0; i<k && this->size>0 ; i++){
                temp.addfirst(this->removefirst());
            }

            if(acc.size == 0){
                acc =temp;
            }
            else{
                acc.tail->next =  temp.head;
                acc.tail = temp.tail;
                acc.size+= temp.size;
            }
            clear(&temp);
            
        }
      this->head =  acc.head;
      this->tail = acc.tail;
      this->size = acc.size;

      clear(&acc);

    }

    // //recursive k reverse

    int findmid(){
       // this will return mid data

       Node* fp = head;
       Node* sp = head;
       Node* mid =NULL ;
       mid = midnode(fp, sp);

       return mid->data;

    }
    



    int kthfromlast(int k){
     Node* slow = head;
     Node* fast = head;

     if(k>= size)
     {
         return -1;
     }

     for(int i=0; i<k; i++){
         fast = fast->next;
     }

     while(fast->next != NULL){
         slow = slow->next;
         fast= fast->next;
     }

     return slow->data;
    }

    // Node* multiply(Node* l1, Node* l2){
    //     // l1 will have the head of 1st LL & l2 will have the head of 2nd LL
    //     Node* newlist = NULL:
    //     multiply(l1->next, l2->next);
        
        
    // }

    int add( Node* l1, Node* l2, int size1, int size2, Linkedlist &res);

    void mergetwosortedlists(Linkedlist &l1, Linkedlist &l2){

        // int counter =0;

        Node* l1temp = l1.head;
        Node* l2temp = l2.head;
     
        while(l1temp !=NULL && l2temp !=NULL) {
            if(l1temp->data < l2temp->data){
                this->addlast(l1temp->data);
                l1temp = l1temp->next;
                //counter++;
            }
            else{
                this->addlast(l2temp->data);
                l2temp= l2temp->next;
                //counter++;
            }
        }

        while(l1temp != NULL){
            this->addlast(l1temp->data);
            l1temp = l1temp->next;
            //counter++;
        }

        while(l2temp != NULL){
            this->addlast(l2temp->data);
            l2temp= l2temp->next;
            //counter++;
        }
        // int sizeoflist = counter;
        // this->size = sizeoflist;
        // cout<<"size of the result list : "<<sizeoflist;
    }


    Linkedlist* mergesorting(){
        Linkedlist* sl = mergesort(this->head, this->tail);
        sl->display();
        return sl;
    }
    
};

int main(int argc, char** argv){

    // Linkedlist* l = new Linkedlist();
    // l->addlast(1);
    // l->addlast(2);
    // l->addlast(25);
    // l->addlast(3); ///  10 20 30
    // l->addlast(4);
    // l->addlast(5);
    // l->display();
    // // l->getsize();
    // cout<<endl;

    // l->oddeven();
    // l->display();
    //l->foldP();
    // l->kreverse(3);
    //l->display();
    //cout<<endl;
    //l->unfoldpublic();
    //cout<<l->findmid()<<endl;
    //cout<< l->kthfromlast(5)<<endl;
    //l->display();

    Linkedlist ll1;
    Linkedlist ll2;
    // Linkedlist ll3;

    ll2.addlast(7);
    ll2.addlast(1);
    ll2.addlast(6);
    ll2.display();

    ll1.addlast(5);
    ll1.addlast(9);
    ll1.addlast(2);
    ll1.addlast(9);
    // ll1.addlast(30);
    ll1.display();
    // ll1.addatidx(2,80);
    // cout<<"after inserting 80 : "<<endl;
    // ll1.display();

    // cout<<ll1.getat(2);
    // ll1.revusing2pointersnxor();
    // cout<<"is pallin : "<<ll1.pallin()<<endl;
    // cout<<ll1.kthfromlast(4)<<"\n";

    // ll1.removelast();
    // ll1.display();

    // cout<<ll1.getsize();
    // ll2.addlast(90);
    // ll2.addlast(11);
    // ll2.addlast(22);
    // ll2.addlast(100);
    // ll2.display();

    // ll3.mergetwosortedlists(ll1, ll2);
    // cout<<"ask";
    // ll3.display();

    // cout<<endl;

    // ll3.foldpub();
    // ll3.display();
    // Linkedlist* l4 = new Linkedlist();
    // l4->addlast(8);
    // l4->addlast(3);
    // l4->addlast(1);
    // l4->addlast(11);
    // l4->addlast(5);
    // l4->addlast(7);
    // l4->addlast(6);
    // l4->addlast(2);
    
    // l4->mergesorting();
    // l4->display();
    // // Linkedlist l2;
    // // l2.addlast(10);
    // // l2.addlast(10);
    // // l2.addlast(10);
    // // l2.addlast(20);
    // // l2.addlast(20);
    // // l2.addlast(30);
    // // l2.addlast(40);
    // // l2.addlast(40);
    // // l2.addlast(40);
    // // l2.display();
    // // l2.removeduplicates();
    // // l2.display();



    // // l->foldpub();
    // // l->addlast(-9);
    // // l->display();

    // //l->foldP();
    // // l->addlast(-9);
    // // l->display();

    // // l->unfoldpublic();
    // // l->display();
    // // l->addfirst(40);
    // // l->addlast(90);
    // //l->display();
 

    // //l->displayrev();

    // // l->revpointrec();
    // // l->display();

    // // l->revdatarec();

    // // l->addatidx(3,100);
    // // l->display();

    // // l->reversedatai();
    // // l->display();

    // // l->reversepointeri();
    // // l->display();



    // // l->removefirst();
    // // l->removefirst();
    // // l->display();

    // // l->removelast();
    // // l->display();

    // // l->addlast(200);
    // // l->display();

    // // l->removeatidx(2);
    // // l->display();

    // // l->getlast();

    // //delete l;

    // delete l4;

}
