#include <typeinfo>
#include <cstring>
#include <string>
class MyString
{
public:
    MyString() : m_data(nullptr), m_len(0) {}

    MyString(const char *s) : m_len(strlen(s))
    {
        _init_data(s);
    }

    MyString(const MyString &rhs) : m_len(rhs.m_len)
    {
        _init_data(rhs.m_data);
    }

    MyString &operator=(const MyString &rhs)
    {
        if (this != &rhs)
        {
            if (m_data)
            {
                delete m_data;
            }
            m_len = rhs.m_len;
            _init_data(rhs.m_data);
        }
        return *this;
    }

    MyString &operator=(MyString &&rhs)
    {
        if (this != &rhs)
        {
            if (m_data)
            {
                delete m_data;
            }

            // move
            m_len = rhs.m_len;
            m_data = rhs.m_data;

            // important !!!
            rhs.m_len = 0;
            rhs.m_data = nullptr;
        }
    }

    virtual ~MyString()
    {
        if (m_data)
        {
            delete m_data;
        }
    }

    bool operator<(const MyString &rhs) const
    {
        return std::string(m_data) < std::string(rhs.m_data);
    }

    bool operator==(const MyString &rhs) const
    {
        return std::string(m_data) < std::string(rhs.m_data);
    }

    char *get()
    {
        return m_data;
    }

private:
    void _init_data(const char *s)
    {
        m_data = new char[m_len + 1];
        memcpy(m_data, s, m_len);
        m_data[m_len] = '\0';
    }
    char *m_data;
    std::size_t m_len;
};