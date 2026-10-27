unsigned char	reverse_bits(unsigned char octet)
{
    unsigned char result;
    int i;

    i = 8;
    result = 0;
    while (i-- > 0)
    {
        result = result * 2 + (octet % 2);
        octet = octet / 2;
    }
    return (result);
}