/* Level 9 Group A
 * by Jahaan Rawat
 */

#ifndef OPTION_EVALS_H
#define OPTION_EVALS_H

#include <iostream>
#include <vector>
#include "Option.h"

using namespace std;

std::vector<double> createMesh(double start, double end, double meshSize);
std::vector<double> createMesh_mult(double start, double end, double meshSize);

std::vector<double> S_pricer_call(vector<double> S_mesh, Option& option);
std::vector<double> S_pricer_put(vector<double> S_mesh, Option& option);

std::vector<double> exp_pricer_call(vector<double> exp_mesh, Option& option);
std::vector<double> exp_pricer_put(vector<double> exp_mesh, Option& option);

std::vector<double> Sig_pricer_call(vector<double > Sig_mesh, Option& option);
std::vector<double> Sig_pricer_put(vector<double > Sig_mesh, Option& option);

std::vector<double> matrixPricer_call(vector<vector<double>> optionParam, Option& option);
std::vector<double> matrixPricer_put(vector<vector<double>> optionParam, Option& option);

std::vector<double> matrixDelta_call(vector<vector<double>> optionParam, Option& option);
std::vector<double> matrixDelta_put(vector<vector<double>> optionParam, Option& option);

std::vector<double> matrixGamma_call(vector<vector<double>> optionParam, Option& option);
std::vector<double> matrixGamma_put(vector<vector<double>> optionParam, Option& option);
#endif 


