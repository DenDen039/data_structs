import matplotlib.pyplot  as plt
import numpy as np
import math
M_S = 3
def bin_search(arr,x):
    low = 0
    high = len(arr) - 1
    mid = 0
    steps = 0
    while low < high:
        mid = (high + low) // 2
        steps+=1
        if x > arr[mid]:
            low = mid + 1
        elif x < arr[mid]:
            high = mid - 1
        else:
            return mid,steps
    if arr[low] == x:
        return low,steps
    if arr[high] == x:
        return high,steps
    raise str("Can't find")
    return -1
def int_search(arr,x):
    low = 0
    high = len(arr) - 1
    mid = 0
    steps = 0
    while arr[low] < x and arr[high] > x:
        if low == high:
            break

        steps+=1
        mid = low + ((x - arr[low]) * (high - low)) // (arr[high] - arr[low])

        if x > arr[mid]:
            low = mid + 1
        elif x < arr[mid]:
            high = mid - 1
        else:
            return mid,steps

    if arr[low] == x:
        return low,steps
    if arr[high] == x:
        return high,steps
    raise str("Wrong answer")
    return -1


START,END,STEP = 0,20.1,0.01
arr_f1,arr_f2,arr_f3 = [], [], []

counter = START
while counter <= END:
    arr_f1.append(int(14*counter*10000))
    counter+=STEP
counter = START+0.1
while counter <= END:
    arr_f2.append(int(100*math.log(counter)*10000))
    counter+=STEP
counter = START
while counter <= END:
    arr_f3.append(int(0.03*counter*counter*counter*10000))
    counter+=STEP

steps1b,steps2b,steps3b = [],[],[]
steps1i,steps2i,steps3i = [],[],[]
for i in arr_f1:
    steps1i.append(int_search(arr_f1,i)[1])
    steps1b.append(bin_search(arr_f1,i)[1])
plt.plot(steps1b,'.',markersize=M_S,label = "binary_search")
plt.plot(steps1i,'.',markersize=M_S,label = "int_search")
plt.title("f1")
plt.legend()
plt.show()
for i in arr_f2:
    steps2i.append(int_search(arr_f2,i)[1])
    steps2b.append(bin_search(arr_f2,i)[1])
plt.plot(steps2b,'.',markersize=M_S,label = "binary_search")
plt.plot(steps2i,'.',markersize=M_S,label = "int_search")
plt.legend()
plt.title("f2")
plt.show()
for i in arr_f3:
    steps3i.append(int_search(arr_f3,i)[1])
    steps3b.append(bin_search(arr_f3,i)[1])
plt.plot(steps3b,'.',markersize=M_S,label = "binary_search")
plt.plot(steps3i,'.',markersize=M_S,label = "int_search")
plt.legend()
plt.title("f3")
plt.show()