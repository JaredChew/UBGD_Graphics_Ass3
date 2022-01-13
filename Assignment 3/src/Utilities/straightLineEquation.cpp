#include "straightLineEquation.h"

float Utilities::StraightLineEquation::gradiantFromTwoPoint(const float& x1, const float& y1, const float& x2, const float& y2) {

	return (y2 - y1) / (x2 - x1);

}

float Utilities::StraightLineEquation::gradiantFromIntersection(const float& y, const float& x, const float& intersection) {

	return (y - intersection) / x;

}

float Utilities::StraightLineEquation::perpendicularGradiant(const float& gradiant) {

	return -1 / gradiant;

}

float Utilities::StraightLineEquation::intersectingPoint(const float& y, const float& x, const float& gradiant) {

	return y - (gradiant * x);

}

float Utilities::StraightLineEquation::yPosAtXPos(const float& x, const float& gradiant, const float& intersection) {

	return (gradiant * x) + intersection;

}

float Utilities::StraightLineEquation::xPosAtYPos(const float& y, const float& gradiant, const float& intersection) {

	return (y - intersection) / gradiant;

}