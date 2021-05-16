char * intToRoman(int val){  
    // Special number
    int numbers[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char romanSymbol[][3] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int length = 13, last;

    // Declaring the result char array
    char *roman = (char *)calloc(20, sizeof(char));

    for (last = 0; last < length && val>0; last++)
    {
        int quot = val / numbers[last];
        val %= numbers[last];
        while (quot--)
        {
            strcat(roman, romanSymbol[last]); // concating string
        }
    }
    return roman;
}