#include<stdio.h>https://github.com/EnnShaou/PG3-0-0.git
#include<Windows.h>

//一般的な貸金計算関数
//この関数は、時間が0以下の場合は0を返し、それ以外の場合は、給与と時間を引数にして、給与を加算していく再帰的な計算を行います。
//引数のsalaryは給与、hoursは時間を表します。
int GeneralSalary(int salary,int hours) {
	if (hours<=0)
	{
		return 0;
	}
	return (salary+GeneralSalary(salary, hours-1));
}
//再帰的な貸金計算関数
//この関数は、時間が0以下の場合は0を返し、それ以外の場合は、給与と時間を引数にして、給与を2倍にして50を引いた値を再帰的に計算します。
//引数のsalaryは給与、hoursは時間を表します。
int ReturnSalary(int salary, int hours) {
	if (hours <= 0)
	{
		return 0;
	}
	return (salary + ReturnSalary(salary*2-50, hours - 1));
}

int main(){
	
	int hours = 0;
	//一般的な貸金計算関数と再帰的な貸金計算関数を比較するためのループ
	while(1) {
		hours++;
		printf("%d\n", GeneralSalary(1024, hours));
		printf("%d\n", ReturnSalary(100, hours));
		if (GeneralSalary(1024, hours)< ReturnSalary(100, hours))
		{
			printf("%d", hours);
			break;
		}

	}
	
	return 0;
}