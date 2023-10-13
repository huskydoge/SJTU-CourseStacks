import time
import subprocess
import hashlib
import os
import math
import matplotlib.pyplot as plt
log_the_size_of_data = []
time_encoding_list_huff = []
time_encoding_list_huff_uniform = []
time_decoding_list_huff = []
time_decoding_list_huff_uniform = []
time_encoding_list_arit = []
time_encoding_list_arit_uniform = []
time_decoding_list_arit = []
time_decoding_list_arit_uniform = []
compression_rate_huff = []
compression_rate_huff_uniform = []
compression_rate_arit = []
compression_rate_arit_uniform = []
# generate a new random txt
def generate_random_txt(stroage_capacity):
    Random_Text = 'Text_Generator_R.py'
    subprocess.run(['python', Random_Text, str(stroage_capacity)])
    log_the_size_of_data.append(math.log(stroage_capacity, 3))
def generate_random_txt_uniform(storage_capacity):
    Random_Text = 'Text_Generator_R2.py'
    subprocess.run(['python', Random_Text, str(storage_capacity)])

# used for showing if we can get the original txt back
def file_hash(filename):
    with open(filename, 'rb') as f:
        return hashlib.md5(f.read()).hexdigest()
def test_adaptive_huffman():
    print("the performance of the adaptive huffman coding is as follows: ")
    files = ['encode.py', 'decode.py']
    time_list = []
    for file in files:
        start_time = time.time()
        subprocess.run(['python', file])
        end_time = time.time()
        run_time = end_time - start_time
        time_list += [run_time]

    Random_Text_size = os.path.getsize('test.txt')
    print("correctness:")
    if file_hash('test.txt') == file_hash('test_adaptive_huffman_decode.txt'):
        print('they are the same')
    else:
        print("they're different")

    print("time consume:")
    print(f"encode time: {time_list[0]}s ")
    print(f"decode time: {time_list[1]}s ")
    time_encoding_list_huff.append(time_list[0])
    time_decoding_list_huff.append(time_list[1])

    print("space consume:")
    adaptive_huffman_encode_size = os.path.getsize('test_adaptive_huffman_encode.txt')
    print(f"in this way the original file size {Random_Text_size}bytes is "
          f"compressed to {adaptive_huffman_encode_size}bytes")
    compression_rate_huff.append(adaptive_huffman_encode_size/Random_Text_size)

def test_adaptive_huffman_uniform():
    print("the performance of the adaptive huffman coding is as follows: ")
    files = ['encode.py', 'decode.py']
    time_list = []
    for file in files:
        start_time = time.time()
        subprocess.run(['python', file])
        end_time = time.time()
        run_time = end_time - start_time
        time_list += [run_time]

    Random_Text_size = os.path.getsize('test.txt')
    print("correctness:")
    if file_hash('test.txt') == file_hash('test_adaptive_huffman_decode.txt'):
        print('they are the same')
    else:
        print("they're different")

    print("time consume:")
    print(f"encode time: {time_list[0]}s ")
    print(f"decode time: {time_list[1]}s ")
    time_encoding_list_huff_uniform.append(time_list[0])
    time_decoding_list_huff_uniform.append(time_list[1])

    print("space consume:")
    adaptive_huffman_encode_size = os.path.getsize('test_adaptive_huffman_encode.txt')
    print(f"in this way the original file size {Random_Text_size}bytes is "
          f"compressed to {adaptive_huffman_encode_size}bytes")
    compression_rate_huff_uniform.append(adaptive_huffman_encode_size/Random_Text_size)

def test_adaptive_arithmetic():
    print("the performance of the adaptive arithmetic coding is as follows: ")

    start_time1 = time.time()
    subprocess.run(['python', './arithmetic_coding/adaptive-arithmetic-compress.py', 'test.txt',
                    'test_adaptive_arithmetic_encode.bin'])
    end_time1 = time.time()
    run_time1 = end_time1 - start_time1

    start_time2 = time.time()
    subprocess.run(
        ['python', './arithmetic_coding/adaptive-arithmetic-decompress.py', 'test_adaptive_arithmetic_encode.bin',
         'test_adaptive_arithmetic_decode.txt'])
    end_time2 = time.time()
    run_time2 = end_time2 - start_time2

    Random_Text_size = os.path.getsize('test.txt')
    print("correctness:")
    if file_hash('test.txt') == file_hash('test_adaptive_arithmetic_decode.txt'):
        print('they are the same')
    else:
        print("they're different")

    print("time consume:")
    print(f"encode time: {run_time1}s ")
    print(f"decode time: {run_time2}s ")
    time_encoding_list_arit.append(run_time1)
    time_decoding_list_arit.append(run_time2)

    print("space consume:")
    adaptive_arithmetic_encode_size = os.path.getsize('test_adaptive_arithmetic_encode.bin')
    print(
        f"in this way the original file size {Random_Text_size}bytes "
        f"is compressed to {adaptive_arithmetic_encode_size}bytes")
    compression_rate_arit.append(adaptive_arithmetic_encode_size/Random_Text_size)

