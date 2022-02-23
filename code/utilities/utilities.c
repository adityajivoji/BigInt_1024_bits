char modifyBit(char n, int p, int b)
{
    int mask = 1 << p;
    return ((n & ~mask) | (b << p));
}

int getBit(char n, int k)
{
    return ((n >> k) & 1);
}