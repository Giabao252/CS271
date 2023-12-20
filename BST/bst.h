#ifndef _BST_H
#define _BST_H

//========================================================
// Bao Luu, Thanh Do, Khoa Nguyen
// CS271, Fall 2023
// bst.h
// This file contains the BST class declaration.
//========================================================

#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


template <class DataT, class KeyT>
class BST {
    public:
        BST(void);
        BST(const BST<DataT, KeyT>& otherBST);
        ~BST(void);

        bool empty(void) const;
        void insert(DataT d, KeyT k);
        void remove(KeyT k);
        void trim(KeyT low, KeyT high);

        DataT get(KeyT k) const;
        DataT max_data(void) const;
        KeyT max_key(void) const;
        DataT min_data(void) const;
        KeyT min_key(void) const;
        KeyT successor(KeyT k) const;
        string in_order(void) const;

        string to_string(void) const;
    
    private:
        //declaring the tree's nodes' attributes
        struct Node {
            KeyT key;
            DataT data;
            Node* p;
            Node* left;
            Node* right;
        };
        Node* root;

//HELPER METHODS BELOW

//========================================================
// delete_tree function
// pre-condition: none
// post-condition: tree rooted at node no longer exists
// parameters: root node of tree to be deleted
// return: none
//========================================================
        void delete_tree(Node* node) {
            if (node->left != NULL) { //checks if left child is NULL to prevent segfault
                delete_tree(node->left); //delete trees on left of root Node
            }
            if (node->right != NULL) { //checks if right child is NULL to prevent segfault
                delete_tree(node->right); //delete trees on right of root Node
            } 
            delete node; //delete root
        }

//========================================================
// copy_tree function
// pre-condition: root Node from copied tree is not NULL
// post-condition: the newNode returned contains all children
// of the node rooted at other_node
// parameters: pointer to Node being copied
// return: a Node that contains all children of the node 
// rooted at other_node
//========================================================
        Node* copy_tree(Node* other_node) {
            if (other_node == NULL) { //copy trees on the left to the a Node pointer to the left of the copied root
                return NULL;
            }

            Node* new_node = new Node;
            new_node->key = other_node->key;
            new_node->data = other_node->data;
            new_node->left = copy_tree(other_node->left); //copy trees on the left to the a Node pointer to the left of the copied root
            new_node->right = copy_tree(other_node->right); //copy trees on the left to the a Node pointer to the right of the copied root
            return new_node;
        }

//========================================================
// inOrderHelper function
// pre-condition: None
// post-condition: a string of ascending keys in a tree 
// consisting of Nodes rooted  at rootNode separated by a space
// parameters: pointer to Node the printed tree is rooted at
// return: a string of ascending keys in a tree consisting
// of Nodes rooted at rootNode separated by a space
//========================================================
        string inOrderHelper(Node *rootNode) const{
            stringstream out;
            if (rootNode == NULL){ //base case, when we try to access the right and left children of leaves
                return "";
            }
            else{
                out << inOrderHelper(rootNode->left); //traverses the left node first, to get to print out values smaller than rootNode
                out << rootNode->key << " "; //appends the key to out string
                out << inOrderHelper(rootNode->right); //then traverses the right node to get to all the nodes in the subtree rooted to the right of rootNode
            }
            string result = out.str();
            return result;
        }

//========================================================
// delete_tree function
// pre-condition: key k exists in the bst, root is not NULL
// post-condition: tree is kept constant, returns the node 
// that contains key k in the tree
// parameters: key K with type KeyT, matching type of keys in bst
// return: pointer to Node containing key
//========================================================
        Node* get_node(KeyT k) const{
            if (root == NULL) { //checks precondition
                return NULL;
            }
            Node* curr = root;
            while (curr != NULL && curr->key != k ) { //while loop terminates when key is found or when the whole tree is traversed through
                if (k <= curr->key) { //if key is smaller than the key of Node currently being traversed through, go left
                    curr = curr->left;
                }
                else if (k > curr->key) { //else go right
                    curr = curr->right;
                }
            }
            if (curr == NULL) { //stops when key is NULL
                return NULL;
            }
            return curr;
        }
//========================================================
// transplant function
// pre-condition: Node u and Node v exists in tree 
// (not checked because trasplant is used in another function that checks this)
// post-condition: bst property is maintained, node u 
// and subtree rooted at u is replaced by v and subtree rooted at v
// parameters: pointer to  node u being transplanted into and pointer to node v
// transplating into u
// return: none
//========================================================
        void transplant(Node* u, Node* v) {
            if (!u->p) { //check if node being transplanted into is a root
                root = v;
            } 
            else if (u == u->p->left) { //transplant v into the left of u.p
                u->p->left = v;
            }
            else { //transplant v into the left of v.p
                u->p->right = v;
            }
            if (v) {
                v->p = u->p; //replace the old link between u and u.p with v and u.p
            }
        }

};

#endif