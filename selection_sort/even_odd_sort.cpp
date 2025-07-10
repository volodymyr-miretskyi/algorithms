#include <iostream>

using namespace std;

/*
* Problem: Sort Even Numbers First
* Task:
* Write a function that uses Selection Sort to sort an array of integers such that:
* All even numbers appear before odd numbers
* Even and odd numbers are each sorted in ascending order
*/


void print_arr(int arr[], int n);

void selection_sort(int arr[], int n);

int main(){
  const int N = 9;
  int numbers[N] = {2, 9, 4, 1, 8, 3, 6, 2, 3};

  selection_sort(numbers, N);
  print_arr(numbers, N);
  return 0;
}

void selection_sort(int arr[], int n){
  int even_end = 0;

  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 == 0) {
      int temp = arr[i];
      arr[i] = arr[even_end];
      arr[even_end] = temp;
      even_end++;
    }
  }

  // Sort evens
  for(int i = 0; i < even_end; i++){
    int min_index = i;

    for (int j = i + 1; j < even_end; j++) {
      if (arr[min_index] > arr[j]) {
        min_index = j;
      }
    }

    if (min_index != i) {
      int temp = arr[i];
      arr[i] = arr[min_index];
      arr[min_index] = temp;
    } 
  }

  // Sort odds
  for(int i = even_end; i < n - 1; i++){
    int min_index = i;

    for (int j = i + 1; j < n; j++) {
      if (arr[min_index] > arr[j]) {
        min_index = j;
      }
    }

    if (min_index != i) {
      int temp = arr[i];
      arr[i] = arr[min_index];
      arr[min_index] = temp;
    } 
  }
}

void print_arr(int arr[], int n){
  for(int i = 0; i < n; i++){
    cout << arr[i] << ", ";
  }
}