#include<bits/stdc++.h>
using namespace std;

class intopre{
	public:
		stack<char>st;
		char result[100];
		int prec(char);
		void prefix(char [] );
};
int intopre::prec(char c){
	if(c=='^') return 3;
	else if(c=='*'||c=='/'||c=='%') return 2;
	else if(c=='+'||c=='-') return 1;
	else return -1;
}
void intopre::prefix(char s[]){
	int i=0,j=0;
	strrev(s);
	cout<<"The reversing expression is ="<<s<<endl;
	while(s[i]!='\0'){
		char c=s[i];
		if((c>='a'&& c<='z')||(c>='A'&& c<='Z')||(c>='0'&& c<='9')){
			result[j++]=c;
		}
		else if(c==')'){
				st.push(c);
		}
		else if(c=='('){
		    	while(st.top()!=')'){
					result[j++]=st.top();
			    	st.pop();
		    	}
				st.pop();
		}
		else {
		   	while(!st.empty() && prec(st.top())>prec(c)){
	 		    result[j++]=st.top();
		     	st.pop();
			}
			st.push(c);
		}
		i++;
	}

	while(!st.empty()){
		result[j]=st.top();
		st.pop();
		j++;
	}
	result[j]='\0';
	strrev(result);
	cout<<"The postfix expresion of the infix expression is = ";
	j=0;
	while(result[j]!='\0'){
		cout<<result[j];
		j++;	
	}
	cout<<endl;

}

int main(){
	intopre a;
	char s[20];
	cout<<"Enter the Infix expression"<<endl;
	cin>>s;
	cout<<"The Infix expression is = ";
	int i=0;
	while(s[i]!='\0'){
		cout<<s[i++];
	}
	cout<<endl;
	a.prefix(s);
return 0;
}