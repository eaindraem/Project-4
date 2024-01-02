//
//  main.cpp
//  Project4
//
//  Created by Melody Myae on 11/2/23.
//

#include <iostream>
#include <cassert>
#include <string>
using namespace std;

int reduplicate(string a[], int n);
int locate(const string a[], int n, string target);
int locationOfMax(const string a[], int n);
int circleLeft(string a[], int n, int pos);
int enumerateRuns(const string a[], int n);
int flip(string a[], int n);
int locateDifference(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int locateAny(const string a1[], int n1, const string a2[], int n2);
int divide(string a[], int n, string divider);





int main() {

    string h[7] = { "nikki", "ron", "asa", "vivek", "", "chris", "donald" };
            assert(locate(h, 7, "chris") == 5);
            assert(locate(h, 7, "asa") == 2);
            assert(locate(h, 2, "asa") == -1);
            assert(locationOfMax(h, 7) == 3);

            string g[4] = { "nikki", "ron", "chris", "tim" };
            assert(locateDifference(h, 4, g, 4) == 2);
            assert(circleLeft(g, 4, 1) == 1 && g[1] == "chris" && g[3] == "ron");

            string c[4] = { "ma", "can", "tu", "do" };
            assert(reduplicate(c, 4) == 4 && c[0] == "mama" && c[3] == "dodo");

            string e[4] = { "asa", "vivek", "", "chris" };
            assert(subsequence(h, 7, e, 4) == 2);

            string d[5] = { "ron", "ron", "ron", "chris", "chris" };
            assert(enumerateRuns(d, 5) == 2);
        
            string f[3] = { "vivek", "asa", "tim" };
            assert(locateAny(h, 7, f, 3) == 2);
            assert(flip(f, 3) == 3 && f[0] == "tim" && f[2] == "vivek");
        
            assert(divide(h, 7, "donald") == 3);
        
            cout << "All tests succeeded" << endl;

}


//APPEND ELEMENT OF THE ARRAY TO THE SAME ELEMENT
int reduplicate(string a[], int n)
{
    //if size of the array is negative, return -1
    if (n < 0)
    {
        return -1;
    }
    else if (n == 0)
    {
        return 0;
    }
    else
    {   //loop through the array and the components append to itself
        for (int i = 0 ; i < n ; i++)
        {
            a[i] += a[i];
        }
        return n;
    }
}




//RETURN THE POSTION OF THE ARRAY THAT IS EQUAL TO TARGET
int locate(const string a[], int n, string target)
{
    int nthEqual = n + 1;
    
    //if size of the array is negative, return -1
    if (n < 0)
    {
        return -1;
    }
    //return -1 when array length is 0(no elements equal to target)
    if (n == 0)
    {
        return -1;
    }
    for (int i = 0 ; i <= n-1 ; i++)
    {
        //if more than 1 is equal to target, take the smallest one
        if (a[i] == target && i < nthEqual)
        {
            nthEqual = i;
        }
    }
    //if none of the element is equal to target, return -1
    if (nthEqual == n+1)
    {
        return -1;
    }
    return nthEqual; //loop completed, value acquired
}

//RETURE POSITION OF THE ARRAY THAT IS >= EVERY STRING IN THE ARRAY
int locationOfMax(const string a[], int n)
{
    int nthBiggest = n-1;
    string comparison = a[nthBiggest];

    //if size of the array is negative, return -1
    if (n < 0)
    {
        return -1;
    }
    if (n == 0)
    {
        return -1;
    }
    //Start from the last element to get the smaller index when 2 elements are equal
    for (int i = n - 2; i >= 0 ; i--)
    {
        if (a[i] >= comparison)
        {
            nthBiggest = i;
            comparison = a[i];
        }
    }
    //if no element in the array, return -1
    
    return nthBiggest;
}


//COPY ALL ELEMENTS AFTER POS ONE PLACE TO THE LEFT, POS GOES TO LAST POSITION
int circleLeft(string a[], int n, int pos)
{
    string temp = a[pos];
    //if size of the array is negative, return -1
    if (n < 0)
    {
        return -1;
    }
    if (n == 0)
    {
        return -1;
    }
    for (int i = pos ; i <= n - 2 ; i++)
    {
        //copy all elements after pos one place to the left
        a[i] = a[i+1];
    }
    a[n-1] = temp;
    return pos;
}


//RETURN THE AMOUNT OF ONE OR MORE CONSECUTIVE IDENTICAL ITEMS
int enumerateRuns(const string a[], int n)
{
    int counter = 0;
    //if size of the array is negative, return -1
    if (n < 0)
    {
        return -1;
    }
    if (n == 0)
    {
        return 0;
    }
    //if next element isn't the same as current element, increase the counter
    for (int i = 0 ; i < n ; i++)
    {
        if (a[i] != a[i+1])
        {
            counter++;
        }
    }
    return counter;
}

//REVERSE THE ORDER OF ELEMENTS AND RETURN N
int flip(string a[], int n)
{
    int j = n - 1;
    //if size of the array is negative, return -1
    if (n < 0)
    {
        return -1;
    }
    if (n == 0)
    {
        return 0;
    }
    for (int i = 0 ; i < n/2 ; i++)
    {
        string temp = a[i];
        a[i] = a[j];
        //cout << i << ": " << a[i] << endl;
        a[j] = temp;
        //cout << j << ": " << a[j] << endl;
        j--;
    }
    return n;
}


//RETURN THE FIRST POSITION THAT AREN'T EQUAL FROM TWO CORRESPONDING ARRAYS
int locateDifference(const string a1[], int n1, const string a2[], int n2)
{
    bool allEqual = true;
    int upperBound = 0;
    //if size of the array is negative, return -1
    if (n1 < 0 || n2 < 0)
    {
        return -1;
    }
    if (n1 == 0 || n2 == 0)
    {
        return 0;
    }
    //set upperbound as the smaller out of two array sizes
    if (n2 < n1)
    {
        upperBound = n2;
    }
    else
    {
        upperBound = n1;
    }
    //check until the upperbound
    for (int i = 0; i < upperBound ; i++)
    {
        if (a1[i] != a2[i])
        {
            allEqual = false;
            return i;
        }
    }
    //if all are equal, return upperbound
    if (allEqual)
    {
        return upperBound;
    }
    return 1;
}


//IF SECOND ARRAY APPEARS IN FIRST ARRAY IN SAME ORDER, RETURN THE FIRST EQUAL POSITION
int subsequence(const string a1[], int n1, const string a2[], int n2)
{
    int j = n2 - 1;
    int i = n1 -1;
    int counter = 0; //counts the amount of equal elements
    if (n1 < 0 || n2 < 0)
    {
        return -1;
    }
    if (n1 == 0 || n2 == 0)
    {
        return 0;
    }
    //scan all elements of n1
    while (i >= 0)
    {

        if (a1[i] == a2[j])
        {
            counter++;
            if (counter == n2)
            {
                return i;
            }
            i--;
            j--;
        }
        if (a1[i] != a2[j])
        {
            i--;
            counter = 0;
        }
    }
    return -1;
}
    

//RETURN SMALLEST POSTION OF FIRST ARRAY THAT IS EQUAL TO ANY OF THE ELEMENTS IN THE SECOND ARRAY
int locateAny(const string a1[], int n1, const string a2[], int n2)
{
    if (n1 < 0 || n2 < 0)
    {
        return -1;
    }
    if (n1 == 0 || n2 == 0)
    {
        return 0;
    }
    //check for all
    for (int i = 0 ; i < n1 ; i++)
    {
        for (int j = 0 ; j < n2 ; j++)
        {
            if (a1[i] == a2[j])
            {
                return i;
            }
        }
    }
    return -1;
}


//REARRAGE THE ARRAY SO THAT THE ELEMENTS SMALLER THE DIVIDER COMES BEFORE THE ELEMENTS GREATER THAN THE DIVIDER
int divide(string a[], int n, string divider)
{
    string temp;
    int m = 0;
    
    if (n < 0)
    {
        return -1;
    }
    if (n == 0)
    {
        return 0;
    }
    //sort array into alphabetical order low to high
    while (m < n) //run multiple times so the last position can travel to the first position if needed
    {
        for (int i  = 0 ; i < n ; i++)
        {
            for (int j = i+1 ; j < n ; j++)
            {
                if (a[i] > a[j])
                {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
                j++;
                }
        }
        m++;
    }
    
    //look for divider or the first string greater than the divider
    for (int i  = 0 ; i < n ; i++)
    {
        if (a[i] >= divider)
        {
            return i;
        }
        if ( i == n-1) //if all elements of array are smaller than the divider
        {
            return n;
        }
    }
    return -1;
}
