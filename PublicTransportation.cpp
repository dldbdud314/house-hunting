#include <iostream>
#include <fstream>
using namespace std;
#define ARRAY_SIZE 25

class PublicTransportation{
	string gu[ARRAY_SIZE] = {"강남구", "강동구", "강북구", "강서구", "관악구",
	"광진구", "구로구", "금천구", "노원구", "도봉구", "동대문구",
	"동작구", "마포구", "서대문구", "서초구", "성동구", "성북구",
	"송파구", "양천구", "영등포구", "용산구", "은평구", "종로구",
	"중구", "중랑구"};
	int subwayStationNum[ARRAY_SIZE];
	int busStationNum[ARRAY_SIZE];
	
	public:
		PublicTransportation(){
			for(int i = 0; i < ARRAY_SIZE; i++){
				subwayStationNum[i] = {0};
				busStationNum[i] = {0};
			}
		}
		
		void getSubwayStationNum(){
			ifstream input;
			input.open("subwayStationNum.txt");
			
			for(int i = 0; i < ARRAY_SIZE; i++)
				input >> subwayStationNum[i];
				
			input.close();
		}
		
		void getBusStationNum(){
			ifstream input;
			input.open("busStationNum.txt");
			
			for(int i = 0; i < ARRAY_SIZE; i++)
				input >> busStationNum[i];
			
			input.close();
		}
		
		void sortSubwayStationNum(){   
			for (int i = ARRAY_SIZE - 1; i >= 1; i--){     
				int currentMax = subwayStationNum[0]; // Find the maximum      
				string currentMaxGu = gu[0];
				int currentMaxIndex = 0;     
				for (int j = 1; j <= i; j++){       
					if (currentMax < subwayStationNum[j]){         
						currentMax = subwayStationNum[j];         
						currentMaxGu = gu[j];
						currentMaxIndex = j;       
						}     
					}     
					// Swap     
					if (currentMaxIndex != i){       
						subwayStationNum[currentMaxIndex] = subwayStationNum[i];       
						subwayStationNum[i] = currentMax;
						gu[currentMaxIndex] = gu[i];       
						gu[i] = currentMaxGu;
					}   
				}
			cout << "지하철역이 많은 구는";
			for(int i = 0; i < 5; i++){
				cout << gu[i] << " ";
			} 
			cout << "입니다."; 
		}
		
		void sortBusStationNum(){   
			for (int i = ARRAY_SIZE - 1; i >= 1; i--){     
				int currentMax = busStationNum[0]; // Find the maximum      
				string currentMaxGu = gu[i];
				int currentMaxIndex = 0;     
				for (int j = 1; j <= i; j++){       
					if (currentMax > busStationNum[j]){         
						currentMax = busStationNum[j];         
						currentMaxGu = gu[j];
						currentMaxIndex = j;       
						}     
					}     
					// Swap     
					if (currentMaxIndex != i){       
						busStationNum[currentMaxIndex] = busStationNum[i];       
						busStationNum[i] = currentMax;
						gu[currentMaxIndex] = gu[i];       
						gu[i] = currentMaxGu;
					}   
				}
			cout << "버스정류장이 많은 구는 "; 
			for(int i = 0; i < 5; i++){
				cout << gu[i] << " ";
			} 
			cout << "입니다."; 
		}
};
