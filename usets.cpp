#include <iostream>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

void populateSet(unordered_set<string> &stopWords)
{
    fstream myfile("stopwords.txt");
    while (myfile)
    {
        string mystring;
        myfile >> mystring;
        // cout << mystring << endl;
        stopWords.insert(mystring);
    }
}

void populateMap(unordered_map<string, int> &umap, unordered_set<string> &stopWords)
{
    fstream myfile("target.txt");
    while (myfile)
    {
        string mystring;
        myfile >> mystring;
        auto it = stopWords.find(mystring);
        if (it == stopWords.end())
        {
            // auto itm = umap.find(mystring);
            // if (itm != umap.end())
            // {
            //     itm->second = itm->second + 1;
            // }
            // else
            // {
            //     umap.insert(pair<string, int>(mystring, 1));
            // }
            umap[mystring] = umap[mystring] + 1;
        }
    }
}

void printSet(unordered_set<string> &set)
{
    for (const auto &elem : set)
    {
        cout << elem << endl;
    }
}

void printMap(unordered_map<string, int> &umap)
{
    for (const auto &elem : umap)
    {
        cout << elem.first << " ==> " << elem.second << endl;
    }
}

int main(int argc, char const *argv[])
{
    unordered_set<string> stopWords;
    populateSet(stopWords);
    printSet(stopWords);
    unordered_map<string, int> umap;
    populateMap(umap, stopWords);
    cout << umap["cougars"] << endl;
    printMap(umap);
    return 0;
}
