/* Level 9 Group A
 * by Jahaan Rawat
 */

#include "EuropeanOption.h"
#include "OptionTypeException.h"
// EuropeanOptions.cpp
#include <cmath>
#include <boost/math/distributions/normal.hpp>

// Helper function to calculate the cumulative standard normal distribution function (CDF)
double N(const double x) {
    boost::math::normal_distribution<> norm_dist(0.0, 1.0);
    return boost::math::cdf(norm_dist, x);
}

// Helper function to calculate d1
double calculate_d1(double S, double K, double t, double r, double sigma, double b) {
    return (log(S / K) + (b + 0.5 * sigma * sigma) * t) / (sigma * sqrt(t));
}

// Function to return a string of option type
std::string EuropeanOption::getName() const {
    std::string type; 
    EuropeanOption::isCall() ? type = "Call " : type = "Put ";  return type + name;
}

// Function for pricing the European option
double EuropeanOption::Price(double S, double K, double t, double r, double sigma, double b) const {
    double d1 = calculate_d1(S, K, t, r, sigma, b);
    double d2 = d1 - sigma * sqrt(t);

    if (EuropeanOption::isCall()) {
        return S * exp((b - r) * t) * N(d1) - K * exp(-r * t) * N(d2);
    }
    else {
        return K * exp(-r * t) * N(-d2) - S * exp((b - r) * t) * N(-d1);
    }
}

// Function for calculating Delta
double EuropeanOption::Delta(double S, double K, double t, double r, double sigma, double b) const {
    double d1 = calculate_d1(S, K, t, r, sigma, b);

    if (EuropeanOption::isCall()) {
        return exp((b - r) * t) * N(d1);
    }
    else {
        return -exp((b - r) * t) * N(-d1);
    }
}

// Function for calculating Gamma
double EuropeanOption::Gamma(double S, double K, double t, double r, double sigma, double b) const {
    double d1 = calculate_d1(S, K, t, r, sigma, b);
    return exp((b - r) * t) * N(d1) / (S * sigma * sqrt(t));
}

double EuropeanOption::Vega(double S, double K, double t, double r, double sigma, double b) const {
    throw NotImplementedException();
}

double EuropeanOption::Theta(double S, double K, double t, double r, double sigma, double b) const {
    throw NotImplementedException();
}

double EuropeanOption::Rho(double S, double K, double t, double r, double sigma, double b) const {
    throw NotImplementedException();
}

// Central difference method to calculate Delta
double EuropeanOption::Delta(double S, double K, double t, double r, double sigma, double b, double h) const {
    double S_plus_h = S + h;
    double S_minus_h = S - h;

    double price_plus_h = Price(S_plus_h, K, t, r, sigma, b);
    double price_minus_h = Price(S_minus_h, K, t, r, sigma, b);

    return (price_plus_h - price_minus_h) / (2 * h);
}

// Central difference method to calculate Gamma
double EuropeanOption::Gamma(double S, double K, double t, double r, double sigma, double b, double h) const {
    double S_plus_h = S + h;
    double S_minus_h = S - h;

    double price_S_plus_h = Price(S_plus_h, K, t, r, sigma, b);
    double price_S_minus_h = Price(S_minus_h, K, t, r, sigma, b);
    double price_S = Price(S, K, t, r, sigma, b);

    return (price_S_plus_h - 2 * price_S + price_S_minus_h) / (h * h);
}

double EuropeanOption::Vega(double S, double K, double t, double r, double sigma, double b, double h) const {
    throw NotImplementedException();
}

double EuropeanOption::Theta(double S, double K, double t, double r, double sigma, double b, double h) const {
    throw NotImplementedException();
}

double EuropeanOption::Rho(double S, double K, double t, double r, double sigma, double b, double h) const {
    throw NotImplementedException();
}

bool EuropeanOption::put_call_parity(double C, double P, double K, double r, double t, double S) const {
    return C + K * exp(-r * t) == P + S;
}

// Put-Call Parity method for calculating the call price from put price
double EuropeanOption::parity_priceCall(double S, double K, double t, double r, double P) const {
    return P - K * exp(-r * t) + S;
}

// Put-Call Parity method for calculating the put price from call price
double EuropeanOption::parity_pricePut(double S, double K, double t, double r, double C) const {
    return C + K * exp(-r * t) - S;
}