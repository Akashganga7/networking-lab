#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

typedef long long int lli;

map<char, vector<pair<char,lli> > > table;

lli distan[1000];

void init()
{
    table.clear();

    for(lli i=0; i<1000; i++)
    {
        distan[i] = 99999;
    }


}

void dijkstra(char start)
{
    priority_queue<char> q;

    distan[start] = 0;
    q.push(start);

    while(!q.empty())
    {
        char u = q.top();
        q.pop();

        for(lli i=0; i<table[u].size(); i++)
        {
            lli temp = table[u][i].first;

            lli costz = table[u][i].second;

            //cout<<temp<<" "<<distan[temp]<<" "<<distan[u]<<" "<<costz<<endl;

            if(distan[u] + costz < distan[temp])
            {
                distan[temp] = distan[u] + costz;

                //cout<<distan[temp]<<" "<<temp<<endl;

                q.push(table[u][i].first);
            }
        }
    }
}

vector<char> find_path(char start,char stop)
{
    queue<char> q;
    vector<char> path;

    q.push(stop);
    path.push_back(stop);

    lli distance = distan[stop];

    while(!q.empty())
    {
        char u = q.front();
        q.pop();

        char hold;
        lli min_distan = distance;

        for(lli i=0; i<table[u].size(); i++)
        {
            if(table[u][i].first == start)
            {
                path.push_back(table[u][i].first);

                return path;
            }
            if(distan[table[u][i].first] < distance)
            {
                if(distan[table[u][i].first] <= min_distan )
                {
                    hold = table[u][i].first;

                    min_distan = min(min_distan,distan[table[u][i].first]);
                }

            }
        }

        distance = distance - distan[hold];
        q.push(hold);
        path.push_back(hold);
    }
}

int main()
{
    freopen("in.txt","rt",stdin);

    init();

    lli nodes,vertexes;
    cin>>nodes>>vertexes;

    for(lli i=1; i<=vertexes; i++)
    {
        char first,second;
        lli cost;

        cin>>first>>second>>cost;

        table[first].push_back(make_pair(second,cost));
        table[second].push_back(make_pair(first,cost));
    }


    cout<<"Adjacency lists is :"<<endl;

    for(char i = 'A';i<='E';i++)
    {
        cout<<i<<" ";

        for(lli j=0;j<table[i].size();j++)
        {
            cout<<table[i][j].first<<" "<<table[i][j].second<<" ";
        }

        cout<<endl;
    }

    cout<<endl;

    vector<char> path;

    char start,stop;
    cin>>start>>stop;

    dijkstra(start);
    path = find_path(start,stop);


    cout<<"The cost between node (A & D) is: ";
    cout<<distan[stop]<<endl;

    cout<<"The shortest path between node (A & D) is: ";
    for(lli i=path.size()-1;i>=0;i--)
    {
        cout<<path[i]<<" ";
    }
    cout<<endl;

    return 0;
}
