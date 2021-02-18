#include "gtest/gtest.h"
#include "expressionstream.h"

class Lab01Fixture : public ::testing::Test {

protected:
    virtual void TearDown() {
        delete stream1;
        delete stream2;
        delete stream3;
        delete stream4;
    }

    virtual void SetUp() {
        stream1=new lab1::expressionstream("6+7+9");
        stream2=new lab1::expressionstream("4   + 6 *5+(8*2)");
        stream3=new lab1::expressionstream("-6 +-9");
        stream4 = new lab1::expressionstream("-2-(-2-(2--2)-2)-2");
    }


public:
    lab1::expressionstream *stream1;
    lab1::expressionstream *stream2;
    lab1::expressionstream *stream3;
    lab1::expressionstream *stream4;
};


TEST(crashTest , constructorTest) {
    lab1::expressionstream stream1("6+7+9");
    lab1::expressionstream stream2("4   + 6 *5+(8*2)");
}

TEST_F(Lab01Fixture, basicNextToken) {
    //1+2+3+5
    EXPECT_EQ("6", stream1->get_next_token());
    EXPECT_EQ("+", stream1->get_next_token());
    EXPECT_EQ("7", stream1->get_next_token());
    EXPECT_EQ("+", stream1->get_next_token());
    EXPECT_EQ("9", stream1->get_next_token());
    EXPECT_EQ("\0", stream1->get_next_token());

    //4   + 6 *5+(8*2)
    EXPECT_EQ("4", stream2->get_next_token());
    EXPECT_EQ("+", stream2->get_next_token());
    EXPECT_EQ("6", stream2->get_next_token());
    EXPECT_EQ("*", stream2->get_next_token());
    EXPECT_EQ("5", stream2->get_next_token());
    EXPECT_EQ("+", stream2->get_next_token());
    EXPECT_EQ("(", stream2->get_next_token());
    EXPECT_EQ("8", stream2->get_next_token());
    EXPECT_EQ("*", stream2->get_next_token());
    EXPECT_EQ("2", stream2->get_next_token());
    EXPECT_EQ(")", stream2->get_next_token());

    //-6 +-9
    EXPECT_EQ("-6", stream3->get_next_token());
    EXPECT_EQ("+", stream3->get_next_token());
    EXPECT_EQ("-9", stream3->get_next_token());

    //-2-(-2-(2--2)-2)-2
    EXPECT_EQ("-2", stream4->get_next_token());
    EXPECT_EQ("-", stream4->get_next_token());
    EXPECT_EQ("(", stream4->get_next_token());
    EXPECT_EQ("-2", stream4->get_next_token());
    EXPECT_EQ("-", stream4->get_next_token());
    EXPECT_EQ("(", stream4->get_next_token());
    EXPECT_EQ("2", stream4->get_next_token());
    EXPECT_EQ("-", stream4->get_next_token());
    EXPECT_EQ("-2", stream4->get_next_token());
    EXPECT_EQ(")", stream4->get_next_token());
    EXPECT_EQ("-", stream4->get_next_token());
    EXPECT_EQ("2", stream4->get_next_token());
    EXPECT_EQ(")", stream4->get_next_token());
    EXPECT_EQ("-", stream4->get_next_token());
    EXPECT_EQ("2", stream4->get_next_token());
}

