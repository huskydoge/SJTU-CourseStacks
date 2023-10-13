import numpy

x = [2, 2, -2, -1, 0, 0, 0, 0, 0]
y = [3, -3, 2, -1, -1, 0, 0, 0, 0]
N = 9

X = numpy.fft.fft(x)
Y = numpy.fft.fft(y)

z = []
for i in range(N):
    z.append(X[i] * Y[i])

print(z)

Z = numpy.fft.ifft(z)
print(Z)
