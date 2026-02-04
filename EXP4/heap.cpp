#include <bits/stdc++.h>
using namespace std;

int main() {
    int K, N;

    cout << "Enter value of K (number of top students): ";
    cin >> K;

    cout << "Enter number of scores (N): ";
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;

    cout << "Enter scores one by one:\n";

    for (int i = 0; i < N; i++) {
        int score;
        cin >> score;

        // Step 1: Insert score
        if (pq.size() < K) {
            pq.push(score);
        }
        else if (score > pq.top()) {
            pq.pop();
            pq.push(score);
        }

        // Step 2: Output cut-off
        if (pq.size() < K) {
            cout << "Cut-off: -1" << endl;
        }
        else {
            cout << "Cut-off: " << pq.top() << endl;
        }
    }

    return 0;
}