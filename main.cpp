#include <iostream>
#include <algorithm>
#include <numeric> //to use iota
#include <vector>
#include <functional>
#include <iomanip>
using namespace std;

void test1(){

struct Point{
int x;
int y;
};

Point p1{1,2};
Point p2{4,3};
Point p3{3,5};
Point p4{3,1};

vector<Point> triangle1{p1,p2,p3};
vector<Point> triangle2{p2,p3,p1};
vector<Point> triangle3{p1,p2,p4};

if(is_permutation(triangle1.begin() , triangle1.end() , triangle2.begin(),[](Point lhs, Point rhs){return lhs.x == rhs.x && lhs.y == rhs.y;})){
cout<<"Triangle 1 and Triangle 2 are equivalent"<<endl;
}else{
cout<<"Triangle 1 and Triangle 2 are equivalent"<<endl;
}


if(is_permutation(triangle1.begin() , triangle1.end() , triangle3.begin() , [] (Point lhs, Point rhs){return lhs.x == rhs.x && lhs.y == rhs.y;})){
    cout<<"Triangle 1 and Triangle 3 are equivalent"<<endl;
}else{
    cout<<"Triangle 1 and Triangle 3 are not equivalent"<<endl;
}

}

void test2(){
vector<int> test_scores{93,88,76,64,91};
int bonus_points{5};

transform(test_scores.begin(),  test_scores.end(), test_scores.begin(), [bonus_points](int score){return score+=bonus_points;});

for(int s: test_scores)
    cout<<s<<" ";
}

void test3(){
vector<int> nums {1,2,3,4,5,6,7,8};

nums.erase(remove_if(nums.begin(), nums.end(),[](int num){return num%2==0;}),nums.end());

for(auto n:nums)
    cout<<n<<" ";
}

//class Person used for test 4

class Person{
friend ostream &operator<<(ostream &os, Person &rhs);

private:
    string name;
    int age;

public:
    Person(string name, int age):name{name},age{age}{};
    Person(const Person &p):name{p.name},age{p.age}{}
    ~Person() = default;

    string get_name(){return name;}
    void set_name(string name){this->name = name;}

    int get_age(){return age;}
    void set_age(int age){this->age = age;}
};

ostream &operator<<(ostream &os, Person &rhs){
os<<"[Person: "<<rhs.name<<" : "<<rhs.age<<"]"<<endl;
return os;
}

void test4(){

Person person1{"Omar",18};
Person person2{"Ahmad",16};
Person person3{"Ali",14};

vector<Person> people {person1,person2,person3};

sort(people.begin(), people.end(),[](Person lhs, Person rhs){return lhs.get_name() < rhs.get_name();});

for(Person p: people)
    cout<<p<<endl;

}

//in_between used for test 5

bool in_between(vector<int> &nums, int start_value, int end_value){
bool result = false;

result = all_of(nums.begin(), nums.end(),[start_value, end_value](int value){return value >= start_value && value <= end_value;});
return result;
}

void test5(){
cout<<boolalpha;

vector<int> nums(10);
iota(nums.begin(),nums.end(),1);

for(int num: nums)
    cout<<num<<" ";
    cout<<endl;

    cout<<in_between(nums,50,60)<<endl;
    cout<<in_between(nums,1,10)<<endl;
    cout<<in_between(nums,5,7)<<endl;
}


//two classes for test 6

class Password_Validator1{
private:
    char restricted_symbol{'$'};
public:
    bool is_valid(string password){
    return all_of(password.begin(), password.end(),[this](char character){return character != restricted_symbol;});
    }
};

class Password_Validator2{
private:
    vector<char> restricted_symbols{'!','$','+'};
public:
    bool is_valid(string password){
    return all_of(password.begin(),password.end(),[this](char character){return none_of(restricted_symbols.begin(), restricted_symbols.end(),[character](char symbol){return character == symbol;});});
    }
};

void test6(){
string password = "hollywood$";
Password_Validator1 pv1;

if(pv1.is_valid(password)){
    cout<<password<<" is valid"<<endl;
}else{
cout<<password<<" is not valid"<<endl;
}

string password2 = "C++ Rocks !$";
Password_Validator2 pv2;

if(pv2.is_valid(password2)){
    cout<<password2<< " is valid"<<endl;
}else{
    cout<<password2<< " is not valid"<<endl;
}
}

int main(){

    test6();
}
