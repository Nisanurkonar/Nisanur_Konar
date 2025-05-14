#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <iomanip>
using namespace std;

// Floyd-Warshall algoritması
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

// Mesafe matrisini yazdır
void printMatrix(const vector<vector<int> > &dist) {
    int V = dist.size();
    cout << "Mesafe Matrisi:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX) {
                cout << setw(5) << "INF ";
            } else {
                cout << setw(5) << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Test 1: Orijinal kod örneğinde verilen grafi test et
void testOriginalGraph() {
    cout << "TEST 1: Orijinal Graf" << endl;
    const int INF = INT_MAX;
    vector<vector<int> > dist(4, vector<int>(4, INF));
    
    dist[0][0] = 0;  dist[0][1] = 4;  dist[0][2] = 2; dist[0][3] = INF;
    dist[1][0] = 4;  dist[1][1] = 0;  dist[1][2] = 5; dist[1][3] = 10;
    dist[2][0] = 2;  dist[2][1] = 5;  dist[2][2] = 0; dist[2][3] = 3;
    dist[3][0] = INF;  dist[3][1] = 10;  dist[3][2] = 3; dist[3][3] = 0;
    
    cout << "Başlangıç Matrisi:" << endl;
    printMatrix(dist);
    
    floydWarshall(dist);
    
    cout << "Floyd-Warshall sonrası:" << endl;
    printMatrix(dist);
    
    // Beklenen sonuçlar için doğrulama
    assert(dist[0][3] == 5); // 0'dan 3'e en kısa yol 5 olmalı (0->2->3)
    assert(dist[3][0] == 5); // 3'ten 0'a en kısa yol 5 olmalı (3->2->0)
    cout << "Test başarılı: Tüm mesafeler doğru hesaplandı!" << endl << endl;
}

// Test 2: Bağlantısız graflar için test
void testDisconnectedGraph() {
    cout << "TEST 2: Bağlantısız Graf" << endl;
    const int INF = INT_MAX;
    vector<vector<int> > dist(5, vector<int>(5, INF));
    
    // İki ayrı bileşen: (0,1,2) ve (3,4)
    dist[0][0] = 0;  dist[0][1] = 1;  dist[0][2] = 3; dist[0][3] = INF; dist[0][4] = INF;
    dist[1][0] = 1;  dist[1][1] = 0;  dist[1][2] = 1; dist[1][3] = INF; dist[1][4] = INF;
    dist[2][0] = 3;  dist[2][1] = 1;  dist[2][2] = 0; dist[2][3] = INF; dist[2][4] = INF;
    dist[3][0] = INF; dist[3][1] = INF; dist[3][2] = INF; dist[3][3] = 0; dist[3][4] = 2;
    dist[4][0] = INF; dist[4][1] = INF; dist[4][2] = INF; dist[4][3] = 2; dist[4][4] = 0;
    
    cout << "Başlangıç Matrisi:" << endl;
    printMatrix(dist);
    
    floydWarshall(dist);
    
    cout << "Floyd-Warshall sonrası:" << endl;
    printMatrix(dist);
    
    // Beklenen sonuçlar için doğrulama
    assert(dist[0][2] == 2); // 0'dan 2'ye en kısa yol 2 olmalı (0->1->2)
    assert(dist[0][3] == INF); // 0'dan 3'e yol olmamalı
    assert(dist[3][4] == 2); // 3'ten 4'e en kısa yol 2 olmalı
    cout << "Test başarılı: Bağlantısız graf doğru hesaplandı!" << endl << endl;
}

// Test 3: Negatif kenar ağırlıkları olan graflar için test
void testNegativeEdges() {
    cout << "TEST 3: Negatif Kenar Ağırlıkları Olan Graf" << endl;
    vector<vector<int> > dist(4, vector<int>(4, INT_MAX));
    
    dist[0][0] = 0;   dist[0][1] = 3;   dist[0][2] = 6;  dist[0][3] = 15;
    dist[1][0] = INT_MAX; dist[1][1] = 0;   dist[1][2] = -2; dist[1][3] = INT_MAX;
    dist[2][0] = INT_MAX; dist[2][1] = INT_MAX; dist[2][2] = 0;  dist[2][3] = 2;
    dist[3][0] = 1;   dist[3][1] = INT_MAX; dist[3][2] = INT_MAX; dist[3][3] = 0;
    
    cout << "Başlangıç Matrisi:" << endl;
    printMatrix(dist);
    
    floydWarshall(dist);
    
    cout << "Floyd-Warshall sonrası:" << endl;
    printMatrix(dist);
    
    // Beklenen sonuçlar için doğrulama
    assert(dist[0][3] == 6); // 0'dan 3'e en kısa yol 6 olmalı (0->1->2->3)
    assert(dist[3][2] == 4); // 3'ten 2'ye en kısa yol 4 olmalı (3->0->1->2)
    cout << "Test başarılı: Negatif kenar ağırlıkları doğru hesaplandı!" << endl << endl;
}

int main() {
    testOriginalGraph();
    testDisconnectedGraph();
    testNegativeEdges();
    
    cout << "Tüm testler başarıyla tamamlandı!" << endl;
    return 0;
}