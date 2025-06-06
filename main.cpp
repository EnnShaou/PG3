#include<stdio.h>
#include<Windows.h>
#include<list>
#include<map>

// 1970山手線の駅
const char* yamanoteLine1970[] = {
	{"品川"},
	{"大崎"},
	{"五反田"},
	{"目黒"},
	{"恵比寿"},
	{"渋谷"},
	{"原宿"},
	{"代々木"},
	{"新宿"},
	{"新大久保"},
	{"高田馬場"},
	{"目白"},
	{"池袋"},
	{"大塚"},
	{"巣鴨"},
	{"駒込"},
	{"田端"},
	{"日暮里"},
	{"鶯谷"},
	{"上野"},
	{"御徒町"},
	{"秋葉原"},
	{"神田"},
	{"東京"},
	{"有楽町"},
	{"新橋"},
	{"浜松町"},
	{"田町"}
};
// 2019年の山手線の駅
const char* yamanoteLine2019[] = {
	{"品川"},
	{"田町"},
	{"浜松町"},
	{"新橋"},
	{"有楽町"},
	{"東京"},
	{"神田"},
	{"秋葉原"},
	{"御徒町"},
	{"上野"},
	{"鶯谷"},
	{"日暮里"},
	{"西日暮里"},
	{"田端"},
	{"駒込"},
	{"巣鴨"},
	{"大塚"},
	{"池袋"},
	{"目白"},
	{"高田馬場"},
	{"新大久保"},
	{"新宿"},
	{"代々木"},
	{"原宿"},
	{"渋谷"},
	{"恵比寿"},
	{"目黒"},
	{"五反田"},
	{"大崎"}
};
//2022年の山手線の駅
const char* yamanoteLine2022[] = {
	{"品川"},
	{"高輪ゲートウェイ"},
	{"田町"},
	{"浜松町"},
	{"新橋"},
	{"有楽町"},
	{"東京"},
	{"神田"},
	{"秋葉原"},
	{"御徒町"},
	{"上野"},
	{"鶯谷"},
	{"日暮里"},
	{"西日暮里"},
	{"田端"},
	{"駒込"},
	{"巣鴨"},
	{"大塚"},
	{"池袋"},
	{"目白"},
	{"高田馬場"},
	{"新大久保"},
	{"新宿"},
	{"代々木"},
	{"原宿"},
	{"渋谷"},
	{"恵比寿"},
	{"目黒"},
	{"五反田"},
	{"大崎"}
};

int main() {

	while (1)
	{
		// 山手線の駅一覧を表示するプログラム

		std::map<int, std::list<const char*>> yamanoteLineMap;// 年ごとの山手線の駅一覧を格納するマップ
		// 1970年、2019年、2022年の山手線の駅一覧をマップに格納
		yamanoteLineMap[1970] = std::list<const char*>(yamanoteLine1970, yamanoteLine1970 + sizeof(yamanoteLine1970) / sizeof(yamanoteLine1970[0]));
		yamanoteLineMap[2019] = std::list<const char*>(yamanoteLine2019, yamanoteLine2019 + sizeof(yamanoteLine2019) / sizeof(yamanoteLine2019[0]));
		yamanoteLineMap[2022] = std::list<const char*>(yamanoteLine2022, yamanoteLine2022 + sizeof(yamanoteLine2022) / sizeof(yamanoteLine2022[0]));
		//
		int year;// ユーザーが表示したい年を入力する変数
		printf("山手線の駅何年の一覧を表示しますか。\n");
		scanf_s("%d", &year);
		
		if (year != 1970 && year != 2019 && year != 2022)
		{
			printf("山手線の駅は1970年、2019年、2022年のいずれかの年の駅一覧しかありません。\n");
			continue;
		}
		if (year == 1970)
		{
			printf("1971年西日暮里開業、挿入するか？\n");
			printf("y/n\n");
			char insert;
			scanf_s(" %c", &insert, 1);
			if (insert == 'y' || insert == 'Y')
			{
				// 1971年の西日暮里駅を1970年の駅一覧に挿入
				yamanoteLineMap[1970].insert(std::next(yamanoteLineMap[1970].begin(), 11), "西日暮里");
				printf("1971年西日暮里を挿入しました。\n");
			}
			else
			{

				printf("1971年西日暮里を挿入しませんでした。\n");
			}
		}
		if (year == 2019)
		{
			printf("2020年高輪ゲートウェイ開業、挿入するか？\n");
			printf("y/n\n");
			char insert;
			scanf_s(" %c", &insert, 1);
			if (insert == 'y' || insert == 'Y')
			{
				// 2020年の高輪ゲートウェイ駅を2019年の駅一覧に挿入
				yamanoteLineMap[2019].insert(std::next(yamanoteLineMap[2019].begin(), 1), "高輪ゲートウェイ");
				printf("2020年高輪ゲートウェイを挿入しました。\n");
			}
			else
			{
				printf("2020年高輪ゲートウェイを挿入しませんでした。\n");
			}
		}

		printf("山手線　%d　年の駅一覧:\n", year);
		// 指定された年の山手線の駅一覧を表示
		for (const auto& name : yamanoteLineMap[year])
		{
			printf("-%s", name);
		}
		printf("\n");

	}
	return 0;
}