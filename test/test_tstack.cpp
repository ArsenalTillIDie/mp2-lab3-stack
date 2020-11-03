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

TEST(Queue, can_push_full_queue) {
    Queue<int> s(2);
    s.push(2);
    s.push(4);
    s.push(3);
    s.pop();
    s.pop();
    ASSERT_EQ(s.next(), 3);
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
    ASSERT_TRUE(s1.next() == s2.next() && s1.getNElems() == s2.getNElems());
}

TEST(Queue, can_deal_with_many_pushes_and_pops) {
    Queue<int> s(3);
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();
    s.push(5);
    s.push(6);
    s.pop();
    s.pop();
    ASSERT_EQ(s.next(), 5);
}

TEST(Queue, works_correctly) {
    Queue<int> queue(5);  // capacity=5, size=0
    queue.push(1);        // data={1, 0, 0, 0, 0}, pop_index=0, push_index=1
    queue.push(2);        // data={1, 2, 0, 0, 0}, pop_index=0, push_index=2
    queue.push(3);        // data={1, 2, 3, 0, 0}, pop_index=0, push_index=3
    queue.pop();          // data={0, 2, 3, 0, 0}, pop_index=1, push_index=3
    queue.push(4);        // data={0, 2, 3, 4, 0}, pop_index=1, push_index=4
    queue.pop();          // data={0, 0, 3, 4, 0}, pop_index=2, push_index=4
    queue.push(5);        // data={0, 0, 3, 4, 5}, pop_index=2, push_index=0
    queue.push(6);        // data={6, 0, 3, 4, 5}, pop_index=2, push_index=1
    queue.push(7);        // data={6, 7, 3, 4, 5}, pop_index=2, push_index=2
    queue.push(8);        // new capasity=8 (for example), data={3, 4, 5, 6, 7, 0, 0, 0}, pop_index=0, push_index=5
    bool mistakeFlag = false;
    if (queue.next() != 3) mistakeFlag = true;
    queue.pop();
    if (queue.next() != 4) mistakeFlag = true;
    queue.pop();
    if (queue.next() != 5) mistakeFlag = true;
    queue.pop();
    if (queue.next() != 6) mistakeFlag = true;
    queue.pop();
    if (queue.next() != 7) mistakeFlag = true;
    queue.pop();
    if (queue.next() != 8) mistakeFlag = true;
    ASSERT_FALSE(mistakeFlag);
}