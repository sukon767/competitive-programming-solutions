n,k=map(int,input().split())
s=input()
for i in range(n):
    print(end=s[i*pow(2,k,n)%n])
print()