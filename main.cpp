#include<stdio.h>
#include<chrono>
#include<string>
/// <summary>
/// コピーの処理時間を計る
/// </summary>
/// <param name="a">文字列</param>
void copy(std::string a) {
	auto start = std::chrono::system_clock::now();// 計測開始
	std::string b = a;
	auto end = std::chrono::system_clock::now();// 計測終了

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);// 経過時間をマイクロ秒単位で計算
	printf("Copy took %lld μ\n", duration.count());// 結果を表示
}
/// <summary>
/// 移動の処理時間を計る
/// </summary>
/// <param name="a">文字列</param>
void move(std::string a) {
	
	auto start = std::chrono::system_clock::now();// 計測開始
	std::string b = std::move(a);
	auto end = std::chrono::system_clock::now();// 計測終了
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);// 経過時間をマイクロ秒単位で計算
	printf("Move took %lld μ\n", duration.count());// 結果を表示
}


int main() {
	std::string A(1000000, 'a');
	copy(A);
	move(A);
	return 0;
}