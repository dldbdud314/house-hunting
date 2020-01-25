#include <iostream>
#include <fstream>
using namespace std;
#define ARRAY_SIZE 25

class PublicSecurity{
	string gu[ARRAY_SIZE] = {"강남구", "강동구", "강북구", "강서구", "관악구",
	"광진구", "구로구", "금천구", "노원구", "도봉구", "동대문구",
	"동작구", "마포구", "서대문구", "서초구", "성동구", "성북구",
	"송파구", "양천구", "영등포구", "용산구", "은평구", "종로구",
	"중구", "중랑구"};
	int crimeNum[ARRAY_SIZE];
	int CCTVNum[ARRAY_SIZE];
	
	public:
		PublicSecurity(){
			for(int i = 0; i < ARRAY_SIZE; i++){
				crimeNum[i] = {0};
				CCTVNum[i] = {0};
			}
		}
		
		void getCrimeNum(){
			ifstream input;
			input.open("crimeNum.txt");
			
			for(int i = 0; i < ARRAY_SIZE; i++)
				input >> crimeNum[i];
				
			input.close();
		}
		
		void getCCTVNum(){
			ifstream input;
			input.open("CCTVNum.txt");
			
			for(int i = 0; i < ARRAY_SIZE; i++)
				input >> CCTVNum[i];
				
			input.close();
		}
		
		void sortCrimeNum(){   
			for (int i = ARRAY_SIZE - 1; i >= 1; i--){     
				int currentMin = crimeNum[0]; // Find the minimum  
				string currentMinGu = gu[0];
				int currentMinIndex = 0;     
				for (int j = 1; j <= i; j++){       
					if (currentMin > crimeNum[j]){         
						currentMin = crimeNum[j];         
						currentMinGu = gu[j];
						currentMinIndex = j;       
						}     
					}     
					// Swap     
					if (currentMinIndex != i){       
						crimeNum[currentMinIndex] = crimeNum[i];       
						crimeNum[i] = currentMin;
						gu[currentMinIndex] = gu[i];       
						gu[i] = currentMinGu;
					}   
				}
			cout << "범죄발생건수가 적은 곳은 ";
			for(int i = 0; i < 3; i++){
				cout << gu[i] << " ";
			} 
			cout << "입니다.";
		}
		
		void sortCCTVNum(){   
			for (int i = ARRAY_SIZE - 1; i >= 1; i--){     
				int currentMax = CCTVNum[0]; // Find the maximum      
				string currentMaxGu = gu[0];
				int currentMaxIndex = 0;     
				for (int j = 1; j <= i; j++){       
					if (currentMax < CCTVNum[j]){         
						currentMax = CCTVNum[j];
						currentMaxGu = gu[j];
						currentMaxIndex = j;       
						}     
					}     
					// Swap     
					if (currentMaxIndex != i){       
						CCTVNum[currentMaxIndex] = CCTVNum[i];       
						CCTVNum[i] = currentMax;
						gu[currentMaxIndex] = gu[i];       
						gu[i] = currentMaxGu;
					}   
				}
			cout << "CCTV가 많은 곳은 ";
			for(int i = 0; i < 3; i++){
				cout << gu[i] << " ";
			} 
			cout << "입니다."; 
		}
};
