#include<iostream>
#include <list>
#include <limits.h>
using namespace std;
 
// Class for an undirected graph
class Graph
{
     
    // No. of vertices
    int V;  
   
    // Pointer to an array
    // containing adjacency lists
    list<int> *adj; 
    bool isCyclicUtil(int v, bool visited[], int parent);
    public:
   
    // Constructor
    Graph(int V);  
   
    // To add an edge to graph
    void addEdge(int v, int w);
   
    // Returns true if there is a cycle
    bool isCyclic(); 
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    }
 
void Graph::addEdge(int v, int w)
{
     
    // Add w to v’s list.
    adj[v].push_back(w);
   
    // Add v to w’s list.
    adj[w].push_back(v);
}bool Graph::isCyclicUtil(int v,
                bool visited[], int parent)
{
     
    // Mark the current node as visited
    visited[v] = true;
 
    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i !=
                       adj[v].end(); ++i)
    {
        if (!visited[*i])
        {
           if (isCyclicUtil(*i, visited, v))
              return true;
        }
 
        // If an adjacent vertex is visited and
        // is not parent of current vertex,
        // then there exists a cycle in the graph.
        else if (*i != parent)
           return true;
    }
    return false;
}
bool Graph::isCyclic()
{
     
    // Mark all the vertices as not
    // visited and not part of recursion
    // stack
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper
    // function to detect cycle in different
    // DFS trees
    for (int u = 0; u < V; u++)
    { 
        if (!visited[u])
          if (isCyclicUtil(u, visited, -1))
             return true;
    }
    return false;
}
 
// Driver program to test above functions
int main()
{
    int n1,n2;
    int size;
    cin>>size;
    graph g(size);
    for(int i = 0; i<(size*2);i++) {
        cin>>n1>>n2;
        g.drawedge(n1,n2);
    }
    if(g.isCyclic())
        cout << "yes";
    else
        cout << "no";
    return 0;
}