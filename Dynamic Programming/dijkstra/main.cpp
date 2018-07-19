#include<bits/stdc++.h>
#define v 9

using namespace std;
int miniDistance(int distance[v], bool sptSet[v])
{
    int xmin=INT_MAX;
    int xmin_index=INT_MAX;
    for(int i=0;i<v;i++)
    {
        if(!sptSet[i] && distance[i]<=xmin)
        {
            xmin=distance[i];
            xmin_index=i;
        }
    }
    return xmin_index;
}
void dijkstra(int graph[v][v], int source)
{
    int distance[v];
    bool sptSet[v];
    for(int i=0;i<v;i++)
    {
        distance[i]=INT_MAX, sptSet[i]=false;
    }
    distance[source]=0;
    for(int i=0; i<v-1;i++)
    {
        int u=miniDistance(distance, sptSet);
        sptSet[u]=true;
        for(int j=0;j<v;j++)
        {
            if(!sptSet[j] && graph[u][j] && distance[u]!=INT_MAX && (distance[u] + graph[u][j] < distance[j]))
                distance[j]=distance[u]+graph[u][j];
        }
    }
    cout << "Minimum distance between " << source << endl;
    for(int i=1;i<v;i++)
    {
        cout << "and " << i << " is " << distance[i] << endl;
    }
}
int main()
{
    int graph[v][v]={ {0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                    };

    dijkstra(graph, 0);
    return 0;
}
