#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Graph {
public:
    Graph(int vertices) : numVertices(vertices), adjList(vertices) {}

    void addEdge(int from, int to, int weight) {
        adjList[from].push_back({to, weight});
        // Đối với đồ thị có hướng, chỉ cần thêm cạnh một chiều
        // adjList[to].push_back({from, weight});
    }

    vector<int> dijkstra(int startVertex) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(numVertices, numeric_limits<int>::max());

        pq.push({0, startVertex});
        distance[startVertex] = 0;

        while (!pq.empty()) {
            int currentVertex = pq.top().second;
            int currentDistance = pq.top().first;
            pq.pop();

            if (currentDistance > distance[currentVertex]) {
                continue; // Bỏ qua nếu đã có đường đi ngắn hơn đến đỉnh này
            }

            for (const auto& neighbor : adjList[currentVertex]) {
                int newDistance = currentDistance + neighbor.second;

                if (newDistance < distance[neighbor.first]) {
                    pq.push({newDistance, neighbor.first});
                    distance[neighbor.first] = newDistance;
                }
            }
        }

        return distance;
    }

private:
    int numVertices;
    vector<vector<pair<int, int>>> adjList;
};

int main() {
    Graph graph(6);

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 3, 5);
    graph.addEdge(2, 3, 2);
    graph.addEdge(3, 4, 2);
    graph.addEdge(4, 5, 1);

    int startVertex = 0;

    vector<int> shortestDistances = graph.dijkstra(startVertex);

    cout << "Shortest Distances from Vertex " << startVertex << ":\n";
    for (int i = 0; i < shortestDistances.size(); ++i) {
        cout << "To Vertex " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}

