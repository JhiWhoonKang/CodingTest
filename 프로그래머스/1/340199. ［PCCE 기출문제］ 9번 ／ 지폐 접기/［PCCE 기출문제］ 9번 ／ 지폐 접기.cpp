#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    sort(wallet.begin(), wallet.end(), [](const int walletA, const int walletB)
         {
             return walletA > walletB;
         });
    
    sort(bill.begin(), bill.end(), [](const int billA, const int billB)
         {
             return billA > billB;
         });
        
    for(;;)
    {       
        if((bill[0] <= wallet[0]) && (bill[1] <= wallet[1]))
        {                
            break;
        }
        else
        {
            ++answer;
            bill[0] /= 2;

            sort(bill.begin(), bill.end(), [](const int billA, const int billB)
             {
                 return billA > billB;
             });
            cout << bill[0] << ", " << bill[1] << "\n";
        }
    }
    
    return answer;
}