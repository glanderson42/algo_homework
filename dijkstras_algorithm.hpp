#include "weight_graph.hpp"

using pair = std::pair<int, double>;

void dijkstra(std::pair<int, int> edges, weight_graph& wg) {
    std::set<pair> visited;
    std::set<pair> unvisited;
    points p(wg);

    int current_point = edges.first;
    double curr_weight = 1;

    for (const auto i : p.p) {
        if (i == current_point) {
            unvisited.insert(std::make_pair(i, curr_weight));
        } else {
            unvisited.insert(std::make_pair(i, 0));
        }
    }

    std::vector<pair> neighbors;

    for (const auto i : wg) {
        if (i->begin_point == current_point) {
            neighbors.push_back(std::make_pair(i->end_point, i->weight));
        } else if (i->end_point == current_point) {
            neighbors.push_back(std::make_pair(i->begin_point, i->weight));
        }
    }

    for (int i = 0; i < neighbors.size(); ++i) {
        for(auto it = std::begin(unvisited); it != std::end(unvisited); ++it) {
            if(curr_weight == it->second) {
                
            }
        }
    }
}
