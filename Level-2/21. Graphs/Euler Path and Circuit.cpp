//https://practice.geeksforgeeks.org/problems/euler-circuit-and-path/1


int isEularCircuit(int V, vector<int>adj[]){
	    // Code here
    vector<int> degree(V);
    for(int i=0;i<V;i++){
        degree[i]=adj[i].size();
    }
    
    int odc=0;
    for(int i=0;i<V;i++){
        if(degree[i]%2==1){
            odc++;
        }
    }
    
    if(odc==0){
        return 2;
    }
    else if(odc==2){
        return 1;
    }
    else{
        return 0;
    }
    
}