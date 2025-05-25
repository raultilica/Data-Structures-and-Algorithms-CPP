#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>

using namespace std;
#define INF INT_MAX

struct Nod {
    int nr;
    int cost;
};

vector<Nod> list[5001];
int parinte[5001];
int dist[5001];
bool used[5001];
int total;

void prim(int V) {
    for (int i = 0; i < V; i++) {
        parinte[i] = -1;
        used[i] = false;
    }
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> PQ;
    dist[0] = 0;
    PQ.push({0, 0, 0});

    while (!PQ.empty()) {
        auto [cost, from, to] = PQ.top();
        PQ.pop();
        if (used[to])
            continue;

        total += cost;
        used[to] = true;
        parinte[to] = from;

        for(auto& next: list[to])
            if(!used[next.nr])
                PQ.push({next.cost, to, next.nr});
    }
}

int main(int argc, char *argv[]) {
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    int V, E;
    fin >> V >> E;
    for (int i = 0; i < E; i++) {
        int from, to, cost;
        fin >> from >> to >> cost;
        list[from].push_back({to, cost});
        list[to].push_back({from, cost});
    }
    prim(V);
    fout << total << '\n' << V - 1 << '\n';

    //Lexicographic order
    vector<pair<int, int>> C;
    for (int i = 1; i < V; i++) {
        int p = parinte[i], b = i;
        if (p > b)
            swap(p, b);
        C.push_back({p, b});
    }
    sort(C.begin(), C.end());
    for (auto &c : C) {
        fout << c.first << ' ' << c.second << '\n';
    }
    return 0;
}
