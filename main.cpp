#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> colorize (vector<vector<int> >& graph, vector<int>& edges_counter);

int main() {
    int vertex, edges;
    vector<pair<int, int> > pairs;
    vector<int> edges_counter;
    pairs.clear();
    edges_counter.clear();
    cin >> vertex >> edges;
    vector<vector<int> > graph;
    vector<int> v(vertex, 0);
    graph.resize(vertex, v);
    auto zero = make_pair(0, 0);
    pairs.resize(graph.size(), zero);
    for (int i = 0; i < edges; i++) {
        int start, end;
        cin >> start >> end;
        auto p1 = make_pair(start, end);
        pairs.push_back(p1);
        graph[start][end] = 1;
        graph[end][start] = 1;
        pairs[start].first += 1;
        pairs[end].first += 1;
        pairs[start].second = start;
        pairs[end].second = end;
    }
    sort(pairs.begin(), pairs.end());
    for (int i = pairs.size() - 1; i >= 0; i--) {
        edges_counter.push_back(pairs[i].second);
    }
    vector<int> colored = colorize(graph, edges_counter);
    int max = -1;
    for (int i = 0; i < colored.size(); i++) {
        if (colored[i] > max) {
            max = colored[i];
        }
    }
    cout << max + 1;
    return 0;
}
