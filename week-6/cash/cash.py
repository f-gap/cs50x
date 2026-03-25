troco = -1
moedas = 0
while(troco < 0):
    troco = int(input("Change owed:"))
while(troco>=25):
    troco -= 25
    moedas+=1
while(troco>=10):
    troco -= 10
    moedas+=1
while(troco>=5):
    troco -= 5
    moedas+=1
while(troco>=1):
    troco -= 1
    moedas+=1
print(moedas)