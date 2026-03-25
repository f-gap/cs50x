altura=0
while (altura < 1 or altura > 8):
    altura = int(input("Height: "))
for i in range(altura):
    for j in range(altura - i):
        print(" ", end="")
    for k in range(i+1):
        print("#",end="")
    print(" ",end="")
    for l in range(i+1):
        print("#",end="")
    print("")
