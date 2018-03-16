#ifndef CODE_SRC_MLMC_LIBOR_CONTROLLER_H_
#define CODE_SRC_MLMC_LIBOR_CONTROLLER_H_

#include <mlmc_libor_types.h>

namespace mlmcLibor {

    class ForwardRates {
        public:
            Matrix finePath;
            Matrix coarsePath;
    };

	class MlmcLiborController {
	    public:

            // Disable default constructor, copy constructor, and assignment operator to
            // enforce no copy policy, as this object makes calls to external resources
            // that we don't control.
            MlmcLiborController()=delete;
            MlmcLiborController(const MlmcLiborController& lhs, const MlmcLiborController& rhs)=delete;
            const MlmcLiborController& operator=(const MlmcLiborController& rhs)=delete;

	        // Alternate constructor
//	        MlmcLiborController(/*sigmaByRef, optionTypeByRef*/);

	        // Default destructor
	        ~MlmcLiborController();

	        // Calculates difference in payouts between fine and coarse levels
	        void calculatePayoutSum(Vector& payoutSum, const int sampleSize, const int level);

	    private:

	        // Calculates forward rate for both fine and course levels
	        void calculateForwardRate(ForwardRates& forwardRates);

            const int numberOfPayoutDates_;
            const int accrualPeriod_; //Time difference between each payout date; normally 0.25 or 0.5
            const int finalMaturityTime_;
            const int numeraire_; //Time reference for dollar amounts
	};
}

#endif /* CODE_SRC_MLMC_LIBOR_CONTROLLER_H_ */
