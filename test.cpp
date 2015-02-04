#include <iostream> 
#include <cassert> 
#include <cmath>     // std::cout
using namespace std; 
template<class T>
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

int GCD(int u, int v);

template<class T>
fraction<T>::fraction(T numer, T denom){
	assert(denom!=0);
	numerator = numer<0? -numer:numer;
	denominator = denom<0 ? -denom:denom;
	whole_number = 0;
	negative =  (numer!=0) && (numer>0) ^ (denom>0) ;
}

template<class T>
fraction<T>::fraction(T numer, T denom, int whole){
	assert(denom!=0 && whole >= 0 );
	numerator = numer<0? -numer:numer;
	denominator = denom<0 ? -denom:denom;
	whole_number = whole;
	negative =  (numer>0) ^ (denom>0);
}


template<class T>
fraction<T>::fraction(T number){
	negative = number<0;
	number = abs(number);
	whole_number = (int)number;
	T remains = (T) (number - whole_number);
	cout<<remains<<endl;
	numerator = 0;
	denominator = 1;
	while( remains > 0){
		cout<<remains<<endl;
		numerator = numerator*10 + round (remains*10); 
		denominator *=10;
		remains =remains *10 - round (remains*10);
	}
}


template<class T>
fraction<T> fraction<T> ::operator+(const fraction &X) const{
	T new_numerator;
	T new_denominator;
	
	T numerator1 = numerator + whole_number*denominator;
	T numerator2 = X.numerator + X.whole_number * X.denominator;
	
	new_numerator = (negative ? -numerator1:numerator1) * X.denominator + (X.negative ? -numerator2:numerator2)*denominator; 
	new_denominator = denominator * X.denominator;
	
	if(whole_number != 0 && X.whole_number != 0){
		bool new_negative = new_numerator<0;
		new_numerator = new_negative ? -new_numerator:new_numerator;
		int new_whole_number = (int)new_numerator /new_denominator;
		new_numerator = fmod(new_numerator , new_denominator);
		new_numerator = new_negative ? -new_numerator:new_numerator;
		return fraction(new_numerator,new_denominator, new_whole_number);
	}
	else return fraction(new_numerator,new_denominator);
	} 


template<>
fraction<int> fraction<int> ::operator+(const fraction &X) const{
	int new_numerator;
	int new_denominator;
	
	int numerator1 = numerator + whole_number*denominator;
	int numerator2 = X.numerator + X.whole_number * X.denominator;
	
	new_numerator = (negative ? -numerator1:numerator1) * X.denominator + (X.negative ? -numerator2:numerator2)*denominator; 
	new_denominator = denominator * X.denominator;
	
	if(whole_number != 0 && X.whole_number != 0){
		bool new_negative = new_numerator<0;
		new_numerator = abs(new_numerator);
		int new_whole_number = (int)new_numerator /new_denominator;
		new_numerator = fmod(new_numerator , new_denominator);
		int greatest_common_divisor = GCD(new_numerator,new_denominator);
		new_numerator = new_negative ? -new_numerator:new_numerator;
		return fraction(new_numerator/greatest_common_divisor,new_denominator/greatest_common_divisor, new_whole_number);
	}
	else {
		int greatest_common_divisor = GCD(abs(new_numerator),new_denominator);
		return fraction(new_numerator/greatest_common_divisor, new_denominator/greatest_common_divisor);

	} 
}


template<class T>
fraction<T> fraction<T> ::operator-(const fraction &X) const{
	T new_numerator;
	T new_denominator;

	T numerator1 = numerator + whole_number*denominator;
	T numerator2 = X.numerator + X.whole_number * X.denominator;
	
	new_numerator = (negative ? -numerator1:numerator1) * X.denominator - (X.negative ? -numerator2:numerator2)*denominator; 
	new_denominator = denominator * X.denominator;

	if(whole_number != 0 && X.whole_number != 0){
		bool new_negative = new_numerator<0;
		new_numerator = new_negative ? -new_numerator:new_numerator;
		int new_whole_number = (int)new_numerator /new_denominator;
		new_numerator = fmod(new_numerator , new_denominator);
		new_numerator = new_negative ? -new_numerator:new_numerator;
		return fraction(new_numerator,new_denominator, new_whole_number);
	}
	else return fraction(new_numerator,new_denominator);

	} 

template<>
fraction<int> fraction<int> ::operator-(const fraction &X) const{
	int new_numerator;
	int new_denominator;

	int numerator1 = numerator + whole_number*denominator;
	int numerator2 = X.numerator + X.whole_number * X.denominator;
	
	new_numerator = (negative ? -numerator1:numerator1) * X.denominator - (X.negative ? -numerator2:numerator2)*denominator; 
	new_denominator = denominator * X.denominator;

	if(whole_number != 0 && X.whole_number != 0){
		bool new_negative = new_numerator<0;
		new_numerator = abs(new_numerator);
		int new_whole_number = (int)new_numerator /new_denominator;
		new_numerator = fmod(new_numerator , new_denominator);
		int greatest_common_divisor = GCD(new_numerator,new_denominator);
		new_numerator = new_negative ? -new_numerator:new_numerator;
		return fraction(new_numerator/greatest_common_divisor,new_denominator/greatest_common_divisor, new_whole_number);
	}
	else {
		int greatest_common_divisor = GCD(abs(new_numerator),new_denominator);
		return fraction(new_numerator/greatest_common_divisor, new_denominator/greatest_common_divisor);

	} 
}	

