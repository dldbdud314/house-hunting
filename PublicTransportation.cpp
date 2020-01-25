#include <iostream>
#include <fstream>
using namespace std;
#define ARRAY_SIZE 25

class PublicTransportation{
	string gu[ARRAY_SIZE] = {"������", "������", "���ϱ�", "������", "���Ǳ�",
	"������", "���α�", "��õ��", "�����", "������", "���빮��",
	"���۱�", "������", "���빮��", "���ʱ�", "������", "���ϱ�",
	"���ı�", "��õ��", "��������", "��걸", "����", "���α�",
	"�߱�", "�߶���"};
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
			cout << "����ö���� ���� ����";
			for(int i = 0; i < 5; i++){
				cout << gu[i] << " ";
			} 
			cout << "�Դϴ�."; 
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
			cout << "������������ ���� ���� "; 
			for(int i = 0; i < 5; i++){
				cout << gu[i] << " ";
			} 
			cout << "�Դϴ�."; 
		}
};
