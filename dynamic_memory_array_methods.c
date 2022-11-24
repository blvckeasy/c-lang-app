#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int arr_size = 10;
int arr2_size = 0;

void fill_array(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    arr[i] = -10 + rand() % 21;
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  puts("");
}

void clear(int arr[]) {
  free(arr);
  arr_size = 0;
}

void append(int arr[], int *size, int element) {
  arr[*size] = element;
  *size += 1;
  arr = realloc(arr, (*size + 1)*sizeof(int));
}

void copy(int arr1[], int arr2[], int *size_1, int size_2) {
  arr1 = realloc(arr1, (arr_size)*sizeof(int));
  *size_1 = size_2;
  for(int i = 0; i < arr_size; i++) {
    arr1[i] = arr2[i];
  }
}

int count(int arr[], int size, int element) {
  int _count = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] == element) {
      _count++;
    }
  }
  return _count;
}

void extend(int arr1[], int arr2[], int *size_1, int size_2) {
  arr1 = realloc(arr1, arr_size*sizeof(int));

  for (int i = *size_1; i < (*size_1 + size_2); i++) {
    arr1[i] = arr2[i - *size_1];
  }

  *size_1 += size_2;
}

int index(int arr[], int size, int element) {
  int _index = -1;
  for (int i = 0; i < size; i++) {
    if (arr[i] == element) {
      _index = i;
      break;
    }
  }
  return _index;
}

void insert(int arr[], int *size, int index, int element) {
  arr = realloc(arr, (*size + 1) * sizeof(int));
  for (int i = *size; i > index; i--) {
    arr[i] = arr[i - 1];
  }
  *size += 1;
  arr[index] = element;
}

int pop(int arr[], int *size, int index) {
  int element = arr[index];
  for(int i = index; i < *size - 1; i++) {
    arr[i] = arr[i + 1];
  }
  arr = realloc(arr, (--*size)*sizeof(int));
  return element;
}

void remove_(int arr[], int *size, int element) {
  for (int i = 0; i < *size; i++) {
    if (arr[i] == element) {
      pop(arr, size, i);
      break;
    }
  }
}

int main () {
  system("cls");
  srand(time(0));

  int *arr = (int*)malloc((arr_size + 1)*sizeof(int));
  int *arr2 = (int*)calloc((arr2_size + 1), sizeof(int));

  fill_array(arr, arr_size);
  printArray(arr, arr_size);
  
  remove_(arr, &arr_size, 2);
  printArray(arr, arr_size);

  return 0;
}