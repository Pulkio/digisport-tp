#include "length.h"


Length::~Length() {}

Length Length::operator+(const Length & right) const {
    return Length(this->_value + right._value);
}

Length Length::create_from_meters(double value) {
    return Length(value);
}

Length Length::create_from_feet(double value) {
    return Length(value * foot_in_meters);
}

double Length::value_in_meters() {
    return _value;
}

Length Length::operator-(const Length &right) const {
    return Length(this->_value - right._value);
}

double Length::value_in_feet() {
    return _value / foot_in_meters;
}

