#include "BlackScholesModel.h"
#include <cmath>

BlackScholesModel::BlackScholesModel(double r, double vol, double K)
    : r(r), vol(vol), K(K) {}

double BlackScholesModel::sigma(double x, double t) const {
    return 0.5 * this->vol * this->vol * x * x;
}

double BlackScholesModel::mu(double x, double t) const {
    return (r - 0.5 * this->vol * this->vol) * x;
}

double BlackScholesModel::b(double x, double t) const {
    return -r;
}

double BlackScholesModel::f(double x, double t) const {
    return 0.0;
}

double BlackScholesModel::BCL(double t) const {
    return 0.0;
}

double BlackScholesModel::BCR(double t) const {
    return 1e10;  // a very large value for a European call option with no upper limit
}

double BlackScholesModel::IC(double x) const {
    return std::max(x - K, 0.0);
}
