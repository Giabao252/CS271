//
//  test_graph.cpp
//  CS 271 Graph Project: Test File
//
//  Created by Dr. Stacey Truex, Bao Luu, Thanh Do, Khoa Nguyen
//

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include "graph.h"

float float_tolerance = 1e-6;
Graph<string, string>* generate_graph(string fname){
    string line;
    ifstream infile(fname);
    vector<string> keys = {};
    vector<string> data = {};
    vector<vector<string>> adjs = {};
    if(infile.is_open()){
        while(getline(infile, line)){
            unsigned long delim = line.find(":");
            string key = line.substr(0, delim);
            string adj = line.substr(delim+1);
            
            keys.push_back(key);
            data.push_back(key + " data");
            delim = adj.find(",");
            vector<string> adj_lst = {};
            while(delim != string::npos){
                adj_lst.push_back(adj.substr(0, delim));
                adj = adj.substr(delim+1);
                delim = adj.find(",");
            }
            adj_lst.push_back(adj);
            adjs.push_back(adj_lst);
        }
    }
    Graph<string,string>* G = new Graph<string, string>(keys, data, adjs);
    return G;
}

void test_get_string(Graph<string,string>* G) {
    try {
        if(G->get("S")==nullptr || G->get("S")->data != "S data") {
            cout << "Incorrect result getting vertex \"s\"" << endl; 
        }
        if(!(G->get("S")->edge[0]== "R")) {
            cout << "Incorrect result getting vertex \"s\"" << endl; 
        }
        if(G->get("a") != nullptr) {
            cout << "Incorrect result getting non-existant vertex \"a\"" << endl;
        }
    } catch(exception& e) {
        cerr << "Error getting vertex from graph : " << e.what() << endl;
    }
}
void test_get_int(Graph<int,int>* G)
{
     try {
        if(G->get(6)==nullptr || G->get(6)->data != 12||G->get(6)->key != 6) {
            cout << "Incorrect result getting vertex \"6\"" << endl; 
        }
        if(!(G->get(6)->edge[0]== 2)) {
            cout << "Incorrect result getting vertex \"s\"" << endl; 
        }
        if(!(G->get(6)->edge[2]== NULL)) {
            cout << "Incorrect result getting vertex \"s\"" << endl; 
        }
        if(G->get(7) != nullptr) {
            cout << "Incorrect result getting non-existant vertex \"a\"" << endl;
        }
        if(!(G->get(1)->edge[0]== 2)) {
            cout << "Incorrect result getting vertex \"s\"" << endl; 
        }
    } catch(exception& e) {
        cerr << "Error getting vertex from graph : " << e.what() << endl;
    }
}
void test_get_int_repeat(Graph<int,int>* G)
{
     try {
        if(G->get(1)==nullptr || G->get(2)->data != 2||G->get(3)->key != 3) {
            cout << "Incorrect result get" << endl; 
        }
        if(!(G->get(3)->edge[0]== 1)) {
            cout << "Incorrect result get" << endl; 
        }
        if(!(G->get(3)->edge[1]== NULL)) {
            cout << "Incorrect result get" << endl; 
        }
        if(G->get(7) != nullptr) {
            cout << "Incorrect result get" << endl; 
        }
        if(!(G->get(1)->edge[0]== 2)) {
            cout << "Incorrect result get" << endl; 
        }
    } catch(exception& e) {
        cerr << "Error getting vertex from graph : " << e.what() << endl;
    }
}
void test_get_empty(Graph<int,int>* G)
{
     try {
        if(!(G->get(1)==nullptr || G->get(2) == nullptr||G->get(3) == nullptr)) {
            cout << "Incorrect result get" << endl; 
        }
    } catch(exception& e) {
        cerr << "Error getting vertex from graph : " << e.what() << endl;
    }
}
void test_get_float(Graph<float,float>* G)
{
     try {
        if(G->get(1.2)==nullptr) {
            cout << "Incorrect result get" << endl;  
        }
        if(G->get(2.3)->data > 4.3 + float_tolerance){
            cout << "Incorrect result get" << endl;  
        } 
        if(G->get(4.34)->key > 4.34 + float_tolerance){
            cout << "Incorrect result get" << endl;  
        }
        if(G->get(1.2)->edge[0] > 1.2+float_tolerance) {
            cout << "Incorrect result get" << endl;  
        }
        if(G->get(1.2)->edge[2] != NULL) {
            cout << "Incorrect result get" << endl;  
        }
        if(G->get(10.2) != nullptr) {
            cout << "Incorrect result get" << endl; 
        }
        if(G->get(2.3)->data > 4.3 + float_tolerance) {
            cout << "Incorrect result get" << endl;  
        }
    } catch(exception& e) {
        cerr << "Error getting vertex from graph : " << e.what() << endl;
    }
}
void test_get_bool(Graph<bool,bool>* G)
{
     try {
        if(G->get(true)==nullptr) {
            cout << "Incorrect result get" << endl;  
        }
        if(G->get(false)==nullptr) {
            cout << "Incorrect result get" << endl;  
        }
        if(G->get(true)->data != false){
            cout << "Incorrect result get" << endl;  
        } 
        if(G->get(false)->data != true){
            cout << "Incorrect result get" << endl;  
        } 
        if(G->get(true)->edge[0] != false){
            cout << "Incorrect result get" << endl;  
        } 
        if(G->get(false)->edge[0] != true){
            cout << "Incorrect result get" << endl;  
        }
        if(G->get(false)->edge[1] != NULL){
            cout << "Incorrect result get" << endl;  
        } 
        if(G->get(true)->edge[1] != NULL){
            cout << "Incorrect result get" << endl;  
        }
        if(G->get(false)->edge[2] != NULL){
            cout << "Incorrect result get" << endl;  
        } 
        if(G->get(true)->edge[2] != NULL){
            cout << "Incorrect result get" << endl;  
        }    
    } catch(exception& e) {
        cerr << "Error getting vertex from graph : " << e.what() << endl;
    }
}
void test_get_char(Graph<char,char>* G)
{
     try {
        if(G->get('a')==nullptr) {
            cout << "Incorrect result get" << endl;  
        }
        if(G->get('b')==nullptr) {
            cout << "Incorrect result get" << endl;  
        }
        if(G->get('a')->data != 'a'){
            cout << "Incorrect result get" << endl;  
        } 
        if(G->get('a')->key != 'a'){
            cout << "Incorrect result get" << endl;  
        } 
        if(G->get('b')->edge[3] != 'e'){
            cout << "Incorrect result get" << endl;  
        } 
        if(G->get('e')->edge != vector<char>()){
            cout << "Incorrect result get" << endl;  
        }
    } catch(exception& e) {
        cerr << "Error getting vertex from graph : " << e.what() << endl;
    }
}
void GetTests(){
    vector<int> empty_keys = {};
    vector<int> empty_data = {};
    vector<vector<int>> empty_edges = {}; //checks for graph with no edges
    
    vector<int> int_keys = {1,2,3,4,5,6};
    vector<int> int_data = {2,4,6,7,10,12};
    vector<vector<int>> int_edges = {{2,6},{3},{4,5},{5},{2},{2,6}}; // also checks for reachable correctness for self-loops
   
    vector<int> int_repeat_keys = {1,2,3};
    vector<int> int_repeat_data = {1,2,3};
    vector<vector<int>> int_repeat_edges = {{2}, {3},{1}}; // checks for reachable correctness with graph of all self-loops

    vector<string> string_keys = {"R","V","S","T","U","Y","W","X"};
    vector<string> string_data = {"R data","V data","S data","T data","U data","Y data","W data","X data"};
    vector<vector<string>> string_edges = {{"V"},{"S"},{"R"},{"S","U","W"},{"Y"},{"W"},{"X"},{"U"}};
    
    vector<float> float_keys = {1.2,2.3,3.3,4.34,5.78,6.6};
    vector<float> float_data = {2.3,4.3,6.3,7.3,10.21,12.213};
    vector<vector<float>> float_edges = {{1.2}, {2.3}, {3.3}, {4.34}, {5.78}, {6.6}}; // checks for reachable correctness with graph of all self-loops

    vector<float> float_repeat_keys = {1.2,2.3};
    vector<float> float_repeat_data = {2.3,4.3};
    vector<vector<float>> float_repeat_edges = {{2.3}, {1.2}}; // checks for reachable correctness with graph of all self-loops

    vector<bool> bool_keys = {true,false};
    vector<bool> bool_data = {false,true};
    vector<vector<bool>> bool_edges = {{false}, {true}}; // checks for infinite loops

    vector<char> char_keys = {'a','b','c','d','e'};
    vector<char> char_data = {'a','b','c','d','e'};
    vector<vector<char>> char_edges = {{'a','b'},{'a','b','c','e'},{'c'},{'e'},{}};
    
    Graph<int,int>* Gempty = new Graph<int,int>(empty_keys, empty_data, empty_edges);
    Graph<string,string>* Gstring = new Graph<string,string>(string_keys, string_data, string_edges);
    Graph<int,int>* Gint = new Graph<int,int>(int_keys, int_data, int_edges);
    Graph<float,float>* Gfloat = new Graph<float,float>(float_keys, float_data, float_edges);
    Graph<bool,bool>* Gbool = new Graph<bool,bool>(bool_keys, bool_data, bool_edges);
    Graph<float,float>* Grepeatfloat = new Graph<float,float>(float_repeat_keys, float_repeat_data, float_repeat_edges);
    Graph<int,int>* Grepeatint = new Graph<int,int>(int_repeat_keys, int_repeat_data, int_repeat_edges);
    Graph<char,char>* Gchar = new Graph<char,char>(char_keys, char_data, char_edges);

    test_get_string(Gstring);
    test_get_int(Gint);
    test_get_int_repeat(Grepeatint);
    test_get_empty(Gempty);
    test_get_float(Gfloat);
    test_get_bool(Gbool);
    test_get_char(Gchar);

    cout << "Finished test get" << endl;
}

