#ifndef PRIVATE_COPY_H
#define PRIVATE_COPY_H

class PrivateCopy
{
public:
    PrivateCopy() = default;
    ~PrivateCopy();

private:
    PrivateCopy(const PrivateCopy &);
    PrivateCopy &operator=(const PrivateCopy &);
};

#endif /* PRIVATE_COPY_H */
