n=input("Enter number of strings: ")
n=int(n)
arr=[]
for i in range(1,n+1):
    item=input("Enter string: ")
    arr.append(item)
prefix=[]
for i in range(0,len(arr)-1):
    pre=""
    k=0
    for j in range(i+1,len(arr)):
        w1=arr[i]
        w2=arr[j]
        while(k<len(w1) and k<len(w2) and w1[k]==w2[k]):
            pre=pre+w1[k]
            k=k+1
        if(len(pre)>0 and pre not in prefix):
            prefix.append(pre)
if(len(prefix)>0):
    print(max(prefix,key=len))
else:
    print("-1")