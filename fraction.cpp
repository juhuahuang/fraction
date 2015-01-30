//fraction.cpp


template<class T>
fraction<T>::fraction(T num, T denom):numerator((abs(num)),denominator(abs(denom)){
	assert(denominator!=0);
	whole_number = 0;
	positive = !( (num>0) ^ (denom>0) );
}

template<class T>
fraction<T>::fraction(T num, T denom, long long whole):numerator((abs(num)),denominator(abs(denom)),whole_number(abs(whole)){
	assert(denominator!=0);
	positive = !( (!( (num>0)^ (denom>0) ) )^ (whole>0) );
}



