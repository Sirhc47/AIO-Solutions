tspin = open('tspin.txt', 'r').readlines()
tspout = open('tspout.txt', 'w')
print(tspin)
n = int(tspin[0].strip())
least = tspin[1].split()
least = list(map(int, least))
most = tspin[2].split()
most = list(map(int, most))
print(least)
print(most)
tomato = 0
works = 1
for i in range(n):
    if least[i] > tomato:
        tomato = least[i]
    elif tomato >= least[i] and tomato <= most[i]:
        tomato = tomato
    else:
        works = 0
        break
if works == 0:
    tspout.write('NO')
    print('NO')
else:
    tspout.write('YES')
    print('YES')
