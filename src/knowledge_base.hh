#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <tuple>
#include <set>

namespace knowledge_base
{

typedef std::vector<std::string> words;
typedef std::pair<std::string, std::string> nepair;
typedef std::tuple<std::string, std::string, std::string> retuple;

words split(const std::string &str, const char &deliminator);

class KnowledgeBaseNER
{
public:
    void load();
    KnowledgeBaseNER(const std::string &inf, const std::string &outf, const char delim)
    {
        this->infile = inf;
        this->outfile = outf;
        this->deliminator = delim;
    }

    // vector<(named entity, entity_class)>
    std::set<nepair> knowledges;
    std::set<std::string> entities;

protected:
    std::string infile;
    std::string outfile;
    char deliminator;
    std::set<std::string> classes;
};

class KnowledgeBaseRE
{
public:
    void load();
    KnowledgeBaseRE(const std::string &inf, const std::string &outf, const char delim)
    {
        this->infile = inf;
        this->outfile = outf;
        this->deliminator = delim;
    }

    // vector<(entity1, entity2, relation_name)>
    std::set<retuple> knowledges;
    std::set<std::string> entities;

protected:
    std::string infile;
    std::string outfile;
    char deliminator;
    std::set<std::string> classes;
};

} // namespace knowledge_base
