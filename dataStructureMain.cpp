#include <iostream>
#include "PopulationDensity.cpp"
#include "PublicSecurity.cpp"
#include "Amenities.cpp"
#include "PublicTransportation.cpp"
#include "rent.cpp"
using namespace std;

int main() {
   string condition; //조건입력하는string 
      
   while(true){
         cout<<"원하시는 조건을 입력해 주세요(집세, 교통, 치안, 편의, 인구밀도 중 택)";
         cin>>condition;
         
      if(condition!="집세"&&condition!="교통"&&condition!="치안"&&condition!="편의"&&condition!="인구밀도") {
            cout<<"다시 입력해 주세요. . ."<<endl; 
            cout<<" "<<endl;
            continue;
         }
         cout<<"사용자가 선택한 조건 >>"<<" "<<condition<<endl;
         cout<<"맞으면 Y, 틀리면 N을 입력해 주세요."<<endl;
      
      string userinput;
      
         cin>>userinput;
         
         if(userinput=="N" || userinput=="n"){
           cout<<"처음으로 돌아갑니다. . ."<<endl;
           cout<<" "<<endl;
          continue;
           }
           cout<<" "<<endl;
       if(condition=="집세"){
        Rent rent;
        rent.getRent();
         
      //세부조건(최소 최대) 입력
      int minRent, maxRent; 
         
      cout << "사용자가 원하는 최소 월세를 입력하시오. (최소 월세는 ";
      rent.minRent();
      cout<<"입니다)"<<endl; 
      cout<<"최소 월세를 입력하시오:"; 
      cin >> minRent;
      cout << "최대 월세를 입력하시오:";
      cin >> maxRent;
         
      //세부조건을 만족하는 구 출력 
      rent.printGu(minRent, maxRent);
   
   }
   else if(condition == "교통"){
      PublicTransportation subway;
      subway.getSubwayStationNum();
      subway.sortSubwayStationNum(); //지하철역 많은 5구 출력 
      cout << endl;
         
      PublicTransportation bus;
      bus.getBusStationNum();
      bus.sortBusStationNum(); //버스정류장 많은 5구 출력   
      cout<<endl;   
   }
   else if(condition == "치안"){
         PublicSecurity crime;
         crime.getCrimeNum();
         crime.sortCrimeNum(); //범죄발생건수가 적은 3구 출력 
         cout << endl;
         
         PublicSecurity cctv;
         cctv.getCCTVNum();
         cctv.sortCCTVNum(); //CCTV가 많은 3구 출력    
         cout<<endl;   
   }
   else if(condition == "인구밀도"){
      PopulationDensity population;
      population.getPopulationDensity();
          
      //세부조건(최소 최대) 입력
      int minPopulation, maxPopulation;
      cout << "사용자가 원하는 최소치를 입력하시오(최소치는"<<" ";
      population.minpopulationDensity();
      cout<<"입니다)"<<endl;
      cout<<"최소치를 입력하시오:" ;
      cin >> minPopulation;
      cout << "최대치를 입력하시오:";
      cin >> maxPopulation;
         
      //세부조건을 만족하는 구 출력 
      population.printGu(minPopulation, maxPopulation);   
      cout<<endl;   
   }
   else if(condition == "편의"){
      Amenities conv;
      conv.getConvienienceStoreNum();
      conv.sortConvienienceStoreNum(); //편의점이 많은 5구 출력 
      cout << endl;
         
      Amenities movies;
      movies.getTheaterNum();
      movies.sortTheaterNum(); //영화관이 많은 5구 출력 
      cout<<endl;         
   }
   cout<<endl; 
   cout<<"더 알아보고 싶으면 RE를 그만 알아보고 싶으면 ESC를 입력해 주세요."<<endl;
   string userchoice;
   cin>>userchoice;
   
   if(userchoice=="RE" || userchoice=="re"){
      cout<<" "<<endl;
         continue;
     }
   else if(userchoice=="ESC" || userchoice=="esc"){
      cout<<"종료합니다.";
         break;
        }
        
   return 0;
}
}
