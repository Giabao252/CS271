//========================================================
// Bao Luu, Thanh Do, Khoa Nguyen
// CS271, Fall 2023
// bst.cpp
// This file contains the implementation of the Binary Search Tree class
// specified in bst.h.
//========================================================
#include <iomanip>
#include <sstream>
#include <string> 
#include <queue>
#include "bst.h"
using namespace std;

//========================================================
// DEFAULT CONSTRUCTOR
// Initialize an empty tree
//========================================================
template <class DataT, class KeyT>
BST<DataT, KeyT>::BST(void) {
    root = NULL; //initialize the tree's root to point to 0
}

//========================================================
// DESTRUCTOR
// Deallocate memory used by the BST and its nodes
//========================================================
template <class DataT, class KeyT>
BST<DataT, KeyT>::~BST(void) {

    if (root != NULL) {
        delete_tree(root);
    }
    root = NULL;
}

//========================================================
// COPY CONSTRUCTOR
//========================================================
template <class DataT, class KeyT>
BST<DataT, KeyT>::BST(const BST<DataT, KeyT>& otherBST) {
    if (otherBST.root == NULL) {
        root = NULL;
    } 
    else {
        root = copy_tree(otherBST.root); 
    }
}

//========================================================
// EMPTY
// PRE-CONDITION: none
// POST-CONDITION: if the tree is empty, return true, else return false
// PARAMETERS: none
// RETURN: boolean value
//========================================================
template <class DataT, class KeyT>
bool BST<DataT, KeyT>::empty(void) const {
    //check if the tree's root node points to NULL, return true
    if (root == NULL) {
        return true;
    }
    //if not, return false
    return false;
}

//================================================================================================================================================================
// INSERT
// PRE-CONDITION: The BST is a valid binary search tree (BST) with its nodes properly ordered before insertion
// POST-CONDITION: A new node containing the data 'd' and key 'k' is added to the BST, and the resulting tree 
// continues to maintain the properties of a valid BST
// PARAMETERS: 
// d: the new node's data
// k: the new node's key
// RETURN: none
//================================================================================================================================================================
template <class DataT, class KeyT>
void BST<DataT, KeyT>::insert(DataT d, KeyT k) {
    //Initialize a new node of data d and key k to be inserted in to the tree
    Node* new_node = new Node; 
    new_node->data = d;
    new_node->key = k;
    new_node->p = NULL;
    new_node->left = NULL;
    new_node->right = NULL;

    //Create pointers to keep track of the parent node and the current node when looking for the insert position
    Node* parent = NULL; 
    Node* curr = root; 

    //traversing down the tree following the BST property to find the correct insert position
    while (curr != NULL) {
        parent = curr; //update the parent's pointer to the root as curr shifts down its children

        //if the new node's key is smaller or equal to the current node's key, shifts to its left child
        if (k <= curr->key) { 
            curr = curr->left;
        }
        //if the new node's key is larger than the current node's key, shifts to its right child
        else if (k > curr->key) {
            curr = curr->right;
        }
    }
    //set the new node's parent to point to the current node that parent pointer is pointing to
    new_node->p = parent;

    if (parent == NULL) { //check if the parent points to NULL after the while loop (tree is empty)
        root = new_node; //set the root node to be the new node
    } 
    else if (k > parent->key) { //check if the node pointed to by the parent key is smaller than the new node's key
        parent->right = new_node; // set its right child to be the new node
    }
    else { 
        parent->left = new_node;
    }
}

//================================================================================================================================================================
// REMOVE
// PRE-CONDITION: The method assumes that the key k exists in the binary search tree (BST) before attempting to remove it
// POST-CONDITION: The node with key k is removed from the BST, and the tree maintains the binary search tree property
// PARAMETERS: 
// k: the key of the node which will be removed
// RETURN: none
//================================================================================================================================================================
template<class DataT, class KeyT>
void BST<DataT, KeyT>::remove(KeyT k) {
    // Get the node with key k
    Node* z = get_node(k);

    // If the node is not found, return without changes
    if (z == NULL) {
        return;
    }
    // If z has no left child, replace z with its right child
    if (!z->left) {
        transplant(z, z->right);
    }
    // If z has no right child, replace z with its left child
    else if (!z->right) {
        transplant(z, z->left);
    }
    // If z has both left and right children, find the successor and replace z with it
    else {
        // get node with minimum key in z's right subtree
        Node* y = z->right;
        while (y->left) {
            y = y->left;
        }
        // If y is not z's right child, perform transplant and reassignment
        if (y->p != z) {
            transplant(y, y->right);
            y->right = z->right;
            y->right->p = z;
        }
        // Replace z with y using transplant and reassign left child
        transplant(z, y);
        y->left = z->left;
        y->left->p = y;
    }
    // Delete the original node z
    delete z;
}

