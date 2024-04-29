#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using adjacency_matrix = std::vector<std::vector<int>>;
class Graph {
public:
  Graph(size_t vertexs, size_t edges)
      : vertex_count_(vertexs), edge_count_(edges) {
    adjacency_matrix graph(vertex_count_, std::vector<int>(vertex_count_));
    for (size_t i = 0; i < edge_count_; ++i) {
      int a, b;
      std::cin >> a >> b;
      --a;
      --b;
      /* (неориентированный граф) */
      graph[a][b] = 1;
      graph[b][a] = 1;
    }
  }

  // BFS
  std::vector<size_t> BreadthFirstSearch(size_t start) {

    std::vector<size_t> enter_order;
    std::vector<bool> visited(vertex_count_);
    std::queue<size_t> q;

    --start;
    visited[start] = true;
    q.push(start);
    enter_order.emplace_back(start + 1);

    while (!q.empty()) {
      auto from = q.front();
      q.pop();

      for (int i = 0; i != vertex_count_; ++i) {
        if (visited[i] == false) {
          visited[i] = true;
          q.push(i);
          enter_order.emplace_back(i + 1);
        }
      }
    }

    return enter_order;
  }

private:
  adjacency_matrix graph;
  size_t vertex_count_ = 0;
  size_t edge_count_ = 0;
};

int main() {
  Graph g(5, 4);
  std::vector<size_t> order_BFS = g.BreadthFirstSearch(1);
}
