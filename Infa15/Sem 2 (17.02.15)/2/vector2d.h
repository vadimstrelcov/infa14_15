class Vector2d
{
private:
	double x,y;
public:	
	Vector2d();
	Vector2d(double x_, double y_);
	Vector2d(Vector2d* A);
	double get_x();
	double get_y();
	void print();
};

