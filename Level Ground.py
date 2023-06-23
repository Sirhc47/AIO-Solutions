groundin = open('groundin.txt', 'r').readlines()
groundout = open('groundout.txt', 'w')
n = int(groundin[0].strip())
altitudes = groundin[1].split()
altitudes = list(map(int, altitudes))
currentstreak = 0
maxnumber = 0
currentnumber = 0
for i in altitudes:
    if i == currentnumber:
        currentstreak += i
 
    else:
        if currentstreak > maxnumber:
            maxnumber = currentstreak
        currentstreak = i
        currentnumber = i
if currentstreak > maxnumber:
    maxnumber = currentstreak
groundout.write(str(maxnumber))
print(maxnumber)
