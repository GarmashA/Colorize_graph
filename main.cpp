#include <vector>
#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

vector<int> colorize (vector<vector<int> >& graph, vector<int>& edges_counter);
vector<vector<int>> read_graph(const string& name_file, vector<pair<int, int>>& list_edges, vector<int>& edges_counter);

int main() {    
    string path = "C:\Users\garmash\Desktop\colorize";
    auto it = fs::directory_iterator(path);
    vector<fs::path> array_path;
    copy_if(fs::begin(it), fs::end(it), std::back_inserter(array_path),
        [](const auto& entry) {
            return fs::is_regular_file(entry);
    });
    for (auto & p : array_path) {
        vector<int> edges_counter;
        vector<pair<int, int>> edges;
        vector<vector<int>> graph = read_graph(p.string(), edges, edges_counter);
        vector<int> colored2 = colorize(graph, edges_counter);
        int max = -1;
        for (int i = 0; i < colored2.size(); i++) {
            if (colored2[i] > max) {
                max = colored2[i];
            }
        }
        cout << p.string() << endl;
        cout << max + 1 << endl;
        /*    для вывода цветов всех вершин
        for (auto i : colored2) {
            cout << i << " ";
        }
        cout << endl;
         */
    }
    return 0;
}
