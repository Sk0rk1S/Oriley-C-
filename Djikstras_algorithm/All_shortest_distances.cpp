#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <climits>

//Returns an array of the shortest path from source vertex to every other vertex in the graph
std::vector<int> dijkstra(int n, std::vector<int> edges, int source) {  
    std::vector<int> distances(n, INT_MAX);
    distances[source] = 0;
    std::vector<std::vector<std::pair<int, int>>> graph(n);
    //Making the adjacency list of vectors that store the edge aswell as the weight
    for(int i = 0; i < edges.size(); i+=3)
    {
        //Because there is already a variable named source...
        int source2 = edges[i];
        int destination = edges[i + 1];
        int weight = edges[i + 2];

        graph[source2].push_back({destination, weight});
    }

    std::priority_queue<std::pair<int, int>> pq;
    //Because std::priority queue will use the first parameter to base it's priority
    //The first part of the pair must always be the weight lol
    //The distance from source to itself is always 0 lol
    pq.push(std::make_pair(0, source));

    while(!pq.empty())
    {
        int visited_vertice = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        //For every edge in visited_vertice's adjacency list
        for(auto& neighbour : graph[visited_vertice])
        {
          //If the neighbours weight + the weight of visited_vertice, (because visited_vertice is neighbours parent we must add it's weight)
          //is less than the neighbours current distance, we update the new distance
            if(neighbour.second + weight < distances[neighbour.first])
            {
                distances[neighbour.first] = neighbour.second + weight;
                pq.push(std::make_pair(distances[neighbour.first], neighbour.first));
            }
        }
    }

  //This for loop is optional but I wanted to return an array that marked unreachable vertices as -1 lol
    for(int i = 0; i < distances.size(); i++)
    {
        if(distances[i] == INT_MAX)
        {
            distances[i] = -1;
        }
    }
    return distances;
}
