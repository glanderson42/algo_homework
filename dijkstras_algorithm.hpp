#ifndef DIJKSTRA
#define DIJKSTRA

#include "weight_graph.hpp"
#include <chrono>
#include <thread>

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
    double result;
    int curr_node = -1;
    double curr_dist = -1;
    bool is_in = true;
    int cilus_count = 0;
    while (is_in) {
        ++cilus_count;
        if (curr_node == -1) {
            curr_node = edges.first;
            curr_dist = 1;
            std::cout << "ELSO IF" << std::endl;
        } else {
            auto min = std::make_pair(std::begin(unvisited)->first, std::begin(unvisited)->second);
            std::cout << "Min: " << min.first << " " << min.second << std::endl;
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(3s);
            for (auto it = std::begin(unvisited); it != std::end(unvisited);
                 ++it) {
                if (it->second >= min.second) {
                    std::cout << "A" << std::endl;
                    curr_node = it->first;
                    curr_dist = it->second; 
                    min.first = it->first;
                    min.second = it->second;
                } else std:: cout << "B" << std::endl;
            }
        }

        std::vector<pair> neighbors;
        for (const auto i : wg) {
            if (i->begin_point == curr_node) {
                neighbors.push_back(std::make_pair(i->end_point, i->weight));
                std::cout << "C" << std::endl;
            } else if (i->end_point == curr_node) {
                std::cout << "D" << std::endl;
                neighbors.push_back(std::make_pair(i->begin_point, i->weight));
            }
        }

        std::cout << "UNVISITED" << std::endl;
        for(const auto it : unvisited) {
            std::cout << it.first << " :: " << it.second << std::endl;
        }
        using namespace std::chrono_literals;
        //std::this_thread::sleep_for(2s);

        std::cout << "NEIGHBORS" << std::endl;
        for(const auto it : neighbors) {
            std::cout << it.first << " :: " << it.second << std::endl;
        }

        //std::this_thread::sleep_for(2s);
        std::cout << curr_dist << std::endl;        
        for(int i = 0; i < neighbors.size(); ++i) {
            for(auto it = std::begin(unvisited); it != std::end(unvisited); ) {
                if(neighbors[i].first == it->first && curr_dist * neighbors[i].second >= it->second) {
                    std::cout << "E" << std::endl;
                    auto first = it->first;
                    it = unvisited.erase(it);
                    //it->second = curr_dist * neighbors[i].second;
                    unvisited.insert(std::make_pair(first, curr_dist * neighbors[i].second)); 
                } else {
                    std::cout << "F" << std::endl;
                    ++it;
                }
            }
        }
        
        visited.insert(std::make_pair(curr_node, curr_dist));
        
        for(auto it = std::begin(unvisited); it != std::end(unvisited); ) {
            if(it->first == curr_node && it->second == curr_dist) {
                std::cout << "G" << std::endl;
                it = unvisited.erase(it);
            } else {
                std::cout << "H" << std::endl;
                ++it;
            }
        }
        
        using namespace std::chrono_literals;
        for(auto it : visited) {
            if(edges.second == it.first) {
                std::cout << "I" << std::endl;
                std::this_thread::sleep_for(3s);
                is_in = false;
                result = it.second;
            }
        }
        std::cout << "result: "; 
        std::cout << result << std::endl;
        std::cout << "CIKLUS: " << cilus_count << std::endl;
    }
}

#endif
