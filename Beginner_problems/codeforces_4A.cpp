/*
    Problem Added by Mohd Saqib - B24316
*/

/*

PROBLEM STATEMENT :---
    https://codeforces.com/problemset/problem/4/A

    Tags - brute,forcemath,*800

    One hot summer day Pete and his friend Billy decided to buy a 
    watermelon. They chose the biggest and the ripest one, in their 
    opinion. After that the watermelon was weighed, and the scales
    showed w kilos. They rushed home, dying of thirst, and decided
    to divide the berry, however they faced a hard problem.

    Pete and Billy are great fans of even numbers, that's why they
    want to divide the watermelon in such a way that each of the 
    two parts weighs even number of kilos, at the same time it is 
    not obligatory that the parts are equal. The boys are extremely 
    tired and want to start their meal as soon as possible, that's 
    why you should help them and find out, if they can divide the 
    watermelon in the way they want. For sure, each of them should 
    get a part of positive weight.

    Input
    The first (and the only) input line contains integer 
    number w (1 ≤ w ≤ 100) — the weight of the watermelon 
    bought by the boys.

    Output
    Print YES, if the boys can divide the watermelon into two parts, 
    each of them weighing even number of kilos; and NO in the opposite 
    case.

    */

// Solution To the Problem Statement

#include <iostream>
using namespace std;

int main() {
    int w;
    cin >> w;

    // Check if w is greater than 2 and even
    if (w > 2 && w % 2 == 0) {
        cout << "yes" << endl; // w can be expressed as the sum of two even numbers
    } else {
        cout << "no" << endl; // w cannot be expressed as such
    }

    return 0;
}
