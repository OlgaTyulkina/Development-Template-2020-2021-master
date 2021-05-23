#include <../gtest/gtest.h>
#include <Text.h>

TEST(text, create_text)
{
	ASSERT_NO_THROW(Text T);
}

TEST(text, add_node)
{
	Text T;
	T.SetCurr("node");
	EXPECT_EQ("node", T.GetCurr());
}

TEST(text, delete_node)
{
	Text T;
	T.SetCurr("node");
	T.deleteCurr();
	ASSERT_NO_THROW(T.SetCurr("node"));
}

TEST(text, add_next)
{
	Text T;
	T.SetCurr("add");
	T.addNext(" ");
	T.next();
	T.addNext("next");
	T.GoHead();
	EXPECT_EQ("add", T.GetCurr());
	T.next();
	EXPECT_EQ(" ", T.GetCurr());
	T.next();
	EXPECT_EQ("next", T.GetCurr());
}

TEST(text, add_down)
{
	Text T;
	T.SetCurr("add");
	T.addDown("down");
	T.GoHead();
	EXPECT_EQ("add", T.GetCurr());
	T.down();
	EXPECT_EQ("down", T.GetCurr());
}

TEST(text, add_next_and_down)
{
	Text T;
	T.SetCurr("Title 1");
	T.addNext("Title 2");
	T.addDown("Title 1.1");
	T.GoHead();
	EXPECT_EQ("Title 1", T.GetCurr());
	T.down();
	EXPECT_EQ("Title 1.1", T.GetCurr());
	T.top();
	T.next();
	EXPECT_EQ("Title 2", T.GetCurr());
}

TEST(text, delete_down)
{
	Text T;
	T.SetCurr("Title 1");
	T.addNext("Title 2");
	T.addDown("Title 1.1");
	T.down();
	T.addNext("Title 1.2");
	T.top();
	T.deleteDown();
	T.GoHead();
	EXPECT_EQ("Title 1", T.GetCurr());
	T.next();
	EXPECT_EQ("Title 2", T.GetCurr());
}

TEST(text, delete_current)
{
	Text T;
	T.SetCurr("Title 1");
	T.addNext("Title 2");
	T.addDown("Title 1.1");
	T.down();
	T.addNext("Title 1.2");
	T.top();
	T.deleteCurr();
	T.GoHead();
	EXPECT_EQ("Title 2", T.GetCurr());
}

