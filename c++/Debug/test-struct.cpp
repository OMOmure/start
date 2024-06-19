#include "iostream"
#include"string"
using namespace std;
struct Stu
{
    string name;
    int age;
    double score;
};
struct Sort
{
    string name;
    int age;
    double score;
}s3;

int main(){
    //Stu stu={.name="shr",.age=18,.score=420}; //第一种——整体赋值
    Stu stu;                                    //第二种——先定义，再赋值
    stu.name="shr";
    stu.age=19;
    stu.score=417;
    cout<<stu.name<<","<<stu.age<<","<<stu.score;

    s3.age=911;                                 //第三种——先全局命名
    cout<<'\n'<<s3.age;
    return 0;
}