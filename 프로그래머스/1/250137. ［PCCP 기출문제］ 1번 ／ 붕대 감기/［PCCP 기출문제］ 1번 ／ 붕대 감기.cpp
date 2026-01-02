#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    #if 0
    t초 동안 붕대(bandage[0])
        1초마다 x만큼 체력 회복(bandage[1])
    -> 성공? y만큼 추가 체력(bandage[2])
        (단, 최대 채력 존재)
        도중 공격 당하면 기술 취소 & 체력 회복 X & 받은 피해량만큼 현재 체력 감소 & 연속 성공 시간: 0으로 초기화
        (이때, 현재 체력 <= 0 -> 끝)
    생존 여부 궁금(남은 체력 return, 미생존: -1)
            
        
    #endif
            
    const int skillNeedTime = bandage[0];
    const int upHealth = bandage[1];
    const int additionalHealth = bandage[2];
    
    int curTime = 0;
    int curHealth = health;
    const int maxHealth = health; 
    
    for(auto attack : attacks)
    {
        int atkTime = attack[0];
        int damage = attack[1];
        int timeDiff = atkTime - curTime - 1; 
        
        if(timeDiff > 0)
        {
            curHealth += (timeDiff * upHealth);
            curHealth += ((timeDiff / skillNeedTime) * additionalHealth);
            if(curHealth > maxHealth)
            {
                curHealth = maxHealth;
            }
        }
        
        curHealth -= damage;
        
        if(curHealth <= 0)
        {
            return -1;
        }
        
        curTime = atkTime;
    }
    
    return curHealth;
}