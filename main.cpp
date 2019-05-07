#include "weight_graph.hpp"
#include "dijkstras_algorithm.hpp"

int main() {
    weight_graph wg;
    // ut kiiratasa curr node kiirtasa
    load_graph_from_file(wg, "graph_4");
    std::cout << wg << std::endl;
    std::pair<int, int> p = std::make_pair(1, 4);
    dijkstra(p, wg);   
    std::cout << wg << std::endl;

    return 0;
}
