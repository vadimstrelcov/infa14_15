#include <iostream>

using namespace std;

namespace Math {

	class Point2D {
	private:
		double x,y;
	public:
		Point2D();
		Point2D(double X, double Y);
		Point2D(Point2D* A);

		void set_x(double X);
		void set_y(double Y);
		double get_x();
		double get_y();
		void print();
	};

	Point2D::Point2D() {
		this->x=0.0;
		this->y=0.0;
	}

	Point2D::Point2D(double X, double Y) {
		this->x=X;
		this->y=Y;
	}

	Point2D::Point2D(Point2D* A) {
		this->x=A->get_x();
		this->y=A->get_y();
	}

	void Point2D::set_x(double X) {
		this->x=X;
	}

	void Point2D::set_y(double Y) {
		this->y=Y;
	}

	double Point2D::get_x() {
		return this->x;
	}

	double Point2D::get_y() {
		return this->y;
	}

	void Point2D::print() {
		cout<<"("<<this->x<<";"<<this->y<<")"<<endl;
	}



	class Point3D : public Point2D
	{
	private:
		double z;
	public:
		Point3D();
		Point3D(double X, double Y, double Z);
		Point3D(Point2D* A, double Z);
		Point3D(Point3D* A);

		void set_z(double Z);
		double get_z();
		void print();
	};

	Point3D::Point3D():Point2D() {
		this->z=0.0;
	}

	Point3D::Point3D(double X, double Y, double Z):Point2D(X, Y) {
		this->z=Z;
	}

	Point3D::Point3D(Point2D* A, double Z):Point2D(A) {
		this->z=Z;
	}

	Point3D::Point3D(Point3D* A) {
		this->set_x(A->get_x());
		this->set_y(A->get_y());
		this->z=A->get_z();
	}

	void Point3D::set_z(double Z) {
		this->z=Z;
	}

	double Point3D::get_z() {
		return this->z;
	}

	void Point3D::print() {
		cout<<"("<<this->get_x()<<";"<<this->get_y()<<";"<<this->z<<")"<<endl;
	}



	class Vector2D : public Point2D
	{
    public:
        Vector2D();
        Vector2D(double X, double Y);
        Vector2D(Vector2D* A);
        Vector2D(Point2D A, Point2D B);

        Vector2D operator + (Vector2D A);
	};

	Vector2D::Vector2D():Point2D() {
	}

	Vector2D::Vector2D(double X, double Y):Point2D(X, Y) {
	}

    Vector2D::Vector2D(Vector2D* A) {
        this->set_x(A->get_x());
        this->set_y(A->get_y());
    }

    Vector2D::Vector2D(Point2D A, Point2D B) {
        this->set_x(B.get_x()-A.get_x());
        this->set_y(B.get_y()-A.get_y());
    }

    Vector2D Vector2D:: operator + (Vector2D A) {
        return Vector2D(this->get_x()+A.get_x(),this->get_y()+A.get_y());
    }



    class Vector3D : public Point3D
    {
    public:
        Vector3D();
        Vector3D(double X, double Y, double Z);
        Vector3D(Vector3D* A);
        Vector3D(Point3D A, Point3D B);
        Vector3D operator + (Vector3D A);
    };

    Vector3D::Vector3D():Point3D() {
    }

    Vector3D::Vector3D(double X, double Y, double Z):Point3D(X,Y,Z) {
    }

    Vector3D::Vector3D(Vector3D* A) {
        this->set_x(A->get_x());
        this->set_y(A->get_y());
        this->set_z(A->get_z());
    }

    Vector3D::Vector3D(Point3D A, Point3D B) {
        this->set_x(B.get_x()-A.get_x());
        this->set_y(B.get_y()-A.get_y());
        this->set_z(B.get_z()-A.get_z());
    }

    Vector3D Vector3D::operator + (Vector3D A) {
        return Vector3D(this->get_x()+A.get_x(),this->get_y()+A.get_y(),this->get_z()+A.get_z());
    }

};

using namespace Math;

int main(int argc, char **argv) {

	Point2D A1, A2(3.0,2.0), A3=Point2D(&A2), A4(5.0,-3.0);
	A1.print();
	A2.print();
	A3.print();
	A4.print();
	cout<<endl;
	Point3D B1, B2(2.0,1.0,-6.0), B3(&A2,3.0), B4=Point3D(&B2);
	B1.print();
	B2.print();
	B3.print();
	B4.print();
	cout<<endl;
	Vector2D C1, C2(-4.0,9.0), C3(&C2), C4(A2,A4), C5=C2+C4;
	C1.print();
	C2.print();
	C3.print();
	C4.print();
	C5.print();
	cout<<endl;
	Vector3D D1, D2(-1.0,5.0,-8.0), D3(&D2), D4(B3,B4), D5=D3+D4;
	D1.print();
	D2.print();
	D3.print();
	D4.print();
	D5.print();

	return 0;
}



