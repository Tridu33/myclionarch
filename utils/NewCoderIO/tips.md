做题的时候，经常遇到范围是2^63，取模2^64的这种题目。遇到这种限制条件时就要想到用unsigned long long类型。

可以简洁地声明为typedef unsigned long long ull。这样，如果ull类型的整数溢出了，就相当于取模2^64了。因为ull的范围是[0,2^64-1]。

而ll的范围是[-2^63,2^63-1]，因为有符号的第63位表示“正负”而不表示数值