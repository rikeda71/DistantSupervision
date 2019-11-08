#include <gtest/gtest.h>
#include <string>
#include "../src/knowledge_base.hh"

using namespace knowledge_base;

class TestKnowledgeBase : public ::testing::Test
{
protected:
    TestKnowledgeBase()
    {
        std::cout << "initialize TestKnowledgeBase" << std::endl;
    }

    ~TestKnowledgeBase()
    {
        std::cout << "deconstruct TestKnowledgeBase" << std::endl;
    }

    virtual void SetUp()
    {
        const std::string inf = "text_i.txt";
        const std::string outf = "text_i.txt";
        klbn = new KnowledgeBaseNER(inf, outf, '\t');
        klbr = new KnowledgeBaseRE(inf, outf, '\t');
        klbn->load();
        klbr->load();
    }
    // virtual void SetUp() {}

    // virtual void SetUp() virtual void TearDown() {}

    KnowledgeBaseNER *klbn;
    KnowledgeBaseRE *klbr;
};

TEST_F(TestKnowledgeBase, Initializing)
{
    std::set<std::pair<std::string, std::string>> st;
    EXPECT_TRUE(klbn->knowledges.size() > 0);
    EXPECT_TRUE(klbn->entities.size() > 0);
    EXPECT_TRUE(klbr->knowledges.size() > 0);
    EXPECT_TRUE(klbr->entities.size() > 0);
}
