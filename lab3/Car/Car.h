#pragma once
#include "stdafx.h"
#include "CarConst.h"

typedef std::pair<int, int> Speed;
typedef std::map<Gear, Speed> SpeedsRange;
extern const SpeedsRange speedsRange;

class CCar
{
public:
	int GetGear() const;
	int GetCurrentSpeed() const;
	Direction GetDirection() const;
	bool IsTurnOnEngine() const;
	bool TurnOnEngine();
	bool TurnOffEngine();

	bool SetGear(int gear);
	bool SetSpeed(int speed);

	bool IsNeutralGear() const;
	bool IsSpeedInRange(Gear const& gear, int speed) const;
	bool CheckGear(int gear) const;

private:
	bool m_isEngineOn = false;
	Gear m_currentGear = Gear::NEUTRAL_GEAR;
	int m_speed = 0;
};