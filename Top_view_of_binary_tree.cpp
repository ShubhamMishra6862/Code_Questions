set<int> hm;
void topview(Node* root,int k){
    if(hm.find(k)==hm.end()){
        cout<<root->data<<" ";
         hm.insert(k);
    }
    if(root->left!=NULL)topview(root->left,k-1);
    if(root->right!=NULL)topview(root->right,k+1);
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    root->right->left->left=new Node(8);
    root->right->left->right=new Node(9);
    topview(root,0);
}
