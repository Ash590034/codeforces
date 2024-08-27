#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Query {
    int l, r, L, R, idx;
};

// Comparison function for Mo's algorithm
bool compare(const Query &a, const Query &b) {
    int blockSize = sqrt(a.l);
    if (a.l / blockSize != b.l / blockSize)
        return a.l / blockSize < b.l / blockSize;
    return a.r < b.r;
}

void add(int x, unordered_map<int, int>& freq) {
    freq[x]++;
}

void remove(int x, unordered_map<int, int>& freq) {
    freq[x]--;
    if (freq[x] == 0) freq.erase(x);
}

bool checkEquality(const unordered_map<int, int>& freqA, const unordered_map<int, int>& freqB) {
    return freqA == freqB;
}

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N + 1), B(N + 1);
    for (int i = 1; i <= N; ++i) cin >> A[i];
    for (int i = 1; i <= N; ++i) cin >> B[i];

    vector<Query> queries(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i].l >> queries[i].r >> queries[i].L >> queries[i].R;
        queries[i].idx = i;
    }

    // Sorting queries based on Mo's Algorithm
    sort(queries.begin(), queries.end(), compare);

    vector<string> results(Q);
    unordered_map<int, int> freqA, freqB;

    int currL = 1, currR = 0, currL_B = 1, currR_B = 0;

    // Process each query
    for (auto &q : queries) {
        while (currR < q.r) add(A[++currR], freqA);
        while (currR > q.r) remove(A[currR--], freqA);
        while (currL > q.l) add(A[--currL], freqA);
        while (currL < q.l) remove(A[currL++], freqA);

        while (currR_B < q.R) add(B[++currR_B], freqB);
        while (currR_B > q.R) remove(B[currR_B--], freqB);
        while (currL_B > q.L) add(B[--currL_B], freqB);
        while (currL_B < q.L) remove(B[currL_B++], freqB);

        // Check if the two frequency distributions match
        if (checkEquality(freqA, freqB)) {
            results[q.idx] = "Yes";
        } else {
            results[q.idx] = "No";
        }
    }

    // Output the results
    for (const string& result : results) {
        cout << result << "\n";
    }

    return 0;
}
