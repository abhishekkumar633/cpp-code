#include<iostream>
using namespace std;
// creating a binary treee 
class Node
{
    public:
    int data;
    Node* left,*right;

    Node(int value)
    {
        left=right=NULL;
        data=value;
    }

    Node* create_binary_tree(){
        int x;
        cin>>x;
        if(x==-1)
        return NULL;

        Node* temp=new Node(x); // here new node is created

        // left child
        cout<<"enter right child elemet"<<x<<" :";
        temp->left=create_binary_tree();  

        // right child
        cout<<"enter right child elemet"<<x<<" :";
        temp->right=create_binary_tree();

        return temp;


    }

     void inorder(Node *root){
        if(root==NULL)
        return;

        inorder(root->left);
        cout<<root->data;
        inorder(root->right);
        
    }

    void preorder(Node* root){
        if(root==NULL)
        return;

        cout<<root->data;
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node* root){
        if(root==NULL)
        return;

         postorder(root->left);
         postorder(root->right);

         cout<<root->data;
    }

};

void total_no_of_nodes(Node* root , int &count){
    if(root==NULL)
    return;

    count++;

    total_no_of_nodes(root->left,count);
    total_no_of_nodes(root->right,count);

}

void sum_of_tree(Node* root,int &sum){
    if(root=NULL)
    return;

    sum += root->data;
    sum_of_tree(root->left,sum);
    sum_of_tree(root->right,sum);

}

void count_leaf(Node* root,int &count){
    if(root==NULL)
    return;

    if(!root->left && !root->right)
    count++;
    return;

    count_leaf(root->left,count);
    count_leaf(root->right,count);
}

int  count_node_without_leaf(Node* root,int &count){

    if(!root->left && !root->right)
    return 0;

    return (1+ count_node_without_leaf(root->left,count)+ count_node_without_leaf(root->right,count));
  
}

 
int main()
{
      Node* tree = new Node(0); // Temporary root initialization
    cout << "Enter the root element: ";
    Node* root = tree->create_binary_tree();

    cout << "\nPreorder traversal: ";
    tree->preorder(root);

    cout << "\nPostorder traversal: ";
    tree->postorder(root);

    cout << "\nInorder traversal: ";
    tree->inorder(root);

}