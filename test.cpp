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
	system("clear");
	int op;
	char rep;
	int chance=0,z=0;
	if(i != 0)
	{
		neat(); cout << "Previously you quit a pushing of data in middle of the process. " ;
		neat(); cout << "Do you want continue ..... : Y/N ";
take:
		neat();  cin >> rep;
		if(rep == 'N' || rep == 'n')
			i=0;
		else if(rep == 'y' || rep == 'Y')
			i = i;
		else
		{
			neat(); cout << "Please enter correct option .... ";
			if(z < 2)
				goto take;
			else
				neat(); cout << "SORRY YOU CROSSED MAXIMUM LIMITS ";
			return;
		}
	}
above :
	//neat();	cout << "------------------------------------------------------------------------";	
	neat();	cout << "------------------------------ Process Menu ----------------------------";	
	neat();	cout << "------------------------------------------------------------------------";	
	neat();	cout << " 1.Push";	
	neat();	cout << " 2.Pop ";
	neat();	cout << " 3.Display";
	neat(); cout << " 4.Goto Main menu" << endl;
	neat(); cout << " --> ";

	cin  >> op;
	if(op == 1)
	{
		chance = 0;
		if(i== MAX)
		{
			system("clear");
			neat();	cout << "************************************************************************";
			neat();	cout << "*************************** STACK OVERFLOW *****************************";
			neat();	cout << "************************************************************************";
			neat(); 
			neat(); cout << "Do you want continue ..... : Y/N ";
			neat();  cin >> rep;
			if(rep == 'y' || rep == 'Y')
				goto above;
			else
				return;
		}
		neat(); cin >> s[i];
		i++;
		neat(); cout << "Data is stored ";
		goto above;
	}
	else if(op == 2)
	{
		chance = 0;
		if(i == 0)
		{
			system("clear");
			neat();	cout << "************************************************************************";
			neat();	cout << "************************** STACK UNDERFLOW *****************************";
			neat();	cout << "************************************************************************";
			neat(); 
			neat(); cout << "Do you want continue ..... : Y/N ";
			neat();  cin >> rep;
			if(rep == 'y' || rep == 'Y')
				goto above;
			else
				return;
			//-------------------------------------------------------------------
		}
		--i;
		neat(); cout << s[i] <<" - is Deleted " ;
		s[i] = 0;
		goto above;
	}
	else if(op == 3)
	{
		chance = 0;
		neat(); cout << "Elements of Stack : ";
		neat();
		for(int k=0;k<MAX;k++)
			cout << s[k] << "  "; 
		goto above;
	}
	else if(op == 4)
	{	
	terminate:
		return;
	}
	else
	{
		if(chance < 2)
		{
			system("clear");//neat();
			neat(); cout << "WRONG OPTION : " << 2-chance << " chances remaining." << endl;
			chance +=1;
			goto above;
		}
		else 
		{
			neat(); cout << "SORRY YOU HAVE MADE MAXIMUM ATTEMPTS " << endl;
			goto terminate;
		}
	}	

}
int main()
{
	Stack <int>obj1;static int i;
	Stack <char>obj2;static int j;
	Stack <float>obj3;static int k;
	Stack <double>obj4;static int l;
	int exit;
	int chance=0;
repeat1:
	system("clear");
repeat :
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
		goto repeat1;
	}
	else if(exit == 2)
	{
		chance=0;
		neat(); cout << "---------------- STACK APPLICATION IS READY FOR CHARCTER ---------------";
		obj2.ICFD(j);
		goto repeat1;
	}
	else if(exit == 3)
	{
		chance=0;
		neat(); cout << "---------------- STACK APPLICATION IS READY FOR FLOAT   ----------------";
		obj3.ICFD(k);
		goto repeat1;
	}
	else if(exit == 4)
	{	
		chance=0;
		neat(); cout << "---------------- STACK APPLICATION IS READY FOR DOUBLE  ----------------";
		obj4.ICFD(l);
		goto repeat1;
	}
	else if(exit == 5)
	{
terminate:
		neat(); cout << "THANKS FOR BEING HERE " ;
		neat(); cout << "PROCESS TERMINATING.....";
		neat();cout << "************************************************************************" << endl;	
		neat(); cout << endl;
		return 0;
	}
	else
	{
		if(chance < 2){
			neat(); cout << "YOU ENTERED WRONG KEY : " << 2-chance << " chances remaining." << endl;
			chance +=1;
			goto repeat;}
		else {
			neat(); cout << "SORRY YOU HAVE MADE MAXIMUM ATTEMPTS " << endl;
			goto terminate;}
	}

	neat();cout << "************************************************************************" << endl;	
}
