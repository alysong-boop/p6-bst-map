#include "BinarySearchTree.hpp"
#include "unit_test_framework.hpp"
#include <sstream>

using namespace std;


TEST(empty) {
    BinarySearchTree<int> bst;
    ASSERT_TRUE(bst.empty());
    bst.insert(3);
    ASSERT_FALSE(bst.empty());
}

TEST(size) {
    BinarySearchTree<int> bst;
    ASSERT_TRUE(bst.size() == 0);
    bst.insert(3);
    ASSERT_TRUE(bst.size() == 1);
    bst.insert(6);
    bst.insert(2);
    ASSERT_TRUE(bst.size() == 3);
}

TEST(height) {
    BinarySearchTree<int> bst;
    ASSERT_TRUE(bst.height() == 0);
    bst.insert(4);
    ASSERT_TRUE(bst.height() == 1);
    bst.insert(5);
    bst.insert(7);
    bst.insert(6);
    ASSERT_TRUE(bst.height() == 4);
    bst.insert(8);
    ASSERT_TRUE(bst.height() == 4);
    bst.insert(3);
    bst.insert(2);
    bst.insert(1);
    ASSERT_TRUE(bst.height() == 4);
    bst.insert(10);
    ASSERT_TRUE(bst.height() == 5);
}

TEST(prefixplusplus) {
    BinarySearchTree<int> bst;
    bst.insert(4);
    bst.insert(5);
    bst.insert(7);
    bst.insert(6);
    bst.insert(8);
    auto i = bst.begin();
    ++i;
    ASSERT_TRUE(*i == 5);

    BinarySearchTree<int> tree;
    tree.insert(8);
    tree.insert(4);
    tree.insert(6);
    tree.insert(3);
    auto j = bst.begin();
    ++j;
    ++j;
    ASSERT_TRUE(*j == 6);
}

TEST(assignment) {
    BinarySearchTree<int> bst;
    bst.insert(67);
    bst.insert(41);
    bst.insert(36);
    bst.insert(64);
    bst.insert(56);
    ASSERT_TRUE(bst.size() == 5);

    BinarySearchTree<int> tree = bst;
    ASSERT_TRUE(tree.size() == 5);
    auto i = tree.begin();
    ++i;
    ++i;
    ASSERT_TRUE(*i == 56);
    tree.insert(3);
    ASSERT_TRUE(tree.size() == 6);
    ASSERT_TRUE(bst.size() == 5);
    auto j = tree.find(3);
    auto k = bst.find(3);
    ASSERT_TRUE(*j == 3);
    ASSERT_TRUE(k == bst.end());
}

TEST(find_) {
    BinarySearchTree<int> bst;
    bst.insert(67);
    bst.insert(41);
    bst.insert(36);
    bst.insert(64);
    bst.insert(56);
    auto i = bst.find(67);
    ASSERT_TRUE(*i == 67);
    *i = 8;
    auto i2  = bst.find(67);
    ASSERT_TRUE(i2 == bst.end());

    auto j = bst.find(2);
    ASSERT_TRUE(j == bst.end());
}

TEST(insert) {
    BinarySearchTree<int> bst;
    bst.insert(67);
    bst.insert(41);
    bst.insert(36);
    bst.insert(64);
    auto i = bst.insert(56);

    ASSERT_TRUE(*i == 56);
    *i = 20;
    auto j = bst.find(56);
    ASSERT_TRUE(j == bst.end());
}

TEST(min_max) {
    BinarySearchTree<int> bst;
    bst.insert(67);
    bst.insert(41);
    bst.insert(36);
    bst.insert(64);
    bst.insert(56);
    auto i = bst.min_element();
    auto j = bst.max_element();
    ASSERT_TRUE(*i == 36);
    ASSERT_TRUE(*j == 67);

    BinarySearchTree<int> tree;
    i = tree.min_element();
    j = tree.max_element();
    ASSERT_TRUE(i == tree.end());
    ASSERT_TRUE(j == tree.end());
    tree.insert(1);
    i = tree.min_element();
    j = tree.max_element();
    ASSERT_TRUE(*i == 1);
    ASSERT_TRUE(*j == 1);
    tree.insert(5);
    tree.insert(3);
    tree.insert(8);
    i = tree.min_element();
    j = tree.max_element();
    ASSERT_TRUE(*i == 1);
    ASSERT_TRUE(*j == 8);

    BinarySearchTree<int> e;
    e.insert(1);
    e.insert(2);
    e.insert(3);
    e.insert(4);
    e.insert(5);
    e.insert(6);
    e.insert(7);
    i = e.min_element();
    j = e.max_element();
    ASSERT_TRUE(*i == 1);
    ASSERT_TRUE(*j == 7);

    BinarySearchTree<int> f;
    f.insert(7);
    f.insert(6);
    f.insert(5);
    f.insert(4);
    f.insert(3);
    f.insert(2);
    f.insert(1);
    i = f.min_element();
    j = f.max_element();
    ASSERT_TRUE(*i == 1);
    ASSERT_TRUE(*j == 7);
}

