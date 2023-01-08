import matplotlib.pyplot as plt 
import numpy as np

N = [64, 128, 512, 1024, 2048, 4096, 8192]

time_ijk = [0.16224, 1.52422, 90.1777, 723.99, 6383.18, 54650.3, 492854]
time_row_blocked = [0.047742 ,0.311857 ,23.3013 ,196.81 ,1891.33 ,15236.1 ,218995]

plt.figure()
fig, ax = plt.subplots()
ax.set_xlabel('Matrix size')
ax.set_ylabel('Time taken in ms')
ax.set_title('Time vs Matrix size for Matrix Multiplication')
ax.plot(N, time_ijk, label='ijk loop')
ax.scatter(N, time_ijk)
ax.plot(N, time_row_blocked, label='Row blocked version,  block size = 32')
ax.scatter(N, time_row_blocked)

ax.text(0, 400000, "matrix sizes are: 64, 128, 512, 1024, 2048, 4096, 8192")

ax.legend()
fig.savefig(f'plot')