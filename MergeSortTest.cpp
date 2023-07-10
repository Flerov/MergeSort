// Copyright 2023, University of Freiburg
// Author: Joel Stanciu

#include <gtest/gtest.h>
#include <vector>
#include "./MergeSort.h"


TEST(MergeSortMain, structure) {
  uninit_int t1;  // is uninitialized, but cant be checkd with gtest
  uninit_int t2(5);
  ASSERT_EQ(t2, 5);
  uninit_int t3 = 8;
  ASSERT_EQ(t3, 8);
  // return value is definitly int, but cant be checkd with gtest
}

TEST(MergeSortMain, merge) {
  std::vector<uninit_int> lst = { 4, 3, 2, 1 };
  std::vector<uninit_int> res = { 3, 4, 2, 1 };
  merge(&lst, 0, 1, 2);
  ASSERT_EQ(lst, res);
  std::vector<uninit_int> res1 = { 3, 4, 1, 2 };
  merge(&lst, 2, 3, 4);
  ASSERT_EQ(lst, res1);
  std::vector<uninit_int> res2 = { 1, 2, 3, 4 };
  merge(&lst, 0, 2, 4);
  ASSERT_EQ(lst, res2);
  std::vector<uninit_int> lst2 = { 4, 2, 3, 1 };
  std::vector<uninit_int> res3 = { 2, 4, 3, 1 };
  merge(&lst2, 0, 1, 2);
  ASSERT_EQ(lst2, res3);
  std::vector<uninit_int> res4 = { 2, 4, 1, 3 };
  merge(&lst2, 2, 3, 4);
  ASSERT_EQ(lst2, res4);
  merge(&lst2, 0, 2, 4);
  ASSERT_EQ(lst2, res2);
}

TEST(MergeSortMain, merge_sort) {
  std::vector<uninit_int> lst = { };
  merge_sort(&lst);
  ASSERT_EQ(lst.size(), 0);
  std::vector<uninit_int> lst1 = { 1 };
  std::vector<uninit_int> res = { 1 };
  merge_sort(&lst1);
  ASSERT_EQ(lst1, res);
  std::vector<uninit_int> lst2 = { 1, 4, -3 };
  std::vector<uninit_int> res1 = { -3, 1, 4 };
  merge_sort(&lst2);
  ASSERT_EQ(lst2, res1);
  std::vector<uninit_int> lst3 = { 1, 2, 3, 4 };
  std::vector<uninit_int> res2 = { 1, 2, 3, 4 };
  merge_sort(&lst3);
  ASSERT_EQ(lst3, res2);
  std::vector<uninit_int> lst4 = { 1, 4, 2, 3 };
  std::vector<uninit_int> res3 = { 1, 2, 3, 4 };
  merge_sort(&lst4);
  ASSERT_EQ(lst4, res3);

  std::vector<uninit_int> l = { 10, 5, 3, 9, 6, 2, 1, 7, 4, 8 };
  std::vector<uninit_int> t = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  merge_sort(&l);
  ASSERT_EQ(l, t);
}
