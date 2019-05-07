#ifndef WEIGHT_GRAPH
#define WEIGHT_GRAPH

#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

struct edge {
    int begin_point;
    int end_point;
    double weight;

    edge() = default;
    edge(const edge& other) {
        begin_point = other.begin_point;
        end_point = other.end_point;
        weight = other.weight;
    }

    edge(int b_point, int e_point, double w)
        : begin_point(b_point), end_point(e_point), weight(w) {}
};

using weight_graph = std::vector<edge*>;

struct points {
    std::set<int> p;

    points() = default;
    points(const points& other) { p = other.p; }

    explicit points(weight_graph& wg) noexcept {
        for (const auto i : wg) {
            p.insert(i->begin_point);
            p.insert(i->end_point);
        }
    }
};

void load_graph_from_file(weight_graph& wg, const std::string filename) {
    std::fstream file(filename);
    int num_of_mx;
    file >> num_of_mx;

    for (int i = 0; i < num_of_mx; ++i) {
        int tmp_begin;
        int tmp_end;
        double tmp_weight;

        file >> tmp_begin;
        file >> tmp_end;
        file >> tmp_weight;

        wg.push_back(new edge(tmp_begin, tmp_end, tmp_weight));
    }

    file.close();
}

std::istream& operator>>(std::istream& in, weight_graph& wg) {
    int size;
    in >> size;

    for (int i = 0; i < size; ++i) {
        int tmp_begin;
        int tmp_end;
        double tmp_weight;
        std::cout << "Give the begin point: ";
        in >> tmp_begin;
        std::cout << "Give the end point: ";
        in >> tmp_end;
        std::cout << "Give the weight: ";
        in >> tmp_weight;

        wg.push_back(new edge(tmp_begin, tmp_end, tmp_weight));
    }

    return in;
}

std::ostream& operator<<(std::ostream& out, weight_graph& wg) {
    for (const auto& edge : wg) {
        out << "Begin point: " << edge->begin_point << " :: "
            << "End point: " << edge->end_point << " :: "
            << "Weight: " << edge->weight << '\n';
    }

    return out;
}

#endif
