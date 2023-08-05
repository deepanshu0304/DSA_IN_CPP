#include<bits/stdc++.h>
using namespace std;
/* it contain basically 3 type of question 
1.)we need to detect the loop if present in link list
2.) remove the loop if present
3.)if present we need to detect the starting point
 */
/*loop can be detected by using map structure we will maintain a visited map which will store if 
we already traversed this node or not and during our complete traverse if we have visited any node twice
then the cycle is surely present also the starting point is same node we traversed two time
here space complex is more so we will use another method  */

/*floyd detect algo 
we will maintain two var fast and slow .. slow will traverse one at time and fast will jump two at time
now if at any point during complete traversal fast and slow pointer overlap then the cycle will be there 
and if not then it is not cyclic the node at which they meet may not be starting node but it is surely a part
of cycle
 */
/*now we need to find the starting node ....after applying floyed detect loop again start your slow pointer from head and keep you fast pointer at the plaace where it was and increase slow and fast pointer each by one step
wherer they meet it will be starting point it can be proved by useing math*/
/*in order to remove loop you need to find dthe last node of loop which yo can easily do and then cahnge its next to null */

int main(){
    
    return 0;
}