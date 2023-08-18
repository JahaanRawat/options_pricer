/* Level 9 Group B
 * by Jahaan Rawat
 */

#include "PerpetualAmericanOption.h"
#include <cmath>
#include "OptionTypeException.h"

// Helper function to calculate y1
double calculate_y1(double S, double K, double r, double sigma, double b) {
    return (0.50 - b/pow(sigma, 2)) + sqrt(pow((b/pow(sigma, 2) - 0.5), 2) + 2*r/pow(sigma, 2));
}

// Helper function to calculate y2
double calculate_y2(double S, double K, double r, double sigma, double b) {
    return (0.50 - b/pow(sigma, 2)) - sqrt(pow((b/pow(sigma, 2) - 0.5), 2) + 2*r/pow(sigma, 2));
}

// Helper function for pricing 
double _get_price(double S, double K, double y) {
    return (K/(y - 1)) * pow((((y - 1)/y) * (S / K)), y);
}

// Function to return a string of option type
std::string PerpetualAmericanOption::getName() const {
    std::string type;
    PerpetualAmericanOption::isCall() ? type = "Call " : type = "Put ";  return type + name;
}

// Function for pricing the Perpetual option option
double PerpetualAmericanOption::Price(double S, double K, double t, double r, double sigma, double b) const {
    double y1 = calculate_y1(S, K, r, sigma, b);
    double y2 = calculate_y2(S, K, r, sigma, b);

    if (PerpetualAmericanOption::isCall()) {
        return _get_price(S, K, y1);
    }
    else {
        return -1.0 * _get_price(S, K, y2);
    }
}

// Function for calculating Delta
double PerpetualAmericanOption::Delta(double S, double K, double t, double r, double sigma, double b) const {
    throw NotImplementedException();
}

// Function for calculating Gamma
double PerpetualAmericanOption::Gamma(double S, double K, double t, double r, double sigma, double b) const {
    throw NotImplementedException();
}

double PerpetualAmericanOption::Vega(double S, double K, double t, double r, double sigma, double b) const {
    throw NotImplementedException();
}

double PerpetualAmericanOption::Theta(double S, double K, double t, double r, double sigma, double b) const {
    throw NotImplementedException();
}

double PerpetualAmericanOption::Rho(double S, double K, double t, double r, double sigma, double b) const {
    throw NotImplementedException();
}

// Central difference method to calculate Delta
double PerpetualAmericanOption::Delta(double S, double K, double t, double r, double sigma, double b, double h) const {
    double S_plus_h = S + h;
    double S_minus_h = S - h;

    double price_plus_h = Price(S_plus_h, K, t, r, sigma, b);
    double price_minus_h = Price(S_minus_h, K, t, r, sigma, b);

    return (price_plus_h - price_minus_h) / (2 * h);
}

// Central difference method to calculate Gamma
double PerpetualAmericanOption::Gamma(double S, double K, double t, double r, double sigma, double b, double h) const {
    double S_plus_h = S + h;
    double S_minus_h = S - h;

    double price_S_plus_h = Price(S_plus_h, K, t, r, sigma, b);
    double price_S_minus_h = Price(S_minus_h, K, t, r, sigma, b);
    double price_S = Price(S, K, t, r, sigma, b);

    return (price_S_plus_h - 2 * price_S + price_S_minus_h) / (h * h);
}

double PerpetualAmericanOption::Vega(double S, double K, double t, double r, double sigma, double b, double h) const {
    throw NotImplementedException();
}

double PerpetualAmericanOption::Theta(double S, double K, double t, double r, double sigma, double b, double h) const {
    throw NotImplementedException();
}

double PerpetualAmericanOption::Rho(double S, double K, double t, double r, double sigma, double b, double h) const {
    throw NotImplementedException();
}

bool PerpetualAmericanOption::put_call_parity(double C, double P, double K, double r, double t, double S) const {
    throw PutCallParityException();
}

// Put-Call Parity method for calculating the call price from put price
double PerpetualAmericanOption::parity_priceCall(double S, double K, double t, double r, double P) const {
    throw PutCallParityException();
}

// Put-Call Parity method for calculating the put price from call price
double PerpetualAmericanOption::parity_pricePut(double S, double K, double t, double r, double C) const {
    throw PutCallParityException();
}