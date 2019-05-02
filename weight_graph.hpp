#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

struct edge {
    int begin_point;
    int end_point;
    int weight;

    edge(int b_point, int e_point, int w)
        : begin_point(b_point), end_point(e_point), weight(w) {}
};

using weight_graph = std::vector<edge*>;

struct points {
    std::set<int> p;

    explicit points(weight_graph& wg) {
        for (const auto i : wg) {
            p.insert(i->begin_point);
            p.insert(i->end_point);
        }
    }
};

void load_graph_from_file(weight_graph& wg, std::string filename) {
    std::fstream file(filename);
    int num_of_mx;
    file >> num_of_mx;

    for (int i = 0; i < num_of_mx; ++i) {
        int tmp_begin;
        int tmp_end;
        int tmp_weight;

        file >> tmp_begin;
        file >> tmp_end;
        file >> tmp_weight;

        wg.push_back(new edge(tmp_begin, tmp_end, tmp_weight));
    }

    file.close();
}

std::ostream& operator<<(std::ostream& out, weight_graph& wg) {
    for (const auto& edge : wg) {
        out << "Begin point: " << edge->begin_point << " :: "
            << "End point: " << edge->end_point << " :: "
            << "Weight: " << edge->weight << '\n';
    }

    return out;
}
