#include <stdio.h>
#include <string.h>

size_t  ft_strlen(const char *str);
char    *ft_strcpy(char *dest, const char *src);

int main(void) {
    const char *testString1 = "1223";
    const char *testString2 = "";
    const char *testString3 = "AabBz\nZ";
    const char *testString4 = "adios;h phs9hpiodvc \nS ADHSASYDFpoup893y0987yu \tKLjhSAd";
    // STRLEN
    printf("ft_strlen: %ld, strlen: %ld\n", ft_strlen(testString1), strlen(testString1));
    printf("ft_strlen: %ld, strlen: %ld\n", ft_strlen(testString2), strlen(testString2));
    printf("ft_strlen: %ld, strlen: %ld\n", ft_strlen(testString3), strlen(testString3));
    printf("ft_strlen: %ld, strlen: %ld\n", ft_strlen(testString4), strlen(testString4));

    // STRCPY
    const char *s1 = "Hello world!";
    char s2[50];
    char s2_[50];
    strcpy(s2, s1);
    ft_strcpy(s2_, s1);
    printf("ft_strcpy: '%s', strcpy: '%s'\n", s2_, s2);


    return 0;
}
