#include<bits/stdc++.h>
using namespace std;
struct Edge
{
	int src, dest, weight;
};
struct Graph
{
	int V, E;
	struct Edge *edge;
};
struct Graph* createGraph(int V, int E)
{
	struct Graph * graph=new Graph;
	graph->V=V;
	graph->E=E;
	graph->edge=new Edge[E];
	return graph;
}

bool compareInterval(Edge a, Edge b)
{
	return (a.weight < b.weight);
}
int root(int parent[], int x)
{
	while(parent[x]!=x)
	{
		x=parent[x];
	}
	return x;
}
void KruskalMST(struct Graph* graph)
{
	sort(graph->edge, graph->edge+graph->E, compareInterval);
	int n=graph->E;
	int parent[graph->V];
	for(int i=0;i<graph->V;i++)
		parent[i]=i;
	int i=0, j=0;
	struct Edge* edge=graph->edge;
	vector<int> v(graph->V - 1);
	while(j<(graph->V-1))
	{
		int x_root=root(parent, edge[i].src);
		int y_root=root(parent, edge[i].dest);
		if(x_root!=y_root)
		{
			v[j]=i;
			j++;
			parent[y_root]=x_root;
		}
		i++;
	}
	for(i=0;i<graph->V-1;i++)
	{
		j=v[i];
		cout << edge[j].src << "  " << edge[j].dest << "  " << edge[j].weight << endl;
	}
}
int main()
 {
 	int V, E;
 	V=4;
 	E=5;

 	struct Graph* graph = createGraph(V, E);
 
 
    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;
 
    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;
 
    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;
 
    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;
 
    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;
 
    KruskalMST(graph);

 	return 0;
 } 
