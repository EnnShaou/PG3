#include<stdio.h>
#include<Windows.h>
class IsShape
{
public:
	// 抽象クラス
	IsShape() :area(0.0f) {}
	virtual ~IsShape() {};
	// 純粋仮想関数
	virtual void Draw() = 0;
	// 面積を計算する純粋仮想関数
	virtual void Size() = 0;

protected:
	// 面積を保持する変数
	float area;
};
// Shapeクラスを継承したCircleとRectクラスの実装
class Circle : public IsShape
{
public:

	Circle(float radius) :radius_(radius) {}
	~Circle() {}
	void Draw() {
		printf("Circle area=%f\n", area);
	}
	void Size() {
		// 面積を計算する
		area = 3.14f * radius_ * radius_;
	}
private:
	float radius_;
};

class Rect : public IsShape
{
public:
	Rect(float length, float width) :
		length_(length), width_(width)
	{
	}
	~Rect() {
	}
	void Draw() {
		printf("Rectangle area=%f\n", area);// 面積を表示
	}
	void Size() {
		// 面積を計算する
		area = length_ * width_;

	}
private:
	float length_;// 長さ
	float width_;// 幅
};


int main() {
	IsShape* shape = new Circle(5.0f);// Circleのインスタンスを作成
	shape->Size();// 面積を計算
	shape->Draw();// 面積を表示
	delete shape;// メモリを解放
	// 次のインスタンスを作成
	shape = new Rect(5.0f, 10.0f);// 長方形のインスタンスを作成
	shape->Size();// 面積を計算
	shape->Draw();//面積を表示
	delete shape;// メモリを解放

	return 0;
}


