#ifndef _STATE_MANAGER_H
#define _STATE_MANAGER_H

#include "debugable.h"
#include "timemanager.h"
#include "display.h"
#include "types.h"

class StateManager : public Debugable {
public:
	StateManager(TimeManager*, Display*, Config*);

	void init();

	void loop(unsigned long);

	/**
	 * The button was simply pressed
	 */
	void buttonPressed();

		/**
		 * The button was long pressed (1s)
		 */
	void buttonLongPressed();

		/**
		 * The rotary encoder was increased
		 */
	void encoderIncrease();

	/**
	 * The rotary encoder was decreased
	 */
	void encoderDecrease();

	/**
	 * Get the current state
	 */
	state_type getCurrentState();


private:
	TimeManager* timeManager;
	Display* display;
	Config* config;

	void applyButtonPressed();
	void applyButtonLongPressed();
	void applyEncoderDelta(int);
	void applyEncoderDeltaChangeBrightness(int);
	void applyEncoderDeltaChangeHue(int);
	void applyEncoderDeltaChangeSaturation(int);
	void applyEncoderDeltaChangeHour(int);
	void applyEncoderDeltaChangeMinute(int);

	bool isButtonPressed;
	bool isButtonLongPressed;
	int encoderDelta;

	state_type currentState;

	void debugState();
	int applyDeltaOnValue(int,int,int,int, bool);


};
#endif
