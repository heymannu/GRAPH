#include<iostream>
#include<list>
#include<map>
#include<stack>
using namespace std;

class topological {
    public :
    void addEdge(int u , int v,map<int ,list<int>> &adj)
    {
        adj[u].push_back(v);
    }

    void DFS(map<int ,list<int>> &adj,map<int,bool > &visited,int src,stack<int> &s)
    {
        int node = src;
        visited[node] = true ;
        for(auto nbr : adj[node])
        {
            if(!visited[nbr])
            {
                DFS(adj,visited,nbr,s);
            }
        }
         s.push(node); // after completion or termination of program , its pushed into stack
      
    }
    void TopoPrint(stack<int> &s)
    {
        while(!s.empty())
        {
            cout<<s.top() <<" -> ";
            s.pop();
        }
        cout <<"END";
    }
    

};
int main()
{
    map<int ,list<int>> adj;
    map<int,bool > visited;
    stack<int> s;
    int u , v,e,n;
    topological t;
     cout<<"Enter the nodes :";
    cin >> n;
    cout<<"Enter the edges :";
    cin >> e;
    cout<<"Enter the edges :";
    for(int i = 0 ; i < e ; i++){
    cin>> u >> v ;
    t.addEdge(u,v,adj);
    }
    t.DFS(adj,visited,1,s);
    t.TopoPrint(s);
    return 0;
}