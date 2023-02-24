#include <gtest/gtest.h>
#include <Matrices.h>

TEST(MAT_Test, Init) {

    const int row = 2, col = 3;
    Matrices::Matrix m(row, col);
    ASSERT_EQ(m.getRows(), row);
    EXPECT_EQ(m.getRows(), row);
    EXPECT_EQ(m.getCols(), col);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            EXPECT_EQ(m(i, j), 0);
        }
    }
}

TEST(MAT_Test, Add) {
    const int row = 2, col = 3;

    Matrices::Matrix m1(row, col);
    Matrices::Matrix m2(row, col);

    m1(0, 1) = 10;
    m2(0, 1) = 5;

    Matrices::Matrix c = m1 + m2;

    EXPECT_EQ(c(0, 1), 15);

    c = c + m2;
    EXPECT_EQ(c(0, 1), 20);
}

TEST(MAT_Test, Multip) {
    Matrices::Matrix a(2, 2);
    Matrices::Matrix b(2, 3);
    Matrices::Matrix c(3, 2);

    a(0, 0) = 6;
    a(0, 1) = 5;
    a(1, 0) = 1;
    a(1, 1) = 2;

    b(0, 0) = 2;
    b(0, 1) = -1;
    b(0, 2) = 3;
    b(1, 0) = 1;
    b(1, 1) = 0;
    b(1, 2) = 4;

    c(0, 0) = 1;
    c(0, 1) = -1;
    c(1, 0) = 2;
    c(1, 1) = 3;
    c(2, 0) = -1;
    c(2, 1) = 2;


    Matrices::Matrix ab(2, 3);
    ab(0, 0) = 17;
    ab(0, 1) = -6;
    ab(0, 2) = 38;

    ab(1, 0) = 4;
    ab(1, 1) = -1;
    ab(1, 2) = 11;

    Matrices::Matrix bc(2, 2);
    bc(0, 0) = -3;
    bc(0, 1) = 1;

    bc(1, 0) = -3;
    bc(1, 1) = 7;

    Matrices::Matrix result_ab = a * b;
    EXPECT_TRUE(ab == result_ab);

    Matrices::Matrix result_bc = b * c;
    EXPECT_TRUE(bc == result_bc);

}

TEST(MAT_Test, EQ_NE) {
    Matrices::Matrix a(2, 2);
    Matrices::Matrix b(2, 3);
    Matrices::Matrix c(2, 2);

    a(0, 0) = 6;
    a(0, 1) = 5;
    a(1, 0) = 1;
    a(1, 1) = 2;

    b(0, 0) = 2;
    b(0, 1) = -1;
    b(0, 2) = 3;
    b(1, 0) = 1;
    b(1, 1) = 0;
    b(1, 2) = 4;

    c(0, 0) = 6;
    c(0, 1) = 5;
    c(1, 0) = 1;
    c(1, 1) = 2;

    EXPECT_TRUE(a == c);
    EXPECT_FALSE(a == b);
    EXPECT_FALSE(b == c);

    EXPECT_FALSE(a != c);
    EXPECT_TRUE(a != b);
    EXPECT_TRUE(c != b);
}