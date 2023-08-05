#include<bits/stdc++.h>
using namespace std;
/*
here we have given with some different structure
one node of list contain data next pointer and also one random pointer
out work is just to clone the list

Approach1
we will copy the entire link list without random pointer and then again we will traverse the list and will check at how much distance does random pointer is pointing and we will attach that pointer at same distance in our clonelist
TC---0(n^2);
SC---0(1);

Approach2
we will copy the entire link list without random pointer ...now we wil create mapping between oldnode and new node ...map<originalnode, clone node>;
so now we will traverse original list and we will find random pointer and using map we will allocate them in clone list .. .we will use unordered map so that its we can access its value in 0(1)
TC---0(n);
SC---0(n);

Approach3
now we need to optimise the space ... what if we do not creatae map but originaly create a link between them ..... than we can take similar step and make our clone rady 
but we need to link both list with some more changes as we are linking them together then we are losing the track of next part of link we need to handle that also ... so we will link them in kind of sawtooth structure .....
BOTH LIST WITHOUT LINKAGE..we are not showing random pointer
 1 ---- 2-----3------4-------NULL

 1 ---- 2-----3------4-------NULL
 
BOTH LIST AFTER LINKAGE

1    2----     3----     4---- 
|    |   |     |   |     |   |
|    |   |     |   |     |   |
|    |   |     |   |     |   |
1----    2-----    3-----    4----NULL

now we will have track aso and we can attach random pointer after that we will revert the changes .
TC---0(n);
SC---0(1)
*/
int main(){
    
    return 0;
}