#include <stdio.h>
// Define the maximum number of memory blocks
#define MAX_BLOCKS 100
// Structure to represent memory blocks
struct MemoryBlock {
int block_id;
int size;
int allocated;
};
// Function to perform best-fit memory allocation
void bestFit(struct MemoryBlock blocks[], int m, int processSize) {
int bestIdx = -1;
for (int i = 0; i < m; i++) {
if (blocks[i].allocated == 0 && blocks[i].size >= processSize) {
if (bestIdx == -1 || blocks[i].size < blocks[bestIdx].size) {
bestIdx = i;
}}
}
if (bestIdx != -1) {
// Allocate the memory block
blocks[bestIdx].allocated = 1;
printf("Process with size %d allocated to block %d\n", processSize, bestIdx + 1);
} else {
printf("Cannot allocate the process with size %d\n", processSize);
}
}
int main() {
int m; // Number of memory blocks
printf("Enter the number of memory blocks: ");
scanf("%d", &m);
struct MemoryBlock blocks[MAX_BLOCKS];
for (int i = 0; i < m; i++) {
blocks[i].block_id = i + 1;
printf("Enter the size of memory block %d: ", i + 1);
scanf("%d", &blocks[i].size);
blocks[i].allocated = 0; // Initialize as unallocated
}
int n; // Number of processes
printf("Enter the number of processes: ");
scanf("%d", &n);
for (int i = 0; i < n; i++) {
int processSize;
printf("Enter the size of process %d: ", i + 1);
scanf("%d", &processSize);
bestFit(blocks, m, processSize);
}
return 0;
}
