#import "length.h"


Length::~Length() {}

Length Length::operator+(const Length & right) {
    return Length(this->_value + right._value);
}

Length Length::create_from_meters(double value) {
    return Length(value);
}

Length Length::create_from_feet(double value) {
    return Length(value * 0.33);
}

double Length::value_in_meters() {
    return _value;
}

Length Length::operator-(const Length &right) {
    return Length(this->_value - right._value);
}

