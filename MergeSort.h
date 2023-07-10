// Copyright 2023, University of Freiburg
// Author: Joel Stanciu

#ifndef MERGESORT_H_
#define MERGESORT_H_

#include <vector>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <utility>

struct uninit_int {
 public:
  int val;

  uninit_int() { ; }

  uninit_int(int other) {  // NOLINT
    val = other;
  }

  operator int() const {
    return val;
  }

  uninit_int& operator=(const int& other) {
    val = other;
    return *this;
  }
};

std::vector<uninit_int>& merge(std::vector<uninit_int>* lst, \
  size_t left, size_t middle, size_t right);

std::vector<uninit_int>& merge_sort(std::vector<uninit_int>* lst, \
  size_t left, size_t right);

std::vector<uninit_int>& merge_sort(std::vector<uninit_int>* lst);

#endif  // MERGESORT_H_
