
# 🎖️ **Veterans Medal of Honor Tracker** 🎖️


## **Project Overview**

Create a C++ program that tracks veterans and the medals they have received. The program will allow the user to:

1. Add a veteran and their medal(s)
2. Display all veterans and medals
3. Search for veterans by medal type
4. Display medal statistics (how many of each medal have been awarded)
5. Exit the program

This project **honors veterans** while practicing:

* Structures
* Vectors
* Loops and conditionals
* Functions
* Input/output operations

---

## **Learning Objectives**

* Create and use a **structure** to store veteran information
* Use **vectors** to manage a dynamic list of veterans
* Implement **menu-driven programs**
* Use **loops** for iteration
* Apply **conditional statements** for searches and statistics
* Learn simple **data analysis techniques**

---

## **Program Structure**

### **Structure Definition**

```cpp
struct Veteran {
    string name;
    int age;
    vector<string> medals; // Each veteran can have multiple medals
};
```

---

### **Function Prototypes**

```cpp
void displayBanner();
void addVeteran(vector<Veteran>& veterans);
void displayVeterans(const vector<Veteran>& veterans);
void searchByMedal(const vector<Veteran>& veterans);
void medalStatistics(const vector<Veteran>& veterans);
```

---

### **Starter Code with TODOs**
* starter code has been provdied under: medalTracker.cpp
* you may use this as your guide to get started.*

---

## **Sample Data for Testing**

* **Veteran 1:** Name = John Smith, Age = 45, Medals = [Purple Heart, Bronze Star]
* **Veteran 2:** Name = Alice Brown, Age = 32, Medals = [Silver Star]
* **Veteran 3:** Name = Michael Lee, Age = 50, Medals = [Bronze Star, Purple Heart]

---

## **Extension Challenges**

1. Add the ability to **remove a veteran** by name
2. Sort veterans **alphabetically** or by **age**
3. Allow **medal input validation** to prevent duplicates



