class Sum
{
private:
	int a,b;
public:
	Sum(int a_, int b_);
	int sum_ab();
	void set_a(int a_);
	void set_b(int b_);
	int get_a();
	int get_b();
	void plus(Sum B);
};
