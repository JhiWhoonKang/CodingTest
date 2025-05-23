#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) 
{
    int answer = 0;
    
    sort(people.begin(), people.end(), [](const int& a ,const int& b){
        return a < b;    
    });
    
    int left = 0;
    int right = people.size() - 1;
    for(;left <= right;)
    {
        if(people[left] + people[right] <= limit)
        {
            ++left;            
        }
        --right;
        ++answer;
    }
    return answer;
}