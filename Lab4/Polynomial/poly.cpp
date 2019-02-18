
#include "poly.h"
#include <math.h>
#include <string>

using namespace std;


/*
	Invariants:
		MAXIMUM_DEGREE: Max degree of the polynomial, one less than array size. Used
			to check validity of operations

		current_degree: stores the current max degree of the polynomial, used to make
			some calculations faster without the need for a loop.

		poly[]: array used to store the polynomial. The index is the power that x is
			raised to i.e. [1,2,3] = 1 + 2x + 3x^2. Max size is capped at MAXIMUM_DEGREE
			 + 1
*/
namespace coen79_lab4 {


    polynomial::polynomial(double c, unsigned int exponent){

        assert(exponent <= MAXIMUM_DEGREE);
        current_degree = exponent;

        coef = new double[MAXIMUM_DEGREE+1];
        clear();
        coef[exponent] = c;

    }

    void polynomial::assign_coef(double coefficient, unsigned int exponent) {

        assert(exponent <= MAXIMUM_DEGREE);
        if(exponent > current_degree) current_degree = exponent;
        coef[exponent] = coefficient;

    }

    void polynomial::add_to_coef(double amount, unsigned int exponent) {


        assert(exponent <= MAXIMUM_DEGREE);
        if(exponent > current_degree) current_degree = exponent;
        coef[exponent] += amount;

    }

    void polynomial::clear() {

        for(unsigned int i = 0; i<=MAXIMUM_DEGREE; i++){
            coef[i] = 0;
        }

    }


    double polynomial::coefficient(unsigned int exponent) const {

        if(exponent > MAXIMUM_DEGREE){
            return 0;
        }
        else {
            return coef[exponent];
        }
    }


    unsigned int polynomial::degree() const {

        unsigned int i;
        unsigned int max = 0;
        for(i=0; i < MAXIMUM_DEGREE+1; i++){
            if(0 != coef[i]){

                max  = i;
            }
        }

        return max;

    }



    double polynomial::eval(double x) const {

        unsigned int i;
        double sum = 0;
        for(i=0; i < MAXIMUM_DEGREE+1; i++){
            sum += coef[i] * pow(x,i);
        }

        return sum;

    }

    bool polynomial::is_zero() const {
        return (degree () == 0) && (coef[0] == 0);
    }

    unsigned int polynomial::next_term(unsigned int e) const {

        unsigned int i;

        for(i=e; i<MAXIMUM_DEGREE;i++){
            if(coef[i] != 0 && i>e){
                return i;
            }
        }
        return 0;

    }

    unsigned int polynomial::previous_term(unsigned int e) const {

        unsigned int i;

        for(i=e; i >= 0;i--){
            if(coef[i] != 0){
                return i;
            }
        }

        return 0;
    }

    polynomial polynomial::derivative() const {

        unsigned int i;
        polynomial p;

        for(i=0; i < MAXIMUM_DEGREE; i++){
            p.assign_coef (coef[i + 1] * (i + 1), i);
        }
        return p;

    }

    polynomial polynomial::antiderivative() const {

        polynomial p;
        for(unsigned int i = 0; i <= degree (); i++)
        {
            p.assign_coef(coefficient(i) * pow(i + 1, -1), i + 1);
        }
        return p;
    }

    double polynomial::definite_integral(double x0, double x1) const {

        polynomial p = antiderivative();
        return p.eval (x1) - p.eval (x0);

    }

    std::ostream &operator<<(ostream &out, const polynomial &p) {

        int i;
        unsigned int d = p.degree();
        bool zero = true;
        for(i = d; i >= 0; i--){
            if(p.coefficient(i) != 0) {

                zero = false;
                if (p.coefficient(i) >= 0 && i != d) {
                    out << "+ ";
                }
                if (p.coefficient(i) < 0) {
                    out << "- ";
                }

                out << abs (p.coefficient(i));

                if (i != 0 && i != 1) {
                    out << "x^" << i << " ";
                } else if (i == 1) {
                    out << "x ";
                }
            }

        }

        if(zero) out << 0;

        return out;

    }

    polynomial operator +(const polynomial& p1, const polynomial& p2){
        polynomial p;
        for(unsigned int i = 0; i < polynomial::MAXIMUM_DEGREE; i++){
            p.assign_coef (p1.coefficient(i)+p2.coefficient(i), i);
        }
        return p;

    }

    polynomial operator -(const polynomial& p1, const polynomial& p2){
        polynomial p;
        for(unsigned int i = 0; i < polynomial::MAXIMUM_DEGREE; i++){
            p.assign_coef (p1.coefficient(i)-p2.coefficient(i), i);
        }
        return p;
    }

    polynomial operator *(const polynomial& p1, const polynomial& p2){

        polynomial p;

        for(int i=0; i<=p1.degree ();i++){
            for(int j=0; j<=p2.degree ();j++){
                p.add_to_coef (p1.coefficient(i)*p2.coefficient(i), i+j);
            }
        }
        return p;
    }


}