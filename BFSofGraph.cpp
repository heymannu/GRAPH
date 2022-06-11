#include<iostream>
#include<map>
#include<list>
#include<queue>
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

    void bfs (map<int,list<int>> &adjList,map<int , bool > &visited ,  queue<int> &q , int source)
    {
        q.push(source);
       visited[source] = true ;

        while( !q.empty())
        {
            int node = q.front();
            cout << node;
             q.pop();
            visited[node] = true ;

            for(auto nbr : adjList[node] )
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true ;
                    
                }
            }

        }

    }
};

int main()
{
    // Map DATA STRUCTURE to make an adjacency list....
    map<int , list<int>> adjList;

     map<int , bool > visited ;
        queue<int> q;
    graph g ;

    cout << "Enter the no of vertices :"<< endl;
    int n,m,u,v,d;
    cin>> n;
    cout << "Enter the no of edges :"<<endl;
    cin>> m;
    cout << "Enter the nodes :" << endl;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> u >> v;
        g.addEdge(u,v,false, adjList);
    }
    g.bfs(adjList,visited ,  q , 0);
    return 0;
}
