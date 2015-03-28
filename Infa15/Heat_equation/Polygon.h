#ifndef POLYGON_H
#define POLYGON_H

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const double epsilon=1.0e-11;

struct Point2D {
    double x,y;
    Point2D() {
    }
    Point2D(double X, double Y) {
        x=X;
        y=Y;
    }
    Point2D(Point2D* A) {
        x=A->x;
        y=A->y;
    }
    bool operator== (Point2D A) {
        return (x==A.x && y==A.y);
    }
    bool operator!= (Point2D A) {
        return (x!=A.x || y!=A.y);
    }
};

struct Edge {
    Point2D first, second;
    char type;
    /*
    	0 - const temperature                value = const temperature
    	1 - const heat flow					 value = const heat flow
    	2 - heat flow ~ delta temperature	 value = -
    */
    double value;
    Edge() {
        first=Point2D();
        second=Point2D();
        type=0;
        value=273.0;
    }
    Edge(Point2D first_, Point2D second_, char type_, double value_) {
        first=Point2D(&first_);
        second=Point2D(&second_);
        type=type_;
        value=value_;
    }
};

struct Line {
    double a,b,c;
    void normalization() {
        double tmp=sqrt(a*a+b*b+c*c);
        a/=tmp;
        b/=tmp;
        c/=tmp;
    }
    Line() {
        a=0.0;
        b=0.0;
        c=0.0;
    }
    Line(double a_, double b_, double c_) {
        a=a_;
        b=b_;
        c=c_;
        normalization();
    }
    Line(Point2D P, Point2D Q) {
        a=P.y-Q.y;
        b=Q.x-P.x;
        c=-a*P.x-b*P.y;
        normalization();
    }
};

struct Heat_Source {
    Point2D coord;
    double power; // W/m^3
    double time_start;
    double time_finish;
    Heat_Source() {
    }
    Heat_Source(Point2D coord_, double power_, double time_start_, double time_finish_) {
        coord=Point2D(&coord_);
        power=power_;
        time_start=time_start_;
        time_finish=time_finish_;
    }
};

struct Rectangle {
    char status, type;
    double value;
    int index_line;
    Rectangle() {}
    Rectangle(char status_, char type_, double value_, int index_line_) {
        status=status_;
        type=type_;
        value=value_;
        index_line=index_line_;
    }
};

class Polygon
{
public:
    Polygon();
    Polygon(const char*, bool, const int, const int, const double);
    void get_partition();
    void solve(double, const int);
    double get_temp_by_xy(double x, double y);

protected:
private:
    bool log;
    FILE* file_log;
    double density, thermal_conduction, specific_heat, heat_transfer; // ro, lambda, c, a
    /*
    	for al 2700.0 kg/m^3, 203.5 W/m/K, 903.0 J/kg/K, 8.7 W/m^2/K
            cu 8920,0 kg/m^3, 401.0 W/m/K, 385.0 J/kg/K, 8.7 W/m^2/K
    */
    double temperature_air, temperature_initial;
    int number_edges; //number of edges, points
    vector<Edge> vect_edges;
    vector<Point2D> vect_points;
    int number_heat_source;
    vector<Line> vect_lines;
    vector<vector<Heat_Source> > vect_heat_source;
    double max_x, max_y, min_x, min_y;
    double h_x, h_y, h_t;
    int n_x, n_y;
    vector<vector<Rectangle> > vect_rectangle; //n_y * n_x     0 - empty 1 - border 2 - within
    vector<vector<double> > U;
    void get_tmp_answer(vector<vector<double> >*, vector<vector<double> >*, double, bool);

};

#endif // POLYGON_H
