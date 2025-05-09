#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void floydWarshall(vector<vector<int> > &dist) {
    int V = dist.size();
    
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    const int INF = INT_MAX;
    vector<vector<int> > dist(4, vector<int>(4, INF));
    
    dist[0][0] = 0;  dist[0][1] = 4;  dist[0][2] = 2; dist[0][3] = INF;
    dist[1][0] = 4;  dist[1][1] = 0;  dist[1][2] = 5; dist[1][3] = 10;
    dist[2][0] = 2;  dist[2][1] = 5;  dist[2][2] = 0; dist[2][3] = 3;
    dist[3][0] = INF;  dist[3][1] = 10;  dist[3][2] = 3; dist[3][3] = 0;
    
    floydWarshall(dist);
    
    for (int i = 0; i < dist.size(); i++) {
        for (int j = 0; j < dist.size(); j++) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}

