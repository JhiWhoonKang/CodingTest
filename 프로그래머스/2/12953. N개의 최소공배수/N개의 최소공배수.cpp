#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int bigdivnum(int a, int b)
{
    while(b != 0)
    {
        int i = a % b;
        a = b;
        b = i;
    }
    return a;
}

/*
    2 | 2 4
      | 1 2
*/
int smallmulnum(int a, int b)
{
    return (a / bigdivnum(a, b)) * (b / bigdivnum(a, b)) * bigdivnum(a, b);
}

int solution(vector<int> arr) {
    int answer = 0;
    
    /*
    1344
    2 | 2 6 8 14
      | 1 3 4 7     => 168
    
    4 | 4 7 8 11
      | 1 7 2 11
    */
    
    sort(arr.begin(), arr.end(), [](const auto& a, const auto& b)
         {
             return a < b;
         });
    
    answer = arr[0];
    for(int idx = 1; idx < arr.size(); ++idx)
    {
        answer = smallmulnum(answer, arr[idx]);
    }
    
    
    return answer;
}