// Copyright 2023, University of Freiburg
// Author: Joel Stanciu

#include <vector>
#include "./MergeSortMain.h"


void merge_sort_timing(size_t arg1) {
  std::vector<uninit_int> test = { 1, 2, 3 };
  size_t size = arg1;
  std::vector<uninit_int> array(size);
  printf("Array of size %ld created.\n", size);

  for (size_t i = 0; i < size; i++) {
    // printf("%d\n", size - i);
    array[i] = size - i;
    // if (i % 10000 == 0) {
    //   printf("%ld: %ld\n", i, array[i]);
    // }
  }
  std::cout << "Values of array initialized." << std::endl;

  auto start_time = std::chrono::steady_clock::now();
  // array = std::move(merge_sort(array));
  merge_sort(&array);
  auto end_time = std::chrono::steady_clock::now();
  int duration = std::chrono::duration_cast<\
    std::chrono::milliseconds>(end_time - start_time).count();
  std::cout.precision(2);
  std::cout << std::fixed << array.size() << "\t" << \
    static_cast<double>(duration) / 1000.0 << "s" << std::endl;
  printf("Running check on list...\n");
  int count_passed = 0;
  int count_failed = 0;
  for (size_t i = 0; i < (size_t)array.size(); i++) {
    if (i+1 == (size_t)array[i]) {
      count_passed += 1;
      // printf("%d: %d \t| ---\n", i, array[i]);
    } else {
      count_failed += 1;
      // printf("%d: %d \t| XXX\n", i, array[i]);
    }
  }
  printf("Statistics: Passed: %d | Failed: %d\n", count_passed, count_failed);
/*	
	printf("Check some elements....\n");
	printf("Array length: %d\n", array.size());
	for (size_t i = 0; i < array.size(); i += 1000) {
          printf("%d: %d\n", i, array[i]);
	}
*/	
}

int main(int argc, char* argv[]) {
  if (argc == 2) {
    merge_sort_timing(atoi(argv[1]));
  } else {
    printf("./MergeSortMain <size-of-array>\n");
    merge_sort_timing(1000000);
  }
}
