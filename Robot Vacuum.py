robotin = open('robotin.txt', 'r').readlines()
robotout = open('robotout.txt', 'w')
x = int(robotin[0])
n = 0
e = 0
s = 0
w = 0
for i in robotin[1]:
    if i == 'N':
        n = n + 1
    if i == 'E':
        e = e + 1
    if i == 'S':
        s = s + 1
    if i == 'W':
        w = w + 1
total = abs(s - n) + abs(e - w)
print(total)
robotout.write(str(total))
