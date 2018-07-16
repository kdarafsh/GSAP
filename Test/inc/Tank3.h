// Copyright © 2018 United States Government as represented by the Administrator of the National
// Aeronautics and Space Administration.  All Rights Reserved.
#ifndef TANK3_H
#define TANK3_H

#include "Model.h"
#include <vector>

class Tank3 final : public PCOE::Model {
public:
    // Constructor
    Tank3() {
        numStates = 3;
        inputs = {"u1", "u2", "u3"};
        outputs = {"p1m", "p2m", "p3m"};
        m_dt = 1;
    }

    // State indices
    struct stateIndices {
        static const unsigned int m1 = 0;
        static const unsigned int m2 = 1;
        static const unsigned int m3 = 2;
    };
    // Input indices
    struct inputIndices {
        static const unsigned int u1 = 0;
        static const unsigned int u2 = 1;
        static const unsigned int u3 = 2;
    };
    // Output indices
    struct outputIndices {
        static const unsigned int p1m = 0;
        static const unsigned int p2m = 1;
        static const unsigned int p3m = 2;
    };
    // Indices
    struct allIndices {
        struct stateIndices states;
        struct inputIndices inputs;
        struct outputIndices outputs;
    } indices;

    // Parameters
    struct Parameters {
        double R1c2;
        double K3;
        double R3;
        double K1;
        double R2;
        double R1;
        double K2;
        double R2c3;
    } parameters;

    std::vector<double> stateEqn(const double t,
                                 const std::vector<double>& x,
                                 const std::vector<double>& u,
                                 const std::vector<double>& n,
                                 const double dt) const override;
    std::vector<double> outputEqn(const double t,
                                  const std::vector<double>& x,
                                  const std::vector<double>& u,
                                  const std::vector<double>& n,
                                  const std::vector<double>& z) const override;
    std::vector<double> initialize(const std::vector<double>& u,
                                   const std::vector<double>& z) const override;
};
#endif
