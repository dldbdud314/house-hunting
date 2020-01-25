#include <iostream>
#include <fstream>
using namespace std;
#define ARRAY_SIZE 25

class PopulationDensity{
	string gu[ARRAY_SIZE] = {"강남구", "강동구", "강북구", "강서구", "관악구",
	"광진구", "구로구", "금천구", "노원구", "도봉구", "동대문구",
	"동작구", "마포구", "서대문구", "서초구", "성동구", "성북구",
	"송파구", "양천구", "영등포구", "용산구", "은평구", "종로구",
	"중구", "중랑구"};
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
			cout << "조건을 만족하는 구는 ";
			for(int i = 0; i < ARRAY_SIZE; i++){
				if(populationDensity[i]>=min && populationDensity[i]<=max)
					cout << gu[i] <<" ";
			}
			cout << "입니다!"; 
		}
};
