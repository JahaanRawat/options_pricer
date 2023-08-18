/* Level 9 Group A
 * by Jahaan Rawat
 */


#include "Option.h"
#include "OptionTypeException.h"
#include "OptionException.h"
#include <vector>

Option::Option(const Option& other) {
    _T = other._T;
    _K = other._K;
    _sig = other._sig;
    _r = other._r;
    _S = other._S;
    _b = other._b;
    _R = other._R;
    _q = other._q;
}

Option& Option::operator=(const Option& other) {
    if (this == &other) {
        return *this;
    }
    _T = other._T;
    _K = other._K;
    _sig = other._sig;
    _r = other._r;
    _S = other._S;
    _b = other._b;
    _R = other._R;
    _q = other._q;
    
    return *this;
}    

// Set functions
void Option::assignParam(std::vector<double> param) {
    _T = param[0];
    _K = param[1];
    _sig = param[2];
    _r = param[3];
    _S = param[4];
    _b = param[5];
    _R = param[6];
    _q = param[7];
}

void Option::setOption(std::unique_ptr<OptionType> optionType) {
    option = std::move(optionType);
    containsOption = true;
}

void Option::T(double newT) {
    _T = newT;
}

void Option::K(double newK) {
    _K = newK;
}

void Option::sig(double newSig) {
    _sig = newSig;
}

void Option::r(double newr) {
    _r = newr;
}

void Option::S(double newS) {
    _S = newS;
}

void Option::b(double newb) {
    _b = newb;
}

void Option::R(double newR) {
    _R = newR;
}

void Option::q(double newq) {
    _q = newq;
}

// Get functions
std::string Option::getOption() {
    return option->getName();
}

double Option::T() const {
    return _T;
}

double Option::K() const {
    return _K;
}

double Option::sig() const {
    return _sig;
}

double Option::r() const {
    return _r;
}

double Option::S() const {
    return _S;
}

double Option::b() const {
    return _b;
}

double Option::R() const {
    return _R;
}

double Option::q() const {
    return _q;
}

// Pricing
double Option::call_price() const {
    try {
        if (!containsOption) {
            throw NoOptionException();
        }
        if (!option->isCall()) {
            option->toggle();
        }
        return option->Price(_S, _K, _T, _r, _sig, _b);
    }
    catch (const OptionTypeException& ex) {
        std::cout << "Error occurred: " << ex.display_error() << std::endl;
    }
    catch (const NoOptionException& ex) {
        std::cout << "Error occurred: " << ex.display_error() << std::endl;
    }
    return -1.0;
}

double Option::put_price() const {
    try {
        if (!containsOption) {
            throw NoOptionException();
        }
        if (option->isCall()) {
            option->toggle();
        }
        return option->Price(_S, _K, _T, _r, _sig, _b);
    }
    catch (const OptionTypeException& ex) {
        std::cout << "Error occurred: " << ex.display_error() << std::endl;
    }
    catch (const NoOptionException& ex) {
        std::cout << "Error occurred: " << ex.display_error() << std::endl;
    }
    return -1.0;
}

// Put Call parity functions
double Option::PCp_callPrice(double P) const {
    try {
        if (!containsOption) {
            throw NoOptionException();
        }
        return option->parity_priceCall(_S, _K, _T, _r, P);
    }
    catch (const OptionTypeException& ex) {
        std::cout << "Error occurred: " << ex.display_error() << std::endl;
    }
    return -1.0;
}

double Option::PCp_putPrice(double C) const {
    try {
        if (!containsOption) {
            throw NoOptionException();
        }
        return option->parity_pricePut(_S, _K, _T, _r, C);
    }
    catch (const OptionTypeException& ex) {
        std::cout << "Error occurred: " << ex.display_error() << std::endl;
    }
    return -1.0;
}

bool Option::PCp_equality(double C, double P) const {
    try {
        if (!containsOption) {
            throw NoOptionException();
        }
        return option->put_call_parity(C, P, _K, _r, _T, _S);
    }
    catch (const OptionTypeException& ex) {
        std::cout << "Error occurred: " << ex.display_error() << std::endl;
    }
    return false;
}

