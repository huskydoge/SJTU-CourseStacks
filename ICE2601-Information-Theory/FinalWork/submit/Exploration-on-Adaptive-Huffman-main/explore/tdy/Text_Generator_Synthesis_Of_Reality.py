from collections import Counter
import pickle


with open('entropy.txt', 'r', encoding='utf-8') as file:
    text = file.read()


char_counts = Counter(text)
total_chars = len(text)
char_probabilities = {char: count / total_chars for char, count in char_counts.items()}


with open('probs.pkl', 'wb') as f:
    pickle.dump(char_probabilities, f)

