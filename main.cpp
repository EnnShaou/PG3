#include<stdio.h>
#include<Windows.h>
class IsShape
{
public:
	IsShape() :area(0.0f) {}
	virtual ~IsShape() {};
	virtual void Draw() = 0;
	virtual void Size() = 0;

protected:
	float area;
};
class Circle : public IsShape
{
public:
	Circle(float radius) :radius_(radius) {}
	~Circle() {}
	void Draw() {
		printf("Circle area=%f\n", area);
	}
	void Size() {
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
		printf("Rectangle area=%f\n", area);
	}
	void Size() {
		area = length_ * width_;

	}
private:
	float length_;
	float width_;
};


int main() {

	IsShape* shape = new Circle(5.0f);
	shape->Size();
	shape->Draw();
	delete shape;

	shape = new Rect(5.0f, 10.0f);
	shape->Size();
	shape->Draw();
	delete shape;

	return 0;
}