def test_adaptive_arithmetic_uniform():
    print("the performance of the adaptive arithmetic coding is as follows: ")

    start_time1 = time.time()
    subprocess.run(['python', './arithmetic_coding/adaptive-arithmetic-compress.py', 'test.txt',
                    'test_adaptive_arithmetic_encode.bin'])
    end_time1 = time.time()
    run_time1 = end_time1 - start_time1

    start_time2 = time.time()
    subprocess.run(
        ['python', './arithmetic_coding/adaptive-arithmetic-decompress.py', 'test_adaptive_arithmetic_encode.bin',
         'test_adaptive_arithmetic_decode.txt'])
    end_time2 = time.time()
    run_time2 = end_time2 - start_time2

    Random_Text_size = os.path.getsize('test.txt')
    print("correctness:")
    if file_hash('test.txt') == file_hash('test_adaptive_arithmetic_decode.txt'):
        print('they are the same')
    else:
        print("they're different")

    print("time consume:")
    print(f"encode time: {run_time1}s ")
    print(f"decode time: {run_time2}s ")
    time_encoding_list_arit_uniform.append(run_time1)
    time_decoding_list_arit_uniform.append(run_time2)

    print("space consume:")
    adaptive_arithmetic_encode_size = os.path.getsize('test_adaptive_arithmetic_encode.bin')
    print(
        f"in this way the original file size {Random_Text_size}bytes "
        f"is compressed to {adaptive_arithmetic_encode_size}bytes")
    compression_rate_arit_uniform.append(adaptive_arithmetic_encode_size/Random_Text_size)

if __name__ == '__main__':
    storage_capacity = 1
    for i in range(10, 18 , 1):
        generate_random_txt(storage_capacity)
        # test_adaptive_huffman()
        test_adaptive_arithmetic()
        generate_random_txt_uniform(storage_capacity)
        # test_adaptive_huffman_uniform()
        test_adaptive_arithmetic_uniform()
        storage_capacity = 3**i


    # plt.plot(log_the_size_of_data, compression_rate_huff, label='Adaptive_huffman')
    plt.plot(log_the_size_of_data, compression_rate_arit, label="Adaptive_arithmetic")
    # plt.plot(log_the_size_of_data, compression_rate_huff_uniform, label='Adaptive_huffman_uniform')
    plt.plot(log_the_size_of_data, compression_rate_arit_uniform, label="Adaptive_arithmetic_uniform")
    plt.title('compression_rate -- log_the_size_of_data')
    plt.xlabel('log_the_size_of_data-axis')
    plt.ylabel('compression_rate-axis')
    plt.legend()
    plt.show()
    # plt.plot(log_the_size_of_data, time_encoding_list_huff, label='Adaptive_huffman')
    plt.plot(log_the_size_of_data, time_encoding_list_arit, label='Adaptive_arithmetic')
    # plt.plot(log_the_size_of_data, time_encoding_list_huff_uniform, label='Adaptive_huffman_uniform')
    plt.plot(log_the_size_of_data, time_encoding_list_arit_uniform, label='Adaptive_arithmetic_uniform')
    plt.title('encoding_time -- log_the_size_of_data')
    plt.xlabel('log_the_size_of_data-axis')
    plt.ylabel('encoding_time-axis')
    plt.legend()
    plt.show()
    # plt.plot(log_the_size_of_data, time_decoding_list_huff, label='Adaptive_huffman')
    plt.plot(log_the_size_of_data, time_decoding_list_arit, label='Adaptive_arithmetic')
    # plt.plot(log_the_size_of_data, time_decoding_list_huff_uniform, label='Adaptive_huffman_uniform')
    plt.plot(log_the_size_of_data, time_decoding_list_arit_uniform, label='Adaptive_arithmetic_uniform')
    plt.title('decoding_time -- log_the_size_of_data')
    plt.xlabel('log_the_size_of_data-axis')
    plt.ylabel('decoding_time-axis')
    plt.legend()
    plt.show()