void test_reachable_string(Graph<string,string>* G) {
    try {
        if(!G->reachable("R", "V")) {
            cout << "Incorrectly identified adjacent vertex \"V\" as unreachable from \"R\"" << endl;
        }
        if(!G->reachable("X", "W")) {
            cout << "Incorrectly identified \"W\" as unreachable from \"X\"" << endl;
        }
        if(!G->reachable("U", "X")) {
            cout << "Incorrectly identified \"X\" as unreachable from \"U\"" << endl;
        }
        if(G->reachable("S", "A")) {
            cout << "Incorrectly identified non-existant vertex \"A\" as reachable from \"S\"" << endl;
        }
        if(G->reachable("S", "Y")) {
            cout << "Incorrectly identified vertex \"Y\" as reachable from \"S\"" << endl;
        }
    } catch(exception& e) {
        cerr << "Error testing reachable : " << e.what() << endl;
    }
}
void test_reachable_int(Graph<int,int>* G) {
    try {
        if(!G->reachable(1, 2)) {
            cout << "Incorrectly identified adjacent vertex \"V\" as unreachable from \"R\"" << endl;
        }
        if(!G->reachable(1, 3)) {
            cout << "Incorrectly identified \"W\" as unreachable from \"X\"" << endl;
        }
        if(!G->reachable(6, 6)) {
            cout << "Incorrectly identified \"6\" as unreachable from \"6\"" << endl;
        }
        if(!G->reachable(5, 2)) {
            cout << "Incorrectly identified \"2\" as unreachable from \"5\"" << endl;
        }
        if(!G->reachable(6, 2)) {
            cout << "Incorrectly identified \"2\" as unreachable from \"6\"" << endl;
        }
        if(G->reachable(7, 4)) {
            cout << "Incorrectly identified non-existant vertex \"A\" as reachable from \"S\"" << endl;
        }
        if(G->reachable(2, 1)) {
            cout << "Incorrectly identified vertex \"Y\" as reachable from \"S\"" << endl;
        }
    } catch(exception& e) {
        cerr << "Error testing reachable : " << e.what() << endl;
    }
}
void test_reachable_float(Graph<float,float>* G) {
    try {
        if(!G->reachable(1.2, 1.2)) {
            cout << "Incorrectly identified adjacent vertex \"1.2\" as unreachable from \"1.2\"" << endl;
        }
        if(!G->reachable(2.3, 2.3)) {
            cout << "Incorrectly identified \"2.3\" as unreachable from \"2.3\"" << endl;
        }
        if(!G->reachable(3.3, 3.3)) {
            cout << "Incorrectly identified \"3.3\" as unreachable from \"3.3\"" << endl;
        }
        if(!G->reachable(4.34, 4.34)) {
            cout << "Incorrectly identified \"4.34\" as unreachable from \"4.34\"" << endl;
        }
        if(!G->reachable(5.78, 5.78)) {
            cout << "Incorrectly identified \"5.78\" as unreachable from \"5.78\"" << endl;
        }
        if(!G->reachable(6.6, 6.6)) {
            cout << "Incorrectly identified \"6.66\" as unreachable from \"6.66\"" << endl;
        }
        if(G->reachable(5.78, 6.66)) {
            cout << "Incorrectly identified vertex \"Y\" as reachable from non-existant vertex \"S\"" << endl;
        }
        if(G->reachable(5.78, 2.3)) {
            cout << "Incorrectly identified vertex \"Y\" as reachable from non-existant vertex \"S\"" << endl;
        }
        if(G->reachable(4, 5)) {
            cout << "Incorrectly identified non-existant vertex \"A\" as reachable from non-existant vertex \"S\"" << endl;
        }
        if(G->reachable(2, 1)) {
            cout << "Incorrectly identified vertex \"Y\" as reachable from non-existant vertex \"S\"" << endl;
        }
    } catch(exception& e) {
        cerr << "Error testing reachable : " << e.what() << endl;
    }
}
void test_reachable_empty(Graph<int,int>* G) {
    try {
        if(G->reachable(2, 1)) {
            cout << "Incorrectly identified vertex \"Y\" as reachable from non-existant vertex \"S\"" << endl;
        }
        if(G->reachable(0, 3)) {
            cout << "Incorrectly identified vertex \"Y\" as reachable from non-existant vertex \"S\"" << endl;
        }
    } catch(exception& e) {
        cerr << "Error testing reachable : " << e.what() << endl;
    }
}
void test_reachable_bool(Graph<bool,bool>* G) {
    try {
        if(!G->reachable(true, false)) {
            cout << "Incorrectly identified adjacent vertex \"false\" as unreachable from \"true\"" << endl;
        }
        if(!G->reachable(false, true)) {
            cout << "Incorrectly identified \"true\" as unreachable from \"false\"" << endl;
        }
        if(!G->reachable(true, true)) {
            cout << "Incorrectly identified \"true\" as unreachable from \"true\"" << endl;
        }
        if(!G->reachable(false, false)) {
            cout << "Incorrectly identified \"false\" as unreachable from \"false\"" << endl;
        }
    } catch(exception& e) {
        cerr << "Error testing reachable : " << e.what() << endl;
    }
}
void test_reachable_repeat__float(Graph<float,float>* G) {
    try {
        if(!G->reachable(2.3, 1.2)) {
            cout << "Incorrectly identified adjacent vertex \"1.2\" as unreachable from \"2.3\"" << endl;
        }
        if(!G->reachable(1.2, 2.3)) {
            cout << "Incorrectly identified \"2.3\" as unreachable from \"1.2\"" << endl;
        }
        if(!G->reachable(2.3, 2.3)) {
            cout << "Incorrectly identified \"2.3\" as unreachable from \"2.3\"" << endl;
        }
        if(!G->reachable(1.2, 1.2)) {
            cout << "Incorrectly identified \"1.2\" as unreachable from \"1.2\"" << endl;
        }
    } catch(exception& e) {
        cerr << "Error testing reachable : " << e.what() << endl;
    }
}
void test_reachable_repeat__int(Graph<int,int>* G) {
    try {
        if(!G->reachable(1, 1)) {
            cout << "Incorrectly identified adjacent vertex \"1\" as unreachable from \"1\"" << endl;
        }
        if(!G->reachable(1, 2)) {
            cout << "Incorrectly identified adjacent vertex \"1\" as unreachable from \"2\"" << endl;
        }
        if(!G->reachable(1, 3)) {
            cout << "Incorrectly identified adjacent vertex \"1\" as unreachable from \"3\"" << endl;
        }
        if(!G->reachable(2, 1)) {
            cout << "Incorrectly identified adjacent vertex \"2\" as unreachable from \"1-=\"" << endl;
        }
        if(!G->reachable(2, 2)) {
            cout << "Incorrectly identified adjacent vertex \"2\" as unreachable from \"2\"" << endl;
        }
        if(!G->reachable(2, 3)) {
            cout << "Incorrectly identified adjacent vertex \"2\" as unreachable from \"3\"" << endl;
        }
        if(!G->reachable(3, 1)) {
            cout << "Incorrectly identified adjacent vertex \"3\" as unreachable from \"1\"" << endl;
        }
        if(!G->reachable(3, 2)) {
            cout << "Incorrectly identified adjacent vertex \"3\" as unreachable from \"2\"" << endl;
        }
        if(!G->reachable(3, 3)) {
            cout << "Incorrectly identified adjacent vertex \"3\" as unreachable from \"3\"" << endl;
        }
    } catch(exception& e) {
        cerr << "Error testing reachable : " << e.what() << endl;
    }
}
void test_reachable_char(Graph<char,char>* G) {
    try {
        if(!G->reachable('b', 'a')) {
            cout << "Incorrectly identified adjacent vertex \"1\" as unreachable from \"1\"" << endl;
        }
        if(!G->reachable('a', 'b')) {
            cout << "Incorrectly identified adjacent vertex \"1\" as unreachable from \"2\"" << endl;
        }
        if(!G->reachable('a', 'a')) {
            cout << "Incorrectly identified adjacent vertex \"1\" as unreachable from \"3\"" << endl;
        }
        if(!G->reachable('a', 'e')) {
            cout << "Incorrectly identified adjacent vertex \"2\" as unreachable from \"1-=\"" << endl;
        }
        if(!G->reachable('d', 'e')) {
            cout << "Incorrectly identified adjacent vertex \"2\" as unreachable from \"2\"" << endl;
        }
        if(G->reachable('c', 'd')) {
            cout << "Incorrectly identified adjacent vertex \"2\" as unreachable from \"3\"" << endl;
        }
        if(G->reachable('a', 'd')) {
            cout << "Incorrectly identified adjacent vertex \"3\" as unreachable from \"1\"" << endl;
        }
        if(G->reachable('a', 'f')) {
            cout << "Incorrectly identified adjacent vertex \"3\" as unreachable from \"2\"" << endl;
        }
        if(G->reachable('c', 'e')) {
            cout << "Incorrectly identified adjacent vertex \"3\" as unreachable from \"3\"" << endl;
        }
    } catch(exception& e) {
        cerr << "Error testing reachable : " << e.what() << endl;
    }
}
void ReachableTests(){
    vector<int> empty_keys = {};
    vector<int> empty_data = {};
    vector<vector<int>> empty_edges = {}; //checks for graph with no edges
    
    vector<int> int_keys = {1,2,3,4,5,6};
    vector<int> int_data = {2,4,6,7,10,12};
    vector<vector<int>> int_edges = {{2,6},{3},{4,5},{5},{2},{2,6}}; // also checks for reachable correctness for self-loops
   
    vector<int> int_repeat_keys = {1,2,3};
    vector<int> int_repeat_data = {1,2,3};
    vector<vector<int>> int_repeat_edges = {{2}, {3},{1}}; // checks for reachable correctness with graph of all self-loops

    vector<string> string_keys = {"R","V","S","T","U","Y","W","X"};
    vector<string> string_data = {"R data","V data","S data","T data","U data","Y data","W data","X data"};
    vector<vector<string>> string_edges = {{"V"},{"S"},{"R"},{"S","U","W"},{"Y"},{"W"},{"X"},{"U"}};
    
    vector<float> float_keys = {1.2,2.3,3.3,4.34,5.78,6.6};
    vector<float> float_data = {2.3,4.3,6.3,7.3,10.21,12.213};
    vector<vector<float>> float_edges = {{1.2}, {2.3}, {3.3}, {4.34}, {5.78}, {6.6}}; // checks for reachable correctness with graph of all self-loops

    vector<float> float_repeat_keys = {1.2,2.3};
    vector<float> float_repeat_data = {2.3,4.3};
    vector<vector<float>> float_repeat_edges = {{2.3}, {1.2}}; // checks for reachable correctness with graph of all self-loops

    vector<bool> bool_keys = {true,false};
    vector<bool> bool_data = {false,true};
    vector<vector<bool>> bool_edges = {{false}, {true}}; // checks for infinite loops
    
    vector<char> char_keys = {'a','b','c','d','e'};
    vector<char> char_data = {'a','b','c','d','e'};
    vector<vector<char>> char_edges = {{'a','b'},{'a','b','c','e'},{'c'},{'e'},{}};

    Graph<int,int>* Gempty = new Graph<int,int>(empty_keys, empty_data, empty_edges);
    Graph<string,string>* Gstring = new Graph<string,string>(string_keys, string_data, string_edges);
    Graph<int,int>* Gint = new Graph<int,int>(int_keys, int_data, int_edges);
    Graph<float,float>* Gfloat = new Graph<float,float>(float_keys, float_data, float_edges);
    Graph<bool,bool>* Gbool = new Graph<bool,bool>(bool_keys, bool_data, bool_edges);
    Graph<float,float>* Grepeatfloat = new Graph<float,float>(float_repeat_keys, float_repeat_data, float_repeat_edges);
    Graph<int,int>* Grepeatint = new Graph<int,int>(int_repeat_keys, int_repeat_data, int_repeat_edges);
    Graph<char,char>* Gchar = new Graph<char,char>(char_keys, char_data, char_edges);

    test_reachable_string(Gstring);
    test_reachable_int(Gint);
    test_reachable_float(Gfloat);
    test_reachable_repeat__float(Grepeatfloat);
    test_reachable_repeat__int(Grepeatint); //segfaults
    test_reachable_bool(Gbool);
    test_reachable_empty(Gempty);
    test_reachable_char(Gchar);
    cout << "Finished test reachable" << endl;
}

