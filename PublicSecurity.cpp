#include <iostream>
#include <fstream>
using namespace std;
#define ARRAY_SIZE 25

class PublicSecurity{
	string gu[ARRAY_SIZE] = {"������", "������", "���ϱ�", "������", "���Ǳ�",
	"������", "���α�", "��õ��", "�����", "������", "���빮��",
	"���۱�", "������", "���빮��", "���ʱ�", "������", "���ϱ�",
	"���ı�", "��õ��", "��������", "��걸", "����", "���α�",
	"�߱�", "�߶���"};
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
			cout << "���˹߻��Ǽ��� ���� ���� ";
			for(int i = 0; i < 3; i++){
				cout << gu[i] << " ";
			} 
			cout << "�Դϴ�.";
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
			cout << "CCTV�� ���� ���� ";
			for(int i = 0; i < 3; i++){
				cout << gu[i] << " ";
			} 
			cout << "�Դϴ�."; 
		}
};
