#include "paramchecker.h"
#include <gtest/gtest.h>
#include <vector>

TEST(VitalsTest, BPM) { 
    std::vector<struct vitalParam> vitalArray;
    vitalParam bpm = {"bpm", 100};
    vitalArray.push_back(bpm);
    ASSERT_EQ(0, vitalsOk(vitalArray));
}
 
TEST(VitalsTest, SPO2) {
    std::vector<struct vitalParam> vitalArray;
    vitalParam spo = {"spo", 90};
    vitalArray.push_back(spo);
    ASSERT_EQ(0, vitalsOk(vitalArray));
}

TEST(VitalsTest, RESP) {
    std::vector<struct vitalParam> vitalArray;
    vitalParam resp = {"resp", 50};
    vitalArray.push_back(resp);
    ASSERT_EQ(0, vitalsOk(vitalArray));
}

TEST(VitalsTest, UNKNOWN) {
    struct vitalParam paramArr[] = {{"bpm", 100},
                                    {"spo", 90},
                                    {"resp", 50},
                                    {"uknown", 60}};
    std::vector<struct vitalParam> vitalArray(paramArr,
                                              paramArr + (sizeof paramArr / sizeof (struct vitalParam)) );
    ASSERT_EQ(-1, vitalsOk(vitalArray));
    
}


TEST(VitalsTest, NEGATIVE1) {
    struct vitalParam paramArr[] = {{"bpm", 100},
                                    {"spo", 10},
                                    {"resp", 50}};
    std::vector<struct vitalParam> vitalArray(paramArr,
                                              paramArr + (sizeof paramArr / sizeof (struct vitalParam)) );
    ASSERT_LE(0, vitalsOk(vitalArray));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

