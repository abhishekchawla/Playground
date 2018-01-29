//
//  main.cpp
//  test
//
//  Created by Abhishek Chawla on 1/4/18.
//  Copyright © 2018 Abhishek Chawla. All rights reserved.
//

#include "Header.h"
using namespace std;

struct A{
    virtual ~A()
    {
        f();
    }

    virtual void f()
    {
        cout<<"A::f"<<endl;
    }

    A(){cout<<"Hello";}
};

struct B: public A{

 ~B()
    {

    }

    virtual void f()
    {
        cout<<"B::f "<<endl;
    }
};

int lengthOfLongestSubstring(string s) {

    if(!s.size())
        return 0;

    unordered_map<char, int> pos;
    int start=0, len=1;

    for(int i=0; i<s.size(); i++)
    {
        if(pos.find(s[i])!=pos.end() && pos[s[i]]>=start)
        {
            len=max(i-start, len);
            start = pos[s[i]]+1;
        }

        pos[s[i]]=i;
    }

    len=max((int)s.size()-1-start, len);
    return len;
}

int removeDuplicates(vector<int>& nums) {

    auto it1=nums.begin();
    auto it2=it1;
    while(it2!=nums.end())
    {
        if(*it1!=*it2)
        {
            it1 = nums.erase(it1+1, it2);
            it2=it1;
        }
        it2++;
    }

    nums.erase(it1+1, it2);
    return static_cast<int>(nums.size());
}

vector<vector<int>> threeSum(vector<int>& nums) {

    vector<vector<int>> ret;

    sort(nums.begin(), nums.end());

    for(int i=0; i<nums.size(); i++)
    {
        int target=-nums[i];
        if(target<0)
            break;

        int front=i+1, back=nums.size()-1;

        while(front<back)
        {
            int sum=nums[front]+nums[back];

            if(sum<target)
                front++;
            else if(sum>target)
                back--;
            else
            {
                ret.push_back({nums[i],nums[front], nums[back]});
                //int fr = nums[front];
                ++front; --back;
                while(front+1<back && nums[front+1]==nums[front])
                    ++front;
                while(back-1>front && nums[back-1]==nums[back])
                    --back;
            }
        }
    }

    return ret;
}

int maximumSwap(int num) {

    int ret=0;
    string str = to_string(num);

    int maxPos = str.size()-1, max = str[maxPos];
    int swapPos=maxPos;
    pair<int, int> pos{swapPos, maxPos};

    for(int i=str.size()-2; i>=0; --i)
    {
        if(str[i]<max)
            swapPos = i;
        else if (str[i] > max)
        {
            if(maxPos>swapPos)
            {
                pos.first = swapPos;
                pos.second = maxPos;
            }

            max = str[i];
            maxPos = i;
        }
    }

    if(maxPos>swapPos)
        swap(str[maxPos], str[swapPos]);
    else
        swap(str[pos.first], str[pos.second]);

    stringstream ss(str);
    int i; ss>>i;

    return i;

}

int widthOfBinaryTree(TreeNode* root) {

    int ret=0;
    return ret;
}

template<typename T>
void doStuff(T t1, enable_if_t<is_integral<T>::value, T> t2=0)
{
    cout<<"do stuff::integral, type ="<<typeid(t2).name()<<endl;
}

string checkForPalindrome(int l, int r, string& s)
{
    string palin = "";

    int L=0, R=0;
    while(l>=0 && r<s.size())
    {
        if(s[l]==s[r])
        {
            L=l;R=r;
            --l;++r;
        }
        else
            break;
    }

    palin = s.substr(L, R-L+1);
    return palin;
}

string longestPalindrome(string s) {

    string longestPalindrome = "";

    for(int i=1; i<s.size(); i++)
    {
        string odd = checkForPalindrome(i-1, i+1, s);
        string even = checkForPalindrome(i-1, i, s);

        string temp = odd.size()>even.size()?odd:even;
        longestPalindrome = temp.size()>longestPalindrome.size()?temp:longestPalindrome;
    }

    return longestPalindrome;
}
//[10, 9, 2, 5, 3, 7, 101, 18]
//O(N^2) algorithm DP algorithm
int lengthofLIS(vector<int>& nums)
{
    if(!nums.size())
        return 0;

    vector<int> len(nums.size(), 1);
         for(int i=0; i<nums.size(); i++)
    {
        for(int j=i+1; j<nums.size(); j++)
           {
               if(nums[j]>nums[i])
                len[j]=max(len[j], len[i]+1);
             }
    }
    return *max_element(len.begin(), len.end());
}

//O(NlogN) binary search algorithm

int lengthofLIS_binSearch(vector<int>& nums)
{
    if(!nums.size())
        return 0;

    vector<int> LIS;

    for(int i: nums)
    {
        auto itr = upper_bound(LIS.begin(), LIS.end(), i);
        if(itr==LIS.end())
            LIS.push_back(i);
        else
            *itr = i;
    }

    return LIS.size();
}


void moveZeroes(vector<int>& nums) {
    //queue<T> pos;

    int j=0;
    for(int i=0; i<nums.size(); i++)
    {
        if(nums[i]!=0)
        {
            swap(nums[i], nums[j++]);
        }
    }
}

//overloading the  << operator for vector
template<typename T>
ostream& operator << (ostream& os, vector<T>& vec)
{
    for(auto i:vec)
        cout<<i<<" ";

    return os;
}

//rule of 5
class BaseClass{

private:

    int m_iSize=0;
    int* m_pResource;

    friend void swap(BaseClass& p1, BaseClass &p2)
    {
        std::swap(p1.m_iSize, p2.m_iSize);
        std::swap(p1.m_pResource, p2.m_pResource);
    }

public:

    //Constructor
    BaseClass(int size)
    {
        m_pResource = new int[size];
    }

    //destructor
    ~BaseClass()
    {
        delete[] m_pResource;
    }

    //Copy-constructor
    BaseClass(BaseClass& param): m_iSize(param.m_iSize),
                                 m_pResource(m_iSize? new int[m_iSize]:nullptr)
    {
        copy(param.m_pResource, param.m_pResource+m_iSize, m_pResource);
    }

    //assingment operator
    BaseClass& operator=(BaseClass param)
    {
        swap(param, *this);
        return *this;
    }

    //move-copy-constructor
    BaseClass(BaseClass&& param)
    {
        swap(param, *this);
    }
};


