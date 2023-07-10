// Copyright 2023, University of Freiburg
// Author: Joel Stanciu

#include <vector>
#include <utility>
#include "./MergeSort.h"


std::vector<uninit_int>& merge(std::vector<uninit_int>* lst, \
  size_t left, size_t middle, size_t right) {
  std::vector<uninit_int> merged;
  merged.reserve(right - left);

  size_t i = left;
  size_t j = middle;

  while (i < middle && j < right) {
    if ((*lst)[i] < (*lst)[j]) {
      merged.push_back(std::move((*lst)[i]));
      i++;
    } else {
      merged.push_back(std::move((*lst)[j]));
      j++;
    }
  }

  while (i < middle) {
    merged.push_back(std::move((*lst)[i]));
    i++;
  }

  while (j < right) {
    merged.push_back(std::move((*lst)[j]));
    j++;
  }

  size_t k = left;
  for (uninit_int& element : merged) {
    (*lst)[k] = std::move(element);
    k++;
  }
  return *lst;
}

std::vector<uninit_int>& merge_sort(std::vector<uninit_int>* lst, \
  size_t left, size_t right) {
  if (left + 1 < right) {
    size_t middle = left + (right - left) / 2;
    merge_sort(lst, left, middle);
    merge_sort(lst, middle, right);
    merge(lst, left, middle, right);
  }
  return *lst;
}

std::vector<uninit_int>& merge_sort(std::vector<uninit_int>* lst) {
  return merge_sort(lst, 0, lst->size());
}

