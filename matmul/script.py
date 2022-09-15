import os

def run():
    # run matmul3 4096 16 and save output to matmul3_4096_16.txt
    os.system("./matmul3 4096 16 > matmul3_4096_16.txt")
    os.system("./matmul3 4096 32 > matmul3_4096_32.txt")
    os.system("./matmul3 4096 64 > matmul3_4096_64.txt")
    os.system("./matmul3 4096 128 > matmul3_4096_128.txt")

if __name__ == "__main__":
    run()