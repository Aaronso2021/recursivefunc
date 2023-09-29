// Author: Aaron Soo

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

/**************************
* Your solutions go here *
* ************************/
int triangleNum(int n){
if (n != 0){
    return n + triangleNum(n-1); //returns the next layer of the triangle down with the current layer of the triangle
}
return n;
}

int rFib(int n){
    if (n <= 0){
        return 0;
    }
    if (n == 1){
        return 1;
    }
    else{
        return rFib(n-1) + rFib(n-2); //returns the previous two numbers of the fibbonaci sequence 
    }
}

int rSumHelper(const vector<int> &v, int i){
    if(v.size() > i){
        return v.at(i) + rSumHelper(v,i+1); //checks and adds the next number of the vector if it is a valid number
    }
}

int rSum(const vector<int> &v){
return rSumHelper(v,0);
}

int rMaxHelper(const vector<int> &v, int start){

    if(v.size() > start){
        return max(v.at(start), rMaxHelper(v,start+1)); //compares current number to next number in array
    }
    return INT_MIN;
}

int rMax(const vector<int> &v){
if(v.empty() == true){
    return INT_MIN;
}
return rMaxHelper(v,0);
}

bool isSorted(const vector<int> &v, int start, int end){
    if (v.size() <= 1){
        return true;
    } else if (v.at(start) <= v.at(start+1) && start+1 < end){ //if the firat and last characters are the same, it removes those letters and continues with the function
        return isSorted(v, start+1, end);
    } else if (v.at(start) > v.at(start+1) && start+1 < end){
        return false;
    }
return true;
}

bool isPalindromeHelper(string s, int start, int end){
    if (start < s.size()/2){
        if(s.at(start) == s.at(end)){
            return isPalindromeHelper(s, start+1,end-1); //calls pallidrome function
        } else{
            return false;
        }
    }
    return true;
}
bool isPalindrome(string s){
    if (s.size() <= 1){
        return true;
    }
return isPalindromeHelper(s, 0, s.size()-1);
}

int rBinarySearch(const vector<int> &v, int low, int high, int target){
    int i = (high + low) /2;
    if (v.size() == 0){
        return -1;
    }
    if(target < v.at(i)){
            if (low == high){
                return -1;
            } 
        return rBinarySearch(v,low,i - 1,target); //check left of tree
    }
    else if (target > v.at(i)){
            if (low == high){
                return -1;
            } 
        return rBinarySearch(v, i+1, high, target); //check right of tree
    }
return i;
}

bool rSubsetSum(const vector<int> &v, int start, int target){
    if(v.size() == 0){
        return false;
    }
    if(target - v.at(start) == 0){ //combination found! 
        return true;
    }
    else if(start  < v.size()-1){
       if (rSubsetSum(v,start+1, target - v.at(start) || rSubsetSum(v, start+1, target))){
        return true; //look at potiential combinations
       };
    }
return false;
}

/***********************************************
* Main and helper functions for quick testing *
* *********************************************/
void readIntVector(vector<int> &v, int n);

int main(){
int question = -1;
cout << "Question: ";
cin >> question;

int n = 0, start = 0, end = 0;
vector<int> v;
string s = "";
switch (question){
case 1: //triangleNum
cout << "Triangle Number n: ";
cin >> n;
cout << triangleNum(n) << endl;
break;
case 2: //rFib
cout << "Nth Fibonacci Number: ";
cin >> n;
cout << rFib(n) << endl;
break;
case 3: //rSum
cout << "Recursive Sum Vector Size: ";
cin >> n;
cout << "Values: ";
readIntVector(v, n);
cout << rSum(v) << endl;
break;
case 4: //rMax
cout << "Recursive Max Vector Size: ";
cin >> n;
cout << "Values: ";
readIntVector(v, n);
cout << rMax(v) << endl;
break;
case 5: //isSorted
cout << "isSorted Vector Size: ";
cin >> n;
cout << "Start and End: ";
cin >> start >> end;
cout << "Values: ";
readIntVector(v, n);
cout << isSorted(v, start, end) << endl;
break;
case 6: //isPalindrome
cout << "String: ";
cin >> s;
cout << isPalindrome(s) << endl;
break;
case 7: //rBinarySearch
cout << "Binary Search Vector Size: ";
cin >> n;
cout << "Target: ";
cin >> end;
cout << "Values: ";
readIntVector(v, n);
cout << rBinarySearch(v, 0, v.size()-1, end) << endl;
break;
case 8: //rSubsetSum
cout << "Subset Sum Vector Size: ";
cin >> n;
cout << "Target: ";
cin >> end;
cout << "Values: ";
readIntVector(v, n);
cout << rSubsetSum(v, 0, end) << endl;
break;
}

return 0;
}

/**************************************************
* Read a vector of integers in from cin *
* v - vector<int> & - the integer vector to fill *
* n - int - the number of integers to read *
* ************************************************/
void readIntVector(vector<int> &v, int n){
int m = 0;
for (int i = 0; i < n; i++){
cin >> m;
v.push_back(m);
}
}
 
