#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include <time.h>

//サイコロの目を判定する関数のプロトタイプ宣言
typedef void(PFunc)(int*,int*);
//サイコロを振る関数
void Dice(PFunc* pResult, int player);
//サイコロの目を判定する関数
void Judgment(int* pResult, int* playerJudgment);


int main(){

	//乱数の初期化
	srand(unsigned int(time(0)));
	int isEnd = 1;
	int playerJudgment = 0;//プレイヤーの予想
	PFunc* pFunc;//関数ポインタの宣言
	pFunc = Judgment;//関数ポインタに関数を代入
	while (1)
	{
		printf("サイコロを振りますか？\n");
		printf("1:振る 2:終了\n");
		scanf_s("%d", &isEnd);
		if (isEnd == 1) {
			printf("サイコロは半なのか丁なのか予想してください\n");
			while (1) {
				printf("1:半 2:丁\n");
				scanf_s("%d", &playerJudgment);
				if (playerJudgment != 1 && playerJudgment != 2) {
					printf("無効な選択です\n");
					continue;
				}
				else break;
			}
			Dice(pFunc, playerJudgment);//サイコロを振る関数を呼び出す
		}
		else if (isEnd == 2) {
			printf("終了します\n");
			break;
		}
		else {
			printf("無効な選択です\n");
		}
	}
	return 0;
}
void Judgment(int* pResult,int*playerJudgment) {
	printf("サイコロの目は%d", *pResult);
	if(*pResult%2==0&&*playerJudgment==2||
		*pResult%2!=0&&*playerJudgment==1)
	{
		printf("おめでとう！\n");
	}
	else
	{
		printf("残念！\n");
	}
}
void Dice(PFunc* pResult, int player)
{
	int dice = rand() % 6 + 1;//サイコロの目を生成
	printf("サイコロが回転しています！！\n");
	Sleep(3 * 1000);//3秒待つ
	pResult(&dice,&player);
}