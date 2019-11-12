// Copyright 2019 Ryuya Ikeda
#include <gtest/gtest.h>
#include <string>
#include "../src/knowledge_base.hh"

class TestKnowledgeBase : public ::testing::Test {
 protected:
  TestKnowledgeBase() {
    std::cout << "initialize TestKnowledgeBase" << std::endl;
  }

  ~TestKnowledgeBase() {
    std::cout << "deconstruct TestKnowledgeBase" << std::endl;
  }

  virtual void SetUp() {
    const std::string infn = "../../test/test_i_NER.txt";
    const std::string infr = "../../test/test_i_RE.txt";
    const std::string outf = "../../test/text_o.txt";
    klbn = new knowledge_base::KnowledgeBaseNER(infn, outf, ' ');
    klbr = new knowledge_base::KnowledgeBaseRE(infr, outf, ' ');
    klbn->load();
    klbr->load();
  }

  knowledge_base::KnowledgeBaseNER *klbn;
  knowledge_base::KnowledgeBaseRE *klbr;
};

TEST_F(TestKnowledgeBase, InitializingTest) {
  EXPECT_GT(klbn->knowledges.size(), 0);
  EXPECT_GT(klbn->entities.size(), 0);
  EXPECT_GT(klbr->knowledges.size(), 0);
  EXPECT_GT(klbr->entities.size(), 0);
}

TEST_F(TestKnowledgeBase, LoadingTest) {
  // test of existing entities
  EXPECT_TRUE(klbn->entities.find("Obama") != klbn->entities.end());
  EXPECT_TRUE(klbn->entities.find("Trump") != klbn->entities.end());
  EXPECT_TRUE(klbn->entities.find("Bush") == klbn->entities.end());
  EXPECT_TRUE(klbr->entities.find("Obama") != klbr->entities.end());
  EXPECT_TRUE(klbr->entities.find("Hawaii") != klbr->entities.end());
  EXPECT_TRUE(klbr->entities.find("Bush") == klbr->entities.end());

  // test of existing knowledges
  knowledge_base::nepair np1 = std::make_pair("Obama", "PER");
  knowledge_base::nepair np2 = std::make_pair("Hawaii", "LOC");
  knowledge_base::nepair np3 = std::make_pair("Bush", "PER");
  EXPECT_TRUE(klbn->knowledges.find(np1) != klbn->knowledges.end());
  EXPECT_TRUE(klbn->knowledges.find(np2) != klbn->knowledges.end());
  EXPECT_TRUE(klbn->knowledges.find(np3) == klbn->knowledges.end());
  knowledge_base::retuple rt1 = std::make_tuple("Obama", "Hawaii", "LiveIn");
  knowledge_base::retuple rt2 = std::make_tuple("Trump", "NewYork", "BornIn");
  knowledge_base::retuple rt3 =
      std::make_tuple("Bush", "Connecticut", "BornIn");
  EXPECT_TRUE(klbr->knowledges.find(rt1) != klbr->knowledges.end());
  EXPECT_TRUE(klbr->knowledges.find(rt2) != klbr->knowledges.end());
  EXPECT_TRUE(klbr->knowledges.find(rt3) == klbr->knowledges.end());
}
