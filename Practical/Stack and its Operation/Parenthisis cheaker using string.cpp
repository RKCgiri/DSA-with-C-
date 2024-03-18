#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    stack<char>s;
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
       if(x[0]==')' ||x[0]=='}' || x[0]==']')
             return false;
       int n=x.size();
       for(int i=0;i<n;i++){
           if(x[i]=='(' || x[i]=='{' || x[i]=='['){
                s.push(x[i]);
           }
           else{
             
             if(!s.empty()){
                  char c=s.top();
                
                   if((x[i]==')'&& c=='(') || (x[i]=='}'&& c=='{') || (x[i]==']'&& c=='['))
                      s.pop();
                  else
                     return false;
             }
            else 
                return false;
                
           }
       }
       if(s.empty())
             return true;
        else
            return false;
    }

};
int main(){
	string s;
	cout<<"enter the string "<<endl;
	cin>>s;
	Solution p;
	cout<<"this is a "<<p.ispar(s)<<" parenthisis"<<endl;
return 0;
}