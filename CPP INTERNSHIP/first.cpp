#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Voter {
public:
    string name;
    string email;
    string password;
    bool hasVoted;
    map<string, string> votes; // candidate name -> position
};

class Candidate {
public:
    string name;
    string position;
    int voteCount;
};

int main() {
    int numVoters, numCandidates;
    vector<Voter> voters;
    vector<Candidate> candidates;

    // get the number of voters and candidates
    cout << "Enter the number of voters: ";
    cin >> numVoters;
    cout << "Enter the number of candidates: ";
    cin >> numCandidates;

    // create the list of candidates
    for (int i = 0; i < numCandidates; i++) {
        string name, position;
        cout << "Enter the name of candidate #" << i+1 << ": ";
        cin >> name;
        cout << "Enter the position of candidate #" << i+1 << ": ";
        cin >> position;
        candidates.push_back({name, position, 0});
    }

    // create the list of voters
    for (int i = 0; i < numVoters; i++) {
        string name, email, password;
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your email: ";
        cin >> email;
        cout << "Enter your password: ";
        cin >> password;
        voters.push_back({name, email, password, false, {}});
    }

    // allow each voter to cast their vote
    for (int i = 0; i < numVoters; i++) {
        Voter& voter = voters[i];
        if (voter.hasVoted) {
            cout << "Sorry, you have already voted." << endl;
            continue;
        }
        cout << "Hello " << voter.name << ". Please enter your vote." << endl;
        for (int j = 0; j < numCandidates; j++) {
            Candidate& candidate = candidates[j];
            cout << j+1 << ". " << candidate.name << " for " << candidate.position << endl;
        }
        int voteIndex;
        cout << "Enter the number of your chosen candidate: ";
        cin >> voteIndex;
        if (voteIndex < 1 || voteIndex > numCandidates) {
            cout << "Invalid candidate selection. Please try again." << endl;
            continue;
        }
        Candidate& chosenCandidate = candidates[voteIndex-1];
        voter.votes[chosenCandidate.name] = chosenCandidate.position;
        chosenCandidate.voteCount++;
        voter.hasVoted = true;
        cout << "Thank you for voting!" << endl;
    }

    // display the election results
    cout << "Election results:" << endl;
    for (int i = 0; i < numCandidates; i++) {
        Candidate& candidate = candidates[i];
        cout << candidate.name << " for " << candidate.position << ": " << candidate.voteCount << " votes" << endl;
    }

    return 0;
}