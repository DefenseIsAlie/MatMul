import os

def run():
    # run matmul3 4096 16 and save output to matmul3_4096_16.txt
    dim_val = [1024, 2048, 4096]
    block_val = [16, 32, 64, 128]
    for question in range(3, 4):
        for dim in dim_val:
            res_list = [0] * 6
            if question == 3:
                for block in block_val:
                    res_list = [0] * 6
                    # run matmul3 5 times and save output to matmul3_4096_16.txt
                    for i in range(5):
                        res = os.popen('./bin/matmul{} {} {}'.format(question, dim, block)).read()
                        result = [float(x) for x in res.split(",")]
                        res_list = [x + y for x, y in zip(res_list, result)]
                    res_list = [x / 5 for x in res_list]
                    for i in range(len(res_list)):
                        if i != 4:
                            res_list[i] = int(res_list[i])
                    res_list = [question, dim, block] + res_list
                    with open('matmul3.txt', 'a') as f:
                        f.write(','.join([str(x) for x in res_list]) + '\n')
                        # f.write(res_list.__str__() + '\n')
            else:
                res_list = [0] * 6
                # run matmul3 5 times and save output to matmul1,2
                for i in range(5):
                    res = os.popen('./bin/matmul{} {}'.format(question, dim)).read()
                    result = [float(x) for x in res.split(",")]
                    res_list = [x + y for x, y in zip(res_list, result)]
                res_list = [x / 5 for x in res_list]
                for i in range(len(res_list)):
                    if i != 4:
                        res_list[i] = int(res_list[i])
                res_list = [question, dim] + res_list
                with open('matmul{}.txt'.format(question), 'a') as f:
                    f.write(','.join([str(x) for x in res_list]) + '\n')
                    # f.write(res_list.__str__() + '\n')



if __name__ == "__main__":
    run()
  