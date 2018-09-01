s = []
with open('LongMsgKAT_256.txt') as f:
    for line in f:
        if line.startswith('MD'):
            s.append(line.split()[2])

s1, s2 = s

res = int(s1, 16) ^ int(s2, 16)

print(bin(res).count('1'))
