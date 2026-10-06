#include <iostream>
using namespace std;

int main() {
    int N, src, dst;
    cin >> N >> src >> dst;

    int **yamki = new int*[N];
    for (int i = 0; i < N; ++i) {
        yamki[i] = new int[N];
        for (int j = 0; j < N; ++j) {
            if (i == j)
                yamki[i][j] = 0;
            else
                cin >> yamki[i][j];
        }
    }

    const int inf = 1e10;
    int *dist = new int[N];
    bool *vis = new bool[N];
    for (int i = 0; i < N; ++i) {
        dist[i] = inf;
        vis[i] = false;
    }
    dist[src] = 0;

    for (int k = 0; k < N; ++k) {
        int u = -1;
        int min_dist = inf;
        for (int i = 0; i < N; ++i) {
            if (!vis[i] && dist[i] < min_dist) {
                min_dist = dist[i];
                u = i;
            }
        }
        if (u == -1 || u == dst) break;
        vis[u] = true;

        for (int v = 0; v < N; ++v) {
            if (yamki[u][v] != 0 && !vis[v]) {
                int new_dist = dist[u] + yamki[u][v];
                if (new_dist < dist[v])
                    dist[v] = new_dist;
            }
        }
    }

    cout << dist[dst] << endl;

    for (int i = 0; i < N; ++i)
        delete[] yamki[i];
    delete[] yamki;
    delete[] dist;
    delete[] vis;
    return 0;
}