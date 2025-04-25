#include<stdio.h>
#include<Windows.h>


//敵クラスの定義
class Enemy
{
public:
	//コンストラクタ
	Enemy():phase_(Phase::Move) {}
	//デストラクタ
	~Enemy() {}
	//敵の状態を列挙型で定義
	enum class Phase
	{
		Move,
		Attack,
		Die,
		COUNT
	};
	//敵の状態を更新する関数
	void Update() {
		//状態を更新する
		for (int next = (static_cast<int>(phase_)); next < static_cast<int>(Phase::COUNT); next++)
		{
			phase_ = static_cast<Phase>(next);
			(this->*stat[static_cast<size_t>(phase_)])();
		}

	}
	//敵の移動、
	void Move() {
	
		printf("Move\n");
	}
	//敵の攻撃
	void Attack() {
	
		printf("Attack\n");
	}
	//敵の死亡
	void Die() {
		printf("Die\n");
	}
	
private:
	//敵の状態を関数ポインタで定義
	static void(Enemy::* stat[])();
	//敵の状態を保持する変数
	Phase phase_;
	
};

int main() {
	//敵クラスのインスタンスを生成
	Enemy* enemy=new Enemy;
	//敵の状態を更新する
	enemy->Update();
	//敵のインスタンスを削除
	delete enemy;
	return 0;
}
//関数ポインタの初期化
void(Enemy::* Enemy::stat[])() = {
		&Enemy::Move,
		&Enemy::Attack,
		&Enemy::Die
};