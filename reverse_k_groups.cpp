#include<iostream>
using namespace std;
struct node{
    int val;
    node* next;
     
    node (int value){
         val=value;
         next=NULL;
    }
     node (){
         val=NULL;
         next=NULL;
    }  
};
 node* reverse_k_groups(node * head,int k){
    if(head || head->next)return head;
    node* dummy=new node();
    dummy->next=head;
    node*first=dummy;
    node* second=new node();
    while()


 }
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    node*head=new node(arr[0]);
    node* mover=head;
    
    for(int i=1;i<n;i++){
         node* temp=new node(arr[i]);
         mover->next=temp;
         mover=temp;

    }
    int k;
    cin>>k;
    node* newhead=reverse_k_groups(head,k);
    node* temp=newhead;
    while(newhead){
        cout<<temp->val;
        temp=temp->next;

    }
    return 0;
}