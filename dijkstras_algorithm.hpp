#ifndef DIJKSTRA
#define DIJKSTRA

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

    double result = 0;
    int curr_node = -1;
    double curr_dist = -1;
    bool is_in = true;
    int cilus_count = 0;
    while (is_in) {
        ++cilus_count;
        if (curr_node == -1) {
            curr_node = edges.first;
            curr_dist = 1;
        } else {
            auto min = std::make_pair(std::begin(unvisited)->first,
                                      std::begin(unvisited)->second);
            for (auto it = std::begin(unvisited); it != std::end(unvisited);
                 ++it) {
                if (it->second >= min.second) {
                    curr_node = it->first;
                    curr_dist = it->second;
                    min.first = it->first;
                    min.second = it->second;
                }
            }
        }

        std::vector<pair> neighbors;
        for (const auto i : wg) {
            if (i->begin_point == curr_node) {
                neighbors.push_back(std::make_pair(i->end_point, i->weight));
            } else if (i->end_point == curr_node) {
                neighbors.push_back(std::make_pair(i->begin_point, i->weight));
            }
        }

        for (int i = 0; i < neighbors.size(); ++i) {
            for (auto it = std::begin(unvisited); it != std::end(unvisited);) {
                if (neighbors[i].first == it->first &&
                    curr_dist * neighbors[i].second >= it->second) {
                    auto first = it->first;
                    it = unvisited.erase(it);
                    unvisited.insert(
                        std::make_pair(first, curr_dist * neighbors[i].second));
                } else {
                    ++it;
                }
            }
        }

        visited.insert(std::make_pair(curr_node, curr_dist));

        for (auto it = std::begin(unvisited); it != std::end(unvisited);) {
            if (it->first == curr_node && it->second == curr_dist) {
                it = unvisited.erase(it);
            } else {
                ++it;
            }
        }

        for (auto it : visited) {
            if (edges.second == it.first) {
                is_in = false;
                result = it.second;
            }
        }

        std::cout << "Current node: " << curr_node << std::endl;
    }

    std::cout << "result: ";
    std::cout << result << std::endl;
}

#endif
