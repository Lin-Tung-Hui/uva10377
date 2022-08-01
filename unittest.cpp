#include <gtest/gtest.h>
#include "main.cpp"

TEST(uva10377, test_1)
{
    std::istringstream iss(R"--(1

7 8
********
* * * **
* *    *
* * ** *
* * *  *
*   * **
********
2 4
RRFLFF FFR
FF
RFFQ)--");

    std::ostringstream oss;

    uva10377(iss, oss);

    EXPECT_EQ(R"--(5 6 W
)--",
              oss.str());
}
