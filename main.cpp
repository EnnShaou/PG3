#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include <time.h>
#include<functional>


using namespace std;

int main() {

	//乱数の初期化
	srand(unsigned int(time(0)));
	int isEnd = 1;
	int playerJudgment = 0;//プレイヤーの予想
	// 判定処理（丁半判定）
	function<void(int*, int*)> pFunc = [](int* pResult, int* playerJudgment) {
		printf("サイコロの目は%d\n", *pResult);
		if (*pResult % 2 == 0 && *playerJudgment == 2 ||
			*pResult % 2 != 0 && *playerJudgment == 1) {
			printf("おめでとう！\n");
		}
		else {
			printf("残念！\n");
		}
		};

	// サイコロを振る関数：引数はプレイヤーの予想だけ
	function<void(int)> Dice = [&pFunc](int player) {
		int dice = rand() % 6 + 1;
		printf("サイコロが回転しています！！\n");
		Sleep(3 * 1000);
		pFunc(&dice, &player);
		};
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
			Dice(playerJudgment);//サイコロを振る関数を呼び出す
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