//================================================================================================================================================================
// GET
// PRE-CONDITION: The BST is not empty (root is not NULL)
// POST-CONDITION: Returns the data associated with the key 'k' if it exists in the BST; otherwise, returns a default value
// PARAMETERS: 
// k: the key of the node to be retrieved
// RETURN: data of the node with the key k
//================================================================================================================================================================
template<class DataT, class KeyT>
DataT BST<DataT, KeyT>::get(KeyT k) const {
    if (root == NULL) {
        return NULL; // If the tree is empty, return a default value (assuming NULL is the default for DataT)
    }
    Node* curr = root;
    while (curr->key != k) {
        if (k <= curr->key) {
            curr = curr->left; // Traverse the left subtree if the key is less than the current node's key.
        }
        else if (k > curr->key) {
            curr = curr->right; // Traverse the right subtree if the key is larger than the current node's key.
        }
    }
    return curr->data; //return the data of the node with key k in the BST
}


//================================================================================================================================================================
// MAX_DATA
// PRE-CONDITION: The BST is not empty (root is not NULL)
// POST-CONDITION: Returns the maximum (rightmost) data in the BST
// PARAMETERS: NONE
// RETURN: data of the node with the maximum key in the BST
//================================================================================================================================================================
template<class DataT, class KeyT>
DataT BST<DataT, KeyT>::max_data(void) const {
    if (root == NULL) {
        return NULL; // If the BST is empty (no root), return NULL (or possibly DataT() to match the return type)
    }
    Node* curr = root; // Start with the root node
    while (curr->right != NULL) {
        curr = curr->right; // Traverse to the rightmost node (maximum key)
    }
    return curr->data; // Return the data of the rightmost node, which has the maximum key
}

//================================================================================================================================================================
// MAX_KEY
// PRE-CONDITION: Assumes that the BST is not empty (root is not NULL)
// POST-CONDITION: Returns the maximum key found in the tree
// PARAMETERS: NONE
// RETURN: The maximum key in the tree
//================================================================================================================================================================
template<class DataT, class KeyT>
KeyT BST<DataT, KeyT>::max_key(void) const {
    if (root == NULL) {
        return NULL; // If the BST is empty (no root), return NULL (or possibly DataT() to match the return type).
    }
    Node* curr = root;
    while (curr->right != NULL) {
        curr = curr->right; // Traverse to the rightmost node, which contains the maximum key.
    }
    return curr->key; // Return the maximum key found
}

//================================================================================================================================================================
// MIN_DATA
// PRE-CONDITION: The BST is not empty (root is not NULL)
// POST-CONDITION: Returns the data of the node with the maximum key in the BST
// PARAMETERS: NONE
// RETURN: the data of the node associated with the minimum key value in the BST
//================================================================================================================================================================
template<class DataT, class KeyT>
DataT BST<DataT, KeyT>::min_data(void) const {
    if (root == NULL) {
        return NULL; // If the BST is empty (no root), return NULL (or possibly DataT() to match the return type).
    }

    Node* curr = root;
    while (curr->left != NULL) {
        curr = curr->left; // Traverse to the leftmost node, which contains the minimum key and its associated data
    }
    return curr->data; // Return the data associated with the minimum key found
 }

//================================================================================================================================================================
// MIN_KEY
// PRE-CONDITION: The BST is not empty (root is not NULL)
// POST-CONDITION: Returns the minimum key value in the BST
// PARAMETERS: NONE
// RETURN: the minimum key value in the BST
//================================================================================================================================================================
template<class DataT, class KeyT>
KeyT BST<DataT, KeyT>::min_key(void) const {
    if (root == NULL) {
        return NULL; // If the BST is empty (no root), return NULL (or possibly DataT() to match the return type).
    }

    Node* curr = root;
    while (curr->left != NULL) {
        curr = curr->left; // Traverse to the leftmost node to find the minimum key
    }
    return curr->key; // Return the minimum key found
 }

