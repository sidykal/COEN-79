// FILE: poly.h
//
//  COEN 79
//  --- Sid Kalidindi, SCU, COEN, 2/7/24
//
//
// CLASS PROVIDED:
//   class polynomial (in the namespace coen79_lab4)
//     A polynomial has one variable x, real number coefficients, and
//     non-negative integer exponents. Such a polynomial can be viewed
//     as having the form:
//       A[n]*x^n + A[n-1]*x^(n-1) + ... A[2]*x^2 + A[1]*x + A[0]
//     where the A[n] are the real number coefficients and x^i represents
//     the variable x raised to the i power. The coefficient A[0] is
//     called the "constant" or "zeroth" term of the polynomial.
//
// HELPER MEMBER FUNCTIONS for the polynomial class
//   void update_current_degree()
//     POSTCONDITION: The current degree is set to the highest exponent
//      with a non-zero coeficient.
//
// MEMBER CONSTANTS
//   const static size_t MAXIMUM_DEGREE
//     The size of the maximum exponent permitted for a polynomial.
//
// CONSTRUCTOR for the polynomial class
//   polynomial(double c = 0.0, unsigned int exponent = 0)
//     PRECONDITION: exponent <= MAXIMUM_DEGREE
//     POSTCONDITION: This polynomial has been created with all zero
//     coefficients, except for coefficient c for the specified exponent.
//     When used as a default constructor (using default values for
//     both arguments), the result is a polynomial with all zero
//     coefficients.
//
// MODIFICATION MEMBER FUNCTIONS for the polynomial class
//   void assign_coef(double coefficient, unsigned int exponent)
//     PRECONDITION: exponent <= MAXIMUM_DEGREE.
//     POSTCONDITION: Sets the coefficient for the specified exponent.
//
//   void add_to_coef(double amount, unsigned int exponent)
//     PRECONDITION: exponent <= MAXIMUM_DEGREE.
//     POSTCONDITION: Adds the given amount to the coefficient of the
//     specified exponent.
//
//   void clear( )
//     POSTCONDITION: All coefficients of this polynomial are set to zero.
//
// CONSTANT MEMBER FUNCTIONS for the polynomial class
//   polynomial antiderivative( ) const
//     PRECONDITION: degree( ) < MAXIMUM_DEGREE
//     POSTCONDITION: The return value is the antiderivative (indefinite integral)
//     of this polynomial.
//     NOTE: The return polynomial always has a constant term of zero.
//
//   double coefficient(unsigned int exponent) const
//     POSTCONDITION: Returns coefficient at specified exponent of this
//     polynomial.
//     NOTE: For exponents > MAXIMUM_DEGREE, the return value is always zero.
//
//   double definite_integral(double x0, double x1) const
//     POSTCONDITION: Returns the value of the definite integral computed from
//     x0 to x1.  The answer is computed analytically.
//
//   unsigned int degree( ) const
//     POSTCONDITION: The function returns the value of the largest exponent
//     with a non-zero coefficient.
//     If all coefficients are zero, then the function returns zero (even
//     though, technically, this polynomial does not have a degree).
//
//   polynomial derivative( ) const
//     POSTCONDITION: The return value is the first derivative of this
//     polynomial.
//
//   double eval(double x) const
//     POSTCONDITION: The return value is the value of this polynomial with the
//     given value for the variable x.
//
//   bool is_zero( ) const
//     POSTCONDITION: The return value is true if and only if the polynomial
//     is the zero polynomial.
//
//   unsigned int next_term(unsigned int e) const
//     POSTCONDITION: The return value is the next exponent n which is LARGER
//     than e such that coefficient(n) != 0.
//     If there is no such term, then the return value is zero.
//
//   unsigned int previous_term(unsigned int e) const
//     POSTCONDITION: The return value is the next exponent n which is SMALLER
//     than e such that coefficient(n) != 0.
//     If there is no such term, then the return value is UINT_MAX
//     from <climits>.
//
// CONSTANT OPERATORS for the polynomial class
//   double operator( ) (double x) const
//     Same as the eval member function.
//
//
// NON-MEMBER BINARY OPERATORS for the polynomial Class
//   polynomial operator +(const polynomial& p1, const polynomial& p2)
//     POSTCONDITION: return-value is a polynomial with each coefficient
//     equal to the sum of the coefficients of p1 & p2 for any given
//     exponent.
//
//   polynomial operator -(const polynomial& p1, const polynomial& p2)
//     POSTCONDITION: return-value is a polynomial with each coefficient
//     equal to the difference of the coefficients of p1 & p2 for any given
//     exponent.
//
//   polynomial operator *(const polynomial& p1, const polynomial& p2)
//     PRECONDITION: p1.degree( ) + p2.degree( ) <= MAXIMUM_DEGREE.
//     POSTCONDITION: Each term of p1 has been multiplied by each term of p2,
//     and the answer is the sum of all these term-by-term products.
//     For example, if p1 is 2x^2 + 3x + 4 and p2 is 5x^2 - 1x + 7, then the
//     return value is 10x^4 + 13x^3 + 31x^2 + 17x + 28.
//
//
// NON-MEMBER OUTPUT FUNCTIONS for the polynomial Class
//   ostream& operator << (ostream& out, const polynomial& p)
//     POSTCONDITION: The polynomial has been printed to ostream out, which,
//     in turn, has been returned to the calling function.
//     The format of the polynomial when printed should be as follows:
//              -2.5x^2 - 4x + 5.9
//     1) There should be exactly 1 space between the numbers and the operators.
//     2) The constant coeficient should be printed by itself: 5.3, not 5.3x^0
//     3) The first coeficient chould be followed by a plain x: 4x, not 4x^1
//     4) The highest degree's coeficient should have a sign: -2.5x^2, but the
//          following values should all be separated by appropriate operators
//          and then printed unsigned: -2.5x^2 - 4x...
//     5) If you manipulate any settings of the outstream inside of this,
//          such as the precision, they should be restored to what they were
//          at the start of the function before returning.
//
//
// The value semantics (copy constructor and assignment operator) are valid for
// the polynomial class.
//
//

