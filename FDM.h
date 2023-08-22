/* Level 9
 * by Jahaan Rawat
 */

#ifndef FDM_HPP
#define FDM_HPP

#include <vector>

namespace FDM {

    // Abstract base class for defining the properties of the one-factor model
    class OneFactorModel {
    public:
        virtual ~OneFactorModel() {}

        // Coefficients of PDE equation
        virtual double sigma(double x, double t) const = 0;
        virtual double mu(double x, double t) const = 0;
        virtual double b(double x, double t) const = 0;
        virtual double f(double x, double t) const = 0;

        // Boundary conditions
        virtual double BCL(double t) const = 0;
        virtual double BCR(double t) const = 0;

        // Initial condition
        virtual double IC(double x) const = 0;
    };

    class FDMSolver {
    private:
        const OneFactorModel& model;

        std::vector<double> vecOld;
        std::vector<double> vecNew;
        std::vector<double> xarr;

    public:
        FDMSolver(const OneFactorModel& model, double Smax, int J);

        void solve(double T, int N);

        const std::vector<double>& current() const;

    private:
        void calculateCoefficients(double tprev, double tnow, std::vector<double>& a,
            std::vector<double>& bb, std::vector<double>& c,
            std::vector<double>& RHS) const;
    };

}  // namespace FDM

#endif

