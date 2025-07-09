#include <iostream>

using namespace std;

/*
* <Binary Search Problem: First Occurrence>
* You're given a sorted array of integers (may contain duplicates). 
* Write a function that performs binary search to find the first occurrence of a given target number.
* If the target is not found, return -1.
*/

int binary_search_first_occurrence(int numbers[],int target, int low, int high);

int main(){
  const int N = 7;
  int numbers[N] = {1, 3, 3, 3, 5, 7, 9};
  int target;

  cout << "Enter number: ";
  cin >> target;
  cout << endl;

  int result = binary_search_first_occurrence(numbers, target, 0, N - 1);

  cout << "Result: " << result << endl;

  return 0;
}


int binary_search_first_occurrence(int numbers[], int target, int low, int high){
  if(low > high){
    return -1;
  }

  int mid_index = (low + high) / 2;
  int mid_prev_index = mid_index - 1;
  int mid_element = numbers[mid_index];

  if(mid_element == target && (mid_index == 0 || numbers[mid_prev_index] != target)) {
    return mid_index;
  }else if(mid_element >= target){
    return binary_search_first_occurrence(numbers, target, low, mid_index - 1);
  }else{
    return binary_search_first_occurrence(numbers, target, mid_index + 1, high);
  }
}