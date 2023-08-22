/* Level 9
 * by Jahaan Rawat
 */

#include "FDM.h"
#include <algorithm>

namespace FDM {

    FDMSolver::FDMSolver(const OneFactorModel& mod, double Smax, int J) : model(mod) {
        double h = Smax / static_cast<double>(J);
        xarr.resize(J + 1);
        for (int i = 0; i <= J; ++i) {
            xarr[i] = i * h;
        }
        vecOld.resize(xarr.size());
        vecNew.resize(xarr.size());
        for (int i = 0; i <= J; ++i) {
            vecOld[i] = model.IC(xarr[i]);
        }
    }

    void FDMSolver::calculateCoefficients(double tprev, double tnow, std::vector<double>& a,
        std::vector<double>& bb, std::vector<double>& c,
        std::vector<double>& RHS) const {
        double k = tnow - tprev;
        double h = xarr[1] - xarr[0];

        for (size_t j = 1; j < xarr.size() - 1; ++j) {
            double tmp1 = k * (model.sigma(xarr[j], tprev) / (h * h));
            double tmp2 = k * ((model.mu(xarr[j], tprev) * 0.5) / h);
            a[j - 1] = tmp1 - tmp2;
            bb[j - 1] = 1.0 - (2.0 * tmp1) + (k * model.b(xarr[j], tprev));
            c[j - 1] = tmp1 + tmp2;
            RHS[j - 1] = k * model.f(xarr[j], tprev);
        }
    }

    void FDMSolver::solve(double T, int N) {
        double k = T / static_cast<double>(N);
        vecNew = vecOld;

        for (int n = 1; n <= N; ++n) {
            double tnow = n * k;
            std::vector<double> a(xarr.size() - 2), bb(xarr.size() - 2), c(xarr.size() - 2), RHS(xarr.size() - 2);
            calculateCoefficients((n - 1) * k, tnow, a, bb, c, RHS);

            vecNew[0] = model.BCL(tnow);
            vecNew[vecNew.size() - 1] = model.BCR(tnow);

            for (size_t i = 1; i < vecNew.size() - 1; ++i) {
                vecNew[i] = (a[i - 1] * vecOld[i - 1]) + (bb[i - 1] * vecOld[i]) + (c[i - 1] * vecOld[i + 1]) - RHS[i - 1];
            }

            vecOld = vecNew;
        }
    }

    const std::vector<double>& FDMSolver::current() const {
        return vecNew;
    }

}  // namespace FDM

