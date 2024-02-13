#include <iostream>
#include <set>

using namespace std;

class AssignmentSubmission
{
private:
    string name;
    string assignmentName;
    int version;

public:
    AssignmentSubmission() {}
    AssignmentSubmission(string n, string a, int v) : name{n}, assignmentName{a}, version{v} {}

    friend ostream &operator<<(ostream &os, const AssignmentSubmission &as)
    {
        os << "Name: " << as.name << " Aname: " << as.assignmentName << " version: " << as.version << endl;
        return os;
    }
    bool operator<(const AssignmentSubmission &rhs) const
    {
        if (name.compare(rhs.name) < 0)
        {
            return true;
        }
        return false;
    }
};

class AssignmentSet
{
};

int main(int argc, char const *argv[])
{
    set<AssignmentSubmission> aset;
    aset.insert(AssignmentSubmission{"subu", "assn1", 1});
    aset.insert(AssignmentSubmission{"ananth", "assn1", 1});
    aset.insert(AssignmentSubmission{"subu", "assn1", 2});

    for (auto &x : aset)
    {
        cout << x;
    }
    return 0;
}
