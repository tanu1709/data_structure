// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.


#include<stdio.h>
#include<stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int j = 0;
    int startPos = -1;
    int endPos = -1;
    *(returnSize + 0) = -1;
    *(returnSize + 1) = -1;

    if(numsSize == 0) {
      return returnSize;
    }

    for(int i = 0; i < numsSize; i++) {
        if(*(nums+i) == target) {
            if(j == 0) {
              startPos = i;
            } else {
              endPos = i;
            }
            // *(returnSize + j) = i;
            j++;
        }
    }
    *(returnSize + 0) = startPos;
    *(returnSize + 1) = endPos;
    return returnSize;
}

int main() {
  int numsSize;
  int *returnSize = (int *)malloc(2*sizeof(int));;
  int target;
  printf("\nEnter array size:");
  scanf("%d", &numsSize);

  int *nums = (int *)malloc(numsSize*sizeof(int));
  printf("\nEnter target:");
  scanf("%d", &target);

  for(int i = 0; i < numsSize; i++) {
    printf("\nEnter value:");
    scanf("%d", (nums+i));
  }
  returnSize = searchRange(nums, numsSize, target, returnSize);
  for(int i = 0; i < 2; i ++) {
    printf("\n Value at %d is %d", i, *(returnSize + i));
  }
  return 0;
}
