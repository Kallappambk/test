#include<iostream>
#include<stdio.h>
using namespace std;

		size_t strlen(const char *p)
		{
			size_t i;
			for(i=0;p[i];i++);
			return i;
		}
		int strcmp(const char* s1,const char* s2)
		{
			size_t i;
			for(i=0;s1[i];i++)
				if(s1[i] != s2[i])
					break;

			if(s1[i] == s2[i])
				return 0;
			else if(s1[i] > s2[i])
				return 1;
			else
				return -1;
		}
		char*  strcpy(char* s1,const char* s2)
		{
			int i,j;
			delete s1;
			s1 = new char[strlen(s2)+1];
			for(i=0;s2[i];i++)
				s1[i] = s2[i];
			s1[i] = '\0';
			return s1;
		}
		char*  strcat(char* s1,const char* s2)
		{
			int i,j;
			char *p = new char[strlen(s1)+1];
			strcpy(p,s1);
			delete[] s1;
			s1 = new char[strlen(p)+strlen(s2)+1];
			for(i=0;p[i];i++)
				s1[i] = p[i];
			for(j=0;s2[j];i++,j++)
				s1[i] = s2[j];
			s1[i] = '\0';

			return s1;
		}

int main()
{
	char *c1,*c2;
	c1 = new char[20];
	c2 = new char[30];	
	cin >> c1;
	cin >> c2;

	cout << c1 << endl;
	cout << c2 << endl;
	cout << strlen(c1) << endl;
	cout << strlen(c2) << endl;
	cout << strcmp(c1,c2) << endl;

	cout << strcpy(c1,c2) << endl;
	cout << strcat(c1,"AB")<< endl;
}
