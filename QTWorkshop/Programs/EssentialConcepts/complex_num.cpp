#include <iostream>

struct Complex {
	public: 
		Complex(int i, int j) {
			this->i = i;
			this->j = j;
		}
		Complex(): i(0),j(0) {}
		float i;
		float j;
	
		Complex operator + (const Complex& other) {
			Complex buf;
			buf.i = i + other.i;
			buf.j = j + other.j;
			return buf;
		}
};

Complex multiply(Complex *first, Complex *second) {
	Complex buf;
	buf.i = first->i*second->i + first->i * second->j;
	buf.j = first->j*second->i + first->j * second->j;

	return buf;
}

int main() {
	Complex first(12,45);
	Complex second(12,45);
	multiply(&first, &second);
}

