#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i,n=nums.size(),k=0;
        for(i=0;i<n;i++)
            {
                if(nums[i]==nums[i+1])
                	k++;
                else
                   nums[i-k]=nums[i];
            }
        return n-k;
    }
    void display(vector<int>v)
    {
    	for(int i=0;i<v.size();i++)
    		cout<<v[i]<<" ";
	}
};
int main()
{  Solution a;
	vector<int>v={3,3,5};
	
int	n=a.removeDuplicates(v); 
	a.display(v);
cout<<n <<endl;
	for(int i=0;i<n;i++)
	cout <<v[i]<<" ";
}