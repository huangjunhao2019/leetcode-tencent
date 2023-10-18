#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){}
    ListNode(int _val):val(_val),next(nullptr){}
    ListNode(int _val,ListNode *_next):val(_val),next(_next){}
};
struct LittleTrain{
    ListNode *dummyHead;
    int size;
    int len;
    LittleTrain(){
        dummyHead=new ListNode(0);
        size=0;
        len=0;
    }
    LittleTrain(int _size){
        dummyHead=new ListNode(0);
        size=_size;
        len=0;
    }
    bool insertFront(int val){
        if(len>=size){
            return false;
        }
        ListNode *temp=new ListNode(val);
        temp->next=dummyHead->next;
        dummyHead->next=temp;
        len++;
        return true;
    }
    bool insertLast(int val){
        if(len>=size){
            return false;
        }
        ListNode *temp=new ListNode(val);
        ListNode *ptr=dummyHead;
        while(ptr->next!=nullptr){
            ptr=ptr->next;
        }
        ptr->next=temp;
        len++;
        return true;
    }
    bool deleteFront(){
        if(len<=0){
            return false;
        }
        dummyHead->next=dummyHead->next->next;
        len--;
        return true;
    }
    bool deleteLast(){
        if(len<=0){
            return false;
        }
        ListNode *ptr=dummyHead;
        while(ptr->next->next!=nullptr){
            ptr=ptr->next;
        }
        ptr->next=nullptr;
        len--;
        return true;
    }
    int getFront(){
        if(len<=0){
            return -1;
        }
        return dummyHead->next->val;
    }
    int getRear(){
        if(len<=0){
            return -1;
        }
        ListNode *ptr=dummyHead;
        while(ptr->next!=nullptr){
            ptr=ptr->next;
        }
        return ptr->val;
    }
    bool isEmpty(){
        return len==0;
    }
    bool isFull(){
        return len==size;
    }
    void printVal(){
        ListNode *ptr=dummyHead->next;
        while(ptr!=nullptr){
            cout<<ptr->val<<" ";
            ptr=ptr->next;
        }
        cout<<endl;
    }
};
int main(){
  //  size=0;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    LittleTrain *lt=new LittleTrain(3);
    lt->printVal();
    bool b1=lt->insertFront(a);
    lt->printVal();
    bool b2=lt->insertLast(b);
    lt->printVal();
    bool b3=lt->insertFront(c);
    lt->printVal();
    bool b4=lt->insertFront(d);
    lt->printVal();
    bool b5=lt->deleteFront();
    lt->printVal();
    bool b7=lt->deleteLast();
    lt->printVal();
    int b9=lt->getFront();
    lt->printVal();
    int b10=lt->getRear();
    lt->printVal();
    bool b11=lt->isEmpty();
    lt->printVal();
    bool b12=lt->isFull();
    lt->printVal();
    cout<<b1<<" "<<b2<<" "<<b3<<" "<<b4<<" "<<b5<<" "<<" "<<b7<<" "<<" "<<b9<<" ";
    cout<<b10<<" "<<b11<<" "<<b12<<endl;
    return 0;

}