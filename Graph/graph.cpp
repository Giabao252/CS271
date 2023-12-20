//========================================================
// Bao Luu, Thanh Do, Khoa Nguyen
// CS271, Fall 2023
// graph.cpp
// This file contains the implementation of the Graph class
// specified in graph.h.
//========================================================
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <list>
#include <set>
#include "graph.h"

// ================================================================================
// CONSTRUCTOR
// ================================================================================
template <class D, class K>
Graph<D, K>::Graph(void) {
    vector<Node*> empty;
    adjList = empty;
}

// ================================================================================
// COPY CONSTRUCTOR
// ================================================================================

template <class D, class K>
Graph<D, K>::Graph(vector<K> keys, vector<D> data, vector<vector<K>> edges) {
    adjList.resize(keys.size()); // resize vector
    for (int i = 0; i < keys.size(); i++)
    {
        // iterate through and copy data
        Node* newNode = new Node;
        newNode->key = keys[i];
        newNode->data = data[i];
        newNode->edge = edges[i];
        adjList[i] = newNode;
    }
}

// ================================================================================
// DESTRUCTOR
// ================================================================================
template <class D, class K>
Graph<D, K>::~Graph(void) {
    for (int i = 0; i < adjList.size(); i++)
    {
        delete adjList[i];
    }
}

// ================================================================================
// GET
// Pre-condition: The adjList vector contains valid pointers to nodes.
// Post-condition: Returns a pointer to the graph node with the specified key k if found; otherwise, returns nullptr
// Parameters: 
// K k: the key of the vertex we are looking for
// Return: pointer to the node with key k
// ================================================================================

template <class D, class K>
typename Graph<D, K>::Node* Graph<D, K>::get(K k) const {
    for (int i = 0; i < adjList.size(); i++)
    {
        // interate through the vertices and fine node with key k
        if (adjList[i]->key == k)
        {
            return adjList[i];
        }
    }

    return nullptr;
}


// ================================================================================
// REACHABLE
// Pre-condition: The graph must be valid, and both vertices u and v should be valid keys in the graph.
// Post-condition: Returns true if there exists a path from vertex with key u to the vertex with key v, 
// and false otherwise. If the graph is empty or if u and v are not valid keys, the function returns false.
// K u: the key of a vertex in the graph at the start of the traversal
// K v: the key of the vertex to be determined if reachable from the vertex of key u
// Return: a boolean type indicating whether vertex v is reachable from u
// ================================================================================
template <class D, class K>
bool Graph<D, K>::reachable(K u, K v) {
    // check if graph, u and v are valid
    if (adjList.size() == 0 || get_reachable_helper(u,v) == false)
    {
        return false;
    }
    
    if (u == v) // a node is reachable from itself
    {
        return true;
    }
    set<K> visited;

    return dfs(u, v, visited);
}

// ================================================================================
// BFS
// Pre-condition: The graph (adjList) must be valid and non-empty, and the source node (s) must exist in the graph
// Post-condition: If the precondition is met, the breadth-first search (BFS) algorithm is executed from the source node (s).
// Parameters: 
// K s: the key of the vertex that the BFS algorithm starts at
// Return: None
// ================================================================================

template <class D, class K>
void Graph<D, K>::bfs(K s) {
    // check if graph and s are valid
    if (adjList.size() == 0 || get(s) == nullptr)
    {
        return;
    }
    
    BFS(s); // run bfs from s
}

// ================================================================================
// PRINT_PATH
// Pre-condition: The graph must be valid (adjList is not empty), and the vertices u and v must be part of the graph.
// Post-condition: If a path exists from vertex u to vertex v, the function prints the path in correct order; otherwise, it does nothing.
// Parameters: 
// K u the key of the vertex at the start of the path to be printed
// K v: the key of the vertex at the end of the path to be printed
// Return: None
// ================================================================================
template <class D, class K>
void Graph<D, K>::print_path(K u, K v) {
    // check if graph, u and v are valid
    if (adjList.size() == 0 || get_reachable_helper(u,v) == false)
    {
        return;
    }

    if (u == v){
        cout << u;
        return;
    }
    BFS(u); // run bfs from u

    Node* target = get(v);
    if (target->pi == K()) // if no path exist return
    {
        return;
    }

    stringstream reversedStr;
    reversedStr << v;
    while (target->pi != K())
    {
        // backtrack through pi to make a reversed string
        reversedStr << " >- " << target->pi;
        target = get(target->pi); 
    }

    string res = reversedStr.str();
    reverse(res.begin(), res.end()); // reverse string to get correct order
    
    cout << res;
}

