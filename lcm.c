
unsigned int    lcm(unsigned int a, unsigned int b)
{
    unsigned int multiple;

    if (a == 0 || b == 0)
        return 0;
    multiple = a;
    while (multiple % b != 0)
        multiple += a;
    return (multiple);
}