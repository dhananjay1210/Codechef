n = int(input())
s = ''
for i in range(1, n + 1):
    s += str(i)


def maxp(m):
    #print(m)
    if len(m) == 2:
        return m[1] + ' ' + m[0] + ' '
    elif len(m) == 3:
        return m[1] + ' ' + m[2] + ' '+ m[0] + ' '
    else:
        if len(m) % 2 == 0:
            return maxp(m[:int(len(m) / 2)]) + maxp(m[int(len(m) / 2):])
        else:
            return maxp(m[:int(len(m) / 2)]) + maxp(m[int(len(m) / 2) :])


print(maxp(s))
print(s[-1],end=' ')
for i in range(len(s)-1):
    print(s[i],end=' ')
