#ifndef NOCOPY_H
#define NOCOPY_H
struct NoCopy
{

    NoCopy(const NoCopy &) = delete;
    
    NoCopy &operator=(const NoCopy &) = delete;

    NoCopy() = default;
    ~NoCopy() = default;
};

#endif /* NOCOPY_H */
