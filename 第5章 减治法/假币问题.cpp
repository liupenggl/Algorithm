#include <iostream.h>
const int N = 8;                       //�������8öӲ������
int a[N] = {2, 2,  2, 2, 2,1, 2, 2}; 
int Coin(int low, int high, int n);

int main()
{
	int i=Coin(0,7,8);
	cout<<"�ٱ��ǵ�"<<i<<"��"<<endl;
	return 0;
}//��ҵ�������2���ٱҵ�������1
int Coin(int low, int high, int n)           //��a[low]~a[high]�в��Ҽٱ�
{
	int i, num1, num2, num3;      // num1��num2��num3�洢3��Ӳ�ҵĸ���
	int add1 = 0, add2 = 0;        //add1��add2�洢ǰ����Ӳ�ҵ�������
	if (n == 1)                              //�ݹ����������
		return low + 1;                         //���ص�����ţ����±��1
	if (n % 3 == 0)                           //3��Ӳ�ҵĸ�����ͬ
		num1 = num2 = n / 3;
	else                                    //ǰ������ öӲ��
		num1 = num2 = n / 3 + 1;
	num3 = n - num1 - num2;
	for (i = 0; i < num1; i++)                    //�����1��Ӳ�ҵ�������
		add1 = add1 + a[low + i];
	for (i = num1; i < num1 + num2; i++)          //�����2��Ӳ�ҵ�������
		add2 = add2 + a[low + i];
	if (add1 < add2)             //�ڵ�1����ң��±귶Χ��low~low+num1-1
		return Coin(low, low + num1 - 1, num1);
	else if (add1 > add2)  //�ڵ�2����ң��±귶Χlow+num1~low+num1+num2-1
		 return Coin(low + num1, low + num1 + num2 - 1, num2);
	else                 //�ڵ�3����ң��±귶Χlow+num1+num2~high
		Coin(low + num1 + num2, high, num3);
}
