#include <stdio.h>

int main() {
    int stages = 5;
    double time[5] = {2.0, 3.5, 1.5, 4.0, 2.5};  // Time delay for each stage
    double total_time = 0;

    for (int i = 0; i < stages; i++) {
        total_time += time[i] * 0.9;  // Optimize each stage by reducing time by 10%
        printf("Stage %d completed in %.2f hours\n", i + 1, time[i] * 0.9);
    }

    printf("Optimized Total Order Fulfillment Time: %.2f hours\n", total_time);
    return 0;
}
