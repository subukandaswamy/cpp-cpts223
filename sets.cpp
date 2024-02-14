#include <iostream>
#include <set>
#include <map>

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
};
class AssignmentNameCompare
{
public:
    bool operator()(const AssignmentSubmission &lhs, const AssignmentSubmission &rhs) const
    {
        if (lhs.getName().compare(rhs.getName()) < 0)
        {
            return true;
        }
        return false;
    }
};



auto AssignmentCompareLambda = [](const AssignmentSubmission &lhs, const AssignmentSubmission &rhs) -> bool
{
    return lhs.getName().compare(rhs.getName()) < 0;
};

class AssignmentSet
{
private:
    set<AssignmentSubmission, decltype(AssignmentCompareLambda)> aset{AssignmentCompareLambda};

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
    friend ostream &operator<<(ostream &os, const AssignmentSet &assignSet)
    {
        for (auto &x : assignSet.aset)
        {
            os << x;
        }
        return os;
    }
};

int main(int argc, char const *argv[])
{
    // AssignmentSet aset;
    // aset.insert(AssignmentSubmission{"subu", "assn1", 1});
    // aset.insert(AssignmentSubmission{"ananth", "assn1", 1});
    // aset.insert(AssignmentSubmission{"subu", "assn1", 2});

    // cout << aset;

    map<string, AssignmentSubmission> amap;
    amap["subu"] = AssignmentSubmission{"subu", "assn1", 1};
    amap.insert(pair<string, AssignmentSubmission>("ananth", AssignmentSubmission{"ananth", "assn1", 1}));
    amap.emplace("michael", AssignmentSubmission{"michael", "PA2", 2});

    for (auto &x : amap)
    {
        cout << x.first << "==>" << x.second;
    }

    return 0;
}
