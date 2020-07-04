//
// BellmanFord algorithm implementation in C++
//
// The All ▲lgorithms Project
//
// https://allalgorithms.com/cpp/graphs/bellman-ford/
// https://github.com/allalgorithms/cpp
//
// Contributed by: Nikunj Taneja
// Github: @underscoreorcus
//
#include <bits/stdc++.h>

struct Edge
{
    int src, dest, weight;
};

struct Graph
{
    // V-> Number of vertices, E -> Number of edges
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

void printArr(int dist[], int n)
{
    printf("Vertex  Distance from source\n");
    for (int i = 0; i < n; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void BellmanFord(struct Graph* graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    // Step I: Initialize distances from src to all other vertices
    // as INFITIVE
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    // Step 2: Relax all edges |V| - 1 times shortest
    // path from src to any other vertex can have at-most |V| -1
    // edges
    for (int i = 1; i <= V-1; i++)
    {
        for (int j =0; j < E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Step 3: check for negative-wight cycles.     The above step
    // guarantes shortest distances if graph doesn't contain
    // negative weight cycle.  If we get a shorter path, than there
    // is a cycle
    for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].src;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            printf("Graph contains negative weight cycle");
    }
    printArr(dist, V);
    return;
}

int main()
{
    /* Sample graph */
    int V = 5;
    int E = 8;
    struct Graph* graph = createGraph(V, E);
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;
    BellmanFord(graph, 0);
    return 0;
}
