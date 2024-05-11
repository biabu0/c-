#include<iostream>
using namespace std;
#include<string>
#define MAX 1000 //通讯录最多人员

struct Persion
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};

struct Addressbooks 
{
	struct Persion personArray[MAX];
	int m_Size;
};

void showMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1--添加联系人 *****" << endl;
	cout << "***** 2--显示联系人 *****" << endl;
	cout << "***** 3--删除联系人 *****" << endl;
	cout << "***** 4--查找联系人 *****"<< endl;
	cout << "***** 5--修改联系人 *****" << endl;
	cout << "***** 6--清空联系人 *****" << endl;
	cout << "***** 0--退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}

// 添加联系人

void addPersion(Addressbooks* abs)
{
	//判断是否满
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已经满，无法添加" << endl;
		return;
	}
	else
	{
		//添加联系人
		string name;
		cout << "输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//性别
		int sex = 0;
		cout << "输入姓别：1-女，2-男" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "请重新输入" << endl;
			}
		}
		//年龄
		int age;
		cout << "输入年龄：" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//手机号
		string phone;
		cout << "输入电话号：" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//地址
		string addr;
		cout << "输入地址：" << endl;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;
		//更新通讯录人数
		abs->m_Size++;
		cout << "当前通讯录人数:" << abs->m_Size << endl;
		cout << "添加成功！" << endl;
		system("pause");
		system("cls");//清屏操作
	}

}
//显示联系人
void showPerson(Addressbooks *abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前通讯录为空" << endl;
		system("pause");
		system("cls");//清屏操作
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "女":"男" )<< "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "手机号：" << abs->personArray[i].m_Phone << "\t";
			cout << "地址：" << abs->personArray[i].m_Addr << endl;
		}
		system("pause");
		system("cls");//清屏操作
	}

}

//检测联系人
int isExit(Addressbooks *abs, string name)
{

	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}

	return -1;
}



void DelectPerson(Addressbooks* abs)
{
	string name;
	cout << "请输入要删除的联系人姓名" << endl;
	cin >> name;
	int ret = isExit(abs,name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			//abs->personArray[i].m_Name = abs->personArray[i + 1].m_Name;
			//abs->personArray[i].m_Addr = abs->personArray[i + 1].m_Addr;
			//abs->personArray[i].m_Age = abs->personArray[i + 1].m_Age;
			//abs->personArray[i].m_Phone = abs->personArray[i + 1].m_Phone;
			//abs->personArray[i].m_Sex = abs->personArray[i + 1].m_Sex;
			abs->personArray[i] = abs->personArray[i + 1];//数据前移
		}
		abs->m_Size -= 1;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
		return;
	}
	system("pause");
	system("cls");
}

void searchPerson(Addressbooks *abs)
{
	string name;
	cout << "请输入要查找的联系人姓名" << endl;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret != -1)
	{
		cout << "联系人已找到" << endl;
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "女" : "男") << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "手机号：" << abs->personArray[ret].m_Phone << "\t";
		cout << "地址：" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks *abs)
{
	string name;
	cout << "请输入要修改的联系人姓名" << endl;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret != -1)
	{
		cout << "联系人已找到" << endl;
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "女" : "男") << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "手机号：" << abs->personArray[ret].m_Phone << "\t";
		cout << "地址：" << abs->personArray[ret].m_Addr << endl;

		//添加联系人
		string name;
		cout << "输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//性别
		int sex = 0;
		cout << "输入姓别：1-女，2-男" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "请重新输入" << endl;
			}
		}
		//年龄
		int age;
		cout << "输入年龄：" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//手机号
		string phone;
		cout << "输入电话号：" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//地址
		string addr;
		cout << "输入地址：" << endl;
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void cleanPerson(Addressbooks *abs)
{
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}

int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;
	//个数
	abs.m_Size = 0;
	int select = 0;

	while (true)
	{
		//调用菜单的显示
		showMenu();
		cin >> select;
		switch (select)
		{
		    case 0:
				cout << "欢迎下次使用" << endl;
				system("pause");
				return 0;
				break;
			case 1:
				addPersion(&abs); //传入地址才能真正的修改通讯录
				break;
			case 2:
				showPerson(&abs);
				break;
			case 3:
				DelectPerson(&abs);
				break;
			case 4:
				searchPerson(&abs);
				break;
			case 5:
				modifyPerson(&abs);
				break;
			case 6:
				cleanPerson(&abs);
				break;
			defulat:
				break;
		}

	}
	


	system("pause");
	return 0;
}