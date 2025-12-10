#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function prototypes
void displayBanner();
void addHeroicDeed(vector<string>& deeds, vector<string>& branches);
void displayDeeds(const vector<string>& deeds, const vector<string>& branches);
void displayStatistics(const vector<string>& deeds, const vector<string>& branches);
void createPatrioticPattern();
void searchByBranch(const vector<string>& deeds, const vector<string>& branches);

int main() {
    vector<string> heroicDeeds;
    vector<string> serviceBranches;
    int choice;

    // Display program banner
    displayBanner();

    do {
        // Main menu
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Add a veteran's heroic deed\n";
        cout << "2. Display all heroic deeds\n";
        cout << "3. Show tribute statistics\n";
        cout << "4. Create patriotic pattern\n";
        cout << "5. Search deeds by branch\n";
        cout << "6. Exit\n";
        cout << "Choose an option (1-6): ";
        cin >> choice;
        cin.ignore();  // clear newline after reading the number

        switch(choice) {
            case 1:
                addHeroicDeed(heroicDeeds, serviceBranches);
                break;
            case 2:
                displayDeeds(heroicDeeds, serviceBranches);
                break;
            case 3:
                displayStatistics(heroicDeeds, serviceBranches);
                break;
            case 4:
                createPatrioticPattern();
                break;
            case 5:
                searchByBranch(heroicDeeds, serviceBranches);
                break;
            case 6:
                cout << "Thank you for honoring our veterans!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while(choice != 6);

    return 0;
}

// Display the program banner
void displayBanner() {
    cout << "========================================\n";
    cout << "      VETERANS DAY TRIBUTE PROGRAM      \n";
    cout << "========================================\n";
    cout << "   Honoring Those Who Served Our Nation\n";
    cout << "========================================\n\n";
}

// Add a new heroic deed and its branch
void addHeroicDeed(vector<string>& deeds, vector<string>& branches) {
    string branch;
    string deed;

    cout << "\n--- Add a Veteran's Heroic Deed ---\n";
    cout << "Enter the veteran's branch (e.g., Army, Navy, Air Force, Marines): ";
    getline(cin, branch);

    cout << "Describe the heroic deed: ";
    getline(cin, deed);

    // Store data in vectors
    if (branch.empty() || deed.empty()) {
        cout << "Branch and deed cannot be empty. Deed not added.\n";
        return;
    }

    branches.push_back(branch);
    deeds.push_back(deed);

    cout << "Heroic deed added successfully!\n";
}

// Display all heroic deeds with their branches
void displayDeeds(const vector<string>& deeds, const vector<string>& branches) {
    cout << "\n--- All Recorded Heroic Deeds ---\n";

    // Check if vectors are empty
    if (deeds.empty()) {
        cout << "No heroic deeds have been recorded yet.\n";
        return;
    }

    // Loop through vectors and print deeds with branch
    for (size_t i = 0; i < deeds.size(); ++i) {
        cout << i + 1 << ". [" << branches[i] << "] " << deeds[i] << "\n";
    }
}

// Show statistics about the deeds and branches
void displayStatistics(const vector<string>& deeds, const vector<string>& branches) {
    cout << "\n--- Tribute Statistics ---\n";

    if (deeds.empty()) {
        cout << "No data available. Please add heroic deeds first.\n";
        return;
    }

    // 1. Count total deeds
    int totalDeeds = static_cast<int>(deeds.size());
    cout << "Total number of heroic deeds recorded: " << totalDeeds << "\n";

    // 2. Count deeds by branch using two vectors:
    //    one for unique branch names, one for counts
    vector<string> uniqueBranches;
    vector<int> branchCounts;

    for (size_t i = 0; i < branches.size(); ++i) {
        string currentBranch = branches[i];

        // Check if this branch is already in uniqueBranches
        bool found = false;
        for (size_t j = 0; j < uniqueBranches.size(); ++j) {
            if (uniqueBranches[j] == currentBranch) {
                // Increment its count
                branchCounts[j]++;
                found = true;
                break;
            }
        }

        // If not found, add it as a new branch with count 1
        if (!found) {
            uniqueBranches.push_back(currentBranch);
            branchCounts.push_back(1);
        }
    }

    // 3. Display results
    cout << "\nDeeds by Service Branch:\n";
    for (size_t i = 0; i < uniqueBranches.size(); ++i) {
        cout << " - " << uniqueBranches[i] << ": " << branchCounts[i] << " deed(s)\n";
    }

    cout << "\nNumber of different branches represented: "
         << uniqueBranches.size() << "\n";
}

// Create a simple patriotic pattern using symbols and loops
void createPatrioticPattern() {
    int rows;

    cout << "\n--- Patriotic Pattern ---\n";
    cout << "Enter the number of rows for the pattern: ";
    cin >> rows;
    cin.ignore();  // clear newline

    if (rows <= 0) {
        cout << "Number of rows must be positive.\n";
        return;
    }

    // Use a simple triangle pattern
    // Cycle through symbols: ★, ●, ▲
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= i; ++j) {
            int mod = j % 3;
            if (mod == 1)
                cout << "★";
            else if (mod == 2)
                cout << "●";
            else
                cout << "▲";
        }
        cout << "\n";
    }
}

// Search heroic deeds by a specific branch
void searchByBranch(const vector<string>& deeds, const vector<string>& branches) {
    cout << "\n--- Search Deeds by Branch ---\n";

    if (deeds.empty()) {
        cout << "No heroic deeds have been recorded yet.\n";
        return;
    }

    string searchBranch;
    cout << "Enter the branch to search for (exact match): ";
    getline(cin, searchBranch);

    bool foundAny = false;
    for (size_t i = 0; i < branches.size(); ++i) {
        if (branches[i] == searchBranch) {  // exact string match
            if (!foundAny) {
                cout << "\nHeroic deeds for branch: " << searchBranch << "\n";
            }
            foundAny = true;
            cout << "- " << deeds[i] << "\n";
        }
    }

    if (!foundAny) {
        cout << "No heroic deeds found for branch: " << searchBranch << "\n";
    }
}
