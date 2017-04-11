// 用Google Test简单地测试一下写的Priority Queue有没有
// 什么明显的问题.

#include <iostream>
#include "gtest/gtest.h"
#include "../priority_queue.h"

// TEST(HELLO, WORLD)
// {
//     EXPECT_EQ(1, 1);
// }

TEST(PRIORITY_Q, POP) {
    PriorityQ<int> pq1 = {3, 1, 6, 4, 2, 5};
    EXPECT_EQ(pq1.IsEmpty(), false);
    EXPECT_EQ(pq1.PopMax(), 6);
    EXPECT_EQ(pq1.PopMax(), 5);
    EXPECT_EQ(pq1.PopMax(), 4);
    EXPECT_EQ(pq1.PopMax(), 3);
    EXPECT_EQ(pq1.PopMax(), 2);
    EXPECT_EQ(pq1.PopMax(), 1);
    EXPECT_EQ(pq1.IsEmpty(), true);
}

TEST(PRIORITY_Q, INSERT_POP) {
    PriorityQ<int> pq2 = {2, 5, 1};
    pq2.Insert(3);  // 1, 2, 3, 5
    EXPECT_EQ(pq2.PopMax(), 5); // 1, 2, 3
    pq2.Insert(-1);  // -1, 1, 2, 3
    EXPECT_EQ(pq2.PopMax(), 3); // -1, 1, 2
    EXPECT_EQ(pq2.PopMax(), 2); // -1, 1
    pq2.Insert(6);  // -1, 1, 6
    EXPECT_EQ(pq2.PopMax(), 6); // -1, 1

    EXPECT_EQ(pq2.Size(), 2);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
