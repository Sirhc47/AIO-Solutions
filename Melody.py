import statistics
 
melodyin = open('melodyin.txt', 'r').read()
melodyout = open('melodyout.txt', 'w')
n = int(melodyin.split()[0])
k = melodyin.split()[1]
splitmelodyin = melodyin.split()
firstlist = []
secondlist = []
thirdlist = []
for i in range(0,int((n)/3)):
    firstlist.append(int(splitmelodyin[3*i+2]))
    secondlist.append(int(splitmelodyin[3*i+3]))
    thirdlist.append(int(splitmelodyin[3*i+4]))
 
print(firstlist,secondlist,thirdlist)
commonfirst = statistics.mode(firstlist)
commonsecond = statistics.mode(secondlist)
commonthird = statistics.mode(thirdlist)
print(commonfirst,commonsecond,commonthird)
 
notfirst = 0
notsecond = 0
notthird = 0
for a in firstlist:
    if a != commonfirst:
        notfirst = notfirst + 1
for b in secondlist:
    if b != commonsecond:
        notsecond = notsecond + 1
for c in thirdlist:
    if c != commonthird:
        notthird = notthird + 1
print(notfirst,notsecond,notthird)
melodyout.write(str(notfirst+notsecond+notthird))
