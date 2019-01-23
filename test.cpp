#include<iostream>
#include<cstdlib>
#define MAX 5
using namespace std;
void neat()
{
	cout << endl;
	for(int i=0;i<35;i++)
		cout << " ";
}
template <class type>
class Stack
{
	type s[MAX];
public :
	Stack()
	{
		int i=0;
		for(i=0;i<MAX;i++)
			s[i] = 0;
	}	
	void ICFD(int &);
};
template <class type>
void Stack<type>::ICFD(int &i)
{
	int op;
	//int i=0;
above :
	neat();	cout << "------------------------------ Process Menu ----------------------------";	
	neat();	cout << " 1.Push";	
	neat();	cout << " 2.Pop ";
	neat();	cout << " 3.Display";
	neat(); cout << " 4.Exit   " << endl;
	neat(); cout << " --> ";
		
		cin  >> op;
	if(op == 1)
	{
		if(i== MAX){
		neat();	cout << "************************************************************************";
		neat();	cout << "*************************** STACK OVERFLOW *****************************";
		neat();	cout << "************************************************************************";
		goto above;}
	neat(); cin >> s[i];
	i++;
	neat(); cout << "Data is stored ";
	goto above;
	}
	else if(op == 2)
	{
	--i;
		if(i == 0){
		neat();	cout << "************************** STACK UNDERFLOW *****************************";
		goto above;}
	s[i] = 0;
	neat(); cout << "Data is Deleted " ;
	goto above;
	}
	else if(op == 3)
	{
	neat(); cout << "Elements of Stack : ";
	neat();
	for(int k=0;k<MAX;k++)
		cout << s[k] << "  "; 
	goto above;
	}
	else 
	return ;	

}
int main()
{
	Stack <int>obj1;static int i;
	Stack <char>obj2;static int j;
	Stack <float>obj3;static int k;
	Stack <double>obj4;static int l;
	int exit,chance=0;
repeat :
	system("clear");
	neat();	cout << "************************************************************************";	
	neat();	cout << "                           STACK IMPLIMENTATION                         "; 
	neat();	cout << "************************************************************************";	
	neat();	cout << "-------------------------------- MENU ----------------------------------";	
	neat();	cout << " 1.Integer";	
	neat();	cout << " 2.Char   ";
	neat();	cout << " 3.Float  ";
	neat();	cout << " 4.Double ";
	neat(); cout << " 5.Exit   " << endl;
	neat(); cout << " --> ";
		
		cin  >> exit;
	if(exit == 1)
	{
	chance=0;
	neat(); cout << "---------------- STACK APPLICATION IS READY FOR INTEGER ----------------";
	obj1.ICFD(i);
	goto repeat;
	}
	else if(exit == 2)
	{
	chance=0;
	neat(); cout << "---------------- STACK APPLICATION IS READY FOR CHARCTER ---------------";
	obj2.ICFD(j);
	goto repeat;
	}
	else if(exit == 3)
	{
	chance=0;
	neat(); cout << "---------------- STACK APPLICATION IS READY FOR FLOAT   ----------------";
	obj3.ICFD();
	goto repeat;
	}
	else if(exit == 4)
	{	
	chance=0;
	neat(); cout << "---------------- STACK APPLICATION IS READY FOR DOUBLE  ----------------";
	obj4.ICFD();
	goto repeat;
	}
	else if(exit == 5)
	{
	neat(); cout << "THANKS FOR BEING HERE " ;
	neat(); cout << "PROCESS TERMINATING.....";
	neat(); cout << endl;
	return 0;
	}
	else
	{
		chance++;
		if(chance == 1){
		neat(); cout << "YOU ENTERED WRONG KEY : " << 3-chance << " chances remaining." << endl;
		goto repeat;}
		else if(chance == 2){
		neat(); cout << "YOU ENTERED WRONG KEY : " << 3-chance << " chances remaining." << endl;
		goto repeat;}
		else {
		neat(); cout << "SORRY YOU HAVE MADE MAXIMUM ATTEMPTS " << 3-chance << " chances remaining." << endl;
		return 0;}
	}
	
	
	
	
	
	neat();cout << "************************************************************************" << endl;	
}
