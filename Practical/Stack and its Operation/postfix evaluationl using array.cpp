#include<bits/stdc++.h>
using namespace std;
class postfixEval{
  	stack<int>st;
 	public:
	 	int result(char []);
		
};

int postfixEval::result(char str[]){
 	int i=0;
 	cout<<"In the function"<<endl;
 	while(str[i]!='\0'){
	 	cout<<i<<" ,";
	 	char c=str[i];
	 	if(isdigit(c)){
			st.push(c-'0');
	 	}
	 	else{
		 	int val1=st.top();
		 	st.pop();
		 	int val2=st.top();
		 	st.pop();
		 	switch(str[i]){
				
			 	case '+': 
	   					 st.push(val2+val1);
				   		break;
			 	case '-':
		               	 st.push(val2 - val1);
		               	 break;
           		case '*':
		               	 st.push(val2 * val1);
		               	 break;
             	case '/':
		               	 st.push(val2 / val1);
		               	 break;
     	    }
					
	 	}
	 	i++;
 	}
 	return st.top();
}

int main(){
 	postfixEval p;
 	char str[20];
 	cout<<"Enter the postfix expression"<<endl;
 	cin>>str;
 	int i=0;
//	while(str[i]!='\0'){
//		cin>>str[i++];
//	}
 	cout<<"The postfox expression is = "<<str<<endl;
 	int res=p.result(str);
 	cout<<"After";
 	cout<<"The result is = "<<res<<endl;
 	return 0;
}