import hashlib
def file_hash(filename):
    with open(filename, 'rb') as f:
        return hashlib.md5(f.read()).hexdigest()

if file_hash('test.txt') == file_hash('test_decode.txt'):
    print('they are the same')
else:
    print("they're different")