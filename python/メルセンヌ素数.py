n = 11213
j = 0
k = 0
i = 0
judge = True

while True:
    j = 2**n - 1
    k = 2**(n - 1)
    print(str(n))
    i = 3
    while i < k:
        if j % i == 0:
            judge = False
            break
        i += 2
    if judge == False:
        judge = True
    else:
        print("     " + str(j))
    n +=1