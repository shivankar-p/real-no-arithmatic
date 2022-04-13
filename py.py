def fromDigits(digits, b):
    """Compute the number given by digits in base b."""
    n = 0
    for d in digits:
        n = b * n + d
        print(n)

fromDigits([1,0,1,0,1,0],4)