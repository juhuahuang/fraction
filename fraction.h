//fraction.h
/*
This class supoorts both normal fraction and mixed fraction.
For normal fraction, "whole_number" is 0. While for mixed fraction,
"whole_number" has to be a positive integer.

Class variable numerator and whole_number are always positive or 0;
Class variable denominator is always positive;
Class variable "negative" indicates a fraction is positive or negative. 

There are there ways to construct a fraction:
1) fraction(T numer,T denom) -> use numerator(numer) and denominator(denom) to 
				construct a fraction. Numer and denom 
				coule be either negative or positive.
				For example: fraction(3,4) -> 3/4
2) fraction(T numer,T denom, int whole) -> use numerator(numer), denominator(denom) and 
				whole_number(whole) to construct a fraction.
				Numer and denom coule be either negative or positive.	
				whole has to be a positve integer.
				For example: fraction(-3,4,7) -> -7(3/4)
3) fraction(T number) -> construct a fraction from a number. The constructor will
			 present the number in form of a fraction (fraction<int>).
			 For example: fraction(0.63) -> 63/100	

	
Also, arithmetic and relational operators are overloaded in the class.
For arithmetic operator, if the two inputs are both mixed fraction, then the 
output will be mixed fraction. If at least one input is normal fraction, the 
output will be normal fraction. Specifically, for class of fraction<int>, in 
the arithmetic operation, the output fraction will be reduced.
*/
template <class T>
class fraction{
	private:
		T numerator;
		T denominator;
		int whole_number; 
		bool negative;
	public:
		fraction(T numer,T denom);
		fraction(T numer,T denom, int whole);
		fraction(T number);
		fraction operator+(const fraction &X) const;
		fraction operator-(const fraction &X) const;
		fraction operator*(const fraction &X) const;
		fraction operator/(const fraction &X) const;
		bool operator==(const fraction &X) const;
		bool operator!=(const fraction &X) const;
		bool operator>(const fraction &X) const;
		bool operator<(const fraction &X) const;
		void display() const;
};


// return greatest common divisor for fraction reduction
int GCD(int u, int v);
