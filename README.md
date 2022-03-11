# Chandu-Chandni-Decryption-Problem

# Problem Statement:
Chandu and Chandni talk on phone for a long time daily. Being afraid that someone will hear
their private conversation, Chandu suggested Chandni an idea. He suggested that he will talk
only with encrypted strings with her and only she would know how to decrypt the string. So that
even if someone hears, He/She would not be able to anticipate their conversation.
Rules of encryption are as follows:
1. String on length N is assumed to be cyclic consisting of lower case English alphabets.
(cyclic string: We call a string cyclic if it can be obtained by concatenating another string
to itself many times (for example, s2 = "abcabcabcabc..." is cyclic since it can be
obtained from s1 = "abc" in such a way)).
2. In each iteration, we pick the last character and put it in the starting of the string. For
example: april performing iterations and collecting each string formed in a set until we
get the original string. Ex: {april,lapri, ilapr, rilap, prila}
3. Sort the set of strings in lexicographically reverse order. Ex: {rilap, prila,lapri, ilapr,
april}
4. Taking the last character of each string in the set is the encrypted string. Ex: pairl
Chandu also sends the position(K) of first letter in encrypted string from original string i.e 2 (p is
on position 2 in original string and is the first character of encrypted string) Now, Chandni is
ofcourse not that brilliant to decrypt the strings in real time and understand what chandu is
saying. So, Chandu decided to write a program for the same.
Help chandu write this program.
(USE HEAP SORT)
Input:
First line contains an integer t, which is the number of test cases. Next t lines contain an
encrypted string and K as described above.
Output:
Print the decrypted string for each test case.
----------------------------
Sample Input
2
d 1
pairl 2
Sample Output
d
april
---------------------------

-- Language Used: C
