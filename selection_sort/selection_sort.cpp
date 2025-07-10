#include <iostream>

using namespace std;

void selection_sort(int arr[], int n);

void print_arr(int arr[], int n);

int main(){
  const int N = 10;
  int numbers[N] = {5, 2, 3, 4, 2, 5, 7, 9, 8, 10};

  selection_sort(numbers, N);
  print_arr(numbers, N);

  return 0;
}


void selection_sort(int arr[], int n){
  int temp = arr[0];

  for(int i = 0; i < n; i++){
    int min_index = i;

    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_index]) {
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
