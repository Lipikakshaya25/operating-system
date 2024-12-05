#include <stdio.h>
void firstfit(int [], int ,int );
int allocation=-1;
int main() 
 {
    int m, n;
    // Input number of memory blocks
    printf("Enter number of memory blocks: ");
    scanf("%d", &m);
	int blockSize[m];
    // Input size of each memory block
    printf("Enter size of each memory block:\n");
    for (int i = 0; i < m; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    // Input size of each process
    printf("Enter size of process:\n");
        scanf("%d", &n);

    // First Fit Allocation
    firstfit(blockSize, m, n);

    return 0;
}
void firstfit(int blockSize[], int m,int n)
{
	for (int i = 0; i < m; i++)
        {
            if (blockSize[i] >= n) {
                allocation= i; 
                break;
}}

    // Output allocation results
    printf("\nFirst Fit Allocation:\n");
    printf("Process allocated to Block %d of size %d\n", allocation,blockSize[allocation]);	
}
