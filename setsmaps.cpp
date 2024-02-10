#include <iostream>
#include <set>

using namespace std;

class AssignmentSubmission
{
private:
    string student_name;
    string assignment_name;
    int version;

public:
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
    cout << aset;
}