// Exact solutions for Greeks
double Option::call_delta() const {
    try {
        if (!containsOption) {
            throw NoOptionException();
        }
        if (!option->isCall()) {
            option->toggle();
        }
        return option->Delta(_S, _K, _T, _r, _sig, _b);
    }
    catch (const OptionTypeException& ex) {
        std::cout << "Error occurred: " << ex.display_error() << std::endl;
    }
    return -1.0; 
}

double Option::put_delta() const {
    try {
        if (!containsOption) {
            throw NoOptionException();
        }
        if (option->isCall()) {
            option->toggle();
        }
        return option->Delta(_S, _K, _T, _r, _sig, _b);
    }
    catch (const OptionTypeException& ex) {
        std::cout << "Error occurred: " << ex.display_error() << std::endl;
    }
    return -1.0; 
}

double Option::call_gamma() const {
    try {
        if (!containsOption) {
            throw NoOptionException();
        }
        if (!option->isCall()) {
            option->toggle();
        }
        return option->Gamma(_S, _K, _T, _r, _sig, _b);
    }
    catch (const OptionTypeException& ex) {
        std::cout << "Error occurred: " << ex.display_error() << std::endl;
    }
    return -1.0;
}

double Option::put_gamma() const {
    try {
        if (!containsOption) {
            throw NoOptionException();
        }
        if (option->isCall()) {
            option->toggle();
        }
        return option->Gamma(_S, _K, _T, _r, _sig, _b);
    }
    catch (const OptionTypeException& ex) {
        std::cout << "Error occurred: " << ex.display_error() << std::endl;
    }
    return -1.0;
}

double Option::call_vega() const {
    try {
        if (!containsOption) {
            throw NoOptionException();
        }
        if (!option->isCall()) {
            option->toggle();
        }
        return option->Vega(_S, _K, _T, _r, _sig, _b);
    }
    catch (const OptionTypeException& ex) {
        std::cout << "Error occurred: " << ex.display_error() << std::endl;
    }
    return -1.0; 
}

double Option::put_vega() const {
    try {
        if (!containsOption) {
            throw NoOptionException();
        }
        if (option->isCall()) {
            option->toggle();
        }
        return option->Vega(_S, _K, _T, _r, _sig, _b);
    }
    catch (const OptionTypeException& ex) {
        std::cout << "Error occurred: " << ex.display_error() << std::endl;
    }
    return -1.0; 
}

double Option::call_theta() const {
    try {
        if (!containsOption) {
            throw NoOptionException();
        }
        if (!option->isCall()) {
            option->toggle();
        }
        return option->Theta(_S, _K, _T, _r, _sig, _b);
    }
    catch (const OptionTypeException& ex) {
        std::cout << "Error occurred: " << ex.display_error() << std::endl;
    }
    return -1.0;
}

double Option::put_theta() const {
    try {
        if (!containsOption) {
            throw NoOptionException();
        }
        if (option->isCall()) {
            option->toggle();
        }
        return option->Theta(_S, _K, _T, _r, _sig, _b);
    }
    catch (const OptionTypeException& ex) {
        std::cout << "Error occurred: " << ex.display_error() << std::endl;
    }
    return -1.0;
}

double Option::call_rho() const {
    try {
        if (!containsOption) {
            throw NoOptionException();
        }
        if (!option->isCall()) {
            option->toggle();
        }
        return option->Rho(_S, _K, _T, _r, _sig, _b);
    }
    catch (const OptionTypeException& ex) {
        std::cout << "Error occurred: " << ex.display_error() << std::endl;
    }
    return -1.0;
}

double Option::put_rho() const {
    try {
        if (!containsOption) {
            throw NoOptionException();
        }
        if (option->isCall()) {
            option->toggle();
        }
        return option->Rho(_S, _K, _T, _r, _sig, _b);
    }
    catch (const OptionTypeException& ex) {
        std::cout << "Error occurred: " << ex.display_error() << std::endl;
    }
    return -1.0;
}

