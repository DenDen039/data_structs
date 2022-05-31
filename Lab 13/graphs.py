import matplotlib.pyplot as plt
import pandas as pd

figure, axis = plt.subplots(3, 3)

r,c = 0,0
for i in range(8):
    level = pow(2,i)
    df = pd.read_csv(f'{level}.csv')
    axis[r, c].set_title(f'Imax = {level}')
    axis[r, c].plot(df["index"],df["moves"]+df["overall_moves"])
    c+=1
    if c == 3:
        c = 0
        r+=1
plt.show()
for i in range(8):
    level = pow(2,i)
    df = pd.read_csv(f'{level}.csv')
    plt.title(f'Imax = {level}')
    plt.plot(df["index"],df["moves"]+df["overall_moves"])
    plt.show()
