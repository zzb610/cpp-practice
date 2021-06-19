void example(int a, int b)
{
}
int main(int argc, char const *argv[])
{
    using func = void (*)(int, int);
    typedef void (*func)(int, int);

    func fn = example;
    return 0;
}
