//fraction.cpp
#include <iostream>
#include "fraction.h"

using namesapce std;

template<class T>
fraction<T>::fraction(T numer, T denom):numerator((abs(num)),denominator(abs(denom)){
	assert(denominator!=0);
	whole_number = 0;
	negative =  (numer!=0) && (numer>0) ^ (denom>0) ;
}

template<class T>
fraction<T>::fraction(T numer, T denom, int whole):numerator((abs(num)),denominator(abs(denom)),whole_number(abs(whole)){
	assert(denominator!=0 && whole >= 0 );
	negative =  (numer>0) ^ (denom>0);
}



template<class T>
fraction<T>::fraction(T number){
	negative = number<0;
	whole_number = (int)number - 0;
	T remains = number - whole_number;
	numerator = 0;
	denominator = 1;
	while( remains > 0){
		numerator = numerator*10 + (int)remain*10; 
		denominator *=10;
		remains = remains *10 - (int)remains*10;  
	}
}


template<class T>
fraction<T> fraction<T> ::operator+(const fraction &X) const{
	T new_numerator;
	T new_denominator;
	int new_whole_number;
	
	new_numerator = (negative ? -numerator:numerator) * X.denominator + (X.negative ? -X.numerator:X.numerator)*denominator; 
	new_denominator = denominator * X.denominator;
	new_whole_number = negative ? -whole_number:whole_number + X.negative ? -X.whole_number:X.whole_number;
	
	return fraction(new_numerator,new_denominator,new_whole_number);
	} 

template<class T>
fraction<T> fraction<T> ::operator-(const fraction &X) const{
	T new_numerator;
	T new_denominator;
	int new_whole_number;
	new_numerator = (negative ? -numerator:numerator) * X.denominator - (X.negative ? -X.numerator:X.numerator) * denominator; 
	new_denominator = denominator * X.denominator;
	new_whole_number = (negative ? -whole_number:whole_number) - (X.negative ? -X.whole_number:X.whole_number);

	return fraction(new_numerator,new_denominator,new_whole_number);
	} 
	
template<class T>	
fraction<T> fraction<T> :: operator*(const fraction &X) const{
	T new_numerator = (numerator + whole_number*denominator)  * (X.numerator + X.whole_number*X.denominator);
	T new_denominator = denominator * X.denominator;
	int new_whole_number = (int)new_numbertor / new_denominator;
	new_numbertor = new_numbertor -  new_whole_number;
	new_numerator = negative^X.negative ? -new_numerator : numerator;
	return fraction(new_numerator ,new_denominator, new_whole_number);
}


template<class T>
fraction<T> fraction<T> :: operator\(const fraction &X) const{
	T new_numerator = (numerator + whole_number*denominator) * X.denominator;
	T new_denominator = denominator * (X.numerator + X.whole_number*X.denominator);
	assert(new_denominator!=0);
	int new_whole_number = (int)new_numbertor / new_denominator;
	new_numbertor = new_numbertor -  new_whole_number;
	new_numerator = negative^X.negative ? -new_numerator : numerator;
	return fraction(new_numerator,new_denominator,new_whole_number);
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
bool fraction<T> :: operator>(const fraction &X) const;{
	if( negative && !X.negative) return false;
	if( !negative && X.negative) return true;
	double value1 = (double)numerator/denominator + (double)whole_number;
	double value2 = (double)X.numerator/X.denominator + (double)X.whole_number;
	return value1 > value2;
}


template<class T>
bool fraction<T> :: operator<(const fraction &X) const;{
	if( negative && !X.negative) return true;
	if( !negative && X.negative) return false;
	double value1 = (double)numerator/denominator + (double)whole_number;
	double value2 = (double)X.numerator/X.denominator + (double)X.whole_number;
	return value1 < value2;
}



template<class T>
void fraction<T> :: display() const{
	if( whole_number == 0){
		if( negative) cout<<"-("<<numerator<<'\'<<denominator<<')'<<endl;
		else cout<<numerator<<'\'<<denominator<<endl;
	}
	else{
		if( negative) cout<<'-'<<whole_number<<'('<<numerator<<'\'<<denominator<<')'<<endl;
		else cout<<whole_number<<'('<<numerator<<'\'<<denominator<<')'<<endl;
	}
}

