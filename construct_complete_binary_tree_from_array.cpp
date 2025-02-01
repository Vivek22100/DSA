#include<iostream>
using namespace std;
struct treenode{
    int data;
    struct treenode* left;
    struct treenode* right;
    treenode(int data1){
        data=data1;
        left=right=nullptr;
    }
};
treenode *arrtotree(int arr[],int i,int n){
    treenode*root= nullptr;
    if(i<n){
        root=new treenode(arr[i]);
        root->left=arrtotree(arr,2*i+1,n);
        root->right=arrtotree(arr,2*i+2,n);
    }
     return root;
}
void inorder(treenode* root){
       if(root==NULL)return;
       inorder(root->left);
       cout<<root->data;
       inorder(root->right);
}

int main(){
      int n;
      cin>>n;
      int arr[n];
      for(int i=0;i<n;i++){
        cin>>arr[i];
      }
      treenode* root =arrtotree(arr,0,n);
      inorder(root);
      return 0;
}