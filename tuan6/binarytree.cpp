#include <iostream>
using namespace std;

struct node
{
    int value;
    node *left;
    node *right;
};

class BinaryTree
{
private:
    node *root;

    int getHeight(node *root)
    {
        if (root == nullptr)
            return 0;
        int left_height = getHeight(root->left) + 1;
        int right_height = getHeight(root->right) + 1;
        return (left_height > right_height) ? left_height : right_height;
    }

     node treeSearch(node *root, int val)
    {
        if (root == nullptr)
            return root ;
        if (root->value == val)
            return root;
        if (root->value < val)
            return treeSearch(root->right, val);
        return treeSearch(root->left, val);
    }

    int countNodes(node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int numberNodes_of_left = countNodes(root->left);
        int numberNodes_of_right = countNodes(root->right);
        return numberNodes_of_left + numberNodes_of_right + 1;
    }

    int countAdult(node *root)
    {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        {
            return 0;
        }
        int numberNodes_of_left = countNodes(root->left);
        int numberNodes_of_right = countNodes(root->right);
        return numberNodes_of_left + numberNodes_of_right + 1;
    }

//     void addRec(node *&root, int e)
//     {
//         if (root == nullptr)
//         {
//             root = new node;
//             root->value = e;
//                root->right=nullptr;
//                root->left=nullptr;
//         }
//      //    else
//      //    {
//      //        int left = getHeight(root->left);
//      //        int right = getHeight(root->right);
//      //        if (left <= right)
//      //            addRec(root->left, e);
//      //        else
//      //            addRec(root->right, e);
//      //    }
//           if(root->value<e) addRec(root->right,e);
//           if(root->value>e) addRec(root->left,e);
//     }


    void addRec(node * &root,int e){
           if (root == nullptr)
        {
            root = new node;
            root->value = e;
               root->right=nullptr;
               root->left=nullptr;
        }
          else if(root->value %2 == e%2){ 
               if(root->value>e){
                    addRec(root->right,e);
               }else{
                    addRec(root->left,e);
               }
          }
          else if (root->value %2 ==1){
               addRec(root->left,e);
          }
          else{
               addRec(root->right,e);
          }
        }

     void deleteNode(node * root, int a){
          if(!root->left) root=root->right;
     }
    
//   void add(node * root,)
    void deleteTree(node *root)
    {
        if (root == nullptr)
            return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }

    
    void inOrder_print(node *current_node)
    {
        if (current_node != nullptr)
        {
            inOrder_print(current_node->left);
            cout << current_node->value << ",";
            inOrder_print(current_node->right);
        }
    }

    void preOrder_print(node *current_node)
    {
        if (current_node != nullptr)
        {
            cout << current_node->value << ",";
            preOrder_print(current_node->left);
            preOrder_print(current_node->right);
        }
    }


void deleteNode(node *&current_node, int val)
{
     if (current_node == nullptr)
     {
          return;
     }
     else if (val < current_node->value)
     {
          deleteNode(current_node->left, val);
     }
     else if (val > current_node->value)
     {
          deleteNode(current_node->right, val);
     }
     else
     {
          // Case 1: node has no children
          if (current_node->left == nullptr && current_node->right == nullptr)
          {
               delete current_node;
               current_node = nullptr;
          }
          // Case 2: node has one child
          else if (current_node->left == nullptr)
          {
               node *temp = current_node;
               current_node = current_node->right;
               delete temp;
          }
          else if (current_node->right == nullptr)
          {
               node *temp = current_node;
               current_node = current_node->left;
               delete temp;
          }
          // Case 3: node has two children
          else
          {
               node *temp = findMin(current_node->right);
               current_node->value = temp->value;
               deleteNode(current_node->right, temp->value);
          }
     }
}

node* findMin(node *current_node)
{
     while (current_node->left != nullptr)
     {
          current_node = current_node->left;
     }
     return current_node;
}
public:
    BinaryTree() : root(nullptr) {};

    bool isInternal(node *n)
    {
        return (n->left != nullptr || n->right != nullptr) ? true : false;
    }

    int countAdult()
    {
        return countAdult(root);
    }
    void deleteNode(int val)
{
     deleteNode(root, val);
}

    int countNodes()
    {
        return countNodes(root);
    }

    void addRec(int a)
    {
        addRec(root, a);
    }
    
    void deleteAll()
    {
        deleteTree(root);
        root = nullptr;
    }

    void inOrder_print()
    {
        inOrder_print(root);
        cout << "*";
    }

    void preOrder_print()
    {
        preOrder_print(root);
        cout << "*";
    }

    void findHeight()
    {
        int height = getHeight(root);
        cout << "Height: " << height << endl;
    }
    void deleteNdoe(node  * &root, int e){
          
   }
};

int main()
{
    BinaryTree tree;
    tree.addRec(2);
    tree.addRec(4);
    tree.addRec(1);
    tree.inOrder_print();
}
