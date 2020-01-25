#include <iostream>
#include <fstream>
using namespace std;
#define ARRAY_SIZE 25

class PopulationDensity{
	string gu[ARRAY_SIZE] = {"������", "������", "���ϱ�", "������", "���Ǳ�",
	"������", "���α�", "��õ��", "�����", "������", "���빮��",
	"���۱�", "������", "���빮��", "���ʱ�", "������", "���ϱ�",
	"���ı�", "��õ��", "��������", "��걸", "����", "���α�",
	"�߱�", "�߶���"};
	int populationDensity[ARRAY_SIZE];
	
	public:
		PopulationDensity(){
			for(int i = 0; i < ARRAY_SIZE; i++)
				populationDensity[i] = {0};
		}
		
		void getPopulationDensity(){
			ifstream input;
			input.open("populationDensity.txt");
			
			for(int i = 0; i < ARRAY_SIZE; i++)
				input >> populationDensity[i];
				
			input.close();
		}
		
		void minpopulationDensity(){
         int minpopulation=populationDensity[0];
         for(int i=1; i<ARRAY_SIZE; i++){
            if(populationDensity[i]<minpopulation){
               minpopulation=populationDensity[i];
               
            }
         }
         cout<<minpopulation<<" ";
      	}
		
		void printGu(int min, int max){
			cout << "������ �����ϴ� ���� ";
			for(int i = 0; i < ARRAY_SIZE; i++){
				if(populationDensity[i]>=min && populationDensity[i]<=max)
					cout << gu[i] <<" ";
			}
			cout << "�Դϴ�!"; 
		}
};
