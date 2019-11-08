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

TEST_F(TestKnowledgeBase, Initializing) {
  std::set<std::pair<std::string, std::string>> st;
  EXPECT_GT(klbn->knowledges.size(), 0);
  EXPECT_GT(klbn->entities.size(), 0);
  EXPECT_GT(klbr->knowledges.size(), 0);
  EXPECT_GT(klbr->entities.size(), 0);
}
