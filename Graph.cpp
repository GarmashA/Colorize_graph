#include <vector>
#include <fstream>
#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

vector<vector<int>> read_graph(string& name_file, vector<pair<int, int>>& list_edges, vector<int>& edges_counter) {
    ifstream fin;
    fin.open(name_file);
    vector<vector<int>> graph;
    int vertex, edges;
    vector<pair<int, int>> pairs;
    list_edges.clear();
    edges_counter.clear();
    if (fin.is_open()) {
        fin >> vertex >> edges;
        vector <int> v(vertex, 0);
        graph.resize(vertex, v);
        auto zero = make_pair(0, 0);
        pairs.resize(graph.size(), zero);
        for (int k = 0; k < edges; k++) {
            int start, end;
            fin >> start >> end;
            auto p1 = make_pair(start, end);
            list_edges.push_back(p1);
            graph[start][end] = 1;
            graph[end][start] = 1;
            pairs[start].first += 1;
            pairs[end].first += 1;
            pairs[start].second = start;
            pairs[end].second = end;
        }
    }
    sort(pairs.begin(), pairs.end());
    for(size_t i = pairs.size()-1;i >= 0; i--){
        edges_counter.push_back(pairs[i].second);
    }
    return graph;
}
