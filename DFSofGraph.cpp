#include<iostream>
#include<map>
#include<list>
using namespace std;

// template <typename T> To make it a generic class 
class graph {

public :
//Adding edges 
    void addEdge(int  u,int  v, bool d,map<int,list<int>> &adjList)
    {
        adjList[u].push_back(v);
        if(d == false) // For direction
            adjList[v].push_back(u);
    }

    void dfs(map<int,list<int>> &adjList,   map<int , bool > &visited,int source)
    {
        cout << source << " ";
        visited[source] = true;
        for(auto nbr : adjList[source])
        {
            if(!visited[nbr])
                dfs(adjList,visited,nbr);
        }
    }
    void falser(map<int,list<int>> &adjList,   map<int , bool > &visited, int source)
    {
        for(auto i : adjList)
        {
            int node = i.first;
            visited[node] = false;
        }
        dfs(adjList, visited,source);
    }
    
};

int main()
{
    // Map DATA STRUCTURE to make an adjacency list....
    map<int , list<int>> adjList;
    map<int , bool > visited;
    graph g ;

    // cout << "Enter the no of vertices :"<< endl;
    // int n,m,u,v,d;
    // cin>> n;
    // cout << "Enter the no of edges :"<<endl;
    // cin>> m;
    // cout << "Enter the nodes :" << endl;
    // for(int i = 0 ; i < m ; i++)
    // {
    //     cin >> u >> v;
    //     g.addEdge(u,v,false, adjList);
    // }
    g.addEdge(0,1,false,adjList);
       g.addEdge(1,2,false,adjList);
          g.addEdge(1,4,false,adjList);
             g.addEdge(4,5,false,adjList);
                g.addEdge(2,3,false,adjList);
                
                  g.falser(adjList,visited,0);
        

    return 0;
}
