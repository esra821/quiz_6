#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

struct Veteran {
    string name;
    int age;
    vector<string> medals; 
};

// Function prototypes
void displayBanner();
void addVeteran(vector<Veteran>& veterans);
void displayVeterans(const vector<Veteran>& veterans);
void searchByMedal(const vector<Veteran>& veterans);
void medalStatistics(const vector<Veteran>& veterans);
void removeVeteran(vector<Veteran>& veterans);
void sortVeteransByAge(vector<Veteran>& veterans);

int main() {
    vector<Veteran> veterans;
    int choice;

    displayBanner();

    do {
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Add a veteran and their medals\n";
        cout << "2. Display all veterans and medals\n";
        cout << "3. Search veterans by medal\n";
        cout << "4. Show medal statistics\n";
        cout << "5. Remove a veteran by name\n";
        cout << "6. Sort veterans by age\n";
        cout << "7. Exit\n";
        cout << "Choose an option (1-7): ";
        cin >> choice;
        cin.ignore(); // clear newline

        switch(choice) {
            case 1: 
                addVeteran(veterans); 
                break;
            case 2: 
                displayVeterans(veterans); 
                break;
            case 3: 
                searchByMedal(veterans); 
                break;
            case 4: 
                medalStatistics(veterans); 
                break;
            case 5: 
                removeVeteran(veterans); 
                break;
            case 6: 
                sortVeteransByAge(veterans); 
                break;
            case 7: 
                cout << "Thank you for honoring our veterans!\n"; 
                break;
            default: 
                cout << "Invalid choice. Try again.\n";
        }

    } while(choice != 7);

    return 0;
}

// =========================
//   FUNCTION DEFINITIONS
// =========================

// Display program banner
void displayBanner() {
    cout << "=============================================\n";
    cout << "      VETERANS MEDAL OF HONOR TRACKER        \n";
    cout << "=============================================\n";
    cout << "   Honoring Those Who Have Served Bravely    \n";
    cout << "=============================================\n\n";
}

// Add a veteran and their medals
void addVeteran(vector<Veteran>& veterans) {
    Veteran v;
    cout << "\n--- Add Veteran ---\n";
    cout << "Enter veteran's name: ";
    getline(cin, v.name);

    cout << "Enter veteran's age: ";
    cin >> v.age;
    cin.ignore();

    int numMedals;
    cout << "How many medals does this veteran have? ";
    cin >> numMedals;
    cin.ignore(); 

    for (int i = 0; i < numMedals; ++i) {
        string medal;
        cout << "Enter name of medal #" << (i + 1) << ": ";
        getline(cin, medal);

        // checks for duplicates
        bool duplicate = false;
        for (const string& m : v.medals) {
            if (m == medal) {
                duplicate = true;
                break;
            }
        }

        if (duplicate) {
            cout << "This veteran already has the medal \"" << medal 
                 << "\". Duplicate not added.\n";
            --i; 
        } else {
            v.medals.push_back(medal);
        }
    }

    veterans.push_back(v);
    cout << "Veteran added successfully.\n";
}

// Display all veterans and their medals
void displayVeterans(const vector<Veteran>& veterans) {
    cout << "\n--- Display All Veterans ---\n";

    if (veterans.empty()) {
        cout << "No veterans have been added yet.\n";
        return;
    }

    for (size_t i = 0; i < veterans.size(); ++i) {
        const Veteran& v = veterans[i];
        cout << "Veteran #" << (i + 1) << ":\n";
        cout << "  Name: " << v.name << "\n";
        cout << "  Age : " << v.age << "\n";
        cout << "  Medals: ";
        if (v.medals.empty()) {
            cout << "None\n";
        } else {
            for (size_t j = 0; j < v.medals.size(); ++j) {
                cout << v.medals[j];
                if (j != v.medals.size() - 1) {
                    cout << ", ";
                }
            }
            cout << "\n";
        }
        cout << "---------------------------------\n";
    }
}

// Search for veterans by medal
void searchByMedal(const vector<Veteran>& veterans) {
    cout << "\n--- Search Veterans by Medal ---\n";

    if (veterans.empty()) {
        cout << "No veterans in the system to search.\n";
        return;
    }

    string searchMedal;
    cout << "Enter the medal to search for: ";
    getline(cin, searchMedal);

    bool foundAny = false;

    for (const Veteran& v : veterans) {
        bool hasMedal = false;
        for (const string& medal : v.medals) {
            if (medal == searchMedal) { // case-sensitive match
                hasMedal = true;
                break;
            }
        }

        if (hasMedal) {
            if (!foundAny) {
                cout << "\nVeterans with medal \"" << searchMedal << "\":\n";
            }
            foundAny = true;
            cout << "  Name: " << v.name << ", Age: " << v.age << "\n";
        }
    }

    if (!foundAny) {
        cout << "No veterans found with the medal \"" << searchMedal << "\".\n";
    }
}

void medalStatistics(const vector<Veteran>& veterans) {
    cout << "\n--- Medal Statistics ---\n";

    if (veterans.empty()) {
        cout << "No veterans in the system. No medal statistics available.\n";
        return;
    }

    map<string, int> medalCount;

    for (const Veteran& v : veterans) {
        for (const string& medal : v.medals) {
            medalCount[medal]++; 
        }
    }

    if (medalCount.empty()) {
        cout << "No medals recorded yet.\n";
        return;
    }

    cout << "Medal\t\tCount\n";
    cout << "-------------------------\n";
    for (const auto& pair : medalCount) {
        cout << pair.first << "\t\t" << pair.second << "\n";
    }
}

void removeVeteran(vector<Veteran>& veterans) {
    cout << "\n--- Remove Veteran ---\n";

    if (veterans.empty()) {
        cout << "No veterans in the system to remove.\n";
        return;
    }

    string nameToRemove;
    cout << "Enter the name of the veteran to remove: ";
    getline(cin, nameToRemove);

    bool found = false;

    for (auto it = veterans.begin(); it != veterans.end(); ++it) {
        if (it->name == nameToRemove) { // case-sensitive match
            veterans.erase(it);
            found = true;
            cout << "Veteran \"" << nameToRemove << "\" has been removed.\n";
            break;
        }
    }

    if (!found) {
        cout << "No veteran found with the name \"" << nameToRemove << "\".\n";
    }
}

void sortVeteransByAge(vector<Veteran>& veterans) {
    cout << "\n--- Sort Veterans by Age ---\n";

    if (veterans.size() < 2) {
        cout << "Not enough veterans to sort.\n";
        return;
    }

    sort(veterans.begin(), veterans.end(),
         [](const Veteran& a, const Veteran& b) {
             return a.age < b.age;
         });

    cout << "Veterans have been sorted by age (youngest to oldest).\n";
}
