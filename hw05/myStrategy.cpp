#include "game.h"

static int DP[5][5][151]={-1};
static bool check[5][5][151]={false};
int D(int ten, int one, int total){

	if(total>150){ 
	
		return 0;
	}
	if(check[ten][one][total]==true) {return DP[ten][one][total];}
	if(ten==0 && one==0) {
		if(check[ten][one][total]==true)
			return DP[0][0][total];
		else{
			int i = total;
			DP[ten][one][total] = i;
			check[ten][one][total]=true;
			return i;
		}
	}
	if(ten==0 && one>0){
		
		int i = D(0,one-1,total+1)/6+
		D(0,one-1,total+2)/6+
		D(0,one-1,total+3)/6+
		D(0,one-1,total+4)/6+
		D(0,one-1,total+5)/6+
		D(0,one-1,total+6)/6;
		DP[ten][one][total] = i;
		check[ten][one][total]=true;
		

		return i;
	} 
	else if(ten>0 && one==0){
		
		int i =D(ten-1,0,total+10)/6+
		D(ten-1,0,total+20)/6+
		D(ten-1,0,total+30)/6+
		D(ten-1,0,total+40)/6+
		D(ten-1,0,total+50)/6+
		D(ten-1,0,total+60)/6;
		DP[ten][one][total] = i;
		check[ten][one][total]=true;

		return i;
	}
	

	if(check[ten][one][total]==true) {return DP[ten][one][total];}
	else{
	
	
		int i =
		(MAX(D(ten-1,one,total+10),D(ten,one-1,total+1))/6+
		MAX(D(ten-1,one,total+20),D(ten,one-1,total+2))/6+
		MAX(D(ten-1,one,total+30),D(ten,one-1,total+3))/6+
		MAX(D(ten-1,one,total+40),D(ten,one-1,total+4))/6+
		MAX(D(ten-1,one,total+50),D(ten,one-1,total+5))/6+
		MAX(D(ten-1,one,total+60),D(ten,one-1,total+6))/6);
		DP[ten][one][total]= i;
		check[ten][one][total]=true;
		
		return i;
	}

}



int table(int ten, int one, int total){
	if(total>150) return 0;
	return DP[ten][one][total];
}

// My strategy to play the dice sum game
// Returns 0 for ten's position, 1 for one's position
int myStrategy(int gameState[4][2], int diceValue){
	static int initialized;		// Static variable, default to zero
	// Add your declaration of DP structure here 宣告array
	//static int DP[5][5][151];
	//static bool check[5][5][151]={false};
	if (!initialized){
		initialized=1;
		// Populate your structure here	填array	
		int zzz = D(4,4,0);
	
		/*for(int i = 4; i >0; i--){
			for(int j = 4; j > 0; j--){
				for(int k = 0; k < 151; k++){
					DP[i][j][k] = creat_DP(i,j,k,DP,check);
					check[i][j][k]=true;
					//cout << DP[i][j][k] << " ";
				}
				//cout << endl;
			}
			//cout << endl;
		}*/

		

	}
	int tenAvailCount=0;	// No. of available ten's position
	for (int j=0; j<4; j++)
		if (gameState[j][0]<=0) {tenAvailCount=4-j; break;}
	int oneAvailCount=0;	// No. of available one's position
	for (int j=0; j<4; j++)
		if (gameState[j][1]<=0) {oneAvailCount=4-j; break;}
	if ((tenAvailCount!=0)&&(oneAvailCount==0)) return(0);
	if ((tenAvailCount==0)&&(oneAvailCount!=0)) return(1);
//	My strategy
	int strategy=3;
	int nextPos, total;
	total=(gameState[0][0]+gameState[1][0]+gameState[2][0]+gameState[3][0])*10
					+(gameState[0][1]+gameState[1][1]+gameState[2][1]+gameState[3][1]);
	switch(strategy){
		case 1:
			nextPos=rand()%2;
			break;
		case 2:
			nextPos=0;
			total=(gameState[0][0]+gameState[1][0]+gameState[2][0]+gameState[3][0])*10
					+(gameState[0][1]+gameState[1][1]+gameState[2][1]+gameState[3][1]);
			if (total+diceValue*10>SCOREMAX)
				nextPos=1;
			break;
		case 3:
			// Add your own strategy (which uses the DP structure) here

			nextPos = table(tenAvailCount-1,oneAvailCount,total+diceValue*10)>table(tenAvailCount,oneAvailCount-1,total+diceValue)?0:1;
			
			break;
		default:
			printf("Error!\n");
	}
	return(nextPos);
}
