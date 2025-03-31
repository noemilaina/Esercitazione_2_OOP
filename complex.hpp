#pragma once

template <typename F> requires std::floating_point<F>
class ComplexNumber{
private:
	F real, imag;
	
public:
	ComplexNumber() : real(0), imag(0) {}
	explicit ComplexNumber (F n) :
		real(n), imag(0) {
			std::cout << "Converting constructor called" << std::endl;
		}
	ComplexNumber(F a, F b) : real(a), imag(b) {}
	F getReal(void) const{
		return real;
	}
	F getImag(void) const{
		return imag;
	}
	ComplexNumber<F> conjugate()const{
		return ComplexNumber<F>(real, -imag);
	}
	ComplexNumber& operator +=(const ComplexNumber& other) {
		real += other.getReal();
		imag += other.getImag();
		return *this;
	}
	ComplexNumber operator+(const ComplexNumber& other) const {
		ComplexNumber result = *this;
		result += other;
		return result;
	}
	ComplexNumber& operator+=(const F& other){
		real += other;
		return *this;
	}
	ComplexNumber& operator *=(const ComplexNumber& other){
		F real_part = real * other.real - imag * other.imag;
		F imag_part = real * other.imag + imag * other.real;
		real = real_part;
		imag = imag_part;
		return *this;
	}
	ComplexNumber<F> operator *(const ComplexNumber& other) const{
		ComplexNumber result = *this;
		result *= other;
		return result;
	}
	ComplexNumber& operator*=(const F& other) {
		real *= other;
			imag *= other;
		return *this;
	}
	ComplexNumber operator*(const F& other) const{
		ComplexNumber result = *this;
		result *= other;
		return result;
	}
};
template<typename F>
ComplexNumber<F>
operator+(const F& f, const ComplexNumber<F>& c) {
	return c + f;
}
template<typename F>
ComplexNumber<F>
operator*(const F& f, const ComplexNumber<F>& c) {
	return c * f;
} 
template<typename F>
std::ostream&
operator<<(std::ostream& os, const ComplexNumber<F>& r){
	if (r.getImag() != 0){
		if (r.getImag() < 0){
			F tmp = -r.getImag();
			os << r.getReal() << "-" << tmp << "i";
		}
		else
			os << r.getReal() << "+" << r.getImag() << "i";
	}
	else
		os << r.getReal();
	
	return os;
}