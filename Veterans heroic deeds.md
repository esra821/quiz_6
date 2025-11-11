

# 🎖️ **Veterans Day Heroic Deeds** 🎖️

## **Project Overview**

You will create a C++ program to honor veterans by recording their heroic deeds. The program will allow a user to:

1. Add a veteran’s heroic deed
2. Display all heroic deeds
3. Show tribute statistics
4. Create a patriotic pattern
5. Search deeds by branch

This project will help you practice:

* Vectors
* Loops and conditionals
* Functions
* Input/output operations
* Basic algorithms

---

## **Step-by-Step Instructions**

### **Step 1: Setup**

1. Create a new file `main.cpp`
2. Include the necessary libraries, for exanple:

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;
```

3. Declare your function prototypes for instance:

```cpp
void displayBanner();
void addHeroicDeed(vector<string>& deeds, vector<string>& branches);
void displayDeeds(const vector<string>& deeds, const vector<string>& branches);
void displayStatistics(const vector<string>& deeds, const vector<string>& branches);
void createPatrioticPattern();
void searchByBranch(const vector<string>& deeds, const vector<string>& branches);
```

---

### **Step 2: Main Function & Menu**
1. Implement your main function and the main menu
   * your main menu should hae the following options;

```cpp
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Add a veteran's heroic deed\n";
        cout << "2. Display all heroic deeds\n";
        cout << "3. Show tribute statistics\n";
        cout << "4. Create patriotic pattern\n";
        cout << "5. Search deeds by branch\n";
        cout << "6. Exit\n";
        cout << "Choose an option (1-6): ";
        cin >> choice;
        cin.ignore();

```

---

### **Step 3: Implement your Functions**
1. Define your functions below the main function

#### **3.1 Display Banner**

#### **3.2 Add Heroic Deed**

#### **3.3 Display All Heroic Deeds**

#### **3.4 Display Statistics**

#### **3.5 Patriotic Pattern**

#### **3.6 Search by Branch**

## **Tips**
* Starter code has been provided: 'heroicDeeds.cpp'
  * You may use this template to get started.
* Implement **one function at a time** and test it.
* Use **meaningful names** for veterans’ branches.
* Always check for **empty vectors** before looping.
* Test all **menu options** before submitting.

---

## **Grading Rubric**

| Category                        | Points |
| ------------------------------- | ------ |
| Program runs and menu works     | 10     |
| Vectors store data correctly    | 15     |
| Functions implemented correctly | 20     |
| Loops & conditionals work       | 15     |
| Input/output handled properly   | 10     |
| Counting & searching correct    | 15     |
| User experience & menu clarity  | 10     |
| Code style & readability        | 5      |

---



