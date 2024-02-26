#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <functional>

using namespace std;

class AssignmentSubmission
{
private:
    string name;
    string assignmentName;
    int version;

public:
    AssignmentSubmission() {}
    string getName() const
    {
        return name;
    }
    string getAssignmentName() const
    {
        return assignmentName;
    }
    AssignmentSubmission(string n, string a, int v) : name{n}, assignmentName{a}, version{v} {}

    friend ostream &operator<<(ostream &os, const AssignmentSubmission &as)
    {
        os << "Name: " << as.name << " Aname: " << as.assignmentName << " version: " << as.version << endl;
        return os;
    }
    bool operator<(const AssignmentSubmission &rhs) const
    {
        if (name.compare(rhs.name) > 0)
        {
            return true;
        }
        return false;
    }
    bool operator==(const AssignmentSubmission &rhs) const
    {
        return name == rhs.name && assignmentName == rhs.assignmentName;
    }
};

class AssignmentSubmissionHash
{
public:
    size_t operator()(const AssignmentSubmission &s) const
    {
        std::size_t h1 = std::hash<std::string>{}(s.getName());
        std::size_t h2 = std::hash<std::string>{}(s.getAssignmentName());
        return h1 ^ (h2 << 1); // or use boost::hash_combine
    }
};

void populateSet(unordered_set<string> &stopWords)
{
    ifstream myfile("stopwords.txt");
    string mystring;
    while (myfile)
    {
        myfile >> mystring;
        // cout << mystring << endl;
        stopWords.insert(mystring);
    }
}

void populateMap(unordered_map<string, int> &umap, unordered_set<string> &stopwords)
{
    ifstream myfile("target.txt");
    string mystring;
    while (myfile)
    {
        myfile >> mystring;
        auto it = stopwords.find(mystring);
        if (it == stopwords.end())
        {
            auto kv = umap.find(mystring);
            if (kv != umap.end())
            {
                kv->second = kv->second + 1;
            }
            else
            {
                umap.insert(pair<string, int>(mystring, 1));
            }
        }
        // umap[mystring] = umap[mystring] + 1;
        // cout << mystring << " " << umap[mystring] << endl;
    }
}

void printMap(unordered_map<string, int> &umap)
{
    for (const auto &elem : umap)
    {
        cout << elem.first << " ==>" << elem.second << endl;
    }
}

void printMap(unordered_map<AssignmentSubmission, int, AssignmentSubmissionHash> &umap)
{
    for (const auto &elem : umap)
    {
        cout << elem.first << " ==>" << elem.second << endl;
    }
}

void printSet(const unordered_set<string> &set)
{
    for (const auto &elem : set)
    {
        cout << elem << endl;
    }
}

int main(int argc, char const *argv[])
{
    unordered_set<string> stopWords;
    populateSet(stopWords);
    printSet(stopWords);
    unordered_map<string, int> umap;
    populateMap(umap, stopWords);
    // cout << umap["ZZZZZ"] << endl;
    printMap(umap);
    // Assignment submission
    unordered_map<AssignmentSubmission, int, AssignmentSubmissionHash> amap;
    amap.insert(pair<AssignmentSubmission, int>(AssignmentSubmission{"subu", "asn1", 1}, 20));
    amap.emplace(AssignmentSubmission{"ananth", "asn1", 2}, 40);
    printMap(amap);
    return 0;
}