void test_bfs_string(Graph<string, string>* G) {
    try {
        G->bfs("T");
        string vertices[8] = {"V", "R", "S", "W", "T", "X", "U", "Y"};
        int distances[8] = {3,2,1,1,0,2,1,2};
        for(int i = 0; i < 8; i++){
            if(G->get(vertices[i])==nullptr || G->get(vertices[i])->distance!=distances[i]) {
                cout << "Incorrect bfs result. Vertex " << vertices[i] << " should have distance " << distances[i] << " from source vertex \"T\"" << endl;
            }
        }

        G->bfs("U");  
        string vertices1[4] = {"U", "Y", "W", "X"};
        int distances1[4] = {0, 1, 2, 3};
        for (int i = 0; i < 4; i++) {
            if (G->get(vertices1[i]) == nullptr || G->get(vertices1[i])->distance != distances1[i]) {
                cout << "Incorrect bfs result. Vertex " << vertices1[i] << " should have distance " << distances1[i] << " from source vertex \"U\"" << endl;
            }
        }

        G->bfs("R");  
        string vertices2[3] = {"V", "S", "R"};
        int distances2[3] = {1, 2, 0};
        for (int i = 0; i < 3; i++) {
            if (G->get(vertices2[i]) == nullptr || G->get(vertices2[i])->distance != distances2[i]) {
                cout << "Incorrect bfs result. Vertex " << vertices2[i] << " should have distance " << distances2[i] << " from source vertex \"R\"" << endl;
            }
        }
        
        G->bfs("X");  
        string vertices3[4] = {"X", "U", "Y", "W"};
        int distances3[4] = {0, 1, 2, 3};
        for (int i = 0; i < 4; i++) {
            if (G->get(vertices3[i]) == nullptr || G->get(vertices3[i])->distance != distances3[i]) {
                cout << "Incorrect bfs result. Vertex " << vertices3[i] << " should have distance " << distances3[i] << " from source vertex \"X\"" << endl;
            }
        }
    } catch(exception& e) {
        cerr << "Error testing bfs tree : " << e.what() << endl;
    }
}

