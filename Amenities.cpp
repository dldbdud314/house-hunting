#include <iostream>
#include <fstream>
using namespace std;
#define ARRAY_SIZE 25

class Amenities{
	string gu[ARRAY_SIZE] = {"강남구", "강동구", "강북구", "강서구", "관악구",
	"광진구", "구로구", "금천구", "노원구", "도봉구", "동대문구",
	"동작구", "마포구", "서대문구", "서초구", "성동구", "성북구",
	"송파구", "양천구", "영등포구", "용산구", "은평구", "종로구",
	"중구", "중랑구"};
	int convienienceStoreNum[ARRAY_SIZE];
	int theaterNum[ARRAY_SIZE];
	
	public:
		Amenities(){
			for(int i = 0; i < ARRAY_SIZE; i++){
				convienienceStoreNum[i] = {0};
				theaterNum[i] = {0};
			}
		}
		
		void getConvienienceStoreNum(){
			ifstream input;
			input.open("convienienceStoreNum.txt");
			
			for(int i = 0; i < ARRAY_SIZE; i++)
				input >> convienienceStoreNum[i];
			input.close();
		}
		
		void getTheaterNum(){
			ifstream input;
			input.open("theaterNum.txt");
			
			for(int i = 0; i < ARRAY_SIZE; i++)
				input >> theaterNum[i];
			input.close();
		}
		
		void sortConvienienceStoreNum(){   
			for (int i = ARRAY_SIZE - 1; i >= 1; i--){     
				int currentMax = convienienceStoreNum[0]; // Find the maximum      
				string currentMaxGu = gu[0];
				int currentMaxIndex = 0;     
				for (int j = 1; j <= i; j++){       
					if (currentMax < convienienceStoreNum[j]){         
						currentMax = convienienceStoreNum[j];         
						currentMaxGu = gu[j];
						currentMaxIndex = j;       
						}     
					}     
					// Swap     
					if (currentMaxIndex != i){       
						convienienceStoreNum[currentMaxIndex] = convienienceStoreNum[i];       
						currentMax = convienienceStoreNum[i];
						gu[currentMaxIndex] = gu[i];       
						gu[i] = currentMaxGu;
					}   
				}
			cout << "편의점이 많은 구는 "; 
			for(int i = 0; i < 5; i++){
				cout << gu[i] << " ";
			} 
			cout << "입니다.";
		}
		
		void sortTheaterNum(){   
			for (int i = ARRAY_SIZE - 1; i >= 1; i--){     
				int currentMax = theaterNum[0]; // Find the maximum      
				string currentMaxGu = gu[0];
				int currentMaxIndex = 0;     
				for (int j = 1; j <= i; j++){       
					if (currentMax < theaterNum[j]){         
						currentMax = theaterNum[j];         
						currentMaxGu = gu[j];
						currentMaxIndex = j;       
						}     
					}     
					// Swap     
					if (currentMaxIndex != i){       
						theaterNum[currentMaxIndex] = theaterNum[i];       
						theaterNum[i] = currentMax;
						gu[currentMaxIndex] = gu[i];       
						gu[i] = currentMaxGu;
					}   
				}
			cout << "영화관이 많은 구는 ";
			for(int i = 0; i < 5; i++){
				cout << gu[i] << " ";
			} 
			cout << "입니다."; 
		}
};
