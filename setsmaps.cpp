#include <iostream>
#include <set>
#include <map>

using namespace std;

class GitCommit
{
public:
    GitCommit(set<string> files_n) : files{files_n} {}
    friend ostream &operator<<(ostream &os, const GitCommit &gc)
    {
        os << "|";
        for (auto &f : gc.files)
        {
            os << f << ":";
        }
        os << "|";
        return os;
    }

private:
    set<string> files;
};

class AssignmentSubmission
{
private:
    string student_name;
    string assignment_name;
    int version;

public:
    AssignmentSubmission(){};

    AssignmentSubmission(string sname, string asname, int version) : student_name{sname}, assignment_name{asname}, version{version} {}

    friend ostream &operator<<(ostream &os, const AssignmentSubmission &as)
    {
        os << as.student_name << ":" << as.assignment_name << ":" << as.version << endl;
        return os;
    }
    bool operator<(const AssignmentSubmission &rhs) const
    {
        // cout << student_name << " compared with " << rhs.student_name << endl;
        if (student_name.compare(rhs.student_name))
            return true;
        return false;
    }
};

class AssignmentSet
{
private:
    set<AssignmentSubmission> aset;

public:
    void insert(AssignmentSubmission as)
    {
        auto res = aset.find(as);
        if (res != aset.end())
        {
            aset.erase(res);
        }
        aset.insert(as);
    }
    friend ostream &operator<<(ostream &os, const AssignmentSet &aset)
    {
        for (auto &a : aset.aset)
        {
            os << a;
        }
        return os;
    }
};

int main(int argc, char const *argv[])
{
    AssignmentSet aset;
    aset.insert(AssignmentSubmission{"subu", "assign1", 1});
    aset.insert(AssignmentSubmission{"ananth", "assign1", 1});
    aset.insert(AssignmentSubmission{"subu", "assign1", 2});
    // cout << aset;

    map<string, AssignmentSubmission> amap;
    // amap["subu"] = AssignmentSubmission{"subu", "assign1", 1};
    // amap.insert(pair<string, AssignmentSubmission>("subu", AssignmentSubmission{"subu", "assign1", 1}));
    // amap.insert(pair<string, AssignmentSubmission>("ananth", AssignmentSubmission{"ananth", "assign1", 1}));

    amap.emplace("subu", AssignmentSubmission{"subu", "assign1", 1});
    amap.emplace("ananth", AssignmentSubmission{"subu", "assign1", 1});
    amap["test"] = AssignmentSubmission("test", "test1", 2);

    for (auto e = amap.begin(); e != amap.end(); e++)
    {
        cout << e->first << "==>" << e->second << endl;
    }

    // map<int, string> tmap;
    // tmap[1] = "subu";
    // tmap[2] = "ananth";
    // cout << tmap[2];
    cout << amap["test"];
    cout << amap["best"];

    string text = "test test this this";
    // build tokenizer later
}