void test_bfs_int(Graph<int, int>* G) {
    try {
        G->bfs(1);  
        int vertices[6] = {1,2,3,4,5,6};
        int distances[6] = {0,1,2,3,3,1};
        for (int i = 0; i < 6; i++) {
            if (G->get(vertices[i]) == nullptr || G->get(vertices[i])->distance != distances[i]) {
                cout << "Incorrect bfs result. Vertex " << vertices[i] << " should have distance " << distances[i] << " from source vertex \"1\"" << endl;
            }
        }

        G->bfs(6);  
        int vertices1[5] = {6, 2, 3, 4, 5};
        int distances1[5] = {0,1,2,3,3};
        for (int i = 0; i < 5; i++) {
            if (G->get(vertices1[i]) == nullptr || G->get(vertices1[i])->distance != distances1[i]) {
                cout << "Incorrect bfs result. Vertex " << vertices1[i] << " should have distance " << distances1[i] << " from source vertex \"6\"" << endl;
            }
        }

        G->bfs(3);  
        int vertices2[3] = {3, 4, 5};
        int distances2[3] = {0, 1, 1};
        for (int i = 0; i < 3; i++) {
            if (G->get(vertices2[i]) == nullptr || G->get(vertices2[i])->distance != distances2[i]) {
                cout << "Incorrect bfs result. Vertex " << vertices2[i] << " should have distance " << distances2[i] << " from source vertex \"3\"" << endl;
            }
        }

        G->bfs(5);  
        int vertices3[4] = {5, 2, 3, 4};
        int distances3[4] = {0, 1, 2, 3};
        for (int i = 0; i < 4; i++) {
            if (G->get(vertices3[i]) == nullptr || G->get(vertices3[i])->distance != distances3[i]) {
                cout << "Incorrect bfs result. Vertex " << vertices3[i] << " should have distance " << distances3[i] << " from source vertex \"5\"" << endl;
            }
        }
        
    } catch(exception& e) {
        cerr << "Error testing bfs tree : " << e.what() << endl;
    }
}

void test_bfs_float(Graph<float, float>* G) {
    try {
        G->bfs(1.2); 
        float vertices[1] = {1.2};
        int distances[1] = {0};
        for (int i = 0; i < 1; i++) {
            if (G->get(vertices[i]) == nullptr || G->get(vertices[i])->distance != distances[i]) {
                cout << "Incorrect bfs result. Vertex " << vertices[i] << " should have distance " << distances[i] << " from source vertex \"1.2\"" << endl;
            }
        }
        G->bfs(3.3); 
        float vertices1[1] = {3.3};
        int distances1[1] = {0};
        for (int i = 0; i < 1; i++) {
            if (G->get(vertices1[i]) == nullptr || G->get(vertices1[i])->distance != distances1[i]) {
                cout << "Incorrect bfs result. Vertex " << vertices1[i] << " should have distance " << distances1[i] << " from source vertex \"3.3\"" << endl;
            }
        }
        G->bfs(6.6); 
        float vertices2[1] = {6.6};
        int distances2[1] = {0};
        for (int i = 0; i < 1; i++) {
            if (G->get(vertices2[i]) == nullptr || G->get(vertices2[i])->distance != distances2[i]) {
                cout << "Incorrect bfs result. Vertex " << vertices2[i] << " should have distance " << distances2[i] << " from source vertex \"6.6\"" << endl;
            }
        }

    } catch(exception& e) {
        cerr << "Error testing bfs tree : " << e.what() << endl;
    }
}

void test_bfs_bool(Graph<bool, bool>* G) {
    try {
        G->bfs(true); 
        bool vertices[2] = {true, false};
        int distances[2] = {0, 1};
        for (int i = 0; i < 2; i++) {
            if (G->get(vertices[i]) == nullptr || G->get(vertices[i])->distance != distances[i]) {
                cout << "Incorrect bfs result. Vertex " << vertices[i] << " should have distance " << distances[i] << " from source vertex \"true\"" << endl;
            }
        }
        G->bfs(false); 
        bool vertices1[2] = {false, true};
        int distances1[2] = {0, 1};
        for (int i = 0; i < 2; i++) {
            if (G->get(vertices1[i]) == nullptr || G->get(vertices1[i])->distance != distances1[i]) {
                cout << "Incorrect bfs result. Vertex " << vertices1[i] << " should have distance " << distances1[i] << " from source vertex \"false\"" << endl;
            }
        }

    } catch(exception& e) {
        cerr << "Error testing bfs tree : " << e.what() << endl;
    }
}



void BFS_Tests(){
    
    vector<int> int_keys = {1,2,3,4,5,6};
    vector<int> int_data = {2,4,6,7,10,12};
    vector<vector<int>> int_edges = {{2,6},{3},{4,5},{5},{2},{2,6}}; // also checks for reachable correctness for self-loops

    vector<string> string_keys = {"R","V","S","T","U","Y","W","X"};
    vector<string> string_data = {"R data","V data","S data","T data","U data","Y data","W data","X data"};
    vector<vector<string>> string_edges = {{"V"},{"S"},{"R"},{"S","U","W"},{"Y"},{"W"},{"X"},{"U"}};
    
    vector<float> float_keys = {1.2,2.3,3.3,4.34,5.78,6.6};
    vector<float> float_data = {2.3,4.3,6.3,7.3,10.21,12.213};
    vector<vector<float>> float_edges = {{1.2}, {2.3}, {3.3}, {4.34}, {5.78}, {6.6}}; 

    vector<bool> bool_keys = {true,false};
    vector<bool> bool_data = {false,true};
    vector<vector<bool>> bool_edges = {{false}, {true}}; 
    
    Graph<string,string>* Gstring = new Graph<string,string>(string_keys, string_data, string_edges);
    Graph<int,int>* Gint = new Graph<int,int>(int_keys, int_data, int_edges);
    Graph<float,float>* Gfloat = new Graph<float,float>(float_keys, float_data, float_edges);
    Graph<bool,bool>* Gbool = new Graph<bool,bool>(bool_keys, bool_data, bool_edges);

    test_bfs_string(Gstring);
    test_bfs_int(Gint);
    test_bfs_float(Gfloat);
    test_bfs_bool(Gbool);

    cout << "Finished test bfs" << endl;
}


