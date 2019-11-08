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
    const std::string inf = "text_i.txt";
    const std::string outf = "text_i.txt";
    klbn = new knowledge_base::KnowledgeBaseNER(inf, outf, '\t');
    klbr = new knowledge_base::KnowledgeBaseRE(inf, outf, '\t');
    klbn->load();
    klbr->load();
  }

  knowledge_base::KnowledgeBaseNER *klbn;
  knowledge_base::KnowledgeBaseRE *klbr;
};

TEST_F(TestKnowledgeBase, Initializing) {
  std::set<std::pair<std::string, std::string>> st;
  EXPECT_GT(klbn->knowledges.size(), 0);
  EXPECT_GT(klbn->entities.size(), 0);
  EXPECT_GT(klbr->knowledges.size(), 0);
  EXPECT_GT(klbr->entities.size(), 0);
}
