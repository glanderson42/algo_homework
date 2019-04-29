#include "weight_graph.hpp"

int main() {
    weight_graph wg;

    load_graph_from_file(wg, "graph_1");

    std::cout << wg << std::endl;

    return 0;
}
