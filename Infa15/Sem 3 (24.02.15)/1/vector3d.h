class Vector3d
{
private:
	double x,y,z;
public:	
	Vector3d();
	Vector3d(double x_, double y_, double z_);
	Vector3d(Vector3d* A);
	double get_x();
	double get_y();
	double get_z();
	void print();

	Vector3d operator + (Vector3d A);	
	Vector3d operator - (Vector3d A);
	double operator * (Vector3d A);
	bool operator == (Vector3d A);

};

