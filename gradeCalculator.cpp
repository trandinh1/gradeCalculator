#include <iostream>
#include <iomanip>
#include <string>
#include <cmath> 

using namespace std;


int main()
{
  double totalGrade = 0, score = 0, totalScore = 0, outOf = 0, totalOutOf = 0; 
  string gradeCategories [100];
  double weight [100];
  double totalWeight = 0;
  int numCategories, numScores;
  string letterGrade;

  cout << "Enter the number of different categories in your class?" << endl;
  cin >> numCategories;
  
  int i;

//Compile how many different grade categories and store their weight
  if(numCategories > 0){
    for (i=0; i< numCategories; i++){
      cout << "Enter the name of the category #" << i + 1 << ":";
      cin >> gradeCategories [i];

      cout << "What percentage is the " << gradeCategories[i] << " category worth? (Type in decimal form): ";
      cin >> weight[i];
      totalWeight += weight[i]; 
          //check for valid weight
          if((totalWeight > 1.0 && totalWeight < 0.0) && (weight[i] < 0)) {
            totalWeight -= weight [i];
            cout << "Try Again! What percentage is the " << gradeCategories [i]<< " category worth? (Type in decimal form): ";
            cin >> weight[i];   
            while((totalWeight > 1.0 && totalWeight < 0.0) && (weight[i] < 0)){
              cout << "Try Again! What percentage is the " << gradeCategories [i]<< " category worth? (Type in decimal form): ";
              cin >> weight[i];   
            }
            totalWeight += weight[i]; 
          }
      


      cout << "Enter the number of scores: ";
      cin >> numScores;
      
      
    
        for(int j = 0; j < numScores; j++){
            cout << "Enter your score for " << gradeCategories[i] << " category: ";
              cin >> score; 
              cout << "Out of ";
              cin >> outOf;
              if (score >= 0.0 && outOf > 0){
              totalScore += score; 
              totalOutOf += outOf;
              }
          
              else {
                cout << "Try again: Enter your score for " << gradeCategories[i] << " category: ";
                cin >> score;
                cout << "Out of ";
                cin >> outOf;
              while (score < 0 || outOf <= 0)
              {
                cout << "Try again: Enter your score for " << gradeCategories[i] << " category: ";
                cin >> score;
                cout << "Out of ";
                cin >> outOf;
              }
              totalScore += score;
              totalOutOf += outOf; 
              }
            
        }
        
        totalGrade += ((totalScore/totalOutOf) * weight[i]);
  }

// Check the corresponding letter grade to the percentage grade (Ex. 90% = is A-)
if (totalGrade >= 93.0 && totalGrade <= 100.0) {
  letterGrade = "A";

} else if (totalGrade >= 90.0 && totalGrade <= 92.99){
  letterGrade = "A-";
}else if (totalGrade >= 87.0 && totalGrade <= 89.99){
  letterGrade = "B+";
}else if (totalGrade >= 83.0 && totalGrade <= 86.99){
  letterGrade = "B";
}else if (totalGrade >= 80.0 && totalGrade <= 82.99){
  letterGrade = "B-";
}else if (totalGrade >= 77.0 && totalGrade <= 79.99){
  letterGrade = "C+";
}else if (totalGrade >= 73.0 && totalGrade <= 76.99){
  letterGrade = "C";
}else if (totalGrade >= 70.0 && totalGrade <= 72.99){
  letterGrade = "C-";
}else if (totalGrade >= 67.0 && totalGrade <= 69.99){
  letterGrade = "D+";
}else if (totalGrade >= 60.0 && totalGrade <= 66.99){
  letterGrade = "D";
}else {
  letterGrade = "F";
}


cout << fixed << setprecision(2) << "Grade Percentage: " << totalGrade << "%"<<endl; 
cout << "Letter Grade: " << letterGrade << endl;
  
    

    
  }
  



}