template<class T>	
fraction<T> fraction<T> :: operator*(const fraction &X) const{
	T new_numerator = (numerator + whole_number*denominator)  * (X.numerator + X.whole_number*X.denominator);
	T new_denominator = denominator * X.denominator;

	if( whole_number != 0 && X.whole_number != 0){
		int new_whole_number = (int)new_numerator / new_denominator;
		new_numerator = fmod(new_numerator , new_denominator);
		new_numerator = negative^X.negative ? -new_numerator : new_numerator;
		return fraction(new_numerator ,new_denominator, new_whole_number);
	}

	else{
		new_numerator = negative^X.negative ? -new_numerator : new_numerator;
		return fraction(new_numerator ,new_denominator);
	}
}

template<>	
fraction<int> fraction<int> :: operator*(const fraction &X) const{
	int new_numerator = (numerator + whole_number*denominator)  * (X.numerator + X.whole_number*X.denominator);
	int new_denominator = denominator * X.denominator;

	if( whole_number != 0 && X.whole_number != 0){
		int new_whole_number = (int)new_numerator / new_denominator;
		new_numerator = fmod(new_numerator , new_denominator);
		int greatest_common_divisor = GCD(new_numerator,new_denominator);
		new_numerator = negative^X.negative ? -new_numerator : new_numerator;
		return fraction(new_numerator/greatest_common_divisor ,new_denominator/greatest_common_divisor, new_whole_number);
	}

	else{	
		int greatest_common_divisor = GCD(new_numerator,new_denominator);
		new_numerator = negative^X.negative ? -new_numerator : new_numerator;
		return fraction(new_numerator /greatest_common_divisor ,new_denominator/greatest_common_divisor);
	}
}


template<class T>
fraction<T> fraction<T> :: operator/(const fraction &X) const{
	T new_numerator = (numerator + whole_number*denominator) * X.denominator;
	T new_denominator = denominator * (X.numerator + X.whole_number*X.denominator);
	assert(new_denominator!=0);

	if( whole_number != 0 && X.whole_number != 0){
		int new_whole_number = (int)new_numerator / new_denominator;
		new_numerator = fmod(new_numerator , new_denominator);
		new_numerator = negative^X.negative ? -new_numerator : new_numerator;
		return fraction(new_numerator,new_denominator,new_whole_number);
	}
	else{
		new_numerator = negative^X.negative ? -new_numerator : new_numerator;
		return fraction(new_numerator ,new_denominator);
	}
}	



template<>
fraction<int> fraction<int> :: operator/(const fraction &X) const{
	int new_numerator = (numerator + whole_number*denominator) * X.denominator;
	int new_denominator = denominator * (X.numerator + X.whole_number*X.denominator);
	assert(new_denominator!=0);
	if( whole_number != 0 && X.whole_number != 0){
		int new_whole_number = (int)new_numerator / new_denominator;
		new_numerator = fmod(new_numerator , new_denominator);
		int greatest_common_divisor = GCD(new_numerator,new_denominator);
		new_numerator = negative^X.negative ? -new_numerator : new_numerator;
		return fraction(new_numerator/greatest_common_divisor ,new_denominator/greatest_common_divisor, new_whole_number);
	}
	
	else{	
		int greatest_common_divisor = GCD(new_numerator,new_denominator);
		new_numerator = negative^X.negative ? -new_numerator : new_numerator;
		return fraction(new_numerator /greatest_common_divisor ,new_denominator/greatest_common_divisor);
	}
}	

template<class T>
bool fraction<T> :: operator==(const fraction &X) const{
	if( negative != X.negative) return false;
	double value1 = (double)numerator/denominator + (double)whole_number;
	double value2 = (double)X.numerator/X.denominator + (double)X.whole_number;
	return value1 ==  value2;
}


template<class T>
bool fraction<T> :: operator!=(const fraction &X) const{
	if( negative != X.negative) return true;
	double value1 = (double)numerator/denominator + (double)whole_number;
	double value2 = (double)X.numerator/X.denominator + (double)X.whole_number;
	return value1 != value2;
}


template<class T>
bool fraction<T> :: operator>(const fraction &X) const{
	if( negative && !X.negative) return false;
	if( !negative && X.negative) return true;
	double value1 = (double)numerator/denominator + (double)whole_number;
	double value2 = (double)X.numerator/X.denominator + (double)X.whole_number;
	return value1 > value2;
}


template<class T>
bool fraction<T> :: operator<(const fraction &X) const{
	if( negative && !X.negative) return true;
	if( !negative && X.negative) return false;
	double value1 = (double)numerator/denominator + (double)whole_number;
	double value2 = (double)X.numerator/X.denominator + (double)X.whole_number;
	return value1 < value2;
}



template<class T>
void fraction<T> :: display() const{
	if( whole_number == 0){
		if( negative) cout<<"-("<<numerator<<'/'<<denominator<<')'<<endl;
		else cout<<numerator<<'/'<<denominator<<endl;
	}
	else{
		if( negative) cout<<'-'<<whole_number<<'('<<numerator<<'/'<<denominator<<')'<<endl;
		else cout<<whole_number<<'('<<numerator<<'/'<<denominator<<')'<<endl;
	}
}





int GCD(int u, int v){
	while( v != 0){
		int r = u % v;
		u = v;
		v = r;
	}
	return u;
}


int main(){
	try{
	fraction<double> a(-5.63);
	} catch(const char* msg){
		cout<<msg<<endl;
	}
	a.display();

/*
	fraction<int> b(1,2,5);
	b.display();

	fraction<int> c = a+b;
	c.display();
	
	fraction<int> d = a-b;
	d.display();

	fraction<int> e = a*b;
	e.display();

	fraction<int> f = a/b;
	f.display();
	cout<< (a>b) << ' '<< (a<b) <<endl;
	cout<< (a==b) << ' '<< (a!=b) <<endl;
*/
	return 0;
}



