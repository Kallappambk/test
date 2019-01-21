#include<iostream>
//#include<string.h>
using namespace std;
//************************************************** STRING BASED FUCTIONS **************************************************************
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
//****************************************************  STRING CLASS *********************************************************************
class String
{
	char *p;
public :
	String()
	{
		p = new char[1];
		p[0] = '\0';
	}
	String (const char *str)
	{
		int i = strlen(str);
		//delete[] p;
		this->p = new char[i+1];
		strcpy(this->p,str);
	}

	//testig
	String (const String &str)
	{
		cout << "Called" << endl;
		int i = strlen(str.p);
		//delete[] p;
		this->p = new char[i+1];
		strcpy(this->p,str.p);
	}
	~String()
	{
		//cout << " ******** " << endl ; 
		delete p;
	}
	friend istream& operator >> (istream &,String &);
        friend ostream& operator << (ostream &,String &);	
	        String& operator =  (const String &); 
	        String& operator =  (const char *); 
	        String& operator += (const String &); 
	        String& operator += (const char *); 
	         String operator +  (const String &);
            	   void operator () (const char *);
	           void operator () (const String &);
		   bool	operator == (const String &);
		   bool	operator != (const String &);
		   bool operator >  (const String &);
		   bool operator >= (const String &);
		   bool operator <  (const String &); 
		   bool operator <= (const String &); 
	
