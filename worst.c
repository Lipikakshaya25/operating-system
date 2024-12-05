#include <stdio.h>
#define MAX_BLOCKS 100
struct MemoryBlock
{
int block_id;
int size;
int allocated;
};
void worstFit(struct MemoryBlock blocks[], int m, int processSize)
{
int worstIdx = -1;
for (int i = 0; i < m; i++)
{
if (blocks[i].allocated == 0 && blocks[i].size >= processSize)
{
if (worstIdx == -1 || blocks[i].size > blocks[worstIdx].size)
{
worstIdx = i;
}
}
}
if (worstIdx != -1) {
blocks[worstIdx].allocated = 1;
printf("Process with size %d allocated to block %d\n", processSize, worstIdx + 1);
}
else
{
printf("Cannot allocate the process with size %d\n", processSize);
}
}
int main() {
int m;
printf("Enter the number of memory blocks: ");
scanf("%d", &m);
struct MemoryBlock blocks[MAX_BLOCKS];
for (int i = 0; i < m; i++)
{
blocks[i].block_id = i + 1;
printf("Enter the size of memory block %d: ", i + 1);
scanf("%d", &blocks[i].size);
blocks[i].allocated = 0;
}
int n;
printf("Enter the number of processes: ");
scanf("%d", &n);
for (int i = 0; i < n; i++) {
int processSize;
printf("Enter the size of process %d: ", i + 1);
scanf("%d", &processSize);
worstFit(blocks, m, processSize);
}
return 0;
}
