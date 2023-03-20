#pragma once

class Length {
public:

    virtual double value_in_meters();

    virtual double value_in_feet();

    virtual Length operator+(const Length &right) const;

    virtual Length operator-(const Length &right) const;

    virtual ~Length();

    static Length create_from_meters(double value);

    static Length create_from_feet(double value);

private:

    double _value;

    Length(double value = 0.0) : _value(value) {};

    constexpr static const double foot_in_meters = 0.3048;
};