//================================================================================================================================================================
// SUCCESSOR
// PRE-CONDITION: The BST is not empty, and the key k exists in the BST
// POST-CONDITION: Returns the successor key of k in the BST, or NULL if k has no successor.
// PARAMETERS: 
// k: The key for which the successor is to be found
// RETURN: The key associated with the successor of the node with key k
//================================================================================================================================================================
template<class DataT, class KeyT>
KeyT BST<DataT, KeyT>::successor(KeyT k) const {
    if (root == NULL){
        return NULL; // // If the BST is empty, there can be no successor, so return NULL
    }
    Node* startNode = get_node(k); // retrieve the node with key k in the BST
    if (startNode == NULL){
        return NULL; // If the key k does not exist in the BST, return NULL
    }
    // check if the node found does not have a right child
    if(startNode->right!=NULL){
        Node* curr = startNode->right; //move the current pointer to point to the right child of startNode
        while (curr->left != NULL) {
            curr = curr->left; // Traverse to the leftmost node in the right subtree to find the successor
        }
        return curr->key; //return the key associated with the successor
    }
    Node* tempNode = startNode->p;
    // If there is no parent, there is no successor
    if (tempNode == NULL){
        return NULL;
    }
    while(tempNode!=NULL && startNode == tempNode->right){
        startNode = tempNode;
        tempNode = startNode->p; // Traverse up the tree to find the successor
    }
    if (tempNode == NULL){
        return NULL; // If the parent is NULL, there is no successor
    }
    return tempNode->key; // Return the key associated with the successor

}

//================================================================================================================================================================
// TRIM
// PRE-CONDITION: Assumes that the Binary Search Tree (BST) is properly initialized and may contain nodes with keys within the range
// specified by low and high.
// POST-CONDITION: Any nodes with keys less than low or greater than high have been removed while preserving the BST's structure.
// PARAMETERS: 
// low : the lower bound of the range for node keys to be retained in the BST.
// high: the upper bound of the range for node keys to be retained in the BST.
// RETURN: NONE
//================================================================================================================================================================
template<class DataT, class KeyT>
void BST<DataT, KeyT>::trim(KeyT low, KeyT high) {

    // Loop to remove nodes with keys less than 'low'
    while (root && root->key < low) {
        Node* tmp = root;
        root = root->right;
        tmp->right = NULL;
        delete_tree(tmp);
    }
    // Loop to remove nodes with keys greater than 'high'
    while (root && root->key > high) {
        Node* tmp = root;
        root = root->left;
        tmp->left = NULL;
        delete_tree(tmp);
    }

    // Find the left limit of the retained key range
    Node* leftLimit = root;
    while (leftLimit && leftLimit->key >= low) {
        leftLimit = leftLimit->left;

        // If the leftLimit key is less than 'low', remove it
        if (leftLimit && leftLimit->key < low) {
            transplant(leftLimit, leftLimit->right);
            Node* tmpLeft = leftLimit;
            leftLimit = leftLimit->right;
            tmpLeft->right = NULL;
            delete_tree(tmpLeft);
        }
    }

    // Find the right limit of the retained key range
    Node* rightLimit = root;
    while (rightLimit && rightLimit->key <= high) {
        rightLimit = rightLimit->right;

        // If the rightLimit key is greater than 'high', remove it
        if (rightLimit && rightLimit->key > high) {
            transplant(rightLimit, rightLimit->left);
            Node* tmpRight = rightLimit;
            rightLimit = rightLimit->left;
            tmpRight->left = NULL;
            delete_tree(tmpRight);
        }
    }

}

//========================================================
// in_order function
// pre-condition: root is not null
// post-condition: a string of keys in the original bst
// printed in descending order, separated by a space
// parameters: none
// return: a string of keys in the original bst
// printed in descending order, separated by a space
//========================================================

template<class DataT, class KeyT>
string BST<DataT, KeyT>::in_order(void) const{
    if (!root) {
        return "";
    }
    string result = inOrderHelper(root); //calls private function inOrderHelper in header file
    result.pop_back(); //deletes the space at the end of the string
    return result;
}

//================================================================================================================================================================
// TO_STRING
// PRE-CONDITION: The BST is not empty
// POST-CONDITION: Returns a string containing the keys of the BST in level order, separated by spaces.
// PARAMETERS: NONE
// RETURN: returns a string
//================================================================================================================================================================
template<class DataT, class KeyT>
string BST<DataT, KeyT>::to_string(void) const{
    if (root == nullptr) {
        return "";
    }

    stringstream result; // Create a stringstream to build the result string
    queue<Node*> nodeQueue; // Create a queue to perform level-order traversal of the BST

    nodeQueue.push(root); // Enqueue the root node

    while (!nodeQueue.empty()) {
        Node* current = nodeQueue.front(); // Dequeue the front node
        nodeQueue.pop();

        // Append the key to the result string
        result << (current->key) << " ";

        // Enqueue left and right children (if they exist)
        if (current->left != nullptr) {
            nodeQueue.push(current->left);
        }
        if (current->right != nullptr) {
            nodeQueue.push(current->right);
        }
    }
    string out;
    out = result.str(); // Convert the stringstream to a string
    if (!out.empty()) {
        out.pop_back(); // Remove the trailing space, if the string is not empty
    }

    return out; // Return the string containing keys in level order
}