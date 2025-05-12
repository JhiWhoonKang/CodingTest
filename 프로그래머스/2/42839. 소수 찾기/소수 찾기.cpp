#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

// 소수 판별 함수
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    set<int> uniqueNumbers;
    sort(numbers.begin(), numbers.end());

    // 모든 길이에 대해 순열 생성
    do {
        for (int len = 1; len <= numbers.size(); ++len) {
            string sub = numbers.substr(0, len);
            int num = stoi(sub);
            uniqueNumbers.insert(num);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    // 소수 개수 세기
    int count = 0;
    for (int num : uniqueNumbers) {
        if (isPrime(num)) count++;
    }

    return count;
}
