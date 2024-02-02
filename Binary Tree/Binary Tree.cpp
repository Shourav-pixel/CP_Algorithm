#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;

    }
};

node* buildTree(node* root)
{
   cout<<"Enter the Node: "<<endl;
   int data;
   cin>>data;
   root = new node(data);
   if(data == -1)
   {
       return NULL;
   }

   cout<<"Enter left child of the node "<<data<<":";
   root->left = buildTree(root->left);
   cout<<"Enter right child of the node "<<data<<":";
   root->right = buildTree(root->right);
   return root;
}

void levelOrderTraversal(node* root)
{
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* temp = q.front();

        q.pop();
        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else{
           cout<<temp->data<<" ";
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }

        }


    }
}

void revreselevelordertraversal(node* root){
    queue<node*> q1;
    q1.push(root);
    q1.push(NULL);
    stack<int> s;
    node* temp = NULL;
    while(!q1.empty()){
        temp = q1.front();
        q1.pop();

        if( temp== NULL){   // // purana level complete traverse ho chuka hai
            s.push(0); // because s.push(temp -> data ) will give error as temp is null
            if(!q1.empty()){
                q1.push(NULL);
            }
        }
        else{
            s.push(temp -> data); // as stack uses FIRST IN LAST OUT method so the first node entered in stack that is root node will be at the last and so on
            if(temp -> left){
                q1.push(temp -> left);
            }
            if(temp -> right){
                q1.push(temp -> right);
            }
        }
    }
    while(!s.empty()){
        if(s.top() == 0){
            s.pop();
            cout<<endl;
        }
        else{
            cout<< s.top() << " ";
            s.pop();
        }
    }
}

void inorder(node* root)
{
    //base case;
    if(root == NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root)
{
    //base case
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root)
{
    //base case
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void buildlevelOrder(node* root)
{
    queue<node*>q;
    cout<<"Enter Data for node:: "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        cout<<"Enter left node for"<<temp->data<<endl;
        int left;
        cin>>left;

        if(left != -1)
        {
           temp->left = new node(left);
           q.push(temp->left);
        }

        cout<<"Enter right node for"<<temp->data<<endl;
        int right;
        cin>>right;

        if(right != -1)
        {
           temp->right = new node(right);
           q.push(temp->right);
        }

    }
}
int main()
{
  node* root = NULL;
  root = buildTree(root);
  //2 3 5 -1 -1 6 -1 -1 4 7 -1 -1 -1
  cout<<"Level Order Traversal::"<<endl;
  levelOrderTraversal(root);
  cout<<endl;
    cout<<"Let's Reverse::"<<endl;
  revreselevelordertraversal(root);

  cout<<endl;

  //LNR WALA
   cout<<"InOrder Traversal::"<<endl;
   inorder(root);
   cout<<endl;
   //NLR Wala
   cout<<"Preorder Traversal:: "<<endl;
   preorder(root);
    cout<<endl;
   //LRN Wala
   cout<<"Postorder Traversal:: "<<endl;
   postorder(root);

  // buildlevelOrder(root);
   //levelOrderTraversal(root);


}
