#include<bits/stdc++.h>
#define inf 100000
using namespace std;

int source,totalnode,totaledge,node1,node2,weight;
vector<vector<pair<int,int> > >adjlist(1000);
vector<int>dist;
vector<int>par;

int pathfind(int dst)
{
    if(dst!=source && par[dst]==-1)
    {
        cout<<"path not found";
        return 0;
    }
    else if(dst==source)
    {
        cout<<source;
        return 0;
    }
    pathfind(par[dst]);
    cout<<" "<<dst;
}
int main()
{

    cin>>totalnode>>totaledge;
    for(int i=0;i<totaledge;i++)
    {
        cin>>node1>>node2>>weight;
        adjlist[node1].push_back(make_pair(node2,weight));
    }
    for(int i=0;i<totalnode;i++)
    {
        cout<<i<<".";
        for(int j=0;j<adjlist[i].size();j++)
        {
            cout<<adjlist[i][j].first<<"("<<adjlist[i][j].second<<")->";
        }
        cout<<endl;
    }
    int testcase;
    cin>>testcase;
    while(testcase--){
    cout<<"Enter Source:";
    cin>>source;
    dist.assign(totalnode,inf);
    par.assign(totalnode,-1);
    dist[source]=0;
    for(int i=0;i<totalnode-1;i++)
    {
        for(int u=0;u<totalnode;u++)
        {
            for(int j=0;j<adjlist[u].size();j++)
            {
                pair<int,int> v=adjlist[u][j];
                if(dist[u]==inf)
                    continue;
                if(dist[u]+v.second<dist[v.first])
                {
                    dist[v.first]=dist[u]+v.second;
                    par[v.first]=u;
                }
            }
        }
    }
    bool hascycle=false;
    for(int u=0;u<totalnode;u++)
    {
        for(int j=0;j<adjlist[u].size();j++)
            {
                pair<int,int>v=adjlist[u][j];
                if(dist[u]==inf)
                    continue;
                    if(dist[u]+v.second<dist[v.first])
                    {
                        hascycle=true;
                        break;
                    }
            }
            if(hascycle)
               break;
    }
    if(hascycle)
    {
        cout<<"The graph has negative cycle";

    }
    else{

        int dest;
        cout<<"enter destination: ";
        cin>>dest;
        cout<<"distance: "<<dist[dest]<<endl;
        pathfind(dest);
    }
    }
}


/*
5 10
0 1 -1
0 2 2
0 3 4
1 0 2
1 2 3
2 3 5
2 4 3
3 2 -1
4 3 4
4 1 -3
*/