void test_print_path_string(Graph<string,string>* G) {
    try {
        stringstream buffer;
        streambuf* prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path("T", "V");
        cout.rdbuf(prevbuf);
        if(buffer.str()!="T -> S -> R -> V") {
            cout << "Incorrect path from vertex \"T\" to vertex \"V\". Expected: T -> S -> R -> V but got : " << buffer.str() << endl;
        }
        buffer.str("");
        
        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path("R", "U");
        cout.rdbuf(prevbuf);
        if(buffer.str()!="") {
            cout << "Incorrect path from vertex \"T\" to vertex \"V\". Expected: T -> S -> R -> V but got : " << buffer.str() << endl;
        }
        buffer.str("");

        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path("T", "R");
        cout.rdbuf(prevbuf);
        if(buffer.str()!="T -> S -> R") {
            cout << "Incorrect path from vertex \"T\" to vertex \"R\". Expected: T -> S -> R but got : " << buffer.str() << endl;
        }
        buffer.str("");

        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path("T", "Y");
        cout.rdbuf(prevbuf);
        if(buffer.str()!="T -> U -> Y") {
            cout << "Incorrect path from vertex \"T\" to vertex \"Y\". Expected: T -> U -> Y but got : " << buffer.str() << endl; //same length
        }
        buffer.str("");

        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path("T", "A");
        cout.rdbuf(prevbuf);
        if(buffer.str()!="") {
            cout << "Incorrect path from vertex \"T\" to vertex \"Y\". Expected: T -> U -> Y but got : " << buffer.str() << endl; //same length
        }
        buffer.str("");

    } catch(exception& e) {
        cerr << "Error testing print path : " << e.what() << endl;
    }
}
void test_print_path_int(Graph<int,int>* G) {
    try {
        stringstream buffer;
        streambuf* prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path(1, 6);
        cout.rdbuf(prevbuf);
        if(buffer.str()!="1 -> 6") {
            cout << "Incorrect path from vertex \"T\" to vertex \"V\". Expected: T -> S -> R -> V but got : " << buffer.str() << endl;
        }
        buffer.str("");
        
        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path(0,6);
        cout.rdbuf(prevbuf);
        if(buffer.str()!="") {
            cout << "Incorrect path from vertex \"T\" to vertex \"V\". Expected: T -> S -> R -> V but got : " << buffer.str() << endl;
        }
        buffer.str("");

        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path(1,5);
        cout.rdbuf(prevbuf);
        if(buffer.str()!="1 -> 2 -> 3 -> 5") {
            cout << "Incorrect path from vertex \"T\" to vertex \"R\". Expected: T -> S -> R but got : " << buffer.str() << endl;
        }
        buffer.str("");

        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path(1,3);
        cout.rdbuf(prevbuf);
        if(buffer.str()!="1 -> 2 -> 3") {
            cout << "Incorrect path from vertex \"T\" to vertex \"R\". Expected: T -> S -> R but got : " << buffer.str() << endl;
        }
        buffer.str("");

        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path(5,3);
        cout.rdbuf(prevbuf);
        if(buffer.str()!="5 -> 2 -> 3") {
            cout << "Incorrect path from vertex \"T\" to vertex \"R\". Expected: T -> S -> R but got : " << buffer.str() << endl;
        }
        buffer.str("");
        
        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path(6,6);
        cout.rdbuf(prevbuf);
        if(buffer.str()!="6") {
            cout << "Incorrect path from vertex \"6\" to vertex \"6\". Expected: 6 but got : " << buffer.str() << endl;
        }
        buffer.str("");

    } catch(exception& e) {
        cerr << "Error testing print path : " << e.what() << endl;
    }
}
void test_print_path_int_repeat(Graph<int,int>* G) {
    try {
        stringstream buffer;
        streambuf* prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path(1, 3);
        cout.rdbuf(prevbuf);
        if(buffer.str()!="1 -> 2 -> 3") {
            cout << "Incorrect path from vertex \"T\" to vertex \"V\". Expected: T -> S -> R -> V but got : " << buffer.str() << endl;
        }
        buffer.str("");
        
        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path(0,6);
        cout.rdbuf(prevbuf);
        if(buffer.str()!="") {
            cout << "Incorrect path from vertex \"T\" to vertex \"V\". Expected: T -> S -> R -> V but got : " << buffer.str() << endl;
        }
        buffer.str("");

        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path(1,2);
        cout.rdbuf(prevbuf);
        if(buffer.str()!="1 -> 2") {
            cout << "Incorrect path from vertex \"T\" to vertex \"R\". Expected: T -> S -> R but got : " << buffer.str() << endl;
        }
        buffer.str("");

        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path(3,1);
        cout.rdbuf(prevbuf);
        if(buffer.str()!="3 -> 1") {
            cout << "Incorrect path from vertex \"T\" to vertex \"R\". Expected: T -> S -> R but got : " << buffer.str() << endl;
        }
        buffer.str("");

        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path(3,2);
        cout.rdbuf(prevbuf);
        if(buffer.str()!="3 -> 1 -> 2") {
            cout << "Incorrect path from vertex \"T\" to vertex \"R\". Expected: T -> S -> R but got : " << buffer.str() << endl;
        }
        buffer.str("");

    } catch(exception& e) {
        cerr << "Error testing print path : " << e.what() << endl;
    }
}
void test_print_path_float(Graph<float,float>* G) {
    try {
        stringstream buffer;
        streambuf* prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path(1.2, 2.3);
        cout.rdbuf(prevbuf);
        if(buffer.str()!="") {
            cout << "Incorrect path from vertex \"T\" to vertex \"V\". Expected: T -> S -> R -> V but got : " << buffer.str() << endl;
        }
        buffer.str("");
        
        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path(1.2,3.3);
        cout.rdbuf(prevbuf);
        if(buffer.str()!="") {
            cout << "Incorrect path from vertex \"T\" to vertex \"V\". Expected: T -> S -> R -> V but got : " << buffer.str() << endl;
        }
        buffer.str("");

        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path(1.2,1.2);
        cout.rdbuf(prevbuf);
        if(buffer.str()!="1.2") {
            cout << "Incorrect path from vertex \"T\" to vertex \"R\". Expected: T -> S -> R but got : " << buffer.str() << endl;
        }
        buffer.str("");

        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path(99.99,100.1);
        cout.rdbuf(prevbuf);
        if(buffer.str()!="") {
            cout << "Incorrect path from vertex \"T\" to vertex \"R\". Expected: T -> S -> R but got : " << buffer.str() << endl;
        }
        buffer.str("");

    } catch(exception& e) {
        cerr << "Error testing print path : " << e.what() << endl;
    }
}
void test_print_path_int_undirected(Graph<int,int>* G) {
    try {
        stringstream buffer;
        streambuf* prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path(3, 1);
        cout.rdbuf(prevbuf);
        if(buffer.str()!="3 -> 1") {
            cout << "Incorrect path from vertex \"T\" to vertex \"V\". Expected: T -> S -> R -> V but got : " << buffer.str() << endl;
        }
        buffer.str("");
        
        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path(1,2);
        cout.rdbuf(prevbuf);
        if(buffer.str()!="1 -> 2") {
            cout << "Incorrect path from vertex \"T\" to vertex \"V\". Expected: T -> S -> R -> V but got : " << buffer.str() << endl;
        }
        buffer.str("");

        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path(1,3);
        cout.rdbuf(prevbuf);
        if(buffer.str()!="1 -> 3") {
            cout << "Incorrect path from vertex \"T\" to vertex \"V\". Expected: T -> S -> R -> V but got : " << buffer.str() << endl;
        }
        buffer.str("");

        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path(2,3);
        cout.rdbuf(prevbuf);
        if(buffer.str()!="2 -> 3") {
            cout << "Incorrect path from vertex \"T\" to vertex \"R\". Expected: T -> S -> R but got : " << buffer.str() << endl;
        }
        buffer.str("");

        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path(99.99,100.1);
        cout.rdbuf(prevbuf);
        if(buffer.str()!="") {
            cout << "Incorrect path from vertex \"T\" to vertex \"R\". Expected: T -> S -> R but got : " << buffer.str() << endl;
        }
        buffer.str("");

    } catch(exception& e) {
        cerr << "Error testing print path : " << e.what() << endl;
    }
}
void test_print_path_char(Graph<char,char>* G) {
    try {
        stringstream buffer;
        streambuf* prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path('a', 'b');
        cout.rdbuf(prevbuf);
        if(buffer.str()!="a -> b") {
            cout << "Incorrect path from vertex \"T\" to vertex \"V\". Expected: T -> S -> R -> V but got : " << buffer.str() << endl;
        }
        buffer.str("");
        
        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path('a', 'c');
        cout.rdbuf(prevbuf);
        if(buffer.str()!="a -> b -> c") {
            cout << "Incorrect path from vertex \"T\" to vertex \"V\". Expected: T -> S -> R -> V but got : " << buffer.str() << endl;
        }
        buffer.str("");

        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path('a', 'e');
        cout.rdbuf(prevbuf);
        if(buffer.str()!="a -> b -> e") {
            cout << "Incorrect path from vertex \"T\" to vertex \"V\". Expected: T -> S -> R -> V but got : " << buffer.str() << endl;
        }
        buffer.str("");

        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path('b', 'a');
        cout.rdbuf(prevbuf);
        if(buffer.str()!="b -> a") {
            cout << "Incorrect path from vertex \"T\" to vertex \"V\". Expected: T -> S -> R -> V but got : " << buffer.str() << endl;
        }
        buffer.str("");

        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path('a', 'd');
        cout.rdbuf(prevbuf);
        if(buffer.str()!="") {
            cout << "Incorrect path from vertex \"T\" to vertex \"V\". Expected: T -> S -> R -> V but got : " << buffer.str() << endl;
        }
        buffer.str("");

        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path('c', 'e');
        cout.rdbuf(prevbuf);
        if(buffer.str()!="") {
            cout << "Incorrect path from vertex \"T\" to vertex \"V\". Expected: T -> S -> R -> V but got : " << buffer.str() << endl;
        }
        buffer.str("");

        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path('b', 'd');
        cout.rdbuf(prevbuf);
        if(buffer.str()!="") {
            cout << "Incorrect path from vertex \"T\" to vertex \"V\". Expected: T -> S -> R -> V but got : " << buffer.str() << endl;
        }
        buffer.str("");

        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path('a', 'a');
        cout.rdbuf(prevbuf);
        if(buffer.str()!="a") {
            cout << "Incorrect path from vertex \"T\" to vertex \"V\". Expected: T -> S -> R -> V but got : " << buffer.str() << endl;
        }
        buffer.str("");

        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path('d', 'd');
        cout.rdbuf(prevbuf);
        if(buffer.str()!="d") {
            cout << "Incorrect path from vertex \"T\" to vertex \"V\". Expected: T -> S -> R -> V but got : " << buffer.str() << endl;
        }
        buffer.str("");

    } catch(exception& e) {
        cerr << "Error testing print path : " << e.what() << endl;
    }
}
void test_print_path_bool(Graph<bool,bool>* G) {
    try {
        stringstream buffer;
        streambuf* prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path(true, false);
        cout.rdbuf(prevbuf);
        if(buffer.str()!="1 -> 0") {
            cout << "Incorrect path from vertex \"T\" to vertex \"V\". Expected: T -> S -> R -> V but got : " << buffer.str() << endl;
        }
        buffer.str("");
        
        /*prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path(false, true);
        cout.rdbuf(prevbuf);
        if(buffer.str()!="false -> true") {
            cout << "Incorrect path from vertex \"T\" to vertex \"V\". Expected: T -> S -> R -> V but got : " << buffer.str() << endl;
        }
        buffer.str("");*/

        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path(false, false);
        cout.rdbuf(prevbuf);
        if(buffer.str()!="0") {
            cout << "Incorrect path from vertex \"T\" to vertex \"V\". Expected: T -> S -> R -> V but got : " << buffer.str() << endl;
        }
        buffer.str("");

        prevbuf = cout.rdbuf(buffer.rdbuf());
        G->print_path(true, true);
        cout.rdbuf(prevbuf);
        if(buffer.str()!="1") {
            cout << "Incorrect path from vertex \"T\" to vertex \"V\". Expected: T -> S -> R -> V but got : " << buffer.str() << endl;
        }
        buffer.str("");

    } catch(exception& e) {
        cerr << "Error testing print path : " << e.what() << endl;
    }
}
void PrintPathTests(){
    vector<int> empty_keys = {};
    vector<int> empty_data = {};
    vector<vector<int>> empty_edges = {}; //checks for graph with no edges
    
    vector<int> int_keys = {1,2,3,4,5,6,7};
    vector<int> int_data = {2,4,6,7,10,12,14};
    vector<vector<int>> int_edges = {{2,6},{3},{4,5},{5},{2},{2,6},{}}; // also checks for reachable correctness for self-loops
   
    vector<int> int_repeat_keys = {1,2,3};
    vector<int> int_repeat_data = {1,2,3};
    vector<vector<int>> int_repeat_edges = {{2}, {3},{1}}; // checks for reachable correctness with graph of all self-loops

    vector<int> int_keys_undirected = {1,2,3};
    vector<int> int_data_undirected = {1,2,3};
    vector<vector<int>> int_undirected_edges = {{2,3}, {1,3},{1,2}}; // checks for reachable correctness with graph of all self-loops

    vector<string> string_keys = {"R","V","S","T","U","Y","W","X"};
    vector<string> string_data = {"R data","V data","S data","T data","U data","Y data","W data","X data"};
    vector<vector<string>> string_edges = {{"V"},{"S"},{"R"},{"S","U","W"},{"Y"},{"W"},{"X","Y"},{"U"}};
    
    vector<float> float_keys = {1.2,2.3,3.3,4.34,5.78,6.6};
    vector<float> float_data = {2.3,4.3,6.3,7.3,10.21,12.213};
    vector<vector<float>> float_edges = {{1.2}, {2.3}, {3.3}, {4.34}, {5.78}, {6.6}}; // checks for reachable correctness with graph of all self-loops

    vector<float> float_repeat_keys = {1.2,2.3};
    vector<float> float_repeat_data = {2.3,4.3};
    vector<vector<float>> float_repeat_edges = {{2.3}, {1.2}}; // checks for reachable correctness with graph of all self-loops

    vector<bool> bool_keys = {true,false};
    vector<bool> bool_data = {false,true};
    vector<vector<bool>> bool_edges = {{false}, {true}}; // checks for infinite loops
    
    vector<char> char_keys = {'a','b','c','d','e'};
    vector<char> char_data = {'a','b','c','d','e'};
    vector<vector<char>> char_edges = {{'a','b'},{'a','b','c','e'},{'c'},{'e'},{}};

    Graph<int,int>* Gempty = new Graph<int,int>(empty_keys, empty_data, empty_edges);
    Graph<string,string>* Gstring = new Graph<string,string>(string_keys, string_data, string_edges);
    Graph<int,int>* Gint = new Graph<int,int>(int_keys, int_data, int_edges);
    Graph<float,float>* Gfloat = new Graph<float,float>(float_keys, float_data, float_edges);
    Graph<bool,bool>* Gbool = new Graph<bool,bool>(bool_keys, bool_data, bool_edges);
    Graph<float,float>* Grepeatfloat = new Graph<float,float>(float_repeat_keys, float_repeat_data, float_repeat_edges);
    Graph<int,int>* Grepeatint = new Graph<int,int>(int_repeat_keys, int_repeat_data, int_repeat_edges);
    Graph<char,char>* Gchar = new Graph<char,char>(char_keys, char_data, char_edges);
    Graph<int,int>* Gintundirected = new Graph<int,int>(int_keys_undirected, int_data_undirected, int_undirected_edges);

    test_print_path_string(Gstring);
    test_print_path_int(Gint);
    test_print_path_int_repeat(Grepeatint);
    test_print_path_float(Gfloat);
    test_print_path_bool(Gbool);
    test_print_path_char(Gchar);
    test_print_path_int_undirected(Gintundirected);
    cout << "Finished test print_path" << endl;
}


