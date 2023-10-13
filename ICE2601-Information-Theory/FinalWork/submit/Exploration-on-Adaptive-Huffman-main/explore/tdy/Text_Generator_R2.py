import pickle
import random
import math
import sys

def main(args):
    with open('probs_uniform.pkl', 'rb') as f:
        char_probabilities = pickle.load(f)
    new_text = ""
    storage_capacity = int(args[0])
    for i in range(storage_capacity):
        rand_char = random.choices(list(char_probabilities.keys()), weights=char_probabilities.values())[0]
        new_text += rand_char

    new_file = open('test.txt', 'w', encoding='utf-8')
    new_file.write(new_text)
    new_file.close()



if __name__ == '__main__':
    main(sys.argv[1:])