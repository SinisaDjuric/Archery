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
	tot_score = 0;
}

TEST_TEAR_DOWN(ScoreTest)
{
}

TEST(ScoreTest, IsFive)
{
	TEST_ASSERT_TRUE (print_score(224, 134) == FIVE);
}

TEST(ScoreTest, IsFour)
{
	TEST_ASSERT_TRUE (print_score(205, 115) == FOUR);
}

TEST(ScoreTest, IsThree)
{
	TEST_ASSERT_TRUE (print_score(183, 93) == THREE);
}

TEST(ScoreTest, IsTwo)
{
	TEST_ASSERT_TRUE (print_score(174, 84) == TWO);
}

TEST(ScoreTest, IsOne)
{
	TEST_ASSERT_TRUE (print_score(163, 73) == ONE);
}

TEST(ScoreTest, IsZero)
{
	TEST_ASSERT_TRUE (print_score(120, 30) == ZERO);
}

TEST(ScoreTest, Is14)
{
	int tot = 0;
	tot = total_score(print_score(224, 134));
	tot = total_score(print_score(205, 115));
	tot = total_score(print_score(224, 134));
	TEST_ASSERT_EQUAL_INT (14, tot);
}

TEST(ScoreTest, Is29)
{
	
	int tot = 0;
	tot = total_score(print_score(224, 134));
	tot = total_score(print_score(205, 115));
	tot = total_score(print_score(183, 93));
	tot = total_score(print_score(174, 84));
	tot = total_score(print_score(163, 73));
	tot = total_score(print_score(120, 30));
	tot = total_score(print_score(205, 115));
	tot = total_score(print_score(224, 134));
	tot = total_score(print_score(183, 93));
	tot = total_score(print_score(174, 84));

	TEST_ASSERT_EQUAL_INT (29, tot);
}


