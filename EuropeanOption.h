#ifndef EUROPEAN_OPTIONS_H
#define EUROPEAN_OPTIONS_H

#include "OptionType.h"

// Concrete implementation of Eurpean Option stratgey class (design pattern)
class EuropeanOption: public OptionType {
	public:
		// Attributes
		bool is_call = OptionType::is_call;
		std::string name = "European Option";


		// Constructor
		EuropeanOption(): OptionType() {};
		// Destructor 
		~EuropeanOption() {};

		// Methods
		bool isCall() const { return OptionType::isCall(); }
		void toggle() { OptionType::toggle(); }
		std::string getName() const;

		// Functions for pricing and greeks exact solution
		double Price(double S, double K, double t, double r, double sigma, double b) const;
		double Delta(double S, double K, double t, double r, double sigma, double b) const;
		double Gamma(double S, double K, double t, double r, double sigma, double b) const;
		double Vega(double S, double K, double t, double r, double sigma, double b) const;
		double Theta(double S, double K, double t, double r, double sigma, double b) const;
		double Rho(double S, double K, double t, double r, double sigma, double b) const;

		// Put call parity methods
		bool put_call_parity(double C, double P, double K, double r, double t, double S) const;
		double parity_priceCall(double S, double K, double t, double r, double P) const;
		double parity_pricePut(double S, double K, double t, double r, double C) const;

		// Functions for Divided differences greeks
		double Delta(double S, double K, double t, double r, double sigma, double b, double h) const;
		double Gamma(double S, double K, double t, double r, double sigma, double b, double h) const;
		double Vega(double S, double K, double t, double r, double sigma, double b, double h) const;
		double Theta(double S, double K, double t, double r, double sigma, double b, double h) const;
		double Rho(double S, double K, double t, double r, double sigma, double b, double h) const;
};
#endif

