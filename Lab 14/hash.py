import random
import matplotlib.pyplot as plt

#Start parametrs
M1 = 1000
M = 60000
LIMIT_LEFT = -1
LIMIT_RIGHT = 1
N = 50000

def hash_func_gorner(key:tuple, P:int=29,SIZE: int = M)->int:
    hash = 0
    for i in key:
        hash = hash*P + i
    return int(hash)%int(SIZE)
def help_hash_func(key:tuple, P:int=6701,SIZE: int = M):
    hash = 0
    for i in key:
        hash = hash+ i
    return hash%P+1
def prepare_data(point:tuple):
    new_data = []
    for i in point:
        new_data.append(int(round(i,2)*100))
    return tuple(new_data)
def FindInTwoClosedHash(table,val):
    steps = 1
    hash = hash_func_gorner(prepare_data(val))
    start = hash
    while table[hash] != val:
        if table[hash] == None:
            return (False,steps)
        hash = (hash+help_hash_func(prepare_data(val)))%M
        if hash == start:
            return (False,steps)
        steps+=1
    return (True,steps)
def FindInOneClosedHash(table,val):
    steps = 1
    hash = hash_func_gorner(prepare_data(val))
    start = hash
    while table[hash] != val:
        if table[hash] == None:
            return (False,steps)
        hash = (hash+1)%M
        if hash == start:
            return (False,steps)
        steps+=1
    return (True,steps)
def FindInOpenHash(table,val):
    steps = 1
    hash = hash_func_gorner(prepare_data(val))
    arr = table[hash]

    for i in arr:
        if i == val:
            return (True,steps)
        steps+=1
    return (False,steps)
def mesuare_hash_table(points,random_points,hash_table,find_el):
    results = [[0],[0]]
    for point in random_points:
        res = find_el(hash_table,point)
        if res[0]:
            index = 0
        else:
            index = 1
        if len(results[index]) < res[1]:
            results[index].extend([0]*(res[1]-len(results[index])))
        results[index][res[1]-1] +=1

    figure, axis = plt.subplots(2, 1)
    axis[0].plot(results[0])
    axis[0].set_title("Found elements")
    axis[1].plot(results[1])
    axis[1].set_title("NotFound elements")
    plt.show()
#Gen points
points = []
random_points = []
for i in range(N):
    points.append((round(random.uniform(LIMIT_LEFT, LIMIT_RIGHT),2),round(random.uniform(LIMIT_LEFT, LIMIT_RIGHT),2),
                    round(random.uniform(LIMIT_LEFT, LIMIT_RIGHT),2)))
    random_points.append((round(random.uniform(LIMIT_LEFT, LIMIT_RIGHT),2),round(random.uniform(LIMIT_LEFT, LIMIT_RIGHT),2),
                    round(random.uniform(LIMIT_LEFT, LIMIT_RIGHT),2)))
buckets = [0 for i in range(M1)]
for point in points:
    buckets[hash_func_gorner(prepare_data(point),SIZE=M1)]+=1

plt.plot(buckets,'.',color='green', marker='.', markersize=1)
plt.plot([50000//M1 for i in range(M1)])
plt.show()

open_hashing = [[] for i in range(M)]
for point in points:
    open_hashing[hash_func_gorner(prepare_data(point))].append(point)
mesuare_hash_table(points,random_points,open_hashing,FindInOpenHash)
one_closed_hashing = [None]*M
for point in points:
    hash = hash_func_gorner(prepare_data(point))
    while one_closed_hashing[hash] != None:
        hash = (hash+1)%M
    one_closed_hashing[hash]= point
mesuare_hash_table(points,random_points,one_closed_hashing,FindInOneClosedHash)
two_closed_hashing = [None]*M
for point in points:
    hash = hash_func_gorner(prepare_data(point))
    while two_closed_hashing[hash] != None:
        hash = (hash+help_hash_func(prepare_data(point)))%M
    two_closed_hashing[hash]= point
mesuare_hash_table(points,random_points,two_closed_hashing,FindInTwoClosedHash)
