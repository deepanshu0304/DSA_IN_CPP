/*
Q.) Problem Link - https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
*/

// ANSWER  (we are not taking input .....The code is in the GFG format.

   bool isSafe(int newx,int newy,vector<vector<int>> &m, int n,vector<vector<int>>&visited){  // invoked by function solve
        if(newx>=0 && newx<n && newy<n && newy>=0 && visited[newx][newy]==0 && m[newx][newy]==1){
            return true;
        }
        else{
            return false;
        }
    }

 void solve(vector<vector<int>> &m, int n,vector<vector<int>>& visited,vector<string>& ans,   // invoked by entry function findPath
    int xcor,int ycor,string &path){
        if(xcor==n-1 && ycor==n-1){
            ans.push_back(path);
        //   path.pop_back();
        //   return;
        }
        visited[xcor][ycor]=1;
        
        //down
        int newx = xcor + 1;
        int newy = ycor;
        if(isSafe(newx,newy,m,n,visited)){
            path.push_back('D');
            func(m,n,visited,ans,newx,newy,path);
           
        }
        //left
        newx = xcor;
        newy = ycor-1;
        if(isSafe(newx,newy,m,n,visited)){
            path.push_back('L');
            func(m,n,visited,ans,newx,newy,path);
            
        }
        //right
        newx = xcor;
        newy = ycor+1;
        if(isSafe(newx,newy,m,n,visited)){
            path.push_back('R');
            func(m,n,visited,ans,newx,newy,path);}
          
            
        //up
        newx = xcor -1;
        newy = ycor;
        if(isSafe(newx,newy,m,n,visited)){
            path.push_back('U');
            func(m,n,visited,ans,newx,newy,path);
            
        
        }
        
        visited[xcor][ycor]=0;
        path.pop_back();
    }


 

     vector<string> findPath(vector<vector<int>> &m, int n) {  /// Entry function
        vector<string> ans;
        if(m[0][0]==0){
            return ans;
        }
        vector<vector<int>> visited(n , vector<int>(n,0));
  
        string path = "";
        int xcor = 0, ycor = 0;
        solve(m,n,visited,ans,xcor,ycor,path);
        sort(ans.begin(),ans.end());
        return ans;
    }
