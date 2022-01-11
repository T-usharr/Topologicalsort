// 

#include <iostream>
#include <vector>
#include <list>

using namespace std;

void addEdge(vector<int> graph[], int u, int v) {
    graph[u].emplace_back(v);
}

void topological_sort(vector<int> graph[], vector<bool>& visited,
                      list<int>& result, int node)
{
    visited[node] = true;
    for (auto i = graph[node].begin(); i != graph[node].end(); i++)
    {
        if (!visited[*i])
           topological_sort(graph, visited, result, *i);
    }
    result.push_front(node);
}

int main() {
    int V = 6;
    vector<int> graph[V];
    vector<bool> visited(V, false);

    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    list<int> result ;
    cout << "Topological sort using DFS: " << endl;
    for (int i=0; i < V; ++i)
        if (!visited[i])
           topological_sort(graph, visited, result, i);
    for (auto i : result)
       cout << i << " ";
    cout << endl;

    return 0;
}


 /* GFG  
#include<bits/stdc++.h>
using namespace std;
void addedge(vector<int>graph[],int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
void toplogical_sortutil(int vertex,vector<int>graph[],vector<bool>visited,stack<int>&stack)
{
    visited[vertex]=true;
    for(auto i=graph[vertex].begin();i!=graph[vertex].end();i++ )
    {
        if(!visited[*i])
        {
            toplogical_sortutil(*i,graph,visited,stack);
        }
        stack.push(vertex);

        }
        
    }
void Toplogical_sort(vector<int>graph[]){
    stack<int>stack;
    vector<bool>visited;

    for(int i=0;i<graph->size();i++){
        visited[i]=false;
    }
    for(int i=0;i<graph->size();i++){
        if(visited[i]==false){
            toplogical_sortutil(i,graph,visited,stack);
        }
    }
    while(!stack.empty()){
        cout<<stack.top()<<" ";
        stack.pop();
    }
}
int main(){
    vector<int>graph[7]; 
 addedge(graph,0,1);
    addedge(graph,0,3);
    addedge(graph,1,2);
    addedge(graph,2,3);
    addedge(graph,2,6);
    addedge(graph,3,4);
    addedge(graph,4,5);
    Toplogical_sort(graph);

    return 0;
}

  */