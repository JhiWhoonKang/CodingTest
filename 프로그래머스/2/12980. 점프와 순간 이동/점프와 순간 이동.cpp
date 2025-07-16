using namespace std;

int solution(int n)
{
    int ans = 1;
    
    if(n == 1)
    {
        return 1;
    }
    
    while(!((n / 2) == 1))
    {
        // if((n % 2))
        // {
        //     ++ans;
        // }
        ans += (n % 2);
        n /= 2;
    }
    ans += (n % 2);
    
    return ans;
}