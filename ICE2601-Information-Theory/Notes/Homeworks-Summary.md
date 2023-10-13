#信息论 #习题 

# Homework 1

1. Show that $x\log x\to 0$, as $x\to 0$. 

2. Show that $H(p) = -p\log p - (1-p)\log (1-p)$ is concave in $p\in [0,1]$.

3. Prove $H(X)\le\log |\mathcal{X}|$ via Lagrange multipler when $|\mathcal{X}|=3$
   $$
   \min f(x,y,z)=x\log x + y\log y + z\log z\\
   s.t \ \ x+y+z=1\\
   x,y,z\geq 0
   $$
   Consider its Lagrangian:
   $$
   g(x,y,z;\lambda) = f(x,y,z)-\lambda(x+y+z)
   $$
   (a). Compute $\nabla g$, i.e., the partial derivatives of $g$ with resepct to $x, y, z$; 

   (b). Let $\nabla  g = 0$, show that $x=y=z$. Thus, $\min f$ is attained only if $x=y=z$.

4. Exercise **2.1, 2.2, 2.5, 2.6, <mark style="background: #FF5582A6;">2.7</mark>** in the textbook of Cover  



# Homework 2
1. Cover book:  $2.8, 2.9, 2.10, 2.14, 2.15$
2. Prove the following equalites via **Expectation** and **fundamental law of probability theory**
   1. $I(X;Y) = H(X)-H(X|Y)$
   2. $I(X;Y)=H(X)+H(Y)-H(X,Y)$
   3. $I(X;Y|Z) = H(X|Z)+H(Y|Z)-H(X,Y|Z)$
3. Prove that

   1. $D(p||q)=0$ if and only if $p(x)=q(x)$
   2. $I(X;Y)=0$  if and only if $X$ and $Y$ are independent 
   3. $D(p(y│x)||q(y│x))=0$ if and only if $p(y|x) = q(y|x)$  for all $y$ and $x$ such that $p(x)>0$
   4. $I (X; Y|Z) = 0$ if and only if $X$ and $Y$ are conditionally independent given $Z$
4. Give $p(z|x,y)=p(z|y)$, show that $p(x|y,z) = p(x|y)$ (That is $X\to Y\to Z$ forms a MC. However, you need to prove it via probability theory argument)
5. Prove via information diagram

   1. Prove that under the constraint that $X→Y→Z$ forms a Markov chain, $X⊥Y|Z$ and $X⊥Z$ imply $X⊥Y$ 
   2. Prove that the implication in (a) continues to be valid without the Markov chain constraint.
   3. Prove that $Y⊥Z|T$ implies $Y⊥Z|(X,T)$ conditioning on $X→Y→Z→T$.
   4. Let $X→Y→Z→T$ form a Markov chain. Determine which of the following inequalities always hold:
      1. $I(X;T)+I (Y ;Z)≥ I (X;Z)+I (Y ;T)$
      2. $I(X;T)+I (Y ;Z)≥ I (X;Y )+I (Z;T)$
      3. $I (X;Y )+I (Z;T)≥ I (X;Z)+I (Y ;T)$


# Homework 3

1. Cover:  2.18, 2.20, 2.21,  2.27, 2.29, 2.32, 2.40
2. Cover: 3.1, 3.3, 3.13

# Homework 4


1. Cover: 4.1, 4.3, <mark style="background: #FF5582A6;">4.6</mark>, <mark style="background: #FF5582A6;">4.7</mark>, 4.10, 4.12, 4.15, 4.20, 4.33, 4.34
2. Optional: 4.21, 4.30

# Homework 5


1. Cover:  5.3, 	5.4,	 5.7,	 5.8, 	5.9, 	5.13,   5.16, 	5.28, 	5.32

# Homework 6


1. Cover:  	7.2,		7.4,		7.5, 		7.8,		7.10,		<mark style="background: #FF5582A6;">7.13</mark>,		7.14,		7.16,		7.23,		7.28

# Homework 8


1. Cover:  	7.32,		7.34,		7.35,		8.1,		9.1,		9.2,		9.4	



