#include "knowledge_base.hh"


knowledge_base::words knowledge_base::split(const std::string &str, const char &deliminator)
{
    knowledge_base::words elems;
    std::stringstream ss(str);
    std::string split_s;
    while (getline(ss, split_s, deliminator))
    {
        if (!split_s.empty())
        {
            elems.push_back(split_s);
        }
    }
    return elems;
}

void knowledge_base::KnowledgeBaseNER::load()
{
    std::ifstream ifs(this->infile);
    std::string str;
    if (ifs.fail())
    {
        std::cerr << "Failed to open " << this->infile << std::endl;
    }
    while (getline(ifs, str))
    {
        auto splited = split(str, this->deliminator);

        if (this->entities.find(splited[0]) == this->entities.end())
        {
            this->entities.insert(splited[0]);
        }
        if (this->classes.find(splited[1]) == this->classes.end())
        {
            this->classes.insert(splited[1]);
        }
        this->knowledges.insert(std::make_pair(splited[0], splited[1]));
    }
}

void knowledge_base::KnowledgeBaseRE::load()
{
    std::ifstream ifs(this->infile);
    std::string str;
    if (ifs.fail())
    {
        std::cerr << "Failed to open " << this->infile << std::endl;
    }
    while (getline(ifs, str))
    {
        auto splited = split(str, this->deliminator);

        if (this->entities.find(splited[0]) == this->entities.end())
        {
            this->entities.insert(splited[0]);
        }
        if (this->entities.find(splited[1]) == this->entities.end())
        {
            this->entities.insert(splited[1]);
        }
        if (this->classes.find(splited[2]) == this->classes.end())
        {
            this->classes.insert(splited[2]);
        }
        this->knowledges.insert(std::make_tuple(splited[0], splited[1], splited[2]));
    }
}
