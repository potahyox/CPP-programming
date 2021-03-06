#include <iostream>
#include <string>
using namespace std;

class String
{
private:
	char* str;
public:
	String() {
		str = new char[0];
	}
	String(const char* input)
	{
		str = new char[strlen(input) + 1];
		strcpy(str, input);
	}
	String(const String& ref)
	{
		str = new char[strlen(ref.str) + 1];
		strcpy(str, ref.str);
	}
	String operator+(String& ref)
	{
		int len = strlen(str) + strlen(ref.str) - 1;
		char* str1 = new char[len];
		strcpy(str1, str);
		strcat(str1, ref.str);

		String obj(str1);

		return obj;
	}
	String& operator+=(String& ref)
	{
		int len = strlen(str) + strlen(ref.str) + 1;
		char* str1 = new char[len];
		
		delete[] str;
		str = str1;

		return *this;
	}
	String& operator=(const String& ref)
	{
		if(str!=NULL)
			delete[] str;
		
		str = new char[strlen(ref.str) + 1];
		strcpy(str, ref.str);
		return *this;
	}
	bool operator==(const String& ref)
	{

	}

	friend ostream& operator<<(ostream& os, String& ref);
	friend istream& operator>>(istream& is, String& ref);
	~String()
	{
		if(str!=NULL)
			delete[] str;
	}
};

ostream& operator<<(ostream& os, String& ref)
{
	os << ref.str;
	return os;
}
istream& operator>>(istream& is, String& ref)
{
	char str[100];
	is >> str;
	ref = String(str);
	return is;
}


int main(void)
{
	String str1 = "I like ";
	String str2 = "string class";
	String str3 = str1 + str2;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	//str1 += str2;
	//if (str1 == str3)
	//	cout << "동일 문자열!" << endl;
	//else
	//	cout << "동일하지 않은 문자열!" << endl;

	String str4;
	cout << "문자열 입력: ";
	cin >> str4;
	cout << "입력한 문자열: " << str4 << endl;
	return 0;
}
