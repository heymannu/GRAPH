#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

class Topological 
{
    public:

    //creating adjlist
    void adj(int u , int v,map < int , list<int >> &adj)
    {
        adj[u].push_back(v);
    }

    void topologicalSort(map < int , list<int >> &adj,queue<int> &q,int n)
    {

    //finding indegree 
    vector<int> indegree(n);
    for(auto i : adj)
    {
        for(auto j: i.second)
        {
            indegree[j]++;
        }
    }

    //0 degree push into queue
    for(int i =1 ;i<n ; i++)    //check nodes from 0 -> n
    {
        if(indegree[i]==0)
            q.push(i);
    }

    //do bfs 
        while(!q.empty())
        {
            int front = q.front();
            cout<< front << " ";    //printing front
            q.pop();

            for(auto nbr : adj[front])    //checking nbrs
            {
                indegree[nbr]--;        
                if(indegree [nbr]== 0)
                    q.push(nbr);
            }
        }
    }
};

int main()
{
    //list
    Topological t;

    map < int , list<int >> adj;

    queue<int> q;
    
    cout << "Enter the no of vertices :"<< endl;
    int n,m,u,v;
    cin>> n;
    cout << "Enter the no of edges :"<<endl;
    cin>> m;
    cout << "Enter the nodes :" << endl;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> u >> v;
        t.adj(u,v,adj);
    }
    t.topologicalSort(adj,q,n);

}