TEST_F(Lab01Fixture, multiDigitNextToken) {
    delete stream1;
    delete stream2;
    delete stream3;
    delete stream4;

    stream1 = new lab1::expressionstream("111+222+5555");
    stream2 = new lab1::expressionstream("265   + 987 *661+(109*345)");
    stream3 = new lab1::expressionstream("-841 +-6987");
    stream4 = new lab1::expressionstream("-826-(-12-(6--7594)-98456)--77");

    //111+222+5555
    EXPECT_EQ("111", stream1->get_next_token());
    EXPECT_EQ("+", stream1->get_next_token());
    EXPECT_EQ("222", stream1->get_next_token());
    EXPECT_EQ("+", stream1->get_next_token());
    EXPECT_EQ("5555", stream1->get_next_token());
    EXPECT_EQ("\0", stream1->get_next_token());

    //265   + 987 *661+(109*345)
    EXPECT_EQ("265", stream2->get_next_token());
    EXPECT_EQ("+", stream2->get_next_token());
    EXPECT_EQ("987", stream2->get_next_token());
    EXPECT_EQ("*", stream2->get_next_token());
    EXPECT_EQ("661", stream2->get_next_token());
    EXPECT_EQ("+", stream2->get_next_token());
    EXPECT_EQ("(", stream2->get_next_token());
    EXPECT_EQ("109", stream2->get_next_token());
    EXPECT_EQ("*", stream2->get_next_token());
    EXPECT_EQ("345", stream2->get_next_token());
    EXPECT_EQ(")", stream2->get_next_token());

    //-841 +-6987
    EXPECT_EQ("-841", stream3->get_next_token());
    EXPECT_EQ("+", stream3->get_next_token());
    EXPECT_EQ("-6987", stream3->get_next_token());

    //-826-(-12-(6--7594)-98456)--77
    EXPECT_EQ("-826", stream4->get_next_token());
    EXPECT_EQ("-", stream4->get_next_token());
    EXPECT_EQ("(", stream4->get_next_token());
    EXPECT_EQ("-12", stream4->get_next_token());
    EXPECT_EQ("-", stream4->get_next_token());
    EXPECT_EQ("(", stream4->get_next_token());
    EXPECT_EQ("6", stream4->get_next_token());
    EXPECT_EQ("-", stream4->get_next_token());
    EXPECT_EQ("-7594", stream4->get_next_token());
    EXPECT_EQ(")", stream4->get_next_token());
    EXPECT_EQ("-", stream4->get_next_token());
    EXPECT_EQ("98456", stream4->get_next_token());
    EXPECT_EQ(")", stream4->get_next_token());
    EXPECT_EQ("-", stream4->get_next_token());
    EXPECT_EQ("-77", stream4->get_next_token());
}

TEST_F(Lab01Fixture, multiDigitCurrentToken) {
    delete stream1;
    delete stream2;
    delete stream3;
    delete stream4;

    stream1 = new lab1::expressionstream("145+623+8549");
    stream2 = new lab1::expressionstream("524   + 652 *888+(797*101)");
    stream3 = new lab1::expressionstream("-546 +-7728");
    stream4 = new lab1::expressionstream("-100-(-35-(1--5517)-98342)--98");

    //145+623+8549
    stream1->get_next_token();
    EXPECT_EQ("145", stream1->get_current_token());
    stream1->get_next_token();
    EXPECT_EQ("+", stream1->get_current_token());
    stream1->get_next_token();
    EXPECT_EQ("623", stream1->get_current_token());
    stream1->get_next_token();
    EXPECT_EQ("+", stream1->get_current_token());
    stream1->get_next_token();
    EXPECT_EQ("8549", stream1->get_current_token());
    stream1->get_next_token();
    EXPECT_EQ("\0", stream1->get_current_token());
    stream1->get_next_token();

    //524   + 652 *888+(797*101)
    stream2->get_next_token();
    EXPECT_EQ("524", stream2->get_current_token());
    stream2->get_next_token();
    EXPECT_EQ("+", stream2->get_current_token());
    stream2->get_next_token();
    EXPECT_EQ("652", stream2->get_current_token());
    stream2->get_next_token();
    EXPECT_EQ("*", stream2->get_current_token());
    stream2->get_next_token();
    EXPECT_EQ("888", stream2->get_current_token());
    stream2->get_next_token();
    EXPECT_EQ("+", stream2->get_current_token());
    stream2->get_next_token();
    EXPECT_EQ("(", stream2->get_current_token());
    stream2->get_next_token();
    EXPECT_EQ("797", stream2->get_current_token());
    stream2->get_next_token();
    EXPECT_EQ("*", stream2->get_current_token());
    stream2->get_next_token();
    EXPECT_EQ("101", stream2->get_current_token());
    stream2->get_next_token();
    EXPECT_EQ(")", stream2->get_current_token());
    stream2->get_next_token();

    //-546 +-7728
    stream3->get_next_token();
    EXPECT_EQ("-546", stream3->get_current_token());
    stream3->get_next_token();
    EXPECT_EQ("+", stream3->get_current_token());
    stream3->get_next_token();
    EXPECT_EQ("-7728", stream3->get_current_token());
    stream3->get_next_token();

    //-100-(-35-(1--5517)-98342)--98
    stream4->get_next_token();
    EXPECT_EQ("-100", stream4->get_current_token());
    stream4->get_next_token();
    EXPECT_EQ("-", stream4->get_current_token());
    stream4->get_next_token();
    EXPECT_EQ("(", stream4->get_current_token());
    stream4->get_next_token();
    EXPECT_EQ("-35", stream4->get_current_token());
    stream4->get_next_token();
    EXPECT_EQ("-", stream4->get_current_token());
    stream4->get_next_token();
    EXPECT_EQ("(", stream4->get_current_token());
    stream4->get_next_token();
    EXPECT_EQ("1", stream4->get_current_token());
    stream4->get_next_token();
    EXPECT_EQ("-", stream4->get_current_token());
    stream4->get_next_token();
    EXPECT_EQ("-5517", stream4->get_current_token());
    stream4->get_next_token();
    EXPECT_EQ(")", stream4->get_current_token());
    stream4->get_next_token();
    EXPECT_EQ("-", stream4->get_current_token());
    stream4->get_next_token();
    EXPECT_EQ("98342", stream4->get_current_token());
    stream4->get_next_token();
    EXPECT_EQ(")", stream4->get_current_token());
    stream4->get_next_token();
    EXPECT_EQ("-", stream4->get_current_token());
    stream4->get_next_token();
    EXPECT_EQ("-98", stream4->get_current_token());
    stream4->get_next_token();
}

