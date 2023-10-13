from collections import Counter
import pickle

with open('entropy.txt', 'r', encoding='utf-8') as file:
    text = file.read()

char_counts = Counter(text)

char_probabilities = {char: 1 / len(char_counts) for char, count in char_counts.items()}


with open('probs_uniform.pkl', 'wb') as f:
    pickle.dump(char_probabilities, f)