#include <iostream> 
#include <cmath>  
#include <exceptions>
#include "fraction.h"
using namespace std;
template<class T>
fraction<T>::fraction(T numer, T denom){
	// denominator can't be 0
	if(denom == 0){
		throw "Denominator can't be zero!";
	}
	numerator = numer<0? -numer:numer;
	denominator = denom<0 ? -denom:denom;
	whole_number = 0;
	negative =  (numer!=0) && (numer>0) ^ (denom>0) ;
}

template<class T>
fraction<T>::fraction(T numer, T denom, int whole){
	// denominator can't be 0 and whole_number has to be positive or 0;
	if( denom == 0) throw "Denominator can't be zero!";
	if( whole<0) throw "whole number in mixed fraction can't be negative!";
	numerator = numer<0? -numer:numer;
	denominator = denom<0 ? -denom:denom;
	whole_number = whole;
	negative =  (numer>0) ^ (denom>0);
}

//construct fraction from a single number.
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
	
	// if inputs are both mixed fraction, then return mixed fraction.
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

// for fraction<int>, fraction reduction will be done.
template<>
fraction<int> fraction<int> ::operator+(const fraction &X) const{
	int new_numerator;
	int new_denominator;
	
	int numerator1 = numerator + whole_number*denominator;
	int numerator2 = X.numerator + X.whole_number * X.denominator;
	
	new_numerator = (negative ? -numerator1:numerator1) * X.denominator + (X.negative ? -numerator2:numerator2)*denominator; 
	new_denominator = denominator * X.denominator;
	
	// if inputs are both mixed fraction, then return mixed fraction.
	if(whole_number != 0 && X.whole_number != 0){
		bool new_negative = new_numerator<0;
		new_numerator = abs(new_numerator);
		int new_whole_number = (int)new_numerator /new_denominator;
		new_numerator = fmod(new_numerator , new_denominator);
		// fraction reduction
		int greatest_common_divisor = GCD(new_numerator,new_denominator);
		new_numerator = new_negative ? -new_numerator:new_numerator;
		return fraction(new_numerator/greatest_common_divisor,new_denominator/greatest_common_divisor, new_whole_number);
	}
	else {
		// fraction reduction
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

	// if inputs are both mixed fraction, then return mixed fraction.
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


// for fraction<int>, fraction reduction will be done.
template<>
fraction<int> fraction<int> ::operator-(const fraction &X) const{
	int new_numerator;
	int new_denominator;

	int numerator1 = numerator + whole_number*denominator;
	int numerator2 = X.numerator + X.whole_number * X.denominator;
	
	new_numerator = (negative ? -numerator1:numerator1) * X.denominator - (X.negative ? -numerator2:numerator2)*denominator; 
	new_denominator = denominator * X.denominator;

	// if inputs are both mixed fraction, then return mixed fraction.
	if(whole_number != 0 && X.whole_number != 0){
		bool new_negative = new_numerator<0;
		new_numerator = abs(new_numerator);
		int new_whole_number = (int)new_numerator /new_denominator;
		new_numerator = fmod(new_numerator , new_denominator);
		// fraction reduction
		int greatest_common_divisor = GCD(new_numerator,new_denominator);
		new_numerator = new_negative ? -new_numerator:new_numerator;
		return fraction(new_numerator/greatest_common_divisor,new_denominator/greatest_common_divisor, new_whole_number);
	}
	else {
		// fraction reduction
		int greatest_common_divisor = GCD(abs(new_numerator),new_denominator);
		return fraction(new_numerator/greatest_common_divisor, new_denominator/greatest_common_divisor);

	} 
}	

template<class T>	
fraction<T> fraction<T> :: operator*(const fraction &X) const{
	T new_numerator = (numerator + whole_number*denominator)  * (X.numerator + X.whole_number*X.denominator);
	T new_denominator = denominator * X.denominator;

	// if inputs are both mixed fraction, then return mixed fraction.
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


// for fraction<int>, fraction reduction will be done.
template<>	
fraction<int> fraction<int> :: operator*(const fraction &X) const{
	int new_numerator = (numerator + whole_number*denominator)  * (X.numerator + X.whole_number*X.denominator);
	int new_denominator = denominator * X.denominator;

	// if inputs are both mixed fraction, then return mixed fraction.
	if( whole_number != 0 && X.whole_number != 0){
		int new_whole_number = (int)new_numerator / new_denominator;
		new_numerator = fmod(new_numerator , new_denominator);
		// fraction reduction
		int greatest_common_divisor = GCD(new_numerator,new_denominator);
		new_numerator = negative^X.negative ? -new_numerator : new_numerator;
		return fraction(new_numerator/greatest_common_divisor ,new_denominator/greatest_common_divisor, new_whole_number);
	}

	else{	
		// fraction reduction
		int greatest_common_divisor = GCD(new_numerator,new_denominator);
		new_numerator = negative^X.negative ? -new_numerator : new_numerator;
		return fraction(new_numerator /greatest_common_divisor ,new_denominator/greatest_common_divisor);
	}
}


template<class T>
fraction<T> fraction<T> :: operator/(const fraction &X) const{
	T new_numerator = (numerator + whole_number*denominator) * X.denominator;
	T new_denominator = denominator * (X.numerator + X.whole_number*X.denominator);
	if( new_denominator == 0) throw "get a zero denominator in division!";

	// if inputs are both mixed fraction, then return mixed fraction.
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


// for fraction<int>, fraction reduction will be done.
template<>
fraction<int> fraction<int> :: operator/(const fraction &X) const{
	int new_numerator = (numerator + whole_number*denominator) * X.denominator;
	int new_denominator = denominator * (X.numerator + X.whole_number*X.denominator);
	// the new denominator might be 0;
	assert(new_denominator!=0);

	// if inputs are both mixed fraction, then return mixed fraction.
	if( whole_number != 0 && X.whole_number != 0){
		int new_whole_number = (int)new_numerator / new_denominator;
		new_numerator = fmod(new_numerator , new_denominator);
		// fraction reduction
		int greatest_common_divisor = GCD(new_numerator,new_denominator);
		new_numerator = negative^X.negative ? -new_numerator : new_numerator;
		return fraction(new_numerator/greatest_common_divisor ,new_denominator/greatest_common_divisor, new_whole_number);
	}
	
	else{	
		// fraction reduction
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


