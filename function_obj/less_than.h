class LessThan
{
public:
    LessThan(int val) : val_(val) {}
    int ComVal() const { return val_; }
    int ComVal(int val) { val_ = val; }
    bool operator()(int value) const { return value < val_; }

private:
    int val_;
};
