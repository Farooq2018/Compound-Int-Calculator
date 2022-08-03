// OverloadingInsertionOp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <queue>
using namespace std;

class VoteCounter
{
private:
    int ACount, BCount, CCount;
public:
    VoteCounter() { ACount = BCount = CCount = 0; }
    VoteCounter& operator<<(const string& candidateName);
    string GetResults();
};

VoteCounter& VoteCounter::operator<<(const string& candidateName) {
    if ("Candidate A" == candidateName)
        ACount++;
    else if ("Candidate B" == candidateName)
        BCount++;
    else if ("Candidate C" == candidateName)
        CCount++;

    return *this;
}

string VoteCounter::GetResults() {
    if (ACount > BCount) {
        if (ACount > CCount)
            return "Candidate A wins!";
        else if (ACount < CCount)
            return "Candidate C wins!";
        else
            return "Tie between candidates A & C!";
    }
    else if (ACount < BCount) {
        if (BCount > CCount)
            return "Candidate B wins!";
        else if (BCount < CCount)
            return "Candidate C wins!";
        else
            return "Tie between candidates B & C!";
    }
    else {
        if (BCount == CCount)
            return "Tie between all 3 candidates!";
        else
            return "Tie between candidates A & B!";
    }
}

int main() {
    const string candidateNames[] = {
       "Candidate A", "Candidate B", "Candidate C"
    };
    const int voteIndices[] = {
       2, 1, 0, 1, 2, 0, 0, 1, 2, 1, 0, 1, 0, 0, 1, 2, 0, 0, 1
    };
    const int voteCount = sizeof(voteIndices) / sizeof(int);

    // Cast the votes
    cout << "Counting votes..." << endl;
    VoteCounter counter;
    for (int i = 0; i < voteCount; i++) {
        int voteIndex = voteIndices[i];
        counter << candidateNames[voteIndex];
    }

    // Reveal the winner
    cout << counter.GetResults() << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
