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

    void print(map<int , list<int>> adjList)
    {
        for(auto i : adjList) // Prints int part
        {
            cout<< i.first <<" ->  ";
            for(auto j : i.second) // Prints List's part 
                cout<< j <<" ,";
                cout<< endl;
        }
        
    }
};

int main()
{
    // Map DATA STRUCTURE to make an adjacency list....
    map<int , list<int>> adjList;
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
    g.print( adjList);
    return 0;
}
