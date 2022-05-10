#include <vector>

using namespace std;

vector<int> colorize (vector<vector<int> >& graph, vector<int>& edges_counter) {
    vector<int> vColors(graph.size(), -1);
        for(auto it : edges_counter) {
            int i = it;
            vector<bool> colored(graph.size(), false);
            for (int j = 0; j < graph.size(); j++) {
                if (graph[i][j] == 1) {
                    if(vColors[j] > -1){
                        colored[vColors[j]] = true;
                    }
                }
            }
            for (int k = 0; k < graph.size(); k++) {
                if (!colored[k]) {
                    vColors[i] = k;
                    break;
                }
            }
        }
        return vColors;
}
