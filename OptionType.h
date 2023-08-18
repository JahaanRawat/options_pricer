/* Level 9 Group A
 * by Jahaan Rawat
 */

#ifndef OPTION_TYPE_H
#define OPTION_TYPE_H


#include <iostream>

// Option interface for the differnt types of concrete option strategy classes
class OptionType {
	public:
		// Attribute
		bool is_call;

		// Constructor 
		OptionType(): is_call(true) {}; 
		virtual ~OptionType() {};

		// Methods
		bool isCall() const { return is_call;} 
		void toggle() { bool temp = is_call; is_call = !temp; }
		virtual std::string getName() const = 0;

		// Put call parity methods
		virtual bool put_call_parity(double C, double P, double K, double r, double t, double S) const = 0;
		virtual double parity_priceCall(double S, double K, double t, double r, double P) const = 0;
		virtual double parity_pricePut(double S, double K, double t, double r, double C) const = 0;

		// Virtual functions for pricing and greeks exact methods
		virtual double Price(double S, double K, double t, double r, double sigma, double b) const = 0;
		virtual double Delta(double S, double K, double t, double r, double sigma, double b) const = 0;
		virtual double Gamma(double S, double K, double t, double r, double sigma, double b) const = 0;
		virtual double Vega(double S, double K, double t, double r, double sigma, double b) const = 0;
		virtual double Theta(double S, double K, double t, double r, double sigma, double b) const = 0;
		virtual double Rho(double S, double K, double t, double r, double sigma, double b) const = 0;

		//Virtual functions for Divided differences greeks
		virtual double Delta(double S, double K, double t, double r, double sigma, double b, double h) const = 0;
		virtual double Gamma(double S, double K, double t, double r, double sigma, double b, double h) const = 0;
		virtual double Vega(double S, double K, double t, double r, double sigma, double b, double h) const = 0;
		virtual double Theta(double S, double K, double t, double r, double sigma, double b, double h) const = 0;
		virtual double Rho(double S, double K, double t, double r, double sigma, double b, double h) const = 0;
};
#endif

