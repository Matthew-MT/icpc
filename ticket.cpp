#include <bits/stdc++.h>

using namespace std;

int traverse(int i, map<int, vector<int>>& edges, vector<bool>& traversed) {
    if (traversed[i]) return 0;
    traversed[i] = true;
    if (edges.count(i) == 0) return 1;
    vector<int>& curEdges = edges.at(i);
    int sum = 1;
    for (int next : curEdges) sum += traverse(next, edges, traversed);
    return sum;
}

int main() {
    map<int, vector<int>> edges;
    vector<int> weights;
    int cities, segments, v1, v2;
    cin >> cities >> segments;
    vector<bool> traversed(cities, false);
    for (int i = 0; i < segments; i++) {
        cin >> v1 >> v2;
        if (!edges.insert({v1, {v2}}).second) edges.at(v1).push_back(v2);
        if (!edges.insert({v2, {v1}}).second) edges.at(v2).push_back(v1);
    }
    int last = 1;
    while (last != -1) {
        weights.push_back(traverse(last, edges, traversed));
        for (; last <= traversed.size(); last++) {
            if (last == traversed.size()) {
                last = -1;
                break;
            } else if (traversed[last] == false) break;
        }
    }
    int traversableWeight = 0, totalWeight = (cities * (cities - 1)) >> 1;
    for (int weight : weights) traversableWeight += (weight * (weight - 1)) >> 1;
    double probability = double(traversableWeight) / double(totalWeight);
    cout << setprecision(20) << probability << "\n";
    return 0;
}
