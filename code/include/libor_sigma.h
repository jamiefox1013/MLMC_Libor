
#ifndef CODE_SRC_LIBOR_SIGMA_H_
#define CODE_SRC_LIBOR_SIGMA_H_

#include <vector>
#include <mlmc_libor_types.h>

namespace mlmcLibor {

	class LiborSigma {
	    public:
	        LiborSigma();

	        //Initialize matrix sigma according to the given size and type of initialization, calibrate parameters if desired
	        LiborSigma(int sigSize, char sigma_type, bool calibrate = false);
	        virtual ~LiborSigma();

	        //Returns reference to the matrix sigma
	        const Matrix& GetSigma() const;


	    private:
	        int sigmaSize;
	        //Matrix of volatility values for each forward rate and each accrual period
	        Matrix sigma;

            //Initialize sigma using predefined parameters and different parametric forms
            void SetSigma1();
            void SetSigma2();
            void SetSigma3();

            //Implement in future
            //Initialize matrix sigma using with calibrated parameters
            void Calibrate();



	};
}

#endif /* CODE_SRC_LIBOR_SIGMA_H_ */
