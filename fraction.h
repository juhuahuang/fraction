//fraction.h

template <class T>
class fraction{
	private:
		T numerator;
		T denominator;
		long long whole_number;
		bool positive;
	public:
		fraction(T num,T denom);
		fraction(T num,T denom, long long whole);
		fraction operator+(const fraction &X) const;
		fraction operator-(const fraction &X) const;
		fraction operator*(const fraction &X) const;
		fraction operator\(const fraction &X) const;
		bool operator==(const fraction &X) const;
		bool operator!=(const fraction &X) const;
		bool operator>(const fraction &X) const;
		bool operator<(const fraction &X) const;
		void display();
};