void test_edge_class_string(Graph<string,string>* G) {
    try {
        string e_class =  G->edge_class("R", "V"); // tree edge
        if(e_class != "tree edge") {
            cout << "Misidentified tree edge (\"R\", \"V\") as : " << e_class << endl;
        }
        e_class = G->edge_class("X", "U"); // back edge
        if(e_class != "back edge") {
            cout << "Misidentified back edge (\"X\", \"U\") as : " << e_class << endl;
        }
        e_class =  G->edge_class("R", "U"); // no edge
        if(e_class != "no edge") {
            cout << "Misidentified non-existant edge (\"R\", \"U\") as : " << e_class << endl;
        }
        e_class = G->edge_class("T", "W"); // forward edge
        if(e_class != "forward edge") {
            cout << "Misidentified forward edge (\"T\", \"W\") as : " << e_class << endl;
        }
        e_class = G->edge_class("T", "S"); // cross edge
        if(e_class != "cross edge") {
            cout << "Misidentified forward edge (\"T\", \"S\") as : " << e_class << endl;
        }
        e_class = G->edge_class("R", "R"); // repeat edge
        if(e_class != "no edge") {
            cout << "Misidentified repeat edge (\"R\", \"R\") as : " << e_class << endl;
        }
    } catch(exception& e) {
        cerr << "Error testing edge class : " << e.what() << endl;
    }
    
}
void test_edge_class_int(Graph<int,int>* G) {
    try {
        string e_class =  G->edge_class(2,6);
        if(e_class != "no edge") {
            cout << "Misidentified tree edge (\"2\", \"6\") as : " << e_class << endl;
        }
        e_class = G->edge_class(1,1);
        if(e_class != "no edge") {
            cout << "Misidentified back edge (\"1\", \"1\") as : " << e_class << endl;
        }
        e_class =  G->edge_class(5,2);
        if(e_class != "back edge") {
            cout << "Misidentified back edge (2,1) as : " << e_class << endl;
        }
        e_class =  G->edge_class(1,6);
        if(e_class != "forward edge") {
            cout << "Misidentified back edge (2,1) as : " << e_class << endl;
        }
        e_class = G->edge_class(1, 2);
        if(e_class != "tree edge") {
            cout << "Misidentified tree edge (1,2) as : " << e_class << endl;
        }
        e_class = G->edge_class(1, 100);
        if(e_class != "no edge") {
            cout << "Misidentified no edge (\"1\", \"100\") as : " << e_class << endl;
        }
        e_class = G->edge_class(6, 2); //bugged
        if(e_class != "cross edge") {
            cout << "Misidentified cross edge (\"6\", \"2\") as : " << e_class << endl;
        }
    } catch(exception& e) {
        cerr << "Error testing edge class : " << e.what() << endl;
    }
    
}
void test_edge_class_int_undirected(Graph<int,int>* G) {
    try {
        string e_class =  G->edge_class(1,2);
        if(e_class != "tree edge") {
            cout << "Misidentified tree edge (\"2\", \"6\") as : " << e_class << endl;
        }
    } catch(exception& e) {
        cerr << "Error testing edge class : " << e.what() << endl;
    }
    
}
void test_edge_class_float(Graph<float,float>* G) {
    try {
        string e_class =  G->edge_class(1.2,2.3);
        if(e_class != "no edge") {
            cout << "Misidentified tree edge (\"2\", \"6\") as : " << e_class << endl;
        }
        e_class = G->edge_class(2.3,6.6);
        if(e_class != "no edge") {
            cout << "Misidentified back edge (\"1\", \"1\") as : " << e_class << endl;
        }
        e_class = G->edge_class(1.2, 100);
        if(e_class != "no edge") {
            cout << "Misidentified no edge (\"1\", \"100\") as : " << e_class << endl;
        }
        e_class = G->edge_class(100, 2.3);
        if(e_class != "no edge") {
            cout << "Misidentified no edge (\"1\", \"100\") as : " << e_class << endl;
        }
    } catch(exception& e) {
        cerr << "Error testing edge class : " << e.what() << endl;
    }
}
void test_edge_class_repeat_float(Graph<float,float>* G) {
    try {
        string e_class =  G->edge_class(1.2,2.3);
        if(e_class != "tree edge") {
            cout << "Misidentified tree edge (\"2\", \"6\") as : " << e_class << endl;
        }
        e_class = G->edge_class(2.3,1.2);
        if(e_class != "back edge") {
            cout << "Misidentified back edge (\"1\", \"1\") as : " << e_class << endl;
        }
        e_class =  G->edge_class(1.2,1.2);
        if(e_class != "no edge") {
            cout << "Misidentified back edge (2,1) as : " << e_class << endl;
        }
        e_class =  G->edge_class(2.3,2.3);
        if(e_class != "no edge") {
            cout << "Misidentified back edge (2,1) as : " << e_class << endl;
        }
    } catch(exception& e) {
        cerr << "Error testing edge class : " << e.what() << endl;
    }
}
void test_edge_class_empty(Graph<int,int>* G) {
    try {
        string e_class =  G->edge_class(2,6);
        if(e_class != "no edge") {
            cout << "Misidentified tree edge (\"2\", \"6\") as : " << e_class << endl;
        }
        e_class = G->edge_class(1,1);
        if(e_class != "no edge") {
            cout << "Misidentified back edge (\"1\", \"1\") as : " << e_class << endl;
        }
        e_class =  G->edge_class(5,2);
        if(e_class != "no edge") {
            cout << "Misidentified back edge (2,1) as : " << e_class << endl;
        }
        e_class =  G->edge_class(1,6);
        if(e_class != "no edge") {
            cout << "Misidentified back edge (2,1) as : " << e_class << endl;
        }
        e_class = G->edge_class(1, 2);
        if(e_class != "no edge") {
            cout << "Misidentified tree edge (1,2) as : " << e_class << endl;
        }
        e_class = G->edge_class(6, 6);
        if(e_class != "no edge") {
            cout << "Misidentified forward edge (1,3) as : " << e_class << endl;
        }
        e_class = G->edge_class(1, 100);
        if(e_class != "no edge") {
            cout << "Misidentified no edge (\"1\", \"100\") as : " << e_class << endl;
        }
        e_class = G->edge_class(6, 2); //bugged
        if(e_class != "no edge") {
            cout << "Misidentified cross edge (\"6\", \"2\") as : " << e_class << endl;
        }
    } catch(exception& e) {
        cerr << "Error testing edge class : " << e.what() << endl;
    }
    
}
void test_edge_class_bool(Graph<bool,bool>* G) {
    try {
        string e_class =  G->edge_class(true,false);
        if(e_class != "tree edge") {
            cout << "Misidentified tree edge (\"2\", \"6\") as : " << e_class << endl;
        }
        e_class =  G->edge_class(true,true);
        if(e_class != "no edge") {
            cout << "Misidentified tree edge (\"2\", \"6\") as : " << e_class << endl;
        }
        e_class =  G->edge_class(false,false);
        if(e_class != "no edge") {
            cout << "Misidentified tree edge (\"2\", \"6\") as : " << e_class << endl;
        }
        e_class =  G->edge_class(false,true);
        if(e_class != "back edge") {
            cout << "Misidentified tree edge (\"2\", \"6\") as : " << e_class << endl;
        }
    } catch(exception& e) {
        cerr << "Error testing edge class : " << e.what() << endl;
    }
    
}
void test_edge_class_char(Graph<char,char>* G) {
    try {
        string e_class =  G->edge_class('a','b');
        if(e_class != "tree edge") {
            cout << "Misidentified tree edge (\"2\", \"6\") as : " << e_class << endl;
        }
        e_class =  G->edge_class('a','d');
        if(e_class != "no edge") {
            cout << "Misidentified no edge (\"2\", \"6\") as : " << e_class << endl;
        }
        e_class =  G->edge_class('a','f');
        if(e_class != "no edge") {
            cout << "Misidentified no edge (\"2\", \"6\") as : " << e_class << endl;
        }
        e_class =  G->edge_class('c','d');
        if(e_class != "no edge") {
            cout << "Misidentified no edge (\"2\", \"6\") as : " << e_class << endl;
        }
        e_class =  G->edge_class('c','e');
        if(e_class != "no edge") {
            cout << "Misidentified no edge (\"2\", \"6\") as : " << e_class << endl;
        }
        e_class =  G->edge_class('b','a');
        if(e_class != "back edge") {
            cout << "Misidentified back edge (\"2\", \"6\") as : " << e_class << endl;
        }
    } catch(exception& e) {
        cerr << "Error testing edge class : " << e.what() << endl;
    }
    
}
void EdgeClassTests(){
    vector<int> empty_keys = {};
    vector<int> empty_data = {};
    vector<vector<int>> empty_edges = {}; //checks for graph with no edges
    
    vector<int> int_keys = {1,2,3,4,5,6};
    vector<int> int_data = {2,4,6,7,10,12};
    vector<vector<int>> int_edges = {{2,6},{3},{4,5},{5},{2},{2,6}}; // also checks for reachable correctness for self-loops
   
    vector<int> int_repeat_keys = {1,2,3};
    vector<int> int_repeat_data = {1,2,3};
    vector<vector<int>> int_repeat_edges = {{2}, {3},{1}}; // checks for reachable correctness with graph of all self-loops

    vector<string> string_keys = {"R","V","S","T","U","Y","W","X"};
    vector<string> string_data = {"R data","V data","S data","T data","U data","Y data","W data","X data"};
    vector<vector<string>> string_edges = {{"V"},{"S"},{"R"},{"S","U","W"},{"Y"},{"W"},{"X"},{"U"}};
    
    vector<float> float_keys = {1.2,2.3,3.3,4.34,5.78,6.6};
    vector<float> float_data = {2.3,4.3,6.3,7.3,10.21,12.213};
    vector<vector<float>> float_edges = {{1.2}, {2.3}, {3.3}, {4.34}, {5.78}, {6.6}}; // checks for reachable correctness with graph of all self-loops

    vector<float> float_repeat_keys = {1.2,2.3};
    vector<float> float_repeat_data = {2.3,4.3};
    vector<vector<float>> float_repeat_edges = {{2.3}, {1.2}}; // checks for reachable correctness with graph of all self-loops

    vector<bool> bool_keys = {true,false};
    vector<bool> bool_data = {false,true};
    vector<vector<bool>> bool_edges = {{false}, {true}}; // checks for infinite loops
    
    vector<int> int_keys_undirected = {1,2,3};
    vector<int> int_data_undirected = {1,2,3};
    vector<vector<int>> int_undirected_edges = {{2,3}, {1,3},{1,2}}; 

    vector<char> char_keys = {'a','b','c','d','e'};
    vector<char> char_data = {'a','b','c','d','e'};
    vector<vector<char>> char_edges = {{'a','b'},{'a','b','c','e'},{'c'},{'e'},{}};

    Graph<int,int>* Gempty = new Graph<int,int>(empty_keys, empty_data, empty_edges);
    Graph<string,string>* Gstring = new Graph<string,string>(string_keys, string_data, string_edges);
    Graph<int,int>* Gint = new Graph<int,int>(int_keys, int_data, int_edges);
    Graph<float,float>* Gfloat = new Graph<float,float>(float_keys, float_data, float_edges);
    Graph<bool,bool>* Gbool = new Graph<bool,bool>(bool_keys, bool_data, bool_edges);
    Graph<float,float>* Grepeatfloat = new Graph<float,float>(float_repeat_keys, float_repeat_data, float_repeat_edges);
    Graph<int,int>* Grepeatint = new Graph<int,int>(int_repeat_keys, int_repeat_data, int_repeat_edges);
    Graph<int,int>* Gintundirected = new Graph<int,int>(int_keys_undirected, int_data_undirected, int_undirected_edges);
    Graph<char,char>* Gchar = new Graph<char,char>(char_keys, char_data, char_edges);

    test_edge_class_string(Gstring);
    test_edge_class_int(Gint);
    test_edge_class_int_undirected(Gintundirected);
    test_edge_class_float(Gfloat);
    test_edge_class_repeat_float(Grepeatfloat);
    test_edge_class_empty(Gempty);
    test_edge_class_bool(Gbool);
    test_edge_class_char(Gchar);
}

