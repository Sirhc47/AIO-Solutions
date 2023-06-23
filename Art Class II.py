artin = open("artin.txt", "r").readlines()
artout = open("artout.txt", "w")
n = int(artin[0])
xlist = []
ylist = []
for i in range(1, n+1):
    xlist.append(int(artin[i].split()[0]))
    ylist.append(int(artin[i].split()[1]))
maxx = max(xlist)
minx = min(xlist)
maxy = max(ylist)
miny = min(ylist)
artout.write(str((maxx-minx)*(maxy-miny)))
