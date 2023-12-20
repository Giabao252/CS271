#ifndef _GRAPH_H
#define _GRAPH_H

//========================================================
// Bao Luu, Thanh Do, Khoa Nguyen
// CS271, Fall 2023
// graph.h
// This file contains the Graph class declaration.
//========================================================

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

template <class D, class K>

class Graph {
    private:
        struct Node {
            K key;
            D data;
            int distance;
            K pi;
            int startT;
            int endT;
            vector<K> edge;
        };
        vector<Node*> adjList;
        bool runDFS = false;

        //========================================================
        // resetNode function
        // pre-condition: a graph with valid nodes
        // post-condition: set initial distance to -1 and initial
        // pi to NULL for each vertex
        // return: none
        //========================================================
        void resetNode(void) {
            for (int i = 0; i < adjList.size(); i++)
            {
                adjList[i]->distance = -1; // set initial distance to -1
                adjList[i]->pi = K(); // set its pi to NULL
            }
        }

        //========================================================
        // get_reachable_helper function
        // pre-condition: a graph and two keys input
        // post-condition: return true if both keys found
        // parameters: k1, k2: keys
        // return: boolean, true if both keys found
        //========================================================
        bool get_reachable_helper(K k1, K k2) const{
            // set initial flag for each key
            bool foundk1 = false; 
            bool foundk2 = false;
            for (int i = 0; i < adjList.size(); i++)
            {
                if (adjList[i]->key == k1){
                        foundk1 = true;
                    }
                if (adjList[i]->key == k2){
                        foundk2 = true;
                    }
                if (foundk1 == true && foundk2 == true){
                    // return true if both key found
                    return true;
                }
            }

            return false;
        }

        //========================================================
        // dfs function
        // pre-condition: a graph, a current key, a target key
        // and a set
        // post-condition: return true if target can be reached
        // from source vertex
        // parameters: current, target: keys; visited: set to 
        // keep track of seen vertex
        // return: boolean, true if target can be reached
        //========================================================
        bool dfs(K current, K target, set<K>& visited) {
            if (current == target) // if found target return true
            {
                return true;
            }
            visited.insert(current); // add node to visited set

            Node* thisNode = get(current);
            for (int i = 0; i < thisNode->edge.size(); i++)
            {
                // dfs each neighbor that is not in the visisted set of current node
                if (visited.find(thisNode->edge[i]) == visited.end())
                {
                    if (dfs(thisNode->edge[i], target, visited))
                    {
                        return true;
                    }
                }
            }
            
            return false;
        }

        //========================================================
        // dfs_time function
        // pre-condition: a graph, a current key,
        // a set, and time t
        // post-condition: run dfs for the graph from current node
        // parameters: current: keys; visited: set to 
        // keep track of seen vertex; t: time 
        // return: none
        //========================================================
        void dfs_time(K current, set<K>& visited, int& t) {
            Node* thisNode = get(current);
            if (thisNode == nullptr) // check if node exist in list
            {
                return;
            }
            visited.insert(current); // add node to visited set
            t++; // increment time
            thisNode->startT = t; // record discovered time

            for (int i = 0; i < thisNode->edge.size(); i++)
            {
                // dfs each neighbor that is not in the visisted set of current node
                if (visited.find(thisNode->edge[i]) == visited.end())
                {
                    dfs_time(thisNode->edge[i], visited, t);
                }
            }
            t++;
            thisNode->endT = t; // record finished time
        }
        
    public: 
        Graph(void);
        Graph(vector<K> keys, vector<D> data, vector<vector<K> > edges);
        ~Graph(void);

        Node* get(K k) const;
        bool reachable(K u, K v);
        void bfs(K s);
        void print_path(K u, K v);
        string edge_class(K u, K v);
        void bfs_tree(K s);
        string BFS(K s);
};


#include "graph.cpp"
#endif