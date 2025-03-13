#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    // 모든 칸의 꿀의 양 합
    long long total = 0;
    for (int i = 0; i < N; i++){
        total += A[i];
    }
    
    // prefix[i] = A[0] + A[1] + ... + A[i-1]
    vector<long long> prefix(N+1, 0);
    for (int i = 0; i < N; i++){
        prefix[i+1] = prefix[i] + A[i];
    }
    
    long long ans = 0;
    
    // Case 1: 벌집이 오른쪽 끝에 있는 경우
    // 왼쪽 벌: 0번에서 시작 → 경로: 1 ~ N-1 (단, 중간 벌의 위치 i는 꿀을 따지 않음)
    // 중간 벌(위치 i): 경로: i+1 ~ N-1
    // 후보값: (total - A[0] - A[i]) + (total - prefix[i+1])
    for (int i = 1; i < N - 1; i++){
        long long candidate = (total - A[0] - A[i]) + (total - prefix[i+1]);
        ans = max(ans, candidate);
    }
    
    // Case 2: 벌집이 왼쪽 끝에 있는 경우
    // 오른쪽 벌: N-1번에서 시작 → 경로: 0 ~ N-2 (단, 중간 벌의 위치 i는 꿀을 따지 않음)
    // 중간 벌(위치 i): 경로: 0 ~ i-1
    // 후보값: (total - A[N-1] - A[i]) + prefix[i]
    for (int i = 1; i < N - 1; i++){
        long long candidate = (total - A[N-1] - A[i]) + prefix[i];
        ans = max(ans, candidate);
    }
    
    // Case 3: 벌집이 중간에 있는 경우 (벌은 양쪽 끝에 배치)
    // 왼쪽 벌: 경로 1 ~ i, 오른쪽 벌: 경로 i ~ N-2, 즉 총합 = total - A[0] - A[N-1] + A[i]
    long long max_mid = 0;
    for (int i = 1; i < N - 1; i++){
        max_mid = max(max_mid, A[i]);
    }
    long long candidate = total - A[0] - A[N-1] + max_mid;
    ans = max(ans, candidate);
    
    cout << ans << "\n";
    return 0;
}
