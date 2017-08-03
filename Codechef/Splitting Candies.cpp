#include <iostream>

using namespace std;
typedef long long ll;

int main()
{
    int cases;
    cin >> cases;
    while(cases--){
        ll candies, students;
        cin >> candies >> students;
        ll student_candy,teacher_candy;
        if(students == 0){
            student_candy = 0;
            teacher_candy = candies;
        }
        else{
            student_candy = candies/students;
            teacher_candy = candies%students;
        }
        cout << student_candy << " " << teacher_candy<<endl;
    }
    return 0;
}
