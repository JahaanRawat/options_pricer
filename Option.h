/* Level 9 Group A
 * by Jahaan Rawat
 */

#ifndef OPTIONS_H
#define OPTIONS_H

#include "OptionType.h"
#include "stdio.h"
#include <vector>

// Option class implementation (strategy design pattern)
class Option {
	
	private:
		/*  
		• T (expiry time/maturity). This is a number, e.g. T = 1 means one year. K (strike price).
		• sig (volatility).
		• r (risk-free interest rate).
		• S (current stock price where we wish to price the option).
		• C = call option price, P = put option price.
		• b cost of carry
		• R foreign risk-free interest rate
		• q divident yield 
		*/
		double _T, _K, _sig, _r, _S, _b, _R, _q;

		// Option Type
		std::unique_ptr<OptionType> option;
		
		// Contains OptionType
		bool containsOption = false;

	public:
		// Constructor
		Option(): _T(0), _K(0), _sig(0), _r(0), _S(0), _b(0), _R(0), _q(0) {}; //Default
		Option(double time, double k, double sigma, double R, double cp, double ca, double rf, double yield) : _T(time), _K(k), _sig(sigma), _r(R), _S(cp), _b(ca), _R(rf), _q(yield) {};
		Option(const Option& other);

		// Destructor
		~Option() {};

		// Operator overload 
		Option& operator=(const Option& other);

		// Set functions
		void assignParam(std::vector<double> param);
		void setOption(std::unique_ptr<OptionType> optionType);
		void T(double newT);
		void K(double newK);
		void sig(double newSig);
		void r(double newr);
		void S(double newS);
		void b(double newb);
		void R(double newR);
		void q(double newq);

		// Get functions
		std::string getOption();
		double T() const;
		double K() const;
		double sig() const;
		double r() const;
		double S() const;
		double b() const;
		double R() const;
		double q() const;

		// Pricing Functions 
		double call_price() const;
		double put_price() const;

		// Put Call Parity
		double PCp_callPrice(double P) const;
		double PCp_putPrice(double C) const;
		bool PCp_equality(double C, double P) const;

		/*
		double call_price(double newT) const;
		double put_price(double newT) const;
		double call_price(double newsig) const;
		double put_price(double newsig) const;
		double call_price(double time, double k, double sigma, double R, double cp, double ca, double rf, double yield) const;
		double put_price(double time, double k, double sigma, double R, double cp, double ca, double rf, double yield) const;
		*/

		// Exact solutions for greeks
		double call_delta() const;
		double put_delta() const;
		double call_gamma() const;
		double put_gamma() const;
		double call_vega() const;
		double put_vega() const;
		double call_theta() const;
		double put_theta() const;
		double call_rho() const;
		double put_rho() const;

		// Divided difference for greeks 
		double call_delta(double h) const;
		double put_delta(double h) const;
		double call_gamma(double h) const;
		double put_gamma(double h) const;
		double call_vega(double h) const;
		double put_vega(double h) const;
		double call_theta(double h) const;
		double put_theta(double h) const;
		double call_rho(double h) const;
		double put_rho(double h) const;
};
#endif
