#include <iostream>
#include <vector>

// Представление графов

// Список ребер
using edge_list = std::vector<std::pair<int, int>>;

edge_list init_graph_1(int vertex_count, int edge_count) {
  edge_list graph(edge_count);
  std::cout << "init graph edge list\n";
  for (auto &[a, b] : graph) {
    std::cin >> a >> b;
  }
  std::cout << '\n';

  return graph;
}

// Матрица смежности
using adjacency_matrix = std::vector<std::vector<int>>;

adjacency_matrix init_graph_2(int vertex_count, int edge_count) {
  adjacency_matrix graph(vertex_count, std::vector<int>(vertex_count));
  std::cout << "init graph adjacency_matrix\n";
  for (size_t i = 0; i < edge_count; ++i) {
    int a, b;
    std::cin >> a >> b;

    /* (неориентированный граф) */
    graph[a][b] = 1;
    graph[b][a] = 1;
  }
  std::cout << '\n';
  return graph;
};

// Список смежности
using adjacency_list = std::vector<std::vector<int>>;

adjacency_list init_graph_3(int vertex_count, int edge_count) {
  adjacency_list graph(vertex_count);
  std::cout << "init graph adjacency_list\n";
  for (size_t i = 0; i < edge_count; i++) {
    int a, b;
    std::cin >> a >> b;

    /* (неориентированный граф) */
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  std::cout << '\n';
  return graph;
}

int main() {
  edge_list graph_1 = init_graph_1(3, 2);
  adjacency_matrix graph_2 = init_graph_2(4, 3);
  adjacency_list graph_3 = init_graph_3(5, 4);
}