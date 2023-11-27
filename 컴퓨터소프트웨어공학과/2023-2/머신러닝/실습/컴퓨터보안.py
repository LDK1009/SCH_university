import math
result = 0
a=51
n=55

for i in range(1,28):
    result = math.pow(a,i)%n
    print("{}^{} mod {} = {}".format(a,i,n,result))
