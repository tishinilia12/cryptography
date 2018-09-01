
from fractions import Fraction
from time import time


def extended_gcd(aa, bb):
    lastremainder, remainder = abs(aa), abs(bb)
    x, lastx, y, lasty = 0, 1, 1, 0
    while remainder:
        lastremainder, (quotient, remainder) = \
            remainder, divmod(lastremainder, remainder)
        x, lastx = lastx - quotient*x, x
        y, lasty = lasty - quotient*y, y
    return lastremainder, lastx * (-1 if aa < 0 else 1), \
           lasty * (-1 if bb < 0 else 1)


def modinv(a, m):
    g, x, y = extended_gcd(a, m)
    if g != 1:
        raise ValueError
    if (x*a)%m!=1:
        raise ValueError
    return x % m
start = time()
x1 = 147
y1 =1881488
Point = [x1, y1]
a = 797
b = 99411806
n = 103240037
NextPoint = Point
k = 1
#
m = Fraction(3 * NextPoint[0]**2 + a, 2 * NextPoint[1])
m = m.numerator * modinv(m.denominator, n)
while True:
    x = (m**2 - NextPoint[0] - Point[0]) % n
    y = (m * (NextPoint[0] - x) - NextPoint[1]) % n
    k += 1
    NextPoint = [x, y]
    #print(f'x = {x} y={y}')
    if Point[0] - NextPoint[0] == 0:
        print(f'k = {k + 1}')
        break;
    if Point != NextPoint:
        m = Fraction(Point[1] - NextPoint[1], Point[0] - NextPoint[0])
        m = m.numerator * modinv(m.denominator, n)                                        
end = time()
print(f'Time: {end - start} sec\n')