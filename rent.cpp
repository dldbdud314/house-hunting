#include <iostream>
#include <fstream>
using namespace std;
#define ARRAY_SIZE 7

class Rent{
	string gu[ARRAY_SIZE] = {"��������", "���ɱ�", "���ϱ�", "���ϱ�",
	"��������", "������", "������"};
	int rent[ARRAY_SIZE];
	
	public:
		Rent(){
			for(int i = 0; i < ARRAY_SIZE; i++)
				rent[i] = {0};
		}
		
		void getRent(){
			ifstream input;
			input.open("rent.txt");
			
			for(int i = 0; i < ARRAY_SIZE; i++)
				input >> rent[i];
				
			input.close();
		}
		
		void minRent(){
         int minrent=rent[0];
         for(int i=1; i<ARRAY_SIZE; i++){
            if(rent[i]<minrent){
               minrent=rent[i];
            
            }
         }
          cout<<minrent;
      }
		
		void printGu(int min, int max){
			cout << "������ �����ϴ� ������ ";
			for(int i = 0; i < ARRAY_SIZE; i++){
				if(rent[i]>=min && rent[i]<=max)
					cout << gu[i] << " ";  
			}
			cout << "�Դϴ�!" << endl; 
		}
};
