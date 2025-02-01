#include<iostream>
#include<vector>
#include<queue>
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
vector<vector<int>> levelordertraversal(treenode*root){
    vector<vector<int>>ans;
    if(root==NULL)return ans;
    queue<treenode*>q;
    q.push(root);
    bool falg=true;
    while(!q.empty()){
        int size=q.size();
        vector<int>level(size);
        for(int i=0;i<size;i++){
            treenode* node=q.front();
            q.pop();
            int ind=falg?i:size-i-1;
            level[ind]=node->data;
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
           
        }
        falg=!falg;
        ans.push_back(level);

    }

 return ans;
}

void print(const  vector<vector<int>>&ans){
    
    for(const auto &level:ans){
        cout<<"[";
        for(int j=0;j<level.size();j++){
            cout<<level[j]<<" ";
        }
        cout<<"]";
    }
}
int main(){
      int n;
      cin>>n;
      int arr[n];
      for(int i=0;i<n;i++){
        cin>>arr[i];
      }
      treenode* root =arrtotree(arr,0,n);
      vector<vector<int>>ans;
      ans=levelordertraversal(root);
      print(ans);
      return 0;
}