#include <iostream>
using namespace std;
#include <stack>

class BSTnode {
public:
    int data;
    BSTnode* left;
    BSTnode* right;
    BSTnode(int x) {
        data = x;
    }
};

class BST {
public:
    BSTnode* root;
    
    void insert(BSTnode** currentNode, int data) {
        if(*currentNode==NULL) 
        {
            *currentNode = new BSTnode(data);
          //  cout<<"test";
            
        } else if (data >= (*currentNode)->data) 
        {
            insert(&((*currentNode)->right), data);
           // cout<<"TEST";
            
        } else {
            insert(&((*currentNode)->left), data);
        }
    }
    
    void deleteNode(BSTnode** currentNode, int data) {
        if(*currentNode==NULL) {
            return;     // node doesn't exist
        }
        
        if (data < (*currentNode)->data) {
     
        deleteNode(&((*currentNode)->left), data);
        
    } else if (data > (*currentNode)->data) {
 
        deleteNode(&((*currentNode)->right), data);
    } 
    else {
        // Node found, check number of children
        if ((*currentNode)->left == NULL) // Node has no left child/only right child 
        {
            BSTnode* temp = *currentNode;
            *currentNode = (*currentNode)->right;
            delete(temp);
        } else if ((*currentNode)->right == NULL) // Node has only left child
        {
            BSTnode* temp = *currentNode;
            *currentNode = (*currentNode)->left;
            delete(temp);
        } 
        else 
        {
            // if node has two children, Find the minVal node in the right subtree
            BSTnode* minRight = (*currentNode)->right;
            while (minRight->left != NULL) {
                minRight = minRight->left;
            }
            
            // Copy the minVal to the current node
            (*currentNode)->data = minRight->data;
            
            // Delete the minVal node in the right subtree
            deleteNode(&((*currentNode)->right), minRight->data);
        }
    }
}
    
    void inorderTraversal(BSTnode* currentNode) {
    if (currentNode==NULL) {
        return;
    }
    inorderTraversal(currentNode->left);
    cout << currentNode->data << " ";
    inorderTraversal(currentNode->right);
}

    BSTnode* findKey(BSTnode* currentNode, int data) {
        if (currentNode==NULL) {
            return NULL;
        }
        
        if (data == currentNode->data) {
            return currentNode;
        } 
        else if (data < currentNode->data) 
        {
        return findKey(currentNode->left, data); // Search in the left subtree
    } 
        else 
    {
        return findKey(currentNode->right, data); // Search in the right subtree
    }
    }
    
     void postorder(BSTnode* currentNode) {
        if (currentNode == NULL)
            return;

        // Traverse left subtree
        postorder(currentNode->left);
        // Traverse right subtree
        postorder(currentNode->right);
        cout << currentNode->data << " ";
     }
     
    void preOrder(BSTnode* root) {

    if (root == NULL)
        return;

    stack<BSTnode*> nodeStack;
    nodeStack.push(root);

    while (nodeStack.empty() == false) {
        
        BSTnode* node = nodeStack.top();  // Pop top item from stack
        cout << node->data << " ";
        nodeStack.pop();

        // Push right and left children to stack
        if (node->right)
            nodeStack.push(node->right);
        if (node->left)
            nodeStack.push(node->left);
    }
}

};

int main()
{
    
    int choice, data;

   BST myTree;
   myTree.insert(&myTree.root, 50);
   myTree.insert(&myTree.root, 39);
   myTree.insert(&myTree.root, 100);
   myTree.insert(&myTree.root, 23);
   myTree.insert(&myTree.root, 48);
   myTree.insert(&myTree.root, 24);
   myTree.insert(&myTree.root, 70);
   
   myTree.deleteNode(&myTree.root, 39);

        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. View postorder traversal" << endl;
        cout << "5. View preorder traversal" << endl;
        cout << "Enter your choice (inorder traversal appears automatically): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                myTree.insert(&(myTree.root), data);
                break;
            case 2:
                cout << "Enter data to delete: ";
                cin >> data;
                myTree.deleteNode(&(myTree.root), data);
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> data;
                if (myTree.findKey(myTree.root, data) != nullptr) {
                    cout << "Key match" << endl;
                }  else {
                    cout << "No key match" << endl;
                    break;
                }
                
            case 4:
                cout << "Here is postorder traversal: ";
                myTree.postorder(myTree.root);
                cout << endl;
                break;
                
            case 5:
                cout << "Here is preorder traversal: ";
                myTree.preOrder(myTree.root);
                cout << endl;
                break;
    
            default:
                break;
        }
   
/*   int searchKey;
    cout << "Enter the key you want to search for: ";
    cin >> searchKey;

    // Call the findKey function
    BSTnode* foundNode = myTree.findKey(myTree.root, searchKey);

    if (foundNode != nullptr) {
        cout << "There's a match!" << endl;
    } else {
        cout << "There's no match." << endl;
    }
*/

  // cout<<myTree.root->data;
  // cout<<(myTree.root->right)->data;
  // cout<<(myTree.root->left)->data;
  
    cout << "Inorder traversal of the tree: ";
   myTree.inorderTraversal(myTree.root);
   cout << endl;

    return 0;
}