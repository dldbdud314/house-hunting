#include <iostream>
#include <fstream>
using namespace std;
#define ARRAY_SIZE 25

class Amenities{
	string gu[ARRAY_SIZE] = {"������", "������", "���ϱ�", "������", "���Ǳ�",
	"������", "���α�", "��õ��", "�����", "������", "���빮��",
	"���۱�", "������", "���빮��", "���ʱ�", "������", "���ϱ�",
	"���ı�", "��õ��", "��������", "��걸", "����", "���α�",
	"�߱�", "�߶���"};
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
			cout << "�������� ���� ���� "; 
			for(int i = 0; i < 5; i++){
				cout << gu[i] << " ";
			} 
			cout << "�Դϴ�.";
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
			cout << "��ȭ���� ���� ���� ";
			for(int i = 0; i < 5; i++){
				cout << gu[i] << " ";
			} 
			cout << "�Դϴ�."; 
		}
};
