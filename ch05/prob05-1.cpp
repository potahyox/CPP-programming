#include <iostream>
using namespace std;

namespace COMP_POS
{
	enum { CLERK, SENIOR, ASSIST, MANAGER };

	void ShowPositionInfo(int pos)
	{
		switch (pos)
		{
		case CLERK:
			cout << "사원" << endl;
			break;
		case SENIOR:
			cout << "주임" << endl;
			break;
		case ASSIST:
			cout << "대리" << endl;
			break;
		case MANAGER:
			cout << "과장" << endl;
		}
	}
}

class NameCard
{
private:
	char* name;
	char* comName;
	char* phoneNum;
	int level;

public:
	NameCard(const char* myname, const char* mycomName, const char* myphoneNum, int mylevel)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		//cout << "초기화1" << endl;

		len = strlen(mycomName) + 1;
		comName = new char[len];
		strcpy(comName, mycomName);

		len = strlen(myphoneNum) + 1;
		phoneNum = new char[len];
		strcpy(phoneNum, myphoneNum);

		level = mylevel;
	}
	NameCard(const NameCard& ref) : level(ref.level)
	{
		name = new char[strlen(ref.name) + 1];
		comName = new char[strlen(ref.comName) + 1];
		phoneNum = new char[strlen(ref.phoneNum) + 1];
		strcpy(name, ref.name);
		strcpy(comName, ref.comName);
		strcpy(phoneNum, ref.phoneNum);
	}
	void ShowNameCardInfo()
	{
		cout << "이름: " << name << endl;
		cout << "회사: " << comName << endl;
		cout << "전화번호: " << phoneNum << endl;
		cout << "직급: "; COMP_POS::ShowPositionInfo(level);
		cout << endl;
	}

	~NameCard()
	{
		delete[] name;
		delete[] comName;
		delete[] phoneNum;
	}
};

int main(void)
{
	//cout << "main:시작" << endl;
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSENIOR;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();
	return 0;
}
