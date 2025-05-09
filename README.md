# Floyd-Warshall Algoritması

## Algoritma Çalışma Mantığı

Floyd-Warshall Algoritması, düğümler arası mesafeleri temsil eden iki boyutlu bir diziyi koruyarak çalışır.  
Başlangıçta, bu dizi yalnızca düğümler arasındaki doğrudan kenarlar kullanılarak doldurulur.  
Daha sonra, algoritma ara düğümler arasında daha kısa yollar olup olmadığını kontrol ederek bu mesafeleri kademeli olarak günceller.

---

## Algoritmanın Avantajları ve Dezavantajları

### Avantajları
- En kısa mesafeyi bulmamıza yardımcı olur.
- Dinamik programlama prensibi ile çalışır.
- Matris tabanlı yaklaşımı benimser.
- Negatif ağırlıklarla çalışmaya izin verir.
- Uygulanması basittir.
- Hafızayı etkin kullanır.

### Dezavantajları
- Yüksek zaman karmaşıklığına sahiptir.
- Graf büyüklüğü artarsa performansta düşme gözlenebilir.
- Negatif döngülerde hatalı sonuçlar üretebilir.
- Bellek gereksinimi artabilir.
- Yalnızca ağırlıklı graflarda kullanılabilir.
- Diğer algoritmalara göre daha yavaş çalışır.

---

## Ne Zaman ve Nerelerde Kullanılır?

### Ne zaman kullanılır?
- Tüm düğümler arası en kısa yollar gerektiğinde
- Negatif ağırlıklı kenarlar olduğunda
- Küçük veya orta büyüklükteki graflar için
- Dinamik programlama ile çözüm üretildiğinde

### Nerelerde Kullanılır?
- Ulaşım ağları ve Navigasyon
- Ağ Optimizasyonu
- Tedarik zinciri ve Lojistik
- Oyun geliştirme ve Yapay Zeka
- Biyoinformatik ve Kimya

---

## C++ Kodu

cpp
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


---

## Floyd-Warshall Algoritmasında Zaman ve Uzay Karmaşıklığı

### Zaman Karmaşıklığı

- Giriş büyüklüğüne bağlı olarak çalışma süresini ifade eder.
- Karışıklık, iç içe geçmiş for döngülerinden kaynaklanır:

cpp
for (int k = 0; k < V; k++) { 
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) { 
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}


- Her döngü için algoritma *V* kez çalışır.  
- Örneğin 4 düğümlü bir graf için: 4 × 4 × 4 = *64 işlem* gerekir.
- Genel zaman karmaşıklığı: *O(V³)* (V, düğüm sayısını ifade eder)
- Büyük graflar için Floyd-Warshall algoritması zaman açısından verimsizdir.  
  Bu durumlarda *Dijkstra* veya *Bellman-Ford* algoritmaları tercih edilebilir.

---

### Uzay Karmaşıklığı

- Algoritma çalıştırıldığında ne kadar ek bellek (RAM) kullanıldığını ifade eder.
- Aşağıdaki gibi bir matris kullanılır:

cpp
vector<vector<int> > dist(4, vector<int>(4, INF));


- V × V boyutunda iki boyutlu bir matris oluşturulur.
- Her hücre bir düğüm çifti arasındaki mesafeyi tutar.
- Tüm mesafeler saklandığı için uzay karmaşıklığı: *O(V²)*
- Örneğin, 4 düğümlü bir grafın uzay karmaşıklığı: 4 × 4 = *16*
