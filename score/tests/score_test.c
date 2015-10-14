#include "../../unity/unity_fixture.h"
#include "../src/score.h"



TEST_GROUP(ScoreTest);

TEST_GROUP_RUNNER(ScoreTest)
{
	RUN_TEST_CASE (ScoreTest, IsFive);
	RUN_TEST_CASE (ScoreTest, IsFour);
	RUN_TEST_CASE (ScoreTest, IsThree);
	RUN_TEST_CASE (ScoreTest, IsTwo);
	RUN_TEST_CASE (ScoreTest, IsOne);
	RUN_TEST_CASE (ScoreTest, IsZero);
	RUN_TEST_CASE (ScoreTest, Is14);
	RUN_TEST_CASE (ScoreTest, Is29);
}

TEST_SETUP(ScoreTest)
{	 
	
}

TEST_TEAR_DOWN(ScoreTest)
{
}

TEST(ScoreTest, IsFive)
{
	TEST_ASSERT_TRUE (printScore(224, 134) == FIVE);
}

TEST(ScoreTest, IsFour)
{
	TEST_ASSERT_TRUE (printScore(205, 115) == FOUR);
}

TEST(ScoreTest, IsThree)
{
	TEST_ASSERT_TRUE (printScore(183, 93) == THREE);
}

TEST(ScoreTest, IsTwo)
{
	TEST_ASSERT_TRUE (printScore(174, 84) == TWO);
}

TEST(ScoreTest, IsOne)
{
	TEST_ASSERT_TRUE (printScore(163, 73) == ONE);
}

TEST(ScoreTest, IsZero)
{
	TEST_ASSERT_TRUE (printScore(120, 30) == ZERO);
}

TEST(ScoreTest, Is14)
{
	static int t = 0;
	t = totalScore(printScore(224, 134),t);
	t = totalScore(printScore(205, 115),t);
	t = totalScore(printScore(224, 134),t);
	TEST_ASSERT_EQUAL_INT (14, t);
}

TEST(ScoreTest, Is29)
{
	
	static int t = 0;
	t = totalScore(printScore(224, 134),t);
	t = totalScore(printScore(205, 115),t);
	t = totalScore(printScore(183, 93),t);
	t = totalScore(printScore(174, 84),t);
	t = totalScore(printScore(163, 73),t);
	t = totalScore(printScore(120, 30),t);
	t = totalScore(printScore(205, 115),t);
	t = totalScore(printScore(224, 134),t);
	t = totalScore(printScore(183, 93),t);
	t = totalScore(printScore(174, 84),t);

	TEST_ASSERT_EQUAL_INT (29, t);
}


