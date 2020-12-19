#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define MAX_NUM 100000

void selectionSort(int data[], int n);
void insertionSort(int data[], int n);
void bubbleSort(int data[], int n);

void merge(int A[], int p, int q, int r);
void mergeSort(int A[], int p, int r);

int partition(int A[], int p, int r);
void quickSort(int A[], int p, int r);

void heapSort(int A[], int n);
void buildHeap(int A[], int n);
void heapify(int A[], int k, int n);

void swap(int *a, int *b);

int mergedArr[MAX_NUM];

int main()
{
  srand(time(NULL));
  int nums[N] = {0,};

  // for (int i = 0; i < N; i++){
  //   nums[i] = rand() % 10;
  //   printf("%d ", nums[i]);
  // }
  // printf("\n");

  // selectionSort(nums, N);
  // bubbleSort(nums, N);
  // insertionSort(nums, N);
  // mergeSort(nums, 0, N-1);
  // quickSort(nums, 0, N - 1);


  // for heap sort: 1..n
  for (int i = 1; i < N; i++){
    nums[i] = rand() % 10;
    printf("%d ", nums[i]);
  }
  printf("\n");
  heapSort(nums, N);


  for (int i = 0; i < N; i++)
  {
    printf("%d ", nums[i]);
  }
  printf("\n");
}

void swap(int *a, int *b)
{
  if (*a == *b)
    return;
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}

void selectionSort(int data[], int n)
{
  for (int last = n - 1; last > 0; last--)
  {

    /* 최댓값 찾기 (Search maxinum value in A[0, ..., last]) */
    int max_idx = 0;
    for (int i = 0; i < last + 1; i++)
    {
      max_idx = (data[max_idx] > data[i]) ? max_idx : i;

      /* 최댓값을 가장 끝으로 이동 (Move max to end) */
      swap(data + max_idx, data + last);
      //  swap(&A[max_idx], &A[last]);
    }
  }
}

void bubbleSort(int data[], int n)
{
  for (int i = n - 1; i > 0; i--)
  {
    for (int j = 0; j < i; j++)
    {
      /*이웃한 쌍을 비교하여, 순서가 잘못되어 있으면 자리 교환
      Compare adjacent items, and swap (if misordered)
      */
      if (data[j] > data[j + 1])
        swap(data + j, data + j + 1);
    }
  }
}

void insertionSort(int data[], int n)
{
  for (int i = 1; i < n + 1; i++)
  {
    for (int j = i; j > 0; j--)
    {
      if (data[j] < data[j - 1])
      {
        /* 적절한 위치가 나올때까지 swap 하면서 원소 이동 */
        swap(data + j, data + j - 1);
      }
      else
      {
        break;
      }
    }
  }
}

// merge sort
void merge(int A[], int p, int q, int r)
{
  // 정렬되어 있는 두 배열 A[p...q]와 A[q+1...r]을 합하여
  // 정렬된 하나의 배열 A[p...r]을 만든다.

  int i = p, j = q + 1;
  int idx = p;

  while (i < q + 1 && j < r + 1)
  {
    if (A[i] < A[j])
    {
      mergedArr[idx++] = A[i++];
    }
    else
    {
      mergedArr[idx++] = A[j++];
    }
  }
  while (i < q + 1)
  { // 왼쪽 부분 배열이 남은 경우
    mergedArr[idx++] = A[i++];
  }
  while (j < r + 1)
  { // 오른쪽 부분 배열이 남은 경우
    mergedArr[idx++] = A[j++];
  }

  for (int i = p; i < r + 1; i++)
  {
    A[i] = mergedArr[i]; // copy mergedArr to A
  }
}

void mergeSort(int A[], int p, int r)
{
  if (p < r)
  {
    int q = (p + r) / 2;
    mergeSort(A, p, q);
    mergeSort(A, q + 1, r);
    merge(A, p, q, r);
  }
}

// quick sort
int partition(int A[], int p, int r)
{
  // 배열 A[p...r] 의 원소들을 A[r]을 기준으로
  // 양쪽으로 재배치하고 A[r]이 자리한 위치를 리턴

  int pivot = A[r], i = p - 1;

  for (int j = p; j < r; j++)
  {
    if (A[j] < pivot)
    {
      i++;
      if (i != j)
        swap(&A[j], &A[i]);
    }
  }
  swap(&A[r], &A[i + 1]);

  return i + 1;
}

void quickSort(int A[], int p, int r)
{
  if (p < r)
  {
    int q = partition(A, p, r);
    quickSort(A, p, q - 1);
    quickSort(A, q + 1, r);
  }
}

// sorting A[1, ..., n]
void heapSort(int A[], int n)
{
  buildHeap(A, n);
  for (int i = n; i > 1; i--)
  {
    swap(&A[1], &A[i]);
    heapify(A, 1, i - 1);
  }
}

void buildHeap(int A[], int n)
{
  for (int i = n / 2; i > 0; i--)
    heapify(A, i, n);
}

void heapify(int A[], int k, int n)
{
  int left = 2 * k, right = 2 * k + 1, max;

  if (right <= n)
    max = (A[left] > A[right]) ? left : right;
  else if (left <= n)
    max = left;
  else
    return;

  if (A[max] > A[k])
  {
    swap(&A[max], &A[k]);
    heapify(A, max, n);
  }
}