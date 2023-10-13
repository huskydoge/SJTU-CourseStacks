import string
import pickle
import random
import numpy as np

def uniform_continous(long):
    fileName=(r'uniform_continous_test\uniform_continous_l{}.txt'.format(long))
    with open(fileName,'w',encoding='utf-8')as file:
        for s in string.ascii_lowercase:
            file.write(s*int(long / 26))
    

def uniform_discontinous(long):
    fileName=r'uniform_discontinous_test\uniform_discontinous_l{}.txt'.format(long)
    with open(fileName,'w',encoding='utf-8')as file:
        for i in range(0, int(long / 26)):
            file.write("abcdefghijklmnopqrstuvwxyz")


def simulate_real_txt(long):
    with open('probs.pkl', 'rb') as f:
        char_probabilities = pickle.load(f)

    fileName=r'simulate_real_test\simulate_real_l{}.txt'.format(long)
    new_text = ""
    for i in range(long):
        rand_char = random.choices(list(char_probabilities.keys()), weights=char_probabilities.values())[0]
        new_text += rand_char

    with open(fileName,'w',encoding='utf-8')as file:
        file.write(new_text)



def normal_distribution_txt(long):


    fileName=r'normal_distribution.test\normal_distribution_l{}.txt'.format(long)
    new_text = ""
    for i in range(long):
        rand_char = np.random.normal(13, 26)  
        new_text += (chr(int(rand_char % 26) + ord('a')))

    with open(fileName,'w',encoding='utf-8')as file:
        file.write(new_text)




for i in range(25,50):
    i = i / 2.5
    print(i)

    uniform_continous(int(2**i))
    uniform_discontinous(int(2**i))
    simulate_real_txt(int(2**i))
    normal_distribution_txt(int(2**i))
