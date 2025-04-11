#include<stdio.h>https://github.com/EnnShaou/PG3.git
#include<Windows.h>



template<typename T>

/// <summary>
/// 2つの数値の最小値を求めるテンプレート関数
/// </summary>
/// <param name="num1">数字１</param>
/// <param name="num2">数字２</param>
T Min(T num1,T num2) {
	if (num1 < num2) {
		return num1;
	}
	else {
		return num2;
	}
}
template<>
/// <summary>
/// char型の特化版
/// </summary>
/// <param name="c1">文字１</param>
/// <param name="c2">文字２</param>
char Min<char>(char c1, char c2) {
	printf("数字以外代入できません\n");
	return c1;

}
int main(){

	printf("%d\n", Min<int>(11, 10));
	printf("%c\n", Min('b', 'a'));
	return 0;
}