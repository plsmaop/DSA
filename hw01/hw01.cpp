#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main(void) {
    int n,m;                                                                            //n筆資料，比m次
    scanf("%d%d", &n,&m);
    int range[m*2];
    int row =31 - __builtin_clz(n)+1;                                                   //log2(n)層+第一層存要處理的array        
    int lookup[row][n];                                                                 //存放sparse table 的maximum
    for(int i = 0; i < n; i++) scanf("%d", &lookup[0][i]);                              //lookup第一層存要處理的array  
    for(int i = 0; i < 2*m-1; i+=2) scanf("%d%d", &(range[i]), &(range[i+1]));          //range[i] = start, range[i+1] = end, 兩兩成對           
    for(int i = 1; (1<<i) <= n; i++){                                                   //lookup下面的層，2的i次方一直到小於等於n
        for(int j = 0; j+(1<<i)<=n; j++){
            lookup[i][j]= max(lookup[i-1][j], lookup[i-1][(j+(1<<(i-1)))]);             //每一次跳2^i個來比較
        }
    }
    for(int i = 0; i < 2*m-1; i+=2){
        int left = range[i]-1;                                                            
        int right = range[i+1]-1;
        int layer = 31 - __builtin_clz(right-left+1);                                   //第幾層
        int ans = max(lookup[layer][left], lookup[layer][right - (1<<layer)+1]);        //由左右差距決定第幾層，再由差距決定是哪兩個區間
        printf("%d\n", ans);                                                            //因上面每往右一個，下面會重疊2^i+1個，所以下面的右邊減掉(2^i+1)
    }
    return 0;
}