TEST(sorting_invariant) {
    BinarySearchTree<int> bst;
    bst.insert(67);
    bst.insert(41);
    bst.insert(36);
    bst.insert(64);
    bst.insert(56);
    ASSERT_TRUE(bst.check_sorting_invariant());

    auto j = bst.find(67);
    *j = 2;
    ASSERT_FALSE(bst.check_sorting_invariant());

    BinarySearchTree<int> tree;
    tree.insert(4);
    tree.insert(5);
    tree.insert(7);
    tree.insert(6);
    ASSERT_TRUE(tree.check_sorting_invariant());

    auto i = tree.find(7);
    *i = 3;
    ASSERT_FALSE(tree.check_sorting_invariant());

    BinarySearchTree<int> e;
    ASSERT_TRUE(e.check_sorting_invariant());
    e.insert(1);
    ASSERT_TRUE(e.check_sorting_invariant());
    auto k = e.find(1);
    *k = 8;
    ASSERT_TRUE(e.check_sorting_invariant());
}

TEST(traverse_inorder) {
    BinarySearchTree<int> tree;
    tree.insert(8);
    tree.insert(6);
    tree.insert(10);
    tree.insert(7);
    tree.insert(4);
    tree.insert(11);
    tree.insert(9);

    ostringstream order;
    tree.traverse_inorder(order);
    ASSERT_TRUE(order.str() == "4 6 7 8 9 10 11 ");

    BinarySearchTree<int> bst;
    bst.insert(67);
    bst.insert(41);
    bst.insert(36);
    bst.insert(64);
    bst.insert(56);

    ostringstream order2;
    bst.traverse_inorder(order2);
    ASSERT_TRUE(order2.str() == "36 41 56 64 67 ");

    BinarySearchTree<int> e;
    ostringstream order3;
    e.traverse_inorder(order3);
    ASSERT_TRUE(order3.str() == "");
}

TEST(traverse_preorder) {
    BinarySearchTree<int> tree;
    tree.insert(8);
    tree.insert(6);
    tree.insert(10);
    tree.insert(7);
    tree.insert(4);
    tree.insert(11);
    tree.insert(9);

    ostringstream order;
    tree.traverse_preorder(order);
    ASSERT_TRUE(order.str() == "8 6 4 7 10 9 11 ");

    BinarySearchTree<int> bst;
    bst.insert(67);
    bst.insert(41);
    bst.insert(36);
    bst.insert(64);
    bst.insert(56);

    ostringstream order2;
    bst.traverse_preorder(order2);
    ASSERT_TRUE(order2.str() == "67 41 36 64 56 ");
}

TEST(min_greater_than) {
    BinarySearchTree<int> tree;
    tree.insert(8);
    tree.insert(6);
    tree.insert(10);
    tree.insert(7);
    tree.insert(4);
    tree.insert(11);
    tree.insert(9);

    auto i = tree.min_greater_than(6);
    ASSERT_TRUE(*i == 7);
    i = tree.min_greater_than(4);
    ASSERT_TRUE(*i == 6);

    BinarySearchTree<int> e;
    e.insert(1);
    e.insert(2);
    e.insert(3);
    e.insert(4);
    e.insert(5);
    e.insert(6);
    e.insert(7);
    auto j = e.min_greater_than(1);
    ASSERT_TRUE(*j == 2);
    j = e.min_greater_than(8);
    ASSERT_TRUE(j == e.end());
}

TEST_MAIN()
