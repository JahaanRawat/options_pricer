#ifndef BLACKSCHOLESMODEL_HPP
#define BLACKSCHOLESMODEL_HPP

#include "FDM.h"

class BlackScholesModel : public FDM::OneFactorModel {
private:
    double r;   // risk-free rate
    double vol; // volatility
    double K;   // strike price
public:
    BlackScholesModel(double r, double vol, double K);
    double sigma(double x, double t) const override;
    double mu(double x, double t) const override;
    double b(double x, double t) const override;
    double f(double x, double t) const override;
    double BCL(double t) const override;
    double BCR(double t) const override;
    double IC(double x) const override;
};

#endif