	friend String& strcpy(String &,const String &);
	friend String& strcat(String &,const String &);
	friend String& strchr(const String &,const char );
	friend size_t  strlen(const String &);
	friend int     strcmp(const String &, const String &);

};
//********************************************* STRCHR() FUNCTION *************************************************************************
String& strchr(const String &s, const char ch)
{
	int i;
	for(i=0;s.p[i];i++)
	{
		if(s.p[i] == ch )
		{	cout << "CHARACTER FOUND " << endl;
		}
	}
	if(!s.p[i])
		cout << " NOT FOUND " << endl;
}
//********************************************* STRCAT() FUNCTION *************************************************************************
String& strcat(String &s1,const String &s2)
{
	String temp;
	int i,j;
	delete[] temp.p;
	temp.p =new char[strlen(s1)+1];
	strcpy(temp , s1);
	delete[] s1.p;
	s1.p = new char[strlen(temp)+strlen(s2)+1];
	for(i=0;temp.p[i];i++)
		s1.p[i]=temp.p[i];
	
	for(j=0;s2.p[j];i++,j++)
	{
		s1.p[i] = s2.p[j];
	}
	s1.p[i] = '\0';
	delete[] temp.p;
	return s1;
}
//********************************************** STRCPY() FUNCTION ***********************************************************************
String& strcpy(String &s1,const String &s2)
{
	int i;
	delete[] s1.p;
	s1.p = new char[strlen(s1)+1];
	for(i=0;s2.p[i];i++)
		s1.p[i] = s2.p[i];
	s1.p[i] = '\0';
	return s1;
}
//*********************************************** STRCMP() FUNCTION **********************************************************************
int strcmp(const String &s1,const String &s2)
{
	int i;
	for(i=0;s1.p[i];i++)
	{		
		if(s1.p[i] != s2.p[i])
			break;
	}
	if(s1.p[i] == s2.p[i])
		return 0;
	else if(s1.p[i] > s2.p[i])
		return 1;
	else
		return -1;
}
//*********************************************** STRLEN() FUNCTION *********************************************************************
size_t strlen(const String &str)
{
	int i;
	for(i=0;str.p[i];i++);
	return i;
}
//*********************************************** < OPERATOR ****************************************************************************
bool String::operator < (const String &str)
{
	int i;
	for(i=0;this->p[i];i++)
	{
		if(this->p[i] < str.p[i])
			return true;
		else if(this->p[i] == str.p[i])
			continue;
		else
			return false;
	}
	if(this->p[i] < str.p[i])
		return true;
	else
		return false;
	
}
//************************************************ <= OPERATOR **************************************************************************
bool String::operator <= (const String &str)
{
	int i;
	for(i=0;this->p[i];i++)
	{
		if(this->p[i] < str.p[i] || this->p[i] == str.p[i])
			continue;
		else
			return false;
	}
	if(this->p[i] < str.p[i] || this->p[i] == str.p[i])
		return true;
	else
		return false;
}
//************************************************ > OPERATOR ***************************************************************************
bool String::operator > (const String &str)
{
	int i;
	for(i=0;this->p[i];i++)
	{
		if(this->p[i] > str.p[i])
			return true;
		else if(this->p[i] == str.p[i])
			continue;
		else
			return false;
	}
	if(this->p[i] > str.p[i])
		return true;
	else
		return false;
}	
//************************************************ >= OPERATOR *************************************************************************
bool String::operator >= (const String &str)
{
	int i;
	for(i=0;this->p[i];i++)
	{
		if(this->p[i] > str.p[i] || this->p[i] == str.p[i])
			continue;
		else
			return false;
	}
	if(this->p[i] > str.p[i] || this->p[i] == str.p[i])
		return true;
	else
		return false;

}	
//************************************************ != OPERATOR *************************************************************************
bool String::operator != (const String &str)
{
	int i;
	for(i=0;this->p[i];i++)
	{
		if(this->p[i]!=str.p[i])
			return true;
	}
	if(this->p[i]!=str.p[i])
		return true;
	else 
		return false;
}
//************************************************* == OPERATOR *************************************************************************
bool String::operator == (const String &str)
{
	int i;
	for(i=0;this->p[i];i++)
	{
		if(this->p[i]!=str.p[i])
			break;
	}
	if(this->p[i]==str.p[i])
		return true;
	else 
		return false;
}
//************************************************** += OPERATOR ************************************************************************
String& String::operator +=  (const String &str)
{
	String *ret;
	ret = new String;
	delete[] ret->p;
	ret->p = new char[strlen(this->p)+1];
	strcpy(ret->p,this->p);
	delete[] this->p;
	this->p = new char[strlen(ret->p)+strlen(str.p)+1];
	strcpy(this->p,ret->p);
	delete ret;
	strcat(this->p,str.p);
	return *this;
}	
//************************************************** += OPERATOR ***********************************************************************
String& String::operator +=  (const char *str)
{
	String *ret;
	ret = new String;
	delete[] ret->p;
	ret->p = new char[strlen(this->p)+1];
	strcpy(ret->p,this->p);
	delete[] this->p;
	this->p = new char[strlen(ret->p)+strlen(str)+1];
	strcpy(this->p,ret->p);
	delete ret;
	strcat(this->p,str);
	return *this;
}	
//************************************************** + OPERATOR *************************************************************************
String String::operator + (const String &str)
{
	String *ret;
	ret = new String;
	delete[] ret->p;
	ret->p = new char[strlen(this->p)+strlen(str.p)+1];
	strcpy(ret->p,this->p);
	strcat(ret->p,str.p);
	return *ret;
}
//*************************************************** = OPERATOR ************************************************************************
String& String::operator = (const char *str)
{
	int i = strlen(str);
	delete[] this->p;
	p = new char [i+1];
	strcpy(this->p,str);
	return *this;
}	
//**************************************************** = OPERATOR ***********************************************************************
String& String::operator = (const String &str)
{
	int i = strlen(str.p);
	delete[] this->p;
	p = new char [i+1];
	strcpy(this->p,str.p);
	return *this;
}	
//**************************************************** () OPERATOR **********************************************************************
void String::operator () (const char *str)
{
	int i = strlen(str);
	delete[] this->p;
	this->p = new char[i+1];
	strcpy(this->p,str);
}
//***************************************************** () OPERATOR ********************************************************************
void String::operator () (const String &str)
{
	int i = strlen(str.p);
        delete[] this->p;
        this->p = new char[i+1];
        strcpy(this->p,str.p);
}
//****************************************************** EXTRACTION OOPERATOR **********************************************************
istream& operator >> (istream &in,String &str)
{
	delete[] str.p;
	FILE *fp;
	char ch;
	int cnt,i=0;
	fp = fopen("temp","w+");
	while((ch=getchar())!='\n')
		fputc(ch,fp);

	cnt = ftell(fp);
	rewind(fp);
	str.p = new char[cnt+1];
	while((ch=fgetc(fp))!=EOF)
		str.p[i++]=ch;
	str.p[i] = '\0';
	remove("temp");
	return in;		
}
//******************************************************* INSERTION OPERATOR ***********************************************************
ostream& operator << (ostream &out,String &str)
{
	out << str.p;
	return out;
}
//******************************************************** MAIN() FUNCTION *************************************************************
int main()
{
	String s1,s2,s3,s4,s5(s1);
	cout << "Enter String s1 : " ;
	cin  >> s1;
	s2 = s1;
	s3 = "Bachagundi\n";
	s4("INDIA");	

	cout << "s1 : " << s1 << endl;
	cout << "S2 : " << s2 << endl;
	cout << "S3 : " << s3 << endl;
	cout << "S4 : " << s4 << endl;
	cout << "S5 : " << s5 << endl;


}
//********************************************************  PROTOTYPES ****************************************************************
/*
cin  >> s1; 	// cin.operator >> (s1); 	==> friend istream& operator >> (&cin ,&s1); 
cout << s1; 	//cout.operator << (s1); 	==> friend ostream& operator << (&cout ,&s1); 
s2(s1)  	//  s2.operator () (&s1) 	==>    void String::operator () (&s2,&s1);
s1("kallappa")  //  s1.operator () ("kallappa") ==>    void String::operator () (&s1,"kallappa");
s1 = "kallappa" //  s1.operator =  ("kallappa") ==> String& String::operator =  (&s1,"kallappa");
s2 = s1 	//  s2.operator =  (&s1) 	==> String& String::operator =  (&s2,&s1);
s3 +=  s2	//  s3.operator += (&s2) 	==> string& string::operator =  (&s3,&s2);
s3 = s1 + s2	//  s1.operator +  (&s2) 	==>  string string::operator =  (&s1,&s2);
s1 == s2	//  s1.operator == (&s2) 	==>    bool String::operator == (&s1,&s2);
s1 != s2	//  s1.operator != (&s2) 	==>    bool String::operator != (&s1,&s2);
s1 > s2		//  s1.operator >  (&s2) 	==>    bool String::operator >  (&s1,&s2);
s1 >= s2	//  s2.operator >= (&s2) 	==>    bool String::operator >= (&s1,&s2);
s1 < s2		//  s1.operator <  (&s2)        ==>    bool String::operator <  (&s1,&s2);
s1 <= s2	//  s1.operator <= (&s2)	==>    bool String::operator <= (&s1,&s2);
*/
