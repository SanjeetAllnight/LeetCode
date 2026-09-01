class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m=classroom.size(),n=classroom[0].size();
        int sr, sc, bit=0;
        unordered_map<int,int>litterBit;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(classroom[i][j]=='S'){
                    sr=i;
                    sc=j;
                }
                else if(classroom[i][j]=='L'){
                    litterBit[i*n+j]=bit++;
                }
            }
        }
        if(bit==0){
            return 0;
        }
        int fullmask=(1<<bit)-1;
        vector<vector<vector<int>>> best(m, vector<vector<int>>(n, vector<int>(1<<bit, -1)));
        queue<array<int,4>>q;
        q.push({sr,sc,0,energy});
        int dr[4]={-1,1,0,0}, dc[4]={0,0,-1,1};
        int moves=0;
        while(!q.empty()){
            for(int k=q.size();k>0;k--){
                auto [r,c,mask,e]=q.front(); q.pop();
                if(mask==fullmask){
                    return moves;
                }
                if(e==0){
                    continue;
                }
                for(int d=0;d<4;d++){
                    int nr=r+dr[d], nc=c+dc[d];
                    if (nr<0 || nr>=m || nc<0 || nc>=n || classroom[nr][nc]=='X'){
                        continue;
                    }
                    int ne=classroom[nr][nc]=='R'? energy:e-1;
                    int nmask=litterBit.count(nr*n+nc)?mask|(1<<litterBit[nr*n+nc]):mask;
                    if(ne>best[nr][nc][nmask]){
                        best[nr][nc][nmask]=ne;
                        q.push({nr,nc,nmask,ne});
                    }
                }
            }
            moves++;
        }
        return -1;

    }
};