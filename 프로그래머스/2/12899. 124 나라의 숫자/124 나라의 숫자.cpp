#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    // n1 바퀴
    int n1 = n / 3 + 1;
    
    char digits[3] = {'4', '1', '2'};
    
    while(n > 0)
    {
        int n2 = n % 3;
        
        answer = digits[n2] + answer;
        
        (n2 == 0) ? n = (n / 3) - 1 : n = n / 3;        
    }
    
    
    
    return answer;
}