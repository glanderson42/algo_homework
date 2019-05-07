#include <cstdlib>
#include <experimental/filesystem>
#include <fstream>

#include "dijkstras_algorithm.hpp"
#include "weight_graph.hpp"

namespace fs = std::experimental::filesystem;

std::pair<int, int> get_edges(std::istream& in) {
    int begin;
    int end;
    std::cout << "Begin point: ";
    in >> begin;
    std::cout << "End point: ";
    in >> end;

    return std::make_pair(begin, end);
}

std::vector<std::string> get_files() {
    std::vector<std::string> test_files;
    std::string curr_path = fs::current_path();
    fs::path tfs_path(curr_path + "/test_files/");
    int counter = 0;
    for (const auto& file : fs::directory_iterator(tfs_path)) {
        ++counter;
        std::cout << counter << ". " << file.path() << std::endl;
        test_files.push_back(file.path());
    }

    return test_files;
}

void check_intput(std::istream& in) {
    if(in.fail()) {
        std::cerr << "Input was not and integer" << std::endl;
        std::cerr << "Exiting..." << std::endl;
        exit(-1);
    }
}

void show_task(const std::string filename) {
    std::ifstream file(filename);

    if(file.is_open()) {
        std::cout << file.rdbuf();
    }
}

void clear_screen() {
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#endif
}

int main() {
    bool is_run = true;
    while (is_run) {
        weight_graph wg;
        int choice;
        std::cout << " ------------------------------- " << std::endl;
        std::cout << "| 1. Add graph from user input  |" << std::endl;
        std::cout << "| 2. Choose from the test files |" << std::endl;
        std::cout << "| 3. Show task                  |" << std::endl;
        std::cout << "| 4. Clear screen               |" << std::endl;
        std::cout << "| 5. Exit                       |" << std::endl;
        std::cout << " ------------------------------- " << std::endl;
        std::cout << "Give the command from 1 to 5: ";
        std::cin >> choice;
        
        check_intput(std::cin);

        switch (choice) {
            case 1: {
                std::cout << "Give the number of edges: " << std::endl;
                std::cin >> wg;
                check_intput(std::cin);
                std::cout << "Give the start and the end point" << std::endl;
                std::pair<int, int> begin_end = get_edges(std::cin);
                std::cout << "Starting dijkstra..." << std::endl;
                dijkstra(begin_end, wg);
                break;
            }

            case 2: {
                std::cout << "Available test files in the test_files dir: "
                          << std::endl;
                int test_file_num = 0;
                std::vector<std::string> files = get_files();
                std::cout << "Give the number of chosen file: ";
                std::cin >> test_file_num;
                check_intput(std::cin);
                load_graph_from_file(wg, files[test_file_num - 1]);
                std::cout << "Chosen graph: " << std::endl;
                std::cout << wg;
                std::cout << "Give the start and the end point" << std::endl;
                std::pair<int, int> begin_end = get_edges(std::cin);
                std::cout << "Starting dijkstra..." << std::endl;
                dijkstra(begin_end, wg);
                break;
            }

            case 3: {
                show_task("feladat_leiras");
                break;
            }

            case 4: {
                clear_screen();
                break;
            }

            case 5: {
                std::cout << "Exiting..." << std::endl;
                is_run = false;
                break;
            }

            default: {
                std::cerr << "Wrong input!" << std::endl;
                break;
            }
        }
    }
    return 0;
}