// Divided differences method
double Option::call_delta(double h) const {
    try {
        if (!containsOption) {
            throw NoOptionException();
        }
        if (!option->isCall()) {
            option->toggle();
        }
        return option->Delta(_S, _K, _T, _r, _sig, _b, h);
    }
    catch (const OptionTypeException& ex) {
        std::cout << "Error occurred: " << ex.display_error() << std::endl;
    }
    return -1.0;
}

double Option::put_delta(double h) const {
    try {
        if (!containsOption) {
            throw NoOptionException();
        }
        if (option->isCall()) {
            option->toggle();
        }
        return option->Delta(_S, _K, _T, _r, _sig, _b, h);
    }
    catch (const OptionTypeException& ex) {
        std::cout << "Error occurred: " << ex.display_error() << std::endl;
    }
    return -1.0;
}

double Option::call_gamma(double h) const {
    try {
        if (!containsOption) {
            throw NoOptionException();
        }
        if (!option->isCall()) {
            option->toggle();
        }
        return option->Gamma(_S, _K, _T, _r, _sig, _b, h);
    }
    catch (const OptionTypeException& ex) {
        std::cout << "Error occurred: " << ex.display_error() << std::endl;
    }
    return -1.0;
}

double Option::put_gamma(double h) const {
    try {
        if (!containsOption) {
            throw NoOptionException();
        }
        if (option->isCall()) {
            option->toggle();
        }
        return option->Gamma(_S, _K, _T, _r, _sig, _b, h);
    }
    catch (const OptionTypeException& ex) {
        std::cout << "Error occurred: " << ex.display_error() << std::endl;
    }
    return -1.0;
}

double Option::call_vega(double h) const {
    try {
        if (!containsOption) {
            throw NoOptionException();
        }
        if (!option->isCall()) {
            option->toggle();
        }
        return option->Vega(_S, _K, _T, _r, _sig, _b, h);
    }
    catch (const OptionTypeException& ex) {
        std::cout << "Error occurred: " << ex.display_error() << std::endl;
    }
    return -1.0;
}

double Option::put_vega(double h) const {
    try {
        if (!containsOption) {
            throw NoOptionException();
        }
        if (option->isCall()) {
            option->toggle();
        }
        return option->Vega(_S, _K, _T, _r, _sig, _b, h);
    }
    catch (const OptionTypeException& ex) {
        std::cout << "Error occurred: " << ex.display_error() << std::endl;
    }
    return -1.0;
}

double Option::call_theta(double h) const {
    try {
        if (!containsOption) {
            throw NoOptionException();
        }
        if (!option->isCall()) {
            option->toggle();
        }
        return option->Theta(_S, _K, _T, _r, _sig, _b, h);
    }
    catch (const OptionTypeException& ex) {
        std::cout << "Error occurred: " << ex.display_error() << std::endl;
    }
    return -1.0;
}

double Option::put_theta(double h) const {
    try {
        if (!containsOption) {
            throw NoOptionException();
        }
        if (option->isCall()) {
            option->toggle();
        }
        return option->Theta(_S, _K, _T, _r, _sig, _b, h);
    }
    catch (const OptionTypeException& ex) {
        std::cout << "Error occurred: " << ex.display_error() << std::endl;
    }
    return -1.0;
}

double Option::call_rho(double h) const {
    try {
        if (!containsOption) {
            throw NoOptionException();
        }
        if (!option->isCall()) {
            option->toggle();
        }
        return option->Rho(_S, _K, _T, _r, _sig, _b, h);
    }
    catch (const OptionTypeException& ex) {
        std::cout << "Error occurred: " << ex.display_error() << std::endl;
    }
    return -1.0;
}

double Option::put_rho(double h) const {
    try {
        if (!containsOption) {
            throw NoOptionException();
        }
        if (option->isCall()) {
            option->toggle();
        }
        return option->Rho(_S, _K, _T, _r, _sig, _b, h);
    }
    catch (const OptionTypeException& ex) {
        std::cout << "Error occurred: " << ex.display_error() << std::endl;
    }
    return -1.0;
}
