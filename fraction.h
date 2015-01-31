//fraction.h

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
		fraction operator\(const fraction &X) const;
		bool operator==(const fraction &X) const;
		bool operator!=(const fraction &X) const;
		bool operator>(const fraction &X) const;
		bool operator<(const fraction &X) const;
		void display() const;
};