#include <iostream>  // Provides ostream
#include <cstdlib>
#include <string>
#include <cassert>
#include <cmath>
#include <climits>
#include "poly.h"

using namespace std;
using namespace coen79_lab4;


namespace coen79_lab4
{
        void polynomial :: update_current_degree(){
		current_degree = degree();
	}

	polynomial :: polynomial(double c, unsigned int exponent){
	        assert(exponent <= MAXIMUM_DEGREE);
        	poly[MAXIMUM_DEGREE + 1];
        	for(int i = 0; i <= MAXIMUM_DEGREE + 1; i++){
            		poly[i] = 0;
        	}
        	poly[exponent] = c;
	}

        void polynomial :: assign_coef(double coefficient, unsigned int exponent){
		assert(exponent <= MAXIMUM_DEGREE);
        	poly[exponent] = coefficient;
	}

        void polynomial :: add_to_coef(double amount, unsigned int exponent){
		assert(exponent <= MAXIMUM_DEGREE);
        	poly[exponent] += amount;
	}

        void polynomial :: clear( ){
		for(int i = 0; i < MAXIMUM_DEGREE + 1; i++){
       			poly[i] = 0;
        	}
        	current_degree = 0;
	}

	polynomial polynomial :: antiderivative( ) const{
		assert(degree() < MAXIMUM_DEGREE);
        	polynomial anti; 
        	for(int i = 0; i < MAXIMUM_DEGREE-1; i++){
            		anti.poly[i+1]=poly[i]/(i+1);
        	}
		anti.poly[0]=0;
		anti.update_current_degree();
        	return anti;
	}
        
	double polynomial :: coefficient(unsigned int exponent) const{
		if(exponent > MAXIMUM_DEGREE){
        		return 0;
        	}
        	return poly[exponent];
	}

        double polynomial :: definite_integral(double x0, double x1) const{
		polynomial anti = this->antiderivative(); 
        	return (anti.eval(x1) - anti.eval(x0));	
	}

