#include <gtest/gtest.h>
#include <ImageEditor.h>

TEST(IMG_E, Init) {
    const string path = "../img/";
    const string or_name = "pikachu.png";
    const string sa_name = "pikachu_init.png";

    ImageEditor imgEditor(path + or_name);

    imgEditor.save(path + sa_name);

    Picture pic1(path + or_name);
    Picture pic2(path + sa_name);

    EXPECT_EQ(pic1.width(), pic2.width());
    EXPECT_EQ(pic1.height(), pic2.height());

    for (int x = 0; x < pic1.width(); ++x) {
        for (int y = 0; y < pic1.height(); ++y) {
            EXPECT_EQ(pic1.red(x, y), pic2.red(x, y));
        }
    }
}

TEST(IMG_E, DoubleSize) {

    const string path = "../img/";
    const string or_name = "pikachu.png";

    ImageEditor imgEditor(path + or_name);

    imgEditor.doubleSize();
    const string sa_name = "pikachu_double.png";
    imgEditor.save(path + sa_name);

    Picture pic1(path + or_name);
    Picture pic2(path + sa_name);

    EXPECT_EQ(pic1.width() * 2, pic2.width());
    EXPECT_EQ(pic1.height() * 2, pic2.height());

    for (int x = 0; x < pic1.width(); ++x) {
        for (int y = 0; y < pic1.height(); ++y) {
            EXPECT_EQ(pic1.red(x, y), pic2.red(x * 2, y * 2));
            EXPECT_EQ(pic1.green(x, y), pic2.green(x * 2, y * 2));
            EXPECT_EQ(pic1.blue(x, y), pic2.blue(x * 2, y * 2));
        }
    }


}

TEST(IMG_E, Filter) {
    const string path = "../img/";
    const string or_name = "pikachu.png";

    ImageEditor imgEditor(path + or_name);
    int rt = 249;
    int gt = 219;
    int bt = 98;
    int t = 50;
    int rn = 234;
    int gn = 53;
    int bn = 247;
    imgEditor.colorFilter(rt, gt, bt, t, rn, gn, bn);
    const string sa_name = "pikachu_filter.png";
    imgEditor.save(path + sa_name);

    Picture pic1(path + or_name);
    Picture pic2(path + sa_name);

    EXPECT_EQ(pic1.width(), pic2.width());
    EXPECT_EQ(pic1.height(), pic2.height());

    for (int x = 0; x < pic1.width(); ++x) {
        for (int y = 0; y < pic1.height(); ++y) {
            if (pic1.red(x, y) == rt && pic1.green(x, y) == gt && pic1.blue(x, y) == bt) {
                EXPECT_EQ(pic2.red(x, y), rn);
                EXPECT_EQ(pic2.green(x, y), gn);
                EXPECT_EQ(pic2.blue(x, y), bn);
            }

        }
    }
}

TEST(ING_F, TurnH) {
    const string path = "../img/";
    const string or_name = "pikachu.png";

    ImageEditor imgEditor(path + or_name);
//    imgEditor.flipVertical();
    imgEditor.flipHorizontal();

    const string sa_name = "pikachu_turnh.png";
    imgEditor.save(path + sa_name);

    Picture pic1(path + or_name);
    Picture pic2(path + sa_name);

    EXPECT_EQ(pic1.width(), pic2.width());
    EXPECT_EQ(pic1.height(), pic2.height());

    for (int x = 0; x < pic1.width(); ++x) {
        for (int y = 0; y < pic1.height(); ++y) {
            EXPECT_EQ(pic1.red(x, y), pic2.red(x, pic2.height() - y - 1));
        }
    }
}

TEST(ING_F, TurnV) {
    const string path = "../img/";
    const string or_name = "pikachu.png";

    ImageEditor imgEditor(path + or_name);
    imgEditor.flipVertical();
//    imgEditor.flipHorizontal();

    const string sa_name = "pikachu_turnv.png";
    imgEditor.save(path + sa_name);

    Picture pic1(path + or_name);
    Picture pic2(path + sa_name);

    EXPECT_EQ(pic1.width(), pic2.width());
    EXPECT_EQ(pic1.height(), pic2.height());

    for (int x = 0; x < pic1.width(); ++x) {
        for (int y = 0; y < pic1.height(); ++y) {
            EXPECT_EQ(pic1.red(x, y), pic2.red(pic2.width() - x - 1, y));
        }
    }
}