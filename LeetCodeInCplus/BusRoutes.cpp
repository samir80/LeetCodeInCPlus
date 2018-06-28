class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        //DFS
        m_nLeastTransfer = -1;
        m_nCurrentTransfer = 0;
        busPath.clear();
        
        BackTrace(routes,S,T);
               
        return m_nLeastTransfer;
        
    }
    
   void BackTrace(vector<vector<int>>& routes, int S, int T){            
        for(int i = 0; i < routes.size() ; i++){
            vector<int>::iterator visitedRet = find(busPath.begin(), busPath.end(),i);
            if(visitedRet != busPath.end())
                continue;
            vector<int>::iterator hasStopRet = find( routes[i].begin( ), routes[i].end( ), S ); 
            if(hasStopRet == routes[i].end())
                continue;  
            if(S == T){
                //reach the destination
                if(m_nLeastTransfer == -1 || m_nCurrentTransfer < m_nLeastTransfer)
                    m_nLeastTransfer = m_nCurrentTransfer; 
                return;
            }
            busPath.push_back(i);
            m_nCurrentTransfer++;
            vector<int>::iterator hasDest = find(routes[i].begin( ), routes[i].end( ), T);
            if(hasDest != routes[i].end()){
                //reach the destination
                if(m_nLeastTransfer == -1 || m_nCurrentTransfer < m_nLeastTransfer)
                    m_nLeastTransfer = m_nCurrentTransfer; 
                
                busPath.pop_back();
                m_nCurrentTransfer--;
                return; 
            }
            
            for(int j = 0; j<routes[i].size(); j++){
                BackTrace(routes,routes[i][j],T);
            }
             busPath.pop_back();
             m_nCurrentTransfer--;
           
        }
    }
    
    int m_nLeastTransfer;
    int m_nCurrentTransfer;
    vector<int> busPath;
    
};
