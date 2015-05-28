class complex
{
private:
	double re, im;
public: 
	complex();
	complex(double re_, double im_);
	void set_re(double re_);
	void set_im(double im_);
	double get_re();
	double get_im();
	void print();
	void input();
	
	complex sum(complex B);
	complex sub(complex B);
	complex mult(complex B);
	complex div(complex B);
	complex conj();
	double modul();
};