        unsigned int polynomial :: degree( ) const{
		int high = 0;
        	for(int i = 0; i < MAXIMUM_DEGREE + 1; i++){
            		if(poly[i] != 0 && i > high){
                		high = i;
            		}
        	}
        	return high;
	}

	polynomial polynomial :: derivative( ) const{
		polynomial derivative;
        	for(int i = 0; i < MAXIMUM_DEGREE + 1; i++){
            		derivative.assign_coef(poly[i + 1]*(i + 1), i);
        	}
        	return derivative;
	}

        double polynomial :: eval(double x) const{
		double sum = 0;
        	for(int i = 0; i <= this->degree(); i++){
            		if(poly[i] != 0) {
                		sum += (poly[i]*pow(x,i));
            		}
        	}
        	return sum;
	}

        bool polynomial :: is_zero( ) const{
		return(degree() == 0);
	}

        unsigned int polynomial :: next_term(unsigned int e) const{
		for(int i = e+1; e < MAXIMUM_DEGREE; i++){
            		if(poly[i] != 0){
                    		return i;
			}
        	}
        	return 0;	
	}

        unsigned int polynomial :: previous_term(unsigned int e) const{
		assert(e <= MAXIMUM_DEGREE);
		for(int i = e-1; i >= 0; i--){
            		if(poly[i] != 0){
                		return i;
			}
        	}
        	return UINT_MAX;
	}

        double polynomial :: operator( ) (double x) const{
		return eval(x);
	}

    	polynomial operator +(const polynomial& p1, const polynomial& p2){
		polynomial temp;
        	for(int i = 0; i < polynomial::MAXIMUM_DEGREE + 1; i++){
         		temp.assign_coef(p1.coefficient(i)+p2.coefficient(i), i);
		}
        	return temp;
	}

    	polynomial operator -(const polynomial& p1, const polynomial& p2){
		polynomial temp;
        	for(int i = 0; i < polynomial::MAXIMUM_DEGREE + 1; i++){
            		temp.assign_coef(p1.coefficient(i)-p2.coefficient(i), i);
		}
        	return temp;
	}

    	polynomial operator *(const polynomial& p1, const polynomial& p2){
		assert((p1.degree() + p2.degree()) <= polynomial::MAXIMUM_DEGREE);
        	polynomial temp;
        	for(int i = 0; i <= p1.degree(); i++)
            		for(int j = 0; j <= p2.degree(); j++)
                		temp.add_to_coef(p1.coefficient(i)*p2.coefficient(j), i+j);
        	return temp;
	}
    
    	std::ostream& operator << (std::ostream& out, const polynomial& p){
		int i = p.degree();
        	if(i > 0) {
            		out <<  p.coefficient(i) << "x^" << i << " ";
            		i = p.previous_term(i);
            		while(i != UINT_MAX) { 
                		if(i > 1) { 
                    			if(p.coefficient(i) < 0) {
                        			out << " - " << (p.coefficient(i) * -1) << "x^" << i;
                    			}
                    			else {
                        			out << " + " << p.coefficient(i) << "x^" << i;
                    			}
                		}
                		else if (i == 1) {
                    			if(p.coefficient(i) < 0) {
                        			out << " - " << (p.coefficient(i) * -1) << "x";
                    			}
                    			else {
                        			out << " + " << p.coefficient(i) << "x";
                    			}
                		}
                	i = p.previous_term(i);
            		}
        	}
		if(p.degree() == 0){
			if(p.coefficient(0) < 0) {
                        	out << "-" << (p.coefficient(0) * -1);
                	}
                	else if (p.coefficient(0) > 0) {
        	                out << p.coefficient(0);
	                }
			else{
				out << "0";
			}
			return out;
		}	
		if(p.coefficient(0) < 0) {
            		out << " - " << (p.coefficient(0) * -1);
        	}
        	else if (p.coefficient(0) > 0) {
            		out << " + " << p.coefficient(0);
        	}
        	return out;
	}
}