void test_bfs_tree_string(Graph<string, string>* G) {
    try {
        stringstream buffer;
        streambuf* prevbuf = cout.rdbuf(buffer.rdbuf());
        G->bfs_tree("T");
        cout.rdbuf(prevbuf);
        if(buffer.str() != "T\nS U W\nR Y X\nV") {
            cout << "Incorrect bfs tree. Expected : \nT\nS U W\nR Y X\nV \nbut got :\n" << buffer.str() << endl;
        }
        stringstream buffer1;
        streambuf* prevbuf1 = cout.rdbuf(buffer1.rdbuf());
        G->bfs_tree("S");
        cout.rdbuf(prevbuf1);
        if(buffer1.str() != "S\nR\nV") {
            cout << "Incorrect bfs tree for Test Case 2. Expected : \nS\nR U V W X Y T \nbut got :\n" << buffer1.str() << endl;
        }
    } catch(exception& e) {
        cerr << "Error testing bfs tree : " << e.what() << endl;
    }
}

void test_bfs_tree_int(Graph<int, int>* G) {
    try {
        stringstream buffer;
        streambuf* prevbuf = cout.rdbuf(buffer.rdbuf());
        G->bfs_tree(1);
        cout.rdbuf(prevbuf);
        if(buffer.str() != "1\n2 6\n3\n4 5") {
            cout << "Incorrect bfs tree. Expected : \n1\n2 6\n3\n4 5\nbut got :\n" << buffer.str() << endl;
        }
        stringstream buffer1;
        streambuf* prevbuf1 = cout.rdbuf(buffer1.rdbuf());
        G->bfs_tree(3);
        cout.rdbuf(prevbuf1);
        if(buffer1.str() != "3\n4 5\n2") {
            cout << "Incorrect bfs tree for Test Case 2. Expected : \n3\n 4 5\n2\nbut got :\n" << buffer1.str() << endl;
        }

        stringstream buffer2;
        streambuf* prevbuf2 = cout.rdbuf(buffer2.rdbuf());
        G->bfs_tree(5);
        cout.rdbuf(prevbuf2);
        if(buffer2.str() != "5\n2\n3\n4") {
            cout << "Incorrect bfs tree for Test Case 3. Expected : \n5\n2\n3\n4\nbut got :\n" << buffer2.str() << endl;
        }
    } catch(exception& e) {
        cerr << "Error testing bfs tree : " << e.what() << endl;
    }
}

