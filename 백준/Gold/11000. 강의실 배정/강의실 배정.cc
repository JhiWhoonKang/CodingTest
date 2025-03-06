#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<pair<int, int>> lectures(N);
    for (int i = 0; i < N; i++) {
        cin >> lectures[i].first >> lectures[i].second;
    }
    
    // 시작 시간을 기준으로 정렬
    sort(lectures.begin(), lectures.end());
    
    priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙 (끝나는 시간 기준)
    
    for (const auto& lecture : lectures) {
        int start = lecture.first;
        int end = lecture.second;
        
        // 현재 강의의 시작 시간이 가장 빠른 종료 시간보다 크거나 같다면, 기존 강의실 사용 가능
        if (!pq.empty() && pq.top() <= start) {
            pq.pop();
        }
        
        pq.push(end); // 새 강의 추가
    }
    
    cout << pq.size() << endl; // 필요한 강의실 개수 출력
    
    return 0;
}