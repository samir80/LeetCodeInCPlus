class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        map<int,int> mapVisitedStop;
        map<int,int> mapLeastTake;
        queue<int> queStop;
        int find = 0;
        
        //BFS
       for(int i = 0; i < routes.size(); i++){
           for(int j=0; j< routes[i].size(); j++){
               if(mapVisitedStop.find(routes[i][j]) == mapVisitedStop.end())
                   mapVisitedStop.insert(pair<int,int>(routes[i][j],0));
           }
       }
       queStop.push(S);
       mapVisitedStop[S] = 1;
       mapLeastTake[S] = 0; 
       while(queStop.size()){
           int nCurrentStop = queStop.front();
           queStop.pop();
           //no need to take a bus
           if(nCurrentStop == T){
               find = 1;
               break;    
           }
           
           
           //take a bus to the next stop.
           for(int i = 0; i < routes.size(); i++){
               vector<int>::iterator hasStop = std::find(routes[i].begin(),routes[i].end(),nCurrentStop);
               if(hasStop == routes[i].end())
                   continue;
               for(int j =0; j < routes[i].size(); j++){
                   if(mapVisitedStop[routes[i][j]] == 0){
                       queStop.push(routes[i][j]);
                       mapVisitedStop[routes[i][j]] = 1; 
                       mapLeastTake[routes[i][j]] = mapLeastTake[nCurrentStop]+1;
                   }                       
               }
           }
       }
        if(find){
            return mapLeastTake[T];
        }else{
            return -1;
        }
        
    }
    
   

     
};
