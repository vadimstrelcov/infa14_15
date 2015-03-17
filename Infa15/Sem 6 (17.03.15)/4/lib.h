template <typename T, int length>
class Vector
{
    T n[length];

public:
    Vector();
    void set_n(int i, T x);
    int get_length();
    T get_n(int i);
	bool operator==(Vector<T, length>);
	bool operator!=(Vector<T, length>);		
	Vector<T, length> operator*(Vector<T, length>);
	Vector<T, length> operator+(Vector<T, length>);
};

template <typename T, int length>
Vector<T, length>::Vector()
{
    
}

template <typename T, int length>
void Vector<T, length>::set_n(int i, T x)
{
    this->n[i] = x;
}

template <typename T, int length>
int Vector<T, length>::get_length()
{
    return length;
}

template <typename T, int length>
T Vector<T, length>::get_n(int i)
{
    return this->n[i];
}

template <typename T, int length>
bool Vector<T, length>::operator==(Vector<T, length> A) {
	bool flag=1;
	for (int i=0;i<length;i++) {
		flag &= (this->n[i]==A.n[i]);
	}
	return flag;
}

template <typename T, int length>
bool Vector<T, length>::operator!=(Vector<T, length> A) {
	return !(*this == A);
}

template <typename T, int length>
Vector<T, length> 	Vector<T, length>::operator*(Vector<T, length> A) {
	if (length==3) {
		Vector<T, length> tmp;
		tmp.set_n(0,this->get_n(1)*A.get_n(2)-this->get_n(2)*A.get_n(1));
		tmp.set_n(1,this->get_n(2)*A.get_n(0)-this->get_n(0)*A.get_n(2));
		tmp.set_n(2,this->get_n(0)*A.get_n(1)-this->get_n(1)*A.get_n(0));
		return tmp;
	}
	Vector<T, length> tmp;
	for (int i=0;i<length;i++) {
		tmp.set_n(i,0);
	}
	return tmp;
} 

template <typename T, int length>
Vector<T, length> Vector<T, length>::operator+(Vector<T, length> A) {
	Vector<T, length> tmp;
	for (int i=0;i<length;i++) {
		tmp.set_n(this->get_n(i)+this0->get_n(i));
	}	return tmp;
} 
