#include<iostream>
using namespace std;
#include<string>
#define MAX 1000 //ͨѶ¼�����Ա

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
	cout << "***** 1--�����ϵ�� *****" << endl;
	cout << "***** 2--��ʾ��ϵ�� *****" << endl;
	cout << "***** 3--ɾ����ϵ�� *****" << endl;
	cout << "***** 4--������ϵ�� *****"<< endl;
	cout << "***** 5--�޸���ϵ�� *****" << endl;
	cout << "***** 6--�����ϵ�� *****" << endl;
	cout << "***** 0--�˳�ͨѶ¼ *****" << endl;
	cout << "*************************" << endl;
}

// �����ϵ��

void addPersion(Addressbooks* abs)
{
	//�ж��Ƿ���
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�Ѿ������޷����" << endl;
		return;
	}
	else
	{
		//�����ϵ��
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//�Ա�
		int sex = 0;
		cout << "�����ձ�1-Ů��2-��" << endl;
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
				cout << "����������" << endl;
			}
		}
		//����
		int age;
		cout << "�������䣺" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//�ֻ���
		string phone;
		cout << "����绰�ţ�" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//��ַ
		string addr;
		cout << "�����ַ��" << endl;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;
		//����ͨѶ¼����
		abs->m_Size++;
		cout << "��ǰͨѶ¼����:" << abs->m_Size << endl;
		cout << "��ӳɹ���" << endl;
		system("pause");
		system("cls");//��������
	}

}
//��ʾ��ϵ��
void showPerson(Addressbooks *abs)
{
	if (abs->m_Size == 0)
	{
		cout << "��ǰͨѶ¼Ϊ��" << endl;
		system("pause");
		system("cls");//��������
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "Ů":"��" )<< "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�ֻ��ţ�" << abs->personArray[i].m_Phone << "\t";
			cout << "��ַ��" << abs->personArray[i].m_Addr << endl;
		}
		system("pause");
		system("cls");//��������
	}

}

//�����ϵ��
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
	cout << "������Ҫɾ������ϵ������" << endl;
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
			abs->personArray[i] = abs->personArray[i + 1];//����ǰ��
		}
		abs->m_Size -= 1;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
		return;
	}
	system("pause");
	system("cls");
}

void searchPerson(Addressbooks *abs)
{
	string name;
	cout << "������Ҫ���ҵ���ϵ������" << endl;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret != -1)
	{
		cout << "��ϵ�����ҵ�" << endl;
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "Ů" : "��") << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�ֻ��ţ�" << abs->personArray[ret].m_Phone << "\t";
		cout << "��ַ��" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks *abs)
{
	string name;
	cout << "������Ҫ�޸ĵ���ϵ������" << endl;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret != -1)
	{
		cout << "��ϵ�����ҵ�" << endl;
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "Ů" : "��") << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�ֻ��ţ�" << abs->personArray[ret].m_Phone << "\t";
		cout << "��ַ��" << abs->personArray[ret].m_Addr << endl;

		//�����ϵ��
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//�Ա�
		int sex = 0;
		cout << "�����ձ�1-Ů��2-��" << endl;
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
				cout << "����������" << endl;
			}
		}
		//����
		int age;
		cout << "�������䣺" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//�ֻ���
		string phone;
		cout << "����绰�ţ�" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//��ַ
		string addr;
		cout << "�����ַ��" << endl;
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void cleanPerson(Addressbooks *abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}

int main()
{
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//����
	abs.m_Size = 0;
	int select = 0;

	while (true)
	{
		//���ò˵�����ʾ
		showMenu();
		cin >> select;
		switch (select)
		{
		    case 0:
				cout << "��ӭ�´�ʹ��" << endl;
				system("pause");
				return 0;
				break;
			case 1:
				addPersion(&abs); //�����ַ�����������޸�ͨѶ¼
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