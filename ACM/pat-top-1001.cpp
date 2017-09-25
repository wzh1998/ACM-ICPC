#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef struct edge{
    int cost;
    int node_first;
    int node_second;
    int state;
}edge;

bool compare(edge &a,edge &b){
    if(a.state != b.state)
        return a.state > b.state;
    if(a.node_first != b.node_first)
        return a.node_first < b.node_first;
    return a.cost < b.cost;
}

