#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

struct Student {
    int C, B, P;
};

// Comparator to sort students based on cleverness first, then beauty
bool compare(const Student& a, const Student& b) {
    if (a.C == b.C) return a.B < b.B;
    return a.C < b.C;
}
int maxMoney(int n,vector<int> b,vector<int> c,vector<int> p){
    vector<Student> students(n);
    for (int i = 0; i < n; ++i) {
        students[i].B=b[i];
        students[i].C=c[i];
        students[i].P=p[i];
    }
    sort(students.begin(), students.end(), compare);
    
    // DP array to store maximum profit up to the i-th student
    vector<int> dp(n);
    
    // Fenwick Tree (or Binary Indexed Tree) to maintain the maximum profit seen so far
    vector<int> BIT(n + 1, 0);
    
    auto update = [&](int idx, int val) {
        for (++idx; idx <= n; idx += idx & -idx) {
            BIT[idx] = max(BIT[idx], val);
        }
    };
    
    auto query = [&](int idx) {
        int res = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            res = max(res, BIT[idx]);
        }
        return res;
    };
    
    for (int i = 0; i < n; ++i) {
        dp[i] = students[i].P + query(students[i].B - 1);
        update(students[i].B, dp[i]);
    }
    
    int result = *max_element(dp.begin(), dp.end()) % MOD;
    
    return result;
}
// int main() {
//     int n;
//     cin >> n;
    
//     vector<Student> students(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> students[i].B ;
//     }
//     for (int i = 0; i < n; ++i) {
//         cin >> students[i].C ;
//     }
//     for (int i = 0; i < n; ++i) {
//         cin >> students[i].P ;
//     }
    
//     // Sort students based on cleverness, then by beauty
//     sort(students.begin(), students.end(), compare);
    
//     // DP array to store maximum profit up to the i-th student
//     vector<int> dp(n);
    
//     // Fenwick Tree (or Binary Indexed Tree) to maintain the maximum profit seen so far
//     vector<int> BIT(n + 1, 0);
    
//     auto update = [&](int idx, int val) {
//         for (++idx; idx <= n; idx += idx & -idx) {
//             BIT[idx] = max(BIT[idx], val);
//         }
//     };
    
//     auto query = [&](int idx) {
//         int res = 0;
//         for (++idx; idx > 0; idx -= idx & -idx) {
//             res = max(res, BIT[idx]);
//         }
//         return res;
//     };
    
//     for (int i = 0; i < n; ++i) {
//         dp[i] = students[i].P + query(students[i].B - 1);
//         update(students[i].B, dp[i]);
//     }
    
//     int result = *max_element(dp.begin(), dp.end()) % MOD;
    
//     cout << result << endl;
//     return 0;
// }
