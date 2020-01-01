// SWERC 2015 - Canvas Painting
// Approach: Find optimal prefix-free codes. O(N log N)
// Author: Miguel Oliveira
#include <iostream>
#include <queue>
using namespace std;

int main() {
  int T, N, length;
  cin >> T;
  while (T--) {
    priority_queue<long long, vector<long long>, greater<long long>> heap;
    cin >> N;
    for (int i = 0; i < N; ++i) {
      cin >> length;
      heap.push(length);
    }
    long long answer = 0;
    while (heap.size() > 1) {
      long long step_size = heap.top();
      heap.pop();
      step_size += heap.top();
      heap.pop();
      answer += step_size;
      heap.push(step_size);
    }
    cout << answer << endl;
  }
  return 0;
}
