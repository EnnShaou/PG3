#include<stdio.h>
#include<Windows.h>

//基底クラス
class Sound
{
public:
	Sound(){}
	//基底クラスのデストラクタ
	virtual ~Sound(){
		printf("Sound destructor\n");
	}
	//鳴き声
	virtual void isBarking(){
		printf("Sound\n");
	}

private:

};
//派生クラス
class Dog :public Sound
{
public:
	Dog (){}
	~Dog() { printf("Dog destructor\n"); }
	void isBarking() {
		printf("wo,wo,wo\n");
	}

private:

};
//派生クラス
class Cat :public Sound
{
public:
	Cat(){}
	~Cat() { printf("Cat destructor\n"); }
	void isBarking() {
		printf("miao.miao,miao\n");
	}
private:

};
//派生クラス
class Bird :public Sound
{
public:
	Bird(){}
	~Bird() { printf("Bird destructor\n"); }
	void isBarking() {
		printf("ji,ji,ji\n");
	}
private:

};


int main(){
	//基底クラスのポインタを作成
	Sound* sound[3];
	//基底クラスのポインタに派生クラスのポインタを代入
	sound[0] = new Dog();
	sound[1] = new Cat();
	sound[2] = new Bird();
	//基底クラスのポインタを使って派生クラスのメンバ関数を呼び出す
	for (int i = 0; i < 3; i++)
	{
		sound[i]->isBarking();
		delete sound[i];
		sound[i] = nullptr;
	}

	return 0;
}