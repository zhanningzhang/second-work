//本次实验的任务为设计实现一个“字符串类”，要求系统设计具有一定弹性和可扩展性，使得后续维护和扩展功能更容易，
// 增加或修改系统功能变得更简单。基本要求和功能如下：
//4、完成字符串类对象直接赋值操作。
//10、独立设计主函数，验证前面所写的各个函数功能。。
#include<iostream>
#include<stdlib.h>
using namespace std;
class String
{	 
private:
	char* pdata;
public:
	String(); //无参构造函数 
	String(const char* pstr);//有参构造函数 
	String(int n);//有参构造函数(形参为整形)
	String(const String& src);//拷贝构造函数
	~String();//析构函数 
public:
	int my_strlen(const char* str);//求字符串长度
	char* my_strcpy(char* pdata, const char* pstr);//拷贝字符串
	int my_strstr(const char* str, const char *word);//查找字符串
	const char* my_strinsert(const char* ret, int a, const char* str);//子串插入
	String& operator = (const String& src);//赋值运算符重载

	void setout()
	{
		cout << pdata << endl;
	}
	
};
//无参构造函数 
String::String() : String(0)
{
	cout << "无参构造函数调用" << endl;
}
//有参构造函数(形参为整形)
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
	cout << "有参构造函数的调用" << endl;
}

//有参构造函数
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
	cout << "有参构造函数调用" << endl;
}
    
//拷贝构造函数
String::String(const String& src)
{
	pdata = new char[my_strlen(src.pdata) + 1];
	my_strcpy(pdata, src.pdata);
	cout << "拷贝构造函数调用" << endl;
}
//赋值
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

//析构函数 
String::~String()
{
	if (pdata == NULL)
		delete[]pdata;
	pdata = NULL;
	cout << "析构函数调用" << endl;
}
//求字符串长度
int String:: my_strlen(const char* str)
{
 	int count = 0;
 	while (*str++ != '\0')
 	{
 		count++;
 	}
 	return count;
}
 
//拷贝字符串
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
 
//查找字符串 编写子串查找函数，查找子串在源串中第一次出现的位置
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

//编写子串插入函数，根据输入的待插入的索引值和子串，将该子串插入并返回插入后的字符串。
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
void test1()//查找字符串函数测试
{
	cout << "输入希望测试的两个数据" << endl;
	char w[100];
	char e[100];
	cin >> w >> e;
	String abcd(w);
	cout << "子串的位置：" << abcd.my_strstr(w, e) << endl;
}
void test2()//子串插入函数测试
{
	cout << "输入希望测试的三个数据(被插入函数 ，插入的位置，插入函数)" << endl;
	char w[100];
	char e[100];
	int n;
	cin >> w >> n >> e;
	String abcd(w);
	cout << "插入后结果为：" << abcd.my_strinsert(w, n, e) << endl;
}
void test3()//有参构造函数(整形)测试
{
	cout << "输入希望测试的一个数据（整形）" << endl;
	int n;
	cin >> n;
	String w(n);
}
void test4()//拷贝字符串函数测试
{
	cout << "输入希望测试的两个数据（将第二个拷贝给第一个）" << endl;
	char w[100];
	char e[100];
		cin >> w >> e;
	String abcd(w);
	cout << abcd.my_strcpy(w,e)<<endl;

}
void test5()//求字符串长度函数测试
{
	cout << "输入希望测试的一个数据（字符串）" << endl;
	char w[100];
	cin >> w;
	String q(w);
	cout << "该字符串长度为：" << q.my_strlen(w) << endl;

}
int main()
{
	cout << "如需验证查找字符串函数，请输入 1；如需验证子串插入函数，请输入 2；如需验证有参构造函数(整形)，请输入 3；" << endl;
	cout << "如需验证拷贝字符串函数，请输入 4；如需验证求字符串长度函数，请输入 5" << endl;
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


