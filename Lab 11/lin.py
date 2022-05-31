from string import ascii_letters
import matplotlib.pyplot  as plt
import time
import math
M_S = 3
def linear1(arr, x):
    arr.append(x)
    i = 0
    while arr[i] != x:
        if arr[i+1] != x:
            i+=2
            continue
        i+=1
    if i == len(arr)-1:
        return -1
    else:
        return i

def linear2(arr, x):
    pos = linear1(arr,x)
    while pos > 0:
        arr[pos],arr[pos-1] = arr[pos-1],arr[pos]
        pos-=1
    return 0

def linear3(arr, x):
    pos = linear1(arr,x)
    if pos == -1:
        return -1
    arr[pos],arr[pos-1] = arr[pos-1],arr[pos]
    return pos-1

def PlotFucntions(arr,title):
    l1_arr,l2_arr,l3_arr = [],[],[]
    for i in arr:

        temp = arr.copy()
        start_time = time.time()
        check = linear1(temp,i)
        l1_arr.append(time.time()-start_time)
        if temp[check] != i:
            raise "Not correct"
        
        temp = arr.copy()
        start_time = time.time()
        check = linear2(temp,i)
        l2_arr.append(time.time()-start_time)
        if temp[check] != i:
            raise "Not correct"

        temp = arr.copy()
        start_time = time.time()
        check = linear3(temp,i)
        l3_arr.append(time.time()-start_time)
        if temp[check] != i:
            raise "Not correct"
    plt.plot(l1_arr,'.',markersize=M_S,label = "lin1")
    plt.plot(l2_arr,'.',markersize=M_S,label = "lin2")
    plt.plot(l3_arr,'.',markersize=M_S,label = "lin3")
    plt.title(title)
    plt.legend()
    plt.show()

N = 1000
acs_arr = list(range(0,N))
dec_arr = list(range(N,0,-1))
normal_arr = []
for i in range(0,N//10):
    normal_arr.extend([i for j in range(10)])

PlotFucntions(acs_arr,"Acsending")
PlotFucntions(dec_arr,"Decsending")
PlotFucntions(normal_arr,"Nomral arr")
