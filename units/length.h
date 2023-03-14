class Length {
    public:

    double value_in_meters();

    virtual Length operator+ (const Length & right);

    virtual Length operator- (const Length & right);

    virtual ~Length();
    
    static Length create_from_meters(double value);

    static Length create_from_feet(double value);

    private:

    double _value;

    Length(double value) : _value(value) {};

};
