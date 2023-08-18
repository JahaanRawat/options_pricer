/* Level 9 Group A
 * by Jahaan Rawat
 */

 // Multiple functions for evaulating multiple options
#include "OptionEvaluators.h"

std::vector<double> createMesh(double start, double end, double meshSize) {
    std::vector<double> mesh;
    double current = start;

    while (current <= end) {
        mesh.push_back(current);
        current += meshSize;
    }

    return mesh;
}

std::vector<double> createMesh_mult(double start, double end, double meshSize) {
    std::vector<double> mesh;
    double current = start;

    while (current > end) {
        mesh.push_back(current);
        current *= meshSize;
    }

    return mesh;
}

std::vector<double> S_pricer_call(std::vector<double> S_mesh, Option& option) {
    vector<double> returnvec;
    for (int i = 0; i < S_mesh.size(); i++) {
        option.S(S_mesh[i]);
        returnvec.push_back(option.call_price());
    }
    return returnvec;
}

std::vector<double> S_pricer_put(vector<double> S_mesh, Option& option) {
    vector<double> returnvec;
    for (int i = 0; i < S_mesh.size(); i++) {
        option.S(S_mesh[i]);
        returnvec.push_back(option.put_price());
    }
    return returnvec;
}

std::vector<double> exp_pricer_call(std::vector<double> exp_mesh, Option& option) {
    vector<double> returnvec;
    for (int i = 0; i < exp_mesh.size(); i++) {
        option.S(exp_mesh[i]);
        returnvec.push_back(option.call_price());
    }
    return returnvec;
}

std::vector<double> exp_pricer_put(vector<double> exp_mesh, Option& option) {
    vector<double> returnvec;
    for (int i = 0; i < exp_mesh.size(); i++) {
        option.S(exp_mesh[i]);
        returnvec.push_back(option.put_price());
    }
    return returnvec;
}

std::vector<double> Sig_pricer_call(std::vector<double> Sig_mesh, Option& option) {
    vector<double> returnvec;
    for (int i = 0; i < Sig_mesh.size(); i++) {
        option.S(Sig_mesh[i]);
        returnvec.push_back(option.call_price());
    }
    return returnvec;
}

std::vector<double> Sig_pricer_put(vector<double> Sig_mesh, Option& option) {
    vector<double> returnvec;
    for (int i = 0; i < Sig_mesh.size(); i++) {
        option.S(Sig_mesh[i]);
        returnvec.push_back(option.put_price());
    }
    return returnvec;
}

std::vector<double> matrixPricer_call(vector<vector<double>> optionParam, Option& option) {
    vector<double> returnvec;
    for (int i = 0; i < optionParam.size(); i++) {
        option.assignParam(optionParam[i]);
        returnvec.push_back(option.call_price());
    }
    return returnvec;
}

std::vector<double> matrixPricer_put(vector<vector<double>> optionParam, Option& option) {
    vector<double> returnvec;
    for (int i = 0; i < optionParam.size(); i++) {
        option.assignParam(optionParam[i]);
        returnvec.push_back(option.put_price());
    }
    return returnvec;
}

std::vector<double> matrixDelta_call(vector<vector<double>> optionParam, Option& option) {
    vector<double> returnvec;
    for (int i = 0; i < optionParam.size(); i++) {
        option.assignParam(optionParam[i]);
        returnvec.push_back(option.call_delta());
    }
    return returnvec;
}

std::vector<double> matrixDelta_put(vector<vector<double>> optionParam, Option& option) {
    vector<double> returnvec;
    for (int i = 0; i < optionParam.size(); i++) {
        option.assignParam(optionParam[i]);
        returnvec.push_back(option.put_delta());
    }
    return returnvec;
}

std::vector<double> matrixGamma_call(vector<vector<double>> optionParam, Option& option) {
    vector<double> returnvec;
    for (int i = 0; i < optionParam.size(); i++) {
        option.assignParam(optionParam[i]);
        returnvec.push_back(option.call_gamma());
    }
    return returnvec;
}

std::vector<double> matrixGamma_put(vector<vector<double>> optionParam, Option& option) {
    vector<double> returnvec;
    for (int i = 0; i < optionParam.size(); i++) {
        option.assignParam(optionParam[i]);
        returnvec.push_back(option.put_gamma());
    }
    return returnvec;
}
