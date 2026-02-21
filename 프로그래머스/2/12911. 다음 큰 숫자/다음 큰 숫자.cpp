#include <string>
#include <vector>
#include <bitset>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int oneCnt = bitset<32>(n).count();
    int bigNum = n + 1;
    
    while(true)
    {
        if(bitset<32>(bigNum).count() == oneCnt)
        {
            return bigNum;
        }
        else
        {
            ++bigNum;
        }
            
    }
}