#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    cout << sizes.size() << "\n";
    
    int maxLength = 0;
    for(int i=0; i<sizes.size(); ++i)
    {
        if(maxLength < sizes[i][0])
        {
            maxLength = sizes[i][0];
        }
        if(maxLength < sizes[i][1])
        {
            maxLength = sizes[i][1];
        }
    }
    
    int minmaxLength = 0;
    for(int i=0; i<sizes.size(); ++i)
    {
        if(sizes[i][0] < sizes[i][1])
        {
            if(minmaxLength < sizes[i][0])
            {
                minmaxLength = sizes[i][0];
            }
        }
        else
        {
            if(minmaxLength < sizes[i][1])
            {
                minmaxLength = sizes[i][1];
            }
        }
    }    
    
    cout << "maxLength: " << maxLength << "minmaxLength: " << minmaxLength << "\n";
    answer = maxLength * minmaxLength;
    
    return answer;
}