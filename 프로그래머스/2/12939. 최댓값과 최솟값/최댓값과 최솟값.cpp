#include <string>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

string solution(string s)
{
    string answer = "";
    
    int max = INT_MIN;
    int min = INT_MAX;
    
    int culIdx = 0;
    
    istringstream iss(s);
    vector<int> numVector = {};
    
    string token;
    while(iss >> token)
    {
        int temp = stoi(token);
        if(temp > max)
        {
            max = temp;
        }
        if(temp < min)
        {
            min = temp;
        }
    }
        
    answer += to_string(min);
    answer += " ";
    answer += to_string(max);
    
    return answer;
}