#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
    node(int num){
        data=num;
        next=NULL;
    }
    
};
node * arrtoll(int arr[],int n){
    if(n==0)return NULL;
    node* head=new node(arr[0]);
    node* mover=head;
    
    for(int i=1;i<n;i++){
        node* temp=new node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
node* sumofll(node* l1,node*l2){
    int val;
    int carry=0;
    node* l3=new node(0);
    node*head=l3;
    while(l1 && l2){
       int  val=l1->data+l2->data+carry;
        carry=(val/10);
       l3->next=new node(val%10);
       
        l3=l3->next;
        l1=l1->next;
        l2=l2->next;
    }
    while(l1){
        int  val=l1->data+carry;
         l3->next=new node(val%10);
         l3=l3->next;
         l1=l1->next;
    }
    while(l2){
        int  val=l2->data+carry;
         l3->next=new node(val%10);
         l3=l3->next;
         l2=l2->next;
    }
    while(carry){
         l3->next=new node(carry);
         carry=0;
    }
    return head->next;


}
int main(){
    int n1,n2;
    cout<<"enter size n1 n2"<<endl;
    cin>>n1>>n2;
    int arr1[n1];
    int arr2[n2];
    cout<<"enter arr1"<<endl;
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    cout<<"enter arr2"<<endl;
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }
    node *head1=arrtoll(arr1,n1);
    node *head2=arrtoll(arr2,n2);
    node * sumll=sumofll(head1,head2);
    node*temp=sumll;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    


    return 0;
}