// ================================================================================
// EDGE_CLASS 
// Pre-condition: The graph is valid (not empty), and both vertices u and v are valid and reachable within the graph.
// Post-condition: The function returns a string indicating the type of edge between vertices u and v in the graph 
// ("no edge", "tree edge", "back edge", "forward edge", or "cross edge"). The DFS traversal has been performed if not already executed.
// Parameters: 
// K u: the key of the vertex at the start of the edge
// K v: the key of the vertex at the other end of the edge 
// Return: string indicating the type of the edge between two given vertex
// ================================================================================
template <class D, class K>
string Graph<D, K>::edge_class(K u, K v) {
    // check if graph, u and v are valid
    if (adjList.size() == 0 || get_reachable_helper(u,v) == false)
    {
        // no edge if not valid 
        return "no edge";
    }

    Node* source = get(u);
    Node* target = get(v);
    bool flag = false;
    for (int i = 0; i < source->edge.size(); i++)
    {
        // check if edge exist between two vertex
        if (source->edge[i] == target->key)
        {
            flag = true;
            break;
        }
    }
    if (flag == false) 
    {
        return "no edge";
    }
    
    // run dfs for the graph, only need to run once for each graph
    if (runDFS == false)
    {
        set<K> visited;
        int t = 0;
        for (int i = 0; i < adjList.size(); i++)
        {
            if (visited.find(adjList[i]->key) == visited.end())
            {
                dfs_time(adjList[i]->key, visited, t);
            }
        }
        runDFS = true;
    }

    if (target->startT - source->startT == 1)
    {
        // if source is parent of target then 
        // it is tree edge
        return "tree edge";
    } else if (target->startT < source->startT && target->endT > source->endT)
    {
        // if target has been traversed and is ancestor
        // then it is back edge
        return "back edge";
    } else if (target->startT > source->startT && target->endT < source->endT)
    {
        // if target has been traversed and is descendant 
        // then it is forward edge
        return "forward edge";
    } else
    {
        return "cross edge";
    }
}

// ================================================================================
// BFS_TREE
// Pre-condition: The graph must be initialized with valid nodes and edges.
// Post-condition: Outputs the BFS tree level by level, starting from the specified node 's'.
// Parameters: 
// K s: The key of the starting node for BFS traversal.
// Return: None
// ================================================================================

template <class D, class K>
void Graph<D, K>::bfs_tree(K s) {
    string res = BFS(s); // run bfs from s
    
    cout << res;
}

// ================================================================================
// BFS
// Pre-condition: The graph is valid (non-empty) and the source node 's' exists in the graph.
// Post-condition: Returns a string representation of the BFS traversal starting from the source node 's'.
// K s: The key of the source node for BFS.
// Return: A string representation of BFS traversal.
// ================================================================================
template <class D, class K>
string Graph<D, K>::BFS(K s) {
    Node* source = get(s);
    // check if graph and source s are valid
    if (adjList.size() == 0 || source == nullptr)
    {
        return "";
    }
    
    resetNode(); 
    set<K> visited; // set to check visited node
    list<Node*> q; // queue for bfs

    source->distance = 0; // set distance at source to 0
    q.push_back(source); 
    int thisLevelNode = 1; // keep track of current level node #
    int nextLevelNode = 0; // keep track of next level node #
    visited.insert(source->key); // add source to visited set
    stringstream res;

    while (!q.empty())
    {
        Node* thisNode = q.front();
        q.pop_front();
        thisLevelNode--;
        
        for (int i = 0; i < thisNode->edge.size(); i++)
        {
            // loop through all edges and set their distance and
            // pi if node not visited
            Node* nextNode = get(thisNode->edge[i]);
            if (nextNode == nullptr) // check in case node doesn't exist in list
            {
                continue;
            }
            
            if (visited.find(nextNode->key) == visited.end()) 
            {   
                nextNode->distance = thisNode->distance + 1; // set next level distance
                if (nextNode->pi == K())
                {
                    nextNode->pi = thisNode->key; // set parent    
                }
                q.push_back(nextNode); // push new node on queue
                nextLevelNode++; // keep track of next level node #
                visited.insert(nextNode->key); // add visited node to set
            }
        }
        
        if (thisLevelNode == 0) 
        {
            // if done with this level, move to new line and
            if (nextLevelNode == 0)
            {
                res << thisNode->key;
            } else
            {
                res << thisNode->key << "\n";
            }
            thisLevelNode = nextLevelNode;
            nextLevelNode = 0; // reset next level node #
        } else
        {
            // else continue to add this level node to string
            res << thisNode->key << " ";
        }
    }

    return res.str();
}