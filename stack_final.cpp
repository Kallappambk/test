#include<iostream>
#include<clocale>
#include<cstdlib>
#define MAX 5
#define RED "\033[31m"
#define RST "\033[0m"
#define GRE "\033[32m"
#define BLU "\033[34m"
#define BLA "\033[30m"
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
		{	i=0;
			for(i=0;i<MAX;i++)
				s[i] = 0;
			i=0;
		}
		else if(rep == 'y' || rep == 'Y')
			i = i;
		else
		{
			cout << RED;
			neat(); cout << "Please enter correct option .... ";
			cout << RST;
			if(z < 2)
				goto take;
			else
			{	cout << RED;
				neat(); cout << "SORRY YOU CROSSED MAXIMUM LIMITS ";
				cout << RST;
				return;
			}
		}
	}
above :
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
			cout << RED;
			neat();	cout << "************************************************************************";
			neat();	cout << "*************************** STACK OVERFLOW *****************************";
			neat();	cout << "************************************************************************";
			neat(); cout << RST;
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
			cout << RED;
			neat();	cout << "************************************************************************";
			neat();	cout << "************************** STACK UNDERFLOW *****************************";
			neat();	cout << "************************************************************************";
			neat(); cout << RST;  
			neat(); cout << "Do you want continue ..... : Y/N ";
			neat();  cin >> rep;
			if(rep == 'y' || rep == 'Y')
				goto above;
			else
				return;
		}
		--i;
		neat(); cout << s[i] <<" - is Deleted " ;
		s[i] = 0;
		goto above;
	}
	else if(op == 3)
	{
		chance = 0;
		system("clear");
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
			cout << RED;
			neat(); cout << "WRONG OPTION : " << 2-chance << " chances remaining." << endl;
			chance +=1;
			cout << RST;
			goto above;
		}
		else 
		{
			cout << RED;
			neat(); cout << "SORRY YOU HAVE MADE MAXIMUM ATTEMPTS " << endl;
			cout << RST;
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
		cout << RED;
		if(chance < 2)
		{
			system("clear");
			neat(); cout << "YOU ENTERED WRONG KEY : " << 2-chance << " chances remaining." << endl;
			cout << RST;
			chance +=1;
			goto repeat;
		}
		else 
		{
			system("clear");
			neat(); cout << "SORRY YOU HAVE MADE MAXIMUM ATTEMPTS " << endl;
			cout << RST;
			goto terminate;
		}
		cout << RST;
	}
}
