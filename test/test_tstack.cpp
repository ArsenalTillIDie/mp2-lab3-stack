#include "utstack.h"

#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length) {
   ASSERT_NO_THROW(TStack<int> s(5));
}

TEST(TStack, can_access_top_elem) {
    TStack<int> s(5);
    s.push(2);
    s.push(4);
    ASSERT_EQ(s.top(), 4);
}

TEST(TStack, can_pop) {
    TStack<int> s(5);
    s.push(2);
    s.push(4);
    s.pop();
    ASSERT_EQ(s.top(), 2);
}

TEST(TStack, can_detect_emptiness) {
    TStack<int> s(5);
    ASSERT_TRUE(s.empty());
}

TEST(TStack, cannot_push_full_stack) {
    TStack<int> s(2);
    s.push(2);
    s.push(4);
    ASSERT_ANY_THROW(s.push(3));
}

TEST(TStack, cannot_pop_empty_stack) {
    TStack<int> s(5);
    ASSERT_ANY_THROW(s.pop());
}

TEST(TStack, copy_constructor_works) {
    TStack<int> s1(5);
    s1.push(2);
    s1.push(4);
    TStack<int> s2(s1);
    ASSERT_TRUE(s1.top() == s2.top() && s1.getMaxSize() == s2.getMaxSize());
}

TEST(Queue, can_create_queue_with_positive_length) {
    ASSERT_NO_THROW(Queue<int> s(5));
}

TEST(Queue, can_access_top_elem) {
    Queue<int> s(5);
    s.push(2);
    s.push(4);
    ASSERT_EQ(s.next(), 2);
}

TEST(Queue, can_pop) {
    Queue<int> s(5);
    s.push(2);
    s.push(4);
    s.pop();
    ASSERT_EQ(s.next(), 4);
}

TEST(Queue, can_detect_emptiness) {
    Queue<int> s(5);
    ASSERT_TRUE(s.empty());
}

TEST(Queue, cannot_push_full_queue) {
    Queue<int> s(2);
    s.push(2);
    s.push(4);
    ASSERT_ANY_THROW(s.push(3));
}

TEST(Queue, cannot_pop_empty_queue) {
    Queue<int> s(5);
    ASSERT_ANY_THROW(s.pop());
}

TEST(Queue, copy_constructor_works) {
    Queue<int> s1(5);
    s1.push(2);
    s1.push(4);
    Queue<int> s2(s1);
    ASSERT_TRUE(s1.next() == s2.next() && s1.getMaxSize() == s2.getMaxSize());
}