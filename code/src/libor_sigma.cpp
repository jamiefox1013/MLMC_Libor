
#include "libor_sigma.h"
#include <iostream>

namespace mlmcLibor {
    LiborSigma::LiborSigma(int sigSize, char sigma_type, bool calibrate)
        : sigma(sigSize, Vector(sigSize, 0.0)) {

        if (calibrate) {
            Calibrate();
        }
        else {
            switch(sigma_type) {
                case '1' :
                    SetSigma1();
                    break;

                case '2' :
                    SetSigma2();
                    break;

                case '3' :
                    SetSigma3();
                    break;
                default :
                    std::cout << "invalid initialization of Sigma" << std::endl;
            } //End switch
        }
    } //End constructor

    LiborSigma::~LiborSigma() {
    }

    const Matrix& LiborSigma::GetSigma() const {
        return sigma;
    }

    void LiborSigma::SetSigma1() {

    }

    void LiborSigma::SetSigma2() {

    }

    void LiborSigma::SetSigma3() {

    }

    void LiborSigma::Calibrate() {

    }
}