void test_bfs_tree_float(Graph<float, float>* G) {
    try {
        stringstream buffer;
        streambuf* prevbuf = cout.rdbuf(buffer.rdbuf());
        G->bfs_tree(1.2);
        cout.rdbuf(prevbuf);
        if(buffer.str() != "1.2") {
            cout << "Incorrect bfs tree. Expected : \n1.2\nbut got :\n" << buffer.str() << endl;
        }
        stringstream buffer1;
        streambuf* prevbuf1 = cout.rdbuf(buffer1.rdbuf());
        G->bfs_tree(3.3);
        cout.rdbuf(prevbuf1);
        if(buffer1.str() != "3.3") {
            cout << "Incorrect bfs tree for Test Case 2. Expected : \n1.2\nbut got :\n" << buffer1.str() << endl;
        }

        stringstream buffer2;
        streambuf* prevbuf2 = cout.rdbuf(buffer2.rdbuf());
        G->bfs_tree(6.6);
        cout.rdbuf(prevbuf2);
        if(buffer2.str() != "6.6") {
            cout << "Incorrect bfs tree for Test Case 3. Expected : \n1.2\nbut got :\n" << buffer2.str() << endl;
        }
    } catch(exception& e) {
        cerr << "Error testing bfs tree : " << e.what() << endl;
    }
}

void test_bfs_tree_bool(Graph<bool, bool>* G) {
    try {
        stringstream buffer;
        streambuf* prevbuf = cout.rdbuf(buffer.rdbuf());
        G->bfs_tree(true);
        cout.rdbuf(prevbuf);
        if(buffer.str() != "1\n0") {
            cout << "Incorrect bfs tree. Expected : \n1\n0\nbut got :\n" << buffer.str() << endl;
        }
        stringstream buffer1;
        streambuf* prevbuf1 = cout.rdbuf(buffer1.rdbuf());
        G->bfs_tree(false);
        cout.rdbuf(prevbuf1);
        if(buffer1.str() != "0\n1") {
            cout << "Incorrect bfs tree for Test Case 2. Expected : \n1\n0\nbut got :\n" << buffer1.str() << endl;
        }
    } catch(exception& e) {
        cerr << "Error testing bfs tree : " << e.what() << endl;
    }
}
void test_bfs_tree_empty(Graph<int, int>* G) {
    try {
        stringstream buffer;
        streambuf* prevbuf = cout.rdbuf(buffer.rdbuf());
        G->bfs_tree(true);
        cout.rdbuf(prevbuf);
        if(buffer.str() != "") {
            cout << "Incorrect bfs tree. Expected : \n1\n0\nbut got :\n" << buffer.str() << endl;
        }
    } catch(exception& e) {
        cerr << "Error testing bfs tree : " << e.what() << endl;
    }
}

void BFS_TreeTests(){
    
    vector<int> int_keys = {1,2,3,4,5,6};
    vector<int> int_data = {2,4,6,7,10,12};
    vector<vector<int>> int_edges = {{2,6},{3},{4,5},{5},{2},{2,6}}; // also checks for reachable correctness for self-loops

    vector<string> string_keys = {"R","V","S","T","U","Y","W","X"};
    vector<string> string_data = {"R data","V data","S data","T data","U data","Y data","W data","X data"};
    vector<vector<string>> string_edges = {{"V"},{"S"},{"R"},{"S","U","W"},{"Y"},{"W"},{"X"},{"U"}};
    
    vector<float> float_keys = {1.2,2.3,3.3,4.34,5.78,6.6};
    vector<float> float_data = {2.3,4.3,6.3,7.3,10.21,12.213};
    vector<vector<float>> float_edges = {{1.2}, {2.3}, {3.3}, {4.34}, {5.78}, {6.6}}; 

    vector<bool> bool_keys = {true,false};
    vector<bool> bool_data = {false,true};
    vector<vector<bool>> bool_edges = {{false}, {true}}; // checks for infinite loops
    
    Graph<string,string>* Gstring = new Graph<string,string>(string_keys, string_data, string_edges);
    Graph<int,int>* Gint = new Graph<int,int>(int_keys, int_data, int_edges);
    Graph<int,int>* Gempty = new Graph<int,int>({},{},{});
    Graph<float,float>* Gfloat = new Graph<float,float>(float_keys, float_data, float_edges);
    Graph<bool,bool>* Gbool = new Graph<bool,bool>(bool_keys, bool_data, bool_edges);

    test_bfs_tree_empty(Gempty);
    test_bfs_tree_string(Gstring);
    test_bfs_tree_int(Gint);
    test_bfs_tree_float(Gfloat);
    test_bfs_tree_bool(Gbool);

    cout << "Finished test bfs_tree" << endl;
}

int main() {

    Graph<string,string>* G = generate_graph("graph_description.txt");
    cout << "Finished creating the graph" << endl;

    ReachableTests();
    BFS_Tests();
    GetTests();
    EdgeClassTests();
    PrintPathTests();
    BFS_TreeTests();

    cout << "Testing completed" << endl;

    delete G;

    return 0;
}