TEST_F(Lab01Fixture, CheckNextType) {
    EXPECT_TRUE(stream1->next_token_is_int());
    EXPECT_FALSE(stream1->next_token_is_op());
    EXPECT_FALSE(stream1->next_token_is_paren_close());
    EXPECT_FALSE(stream1->next_token_is_paren_open());
    EXPECT_TRUE(stream1->next_token_is_int());
    stream1->get_next_token();

    EXPECT_TRUE(stream1->next_token_is_op());
    EXPECT_FALSE(stream1->next_token_is_int());
    EXPECT_FALSE(stream1->next_token_is_paren_close());
    EXPECT_FALSE(stream1->next_token_is_paren_open());
    EXPECT_TRUE(stream1->next_token_is_op());
    stream1->get_next_token();

    EXPECT_TRUE(stream1->next_token_is_int());
    EXPECT_FALSE(stream1->next_token_is_op());
    EXPECT_FALSE(stream1->next_token_is_paren_close());
    EXPECT_FALSE(stream1->next_token_is_paren_open());
    EXPECT_TRUE(stream1->next_token_is_int());
    stream1->get_next_token();

    EXPECT_TRUE(stream1->next_token_is_op());
    EXPECT_FALSE(stream1->next_token_is_int());
    EXPECT_FALSE(stream1->next_token_is_paren_close());
    EXPECT_FALSE(stream1->next_token_is_paren_open());
    EXPECT_TRUE(stream1->next_token_is_op());
    stream1->get_next_token();

    EXPECT_TRUE(stream1->next_token_is_int());
    EXPECT_FALSE(stream1->next_token_is_op());
    EXPECT_FALSE(stream1->next_token_is_paren_close());
    EXPECT_FALSE(stream1->next_token_is_paren_open());
    EXPECT_TRUE(stream1->next_token_is_int());
    stream1->get_next_token();

    EXPECT_FALSE(stream1->next_token_is_int());
    EXPECT_FALSE(stream1->next_token_is_op());
    EXPECT_FALSE(stream1->next_token_is_paren_close());
    EXPECT_FALSE(stream1->next_token_is_paren_open());
    EXPECT_FALSE(stream1->next_token_is_int());

    EXPECT_TRUE(stream2->next_token_is_int());
    stream2->get_next_token();
    EXPECT_TRUE(stream2->next_token_is_op());
    stream2->get_next_token();
    EXPECT_TRUE(stream2->next_token_is_int());
    stream2->get_next_token();
    EXPECT_TRUE(stream2->next_token_is_op());
    stream2->get_next_token();
    EXPECT_TRUE(stream2->next_token_is_int());
    stream2->get_next_token();
    EXPECT_TRUE(stream2->next_token_is_op());
    stream2->get_next_token();

    EXPECT_FALSE(stream2->next_token_is_int());
    EXPECT_FALSE(stream2->next_token_is_op());
    EXPECT_FALSE(stream2->next_token_is_paren_close());
    EXPECT_TRUE(stream2->next_token_is_paren_open());
    EXPECT_FALSE(stream2->next_token_is_int());
    stream2->get_next_token();

    EXPECT_TRUE(stream2->next_token_is_int());
    stream2->get_next_token();
    EXPECT_TRUE(stream2->next_token_is_op());
    stream2->get_next_token();
    EXPECT_TRUE(stream2->next_token_is_int());
    stream2->get_next_token();

    EXPECT_FALSE(stream2->next_token_is_int());
    EXPECT_FALSE(stream2->next_token_is_op());
    EXPECT_TRUE(stream2->next_token_is_paren_close());
    EXPECT_FALSE(stream2->next_token_is_paren_open());
    EXPECT_FALSE(stream2->next_token_is_int());
    stream2->get_next_token();

    EXPECT_TRUE(stream4->next_token_is_int());
    EXPECT_FALSE(stream4->next_token_is_op());
    stream4->get_next_token();
    EXPECT_TRUE(stream4->next_token_is_op());
    stream4->get_next_token();
    EXPECT_TRUE(stream4->next_token_is_paren_open());
    EXPECT_FALSE(stream4->next_token_is_op());
    stream4->get_next_token();
    EXPECT_TRUE(stream4->next_token_is_int());
    EXPECT_FALSE(stream4->next_token_is_op());
    stream4->get_next_token();
    EXPECT_TRUE(stream4->next_token_is_op());
    stream4->get_next_token();
    EXPECT_TRUE(stream4->next_token_is_paren_open());
    EXPECT_FALSE(stream4->next_token_is_op());
    stream4->get_next_token();
    EXPECT_TRUE(stream4->next_token_is_int());
    EXPECT_FALSE(stream4->next_token_is_op());
    stream4->get_next_token();
    EXPECT_TRUE(stream4->next_token_is_op());
    EXPECT_FALSE(stream4->next_token_is_int());
    stream4->get_next_token();
    EXPECT_TRUE(stream4->next_token_is_int());
    EXPECT_FALSE(stream4->next_token_is_op());
    stream4->get_next_token();
    EXPECT_TRUE(stream4->next_token_is_paren_close());
    EXPECT_FALSE(stream4->next_token_is_paren_open());
    EXPECT_FALSE(stream4->next_token_is_op());
    stream4->get_next_token();
    EXPECT_TRUE(stream4->next_token_is_op());
    EXPECT_FALSE(stream4->next_token_is_int());
    stream4->get_next_token();
    EXPECT_TRUE(stream4->next_token_is_int());
    EXPECT_FALSE(stream4->next_token_is_op());
    stream4->get_next_token();
    EXPECT_TRUE(stream4->next_token_is_paren_close());
    EXPECT_FALSE(stream4->next_token_is_paren_open());
    EXPECT_FALSE(stream4->next_token_is_op());
    stream4->get_next_token();
    EXPECT_TRUE(stream4->next_token_is_op());
    EXPECT_FALSE(stream4->next_token_is_int());
    stream4->get_next_token();
    EXPECT_TRUE(stream4->next_token_is_int());
    EXPECT_FALSE(stream4->next_token_is_op());
    stream4->get_next_token();
}