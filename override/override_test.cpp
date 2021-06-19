

struct Base
{
    // 只有虚函数才能被覆写
    virtual void vfunc(float) {}
};

struct Derived : Base
{
    virtual void vfunc(float) override {}
};