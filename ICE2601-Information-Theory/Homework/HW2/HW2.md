Homework 2

DDL: March 15.

1. Cover book:  $2.8, 2.9, 2.10, 2.14, 2.15$
2. Prove the following equalites via **Expectation** and **fundamental law of probability theory**
   1. $I(X;Y) = H(X)-H(X|Y)$
   2. $I(X;Y)=H(X)+H(Y)-H(X;Y)$
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

