#include <iostream>
#include <string>
#include <cmath>

using std::pair;
using std::cout;

pair<int, int> nckc(int n, int k) {
    if (k == 0 || k == n) return {1, 1};
    else if (k == 1 || k + 1 == n) return {1 + n, n};
    else {
        pair<int, int> temp = nckc(n, k - 1);
        int tempProd = ((temp.second * (n - (k - 1))) / k);
        return {temp.first + tempProd, tempProd};
    }
}

int main() {
    int N, n, m, W;

    std::cin >> N;
    while (std::cin >> N >> n >> m >> W) {
        int T = int(std::floor(float(N + 1) / 2));
        if (n >= T) cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!\n";
        else if (m >= T) cout << "RECOUNT!\n";
        else {
            int
                cur = n + m,
                need = T - m,
                rem = N - cur,
                lose = rem - (need - 1);
            float tempProb = float(nckc(rem, lose).first) * 100.f;
            while (100.f - tempProb > W && n > 1) tempProb /= float(n--);
            if (100.f - tempProb > W) cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!\n";
            else cout << "PATIENCE, EVERYONE!\n";
        }
    }

    return 0;
}
