#include<string>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits){
         this->digits=digits;
         this->d_len=digits.size();
         letterCombinationsSearch(0);
         return strCombinations;
    }

    void letterCombinationsSearch(int n){
        if(n>=d_len-1){
            for(int j=0;j<Solution::phoneStr[digits[d_len-1]].size();j++){
                ret_one.push_back(Solution::phoneStr[digits[d_len-1]][j]);
                strCombinations.push_back(ret_one);
                ret_one.erase(ret_one.size()-1);
            }
        }else{
             for(int j=0;j<Solution::phoneStr[digits[n]].size();j++){
                 ret_one.push_back(Solution::phoneStr[digits[n]][j]);
                 letterCombinationsSearch(n+1);
                 ret_one.erase(ret_one.size()-1);
             }
        }
    }
    
    
    
    static map<char,string> phoneStr;
    
    string digits;
    int d_len;
    string ret_one;
    
    vector<string> strCombinations;
};

map<char,string> Solution::phoneStr={
    {'2',"abc"},
    {'3',"def"},
    {'4',"ghi"},
    {'5',"jkl"},
    {'6',"mno"},
    {'7',"pqrs"},
    {'8',"tuv"},
    {'9',"wxyz"}
};

