#include <stdio.h>

#define W 10
#define MAX_CAPACITY 50  
#define ITEMS 5  

int main() {
    int c[WAREHOUSES] = {20, 30, 50, 40, 35, 45, 25, 30, 50, 20};  
    int invent[ITEMS] = {10, 15, 20, 25, 30};  

    int dp[W + 1][MAX_CAPACITY + 1] = {0};  

    for (int i = 0; i < W; i++) {  
        for (int j = MAX_CAPACITY; j >= invent[i % ITEMS]; j--) {  
            if (dp[i][j] < dp[i][j - invent[i % ITEMS]] + invent[i % ITEMS]) {  
                dp[i + 1][j] = dp[i][j - invent[i % ITEMS]] + invent[i % ITEMS]; 
            } else {
                dp[i + 1][j] = dp[i][j];
            }
        }
    }

    printf("New inventory allocation: %d items used\n", dp[W][MAX_CAPACITY]);
    return 0;
}
