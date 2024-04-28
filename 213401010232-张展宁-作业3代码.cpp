//����ʵ�������Ϊ���ʵ��һ�����ַ����ࡱ��Ҫ��ϵͳ��ƾ���һ�����ԺͿ���չ�ԣ�ʹ�ú���ά������չ���ܸ����ף�
// ���ӻ��޸�ϵͳ���ܱ�ø��򵥡�����Ҫ��͹������£�
//4������ַ��������ֱ�Ӹ�ֵ������
//10�������������������֤ǰ����д�ĸ����������ܡ���
#include<iostream>
#include<stdlib.h>
using namespace std;
class String
{	 
private:
	char* pdata;
public:
	String(); //�޲ι��캯�� 
	String(const char* pstr);//�вι��캯�� 
	String(int n);//�вι��캯��(�β�Ϊ����)
	String(const String& src);//�������캯��
	~String();//�������� 
public:
	int my_strlen(const char* str);//���ַ�������
	char* my_strcpy(char* pdata, const char* pstr);//�����ַ���
	int my_strstr(const char* str, const char *word);//�����ַ���
	const char* my_strinsert(const char* ret, int a, const char* str);//�Ӵ�����
	String& operator = (const String& src);//��ֵ���������

	void setout()
	{
		cout << pdata << endl;
	}
	
};
//�޲ι��캯�� 
String::String() : String(0)
{
	cout << "�޲ι��캯������" << endl;
}
//�вι��캯��(�β�Ϊ����)
String::String(int n)
{
	if (n == 0)
	{
		pdata = 0;
		return;
	}
	int a[100];
	int temp = 0;
	for (int i = 0; n != 0; i++)
	{
		a[i] = n % 10;
		n = n / 10;
		temp++;
	}
     char *w = new char[temp+1];
	for (int i = temp-1; i >= 0; i--)
	{
		w[i] = a[i] + '0';
		cout << w[i];
	}
	cout << endl << endl;
	cout << "�вι��캯���ĵ���" << endl;
}

//�вι��캯��
String::String(const char* pstr)
{
	if (pstr == NULL)
	{
		pdata = NULL;
		return;
	}
	else
    
		pdata = new char[my_strlen(pstr) + 1];
	if (pdata == NULL)
		return;
 	my_strcpy(pdata, pstr);
	cout << "�вι��캯������" << endl;
}
    
//�������캯��
String::String(const String& src)
{
	pdata = new char[my_strlen(src.pdata) + 1];
	my_strcpy(pdata, src.pdata);
	cout << "�������캯������" << endl;
}
//��ֵ
String& String::operator =(const String& src)
{
	if (this == &src)
	{
		return *this;
	}
	if (pdata != NULL)
		delete[]pdata;
	pdata = new char[my_strlen(src.pdata) + 1];
	my_strcpy(pdata, src.pdata);
	return *this;
}

//�������� 
String::~String()
{
	if (pdata == NULL)
		delete[]pdata;
	pdata = NULL;
	cout << "������������" << endl;
}
//���ַ�������
int String:: my_strlen(const char* str)
{
 	int count = 0;
 	while (*str++ != '\0')
 	{
 		count++;
 	}
 	return count;
}
 
//�����ַ���
char*String:: my_strcpy(char* pdata, const char* pstr)
{
 	char* ret = pdata;
 	int i = 0;
 	for (i = 0; pstr[i] != '\0'; i++)
 	{
 		ret[i] = pstr[i];
 	}
 	ret[i] ='\0';
 	return ret;
}
 
//�����ַ��� ��д�Ӵ����Һ����������Ӵ���Դ���е�һ�γ��ֵ�λ��
int String::my_strstr(const char* str,const char* word)
{
	int len1 = my_strlen(str);
	int len2 = my_strlen(word);
	int i = 0, j = 0;
	while (i <= len1 - 1 && j <= len2 - 1)
	{
		if (*(str + i) == *(word + j))
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j == len2)
	{
		return i-j+1;
	}
	else
		return NULL;
}

//��д�Ӵ����뺯������������Ĵ����������ֵ���Ӵ��������Ӵ����벢���ز������ַ�����
const char* String::my_strinsert(const char* ret, int a, const char* str)
{
	int length = my_strlen(ret)+ my_strlen(str); 
	int i = 0;
	int j = 0;
	int temp = 0;
	if (a <= 0 || a > my_strlen(ret))
	{
		return ret;
	}
	else
	{
		char* pdata = new char[length];
		
		for (i = 0;i<a-1;i++)
		{
			*(pdata + i) = *(ret + i);
		}
		for (i = a-1,j=0; j < my_strlen(str); i++,j++)
		{
			*(pdata + i) = *(str + j);
		}
		temp = i;
		for (i = temp,j=a-1; i < length; i++,j++)
		{
			*(pdata + i) = *(ret +j );
		}
		*(pdata + i) = '\0';
		return pdata;
		delete[]pdata;
	}
}
void test1()//�����ַ�����������
{
	cout << "����ϣ�����Ե���������" << endl;
	char w[100];
	char e[100];
	cin >> w >> e;
	String abcd(w);
	cout << "�Ӵ���λ�ã�" << abcd.my_strstr(w, e) << endl;
}
void test2()//�Ӵ����뺯������
{
	cout << "����ϣ�����Ե���������(�����뺯�� �������λ�ã����뺯��)" << endl;
	char w[100];
	char e[100];
	int n;
	cin >> w >> n >> e;
	String abcd(w);
	cout << "�������Ϊ��" << abcd.my_strinsert(w, n, e) << endl;
}
void test3()//�вι��캯��(����)����
{
	cout << "����ϣ�����Ե�һ�����ݣ����Σ�" << endl;
	int n;
	cin >> n;
	String w(n);
}
void test4()//�����ַ�����������
{
	cout << "����ϣ�����Ե��������ݣ����ڶ�����������һ����" << endl;
	char w[100];
	char e[100];
		cin >> w >> e;
	String abcd(w);
	cout << abcd.my_strcpy(w,e)<<endl;

}
void test5()//���ַ������Ⱥ�������
{
	cout << "����ϣ�����Ե�һ�����ݣ��ַ�����" << endl;
	char w[100];
	cin >> w;
	String q(w);
	cout << "���ַ�������Ϊ��" << q.my_strlen(w) << endl;

}
int main()
{
	cout << "������֤�����ַ��������������� 1��������֤�Ӵ����뺯���������� 2��������֤�вι��캯��(����)�������� 3��" << endl;
	cout << "������֤�����ַ��������������� 4��������֤���ַ������Ⱥ����������� 5" << endl;
	int n;
	cin >> n;
	if (n == 1)
	{
		test1();
	}
	else if (n == 2)
	{
		test2();
	}
	else if (n == 3)
	{
		test3();
	}
	else if (n == 4)
	{
		test4();
	}
	else if (n == 5)
	{
		test5();
	}
 	return 0;
 
}


