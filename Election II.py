elecin = open('elecin.txt', 'r').read().split()
elecout = open('elecout.txt', 'w')
n = int(elecin[0])
a = 0
b = 0
c  = 0
for l in elecin[1]:
    if l == 'B':
        b += 1
    if l == 'A':
        a += 1
    if l == 'C':
        c += 1
print(a, b, c)
list = [a, b, c]
list.sort()
if list[1] == list[2]:
    elecout.write('T')
    print('T')
else:
    if a > b and a > c:
        elecout.write('A')
        print('A')
    elif b > a and b > c:
        elecout.write('B')
        print('B')
    elif c > a and c > b:
        elecout.write('C')
        print('C')
