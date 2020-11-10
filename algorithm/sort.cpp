#include <stdio.h>

#define N 5

void swap(int *a, int *b){
  if (*a == *b)
    return;
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}

void selectionSort(int data[], int n){
  for (int last = n - 1; last > 0; last--){

    /* 최댓값 찾기 (Search maxinum value in A[0, ..., last]) */
    int max_idx = 0;
    for (int i = 0; i < last+1; i++){
      max_idx = (data[max_idx] > data[i]) ? max_idx : i;  
      
      /* 최댓값을 가장 끝으로 이동 (Move max to end) */
      swap(data+max_idx, data+last);
      //  swap(&A[max_idx], &A[last]);
    }
  }
}

void bubbleSort(int data[], int n){
  for(int i=n-1; i>0; i--){
    for(int j=0; j<i; j++){
      /*이웃한 쌍을 비교하여, 순서가 잘못되어 있으면 자리 교환
      Compare adjacent items, and swap (if misordered)
      */
      if(data[j] > data[j+1])
        swap(data+j, data+j+1);
    }
  }
}


void insertionSort(int data[], int n){
  for(int i=1; i<n+1; i++){
    for(int j=i; j>0; j--){
      if(data[j] < data[j-1]){
        /* 적절한 위치가 나올때까지 swap 하면서 원소 이동 */
        swap(data+j, data+j-1);
      }else{
        break;
      }
    }
  }
}

int main(){
  int nums[] = {0, 1, 3, 2, 4};  
  //selectionSort(nums, N);
  // bubbleSort(nums, N);
  insertionSort(nums, N);

  for(int i=0; i<N; i++){
    printf("%d ", nums[i]);
  }
  printf("\n");
}