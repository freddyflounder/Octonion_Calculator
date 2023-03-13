//Andy Vick, 28 April 2022, Octonion Addition and Multiplication Calculator 

//header    

#include<iostream> 

using namespace std; 

class Octonion  

  

{  

  

private:  

  

double octonion[8]; //can be any octonion, 8 piece number with 7 imaginary components 

  

public:  

  

Octonion(); //constructor function, initializes all to 0 

  

double get(int i); //accessor function, i to access e_i component, e_0=real component 

  

void set(int i, double v); //mutator function, i for e_i component, v for value to change toward 

void output(); //outputs octonion with standard r+e_1+e_2+... notation for octonions 

void input(); //input values for each part of the octonion 

  

};  

  

Octonion operator +(Octonion o_1, Octonion o_2); //adds two octonions together by components; a*e_i+b*e_i=(a+b)e_i 

  

Octonion operator *(Octonion o_1, Octonion o_2); //multiplies two octonions together using the Fano plane diagram and 8 digit multiplication 

  

//implementation    

  

//https://math.stackexchange.com/questions/3394507/a-real-example-of-an-octonion-product 

  

// (citation for Fano plane and octonion multiplication, to find formula look under heading "Octonion Solution is Calculated" 

  

#include <iostream>    

  

Octonion::Octonion() {  

  

for (int i(0); i < 8; i++)  

  

octonion[i] = 0;  

  

}  

  

double Octonion::get(int i)  

  

{  

  

return octonion[i];  

  

}  

  

void Octonion::set(int i, double v)  

  

{  

  

octonion[i] = v;  

  

}  

  

void Octonion::output() 

{ 

    cout<<octonion[0]; 

    for(int i(1); i<8; i++) 

    { 

        if(octonion[i]<0) 

        cout<<octonion[i]<<"e_"<<i; 

        else if (octonion[i]>0) 

        cout<<"+"<<octonion[i]<<"e_"<<i; 

        else if (octonion[i]==0) 

        cout<<" "; 

    } 

} 

  

void Octonion::input() 

{ 

    cout<<"Please input 8 values for this octonion: "; 

    for(int i(0); i<8; i++) 

    { 

        cin>>octonion[i]; 

    } 

} 

  

Octonion operator +(Octonion o_1, Octonion o_2) 

  

{  

  

Octonion add;  

  

for (int i(0); i < 8; i++)  

  

add.set(i, (o_1.get(i) + o_2.get(i)));  

  

return add;  

  

}  

//for (a+be_1+ce_2+de_3+ee_4+fe_5+ge_6+he_7)*(i+je_1+ke_2+le_3+me_4+ne_5+oe_6+pe_7) 

Octonion operator *(Octonion o_1, Octonion o_2)  

  

{  

  

Octonion mult;  

  

//equation for real entry: ai-bj-ck-dl-me-nf-og-ph,     

mult.set(0, (o_1.get(0) * o_2.get(0))); //adds ai to mult[0] 

  

for (int i(1); i < 8; i++) //loop for finishing real entry 

mult.set(0, mult.get(0) - (o_1.get(i) * o_2.get(i))); //subtracts out the other products listed above 

  

//equation for e_1: aj+bi+cl-dk-mf+ne+oh-pg 

mult.set(1, o_1.get(0) * o_2.get(1)); //sets mult[1]=aj 

  

for (int i(1); i < 8; i++) //loop for e_1, the first imaginary component     

  

{  

  

if ((i % 2) == 0 && (i < 5)) //adds cl and ne to mult[1] 

  

mult.set(1, mult.get(1) + o_1.get(i) * o_2.get(i + 1)); 

  

else if (i == 6) //subtracts pg from mult[1] 

  

mult.set(1, mult.get(1) - o_1.get(i) * o_2.get(i + 1));  

  

else if (i == 1 || i == 7)  //adds bi and oh to mult[1] 

  

mult.set(1, mult.get(1) + o_1.get(i) * o_2.get(i - 1));  

  

else //subtracts dk from mult[1] 

  

mult.set(1, mult.get(1) - o_1.get(i) * o_2.get(i - 1));  

  

}  

  

  

  

  

//equation for e_2: ak-bl+ci+dj-mg-nh+oe+pf 

for (int i(0); i < 8; i++) //loop for e_2     

  

{  

  

if (i == 0 || i == 4 || i == 5) //adds ak, oe, and pf to mult[2] 

  

mult.set(2, mult.get(2) + o_1.get(i) * o_2.get(i + 2));  

  

else if (i == 1) //subtracts bl from mult[2] 

  

mult.set(2, mult.get(2) - o_1.get(i) * o_2.get(i + 2));  

  

else if (i == 2 || i == 3) //adds ci and dj to mult[2] 

  

mult.set(2, mult.get(2) + o_1.get(i) * o_2.get(i - 2));  

  

else if (i==7 || i==6) //subtracts mg and nh from mult[2] 

  

mult.set(2, mult.get(2) - o_1.get(i) * o_2.get(i - 2));  

  

}  

  

  

  

  

//equation for e_3:  al+bk-cj+di-mh+ng-of+pe 

for (int i(0); i < 8; i++) //loop for e_3     

  

{  

  

if (i == 0 || i == 4) //adds al & mh to mult[3] 

  

mult.set(3, mult.get(3) + o_1.get(i) * o_2.get(i + 3));  

  

else if (i == 1) //adds bk to mult[3] 

  

mult.set(3, mult.get(3) + o_1.get(i) * o_2.get(i + 1));  

  

else if (i == 2) //subtracts cj from mult[3] 

  

mult.set(3, mult.get(3) - o_1.get(i) * o_2.get(i - 1));  

  

else if (i == 3) //adds di to mult[3] 

  

mult.set(3, mult.get(3) + o_1.get(i) * o_2.get(i - 3));  

  

else if (i == 5) //subtracts of from mult[3] 

  

mult.set(3, mult.get(3) - o_1.get(i) * o_2.get(i + 1));  

  

else if (i == 6) //adds ng to mult[3] 

  

mult.set(3, mult.get(3) + o_1.get(i) * o_2.get(i - 1));  

  

else if (i == 7) //subtracts mh from mult[3] 

  

mult.set(3, mult.get(3) - o_1.get(i) * o_2.get(i - 3));  

  

   

  

}  

//equation for e_4:  ma-nb-oc-pd+ei+fj+gk+hl 

for (int i(0); i < 8; i++) //loop for e_4, over halfway there!     

  

{  

  

if (i == 0) //adds ma to mult[4] 

  

mult.set(4, mult.get(4) + o_1.get(i) * o_2.get(i + 4));  

  

else if (i == 1 || i == 2 || i == 3) //subtracts nb, oc, and pd from mult[4] 

  

mult.set(4, mult.get(4) - o_1.get(i) * o_2.get(i + 4));  

  

else if (i > 3) //adds ei, fj, gk, and hl to mult[4] 

  

mult.set(4, mult.get(4) + o_1.get(i) * o_2.get(i - 4));  

  

}  

//equation for e_5: mb+na+od-pc-ej+fi-gl+hk 

for (int i(0); i < 8; i++) // loop for e_5     

  

{  

  

if (i == 0) //adds na to mult[5] 

  

mult.set(5, mult.get(5) + o_1.get(i) * o_2.get(i + 5));  

  

else if (i == 1 || i == 3) //adds mb and od to mult[5] 

  

mult.set(5, mult.get(5) + o_1.get(i) * o_2.get(i + 3));  

  

else if (i == 2) //subtracts pc from mult[5] 

  

mult.set(5, mult.get(5) - o_1.get(i) * o_2.get(i + 5));  

  

else if (i == 4) //subtracts ej from mult[5] 

  

mult.set(5, mult.get(5) - o_1.get(i) * o_2.get(i - 3));  

  

else if (i == 5 || i == 7) //adds fi and hk to mult[5] 

  

mult.set(5, mult.get(5) + o_1.get(i) * o_2.get(i - 5));  

  

else if (i == 6) //subtracts gl from mult[5] 

  

mult.set(5, mult.get(5) - o_1.get(i) * o_2.get(i - 3));  

  

}  

  

   

//equation for e_6: mc-nd+oa+pb-ek+fl+gi-hj 

for (int i(0); i < 8; i++) //loop for e_6, desperately trying not to lose hope     

  

{  

  

if (i == 0 || i == 1) //adds oa and pb to mult[6] 

  

mult.set(6, mult.get(6) + o_1.get(i) * o_2.get(i + 6));  

  

else if (i == 2) //adds mc to mult[6] 

  

mult.set(6, mult.get(6) + o_1.get(i) * o_2.get(i + 2));  

  

else if (i == 3) //subtracts nd from mult[6] 

  

mult.set(6, mult.get(6) - o_1.get(i) * o_2.get(i + 2));  

  

else if (i == 4) //subtracts ek from mult[6] 

  

mult.set(6, mult.get(6) - o_1.get(i) * o_2.get(i - 2));  

  

else if (i == 5) //adds fl to mult[6] 

  

mult.set(6, mult.get(6) + o_1.get(i) * o_2.get(i - 2));  

  

else if (i == 6) //adds gi to mult[6] 

  

mult.set(6, mult.get(6) + o_1.get(i) * o_2.get(i - 6));  

  

else if (i == 7) //subtracts hj from mult[6] 

  

mult.set(6, mult.get(6) - o_1.get(i) * o_2.get(i - 6));  

  

}  

  

  

//equation for e_7: md+nc-ob+pa-el-fk+gj+hi 

for (int i(0); i < 8; i++) //loop for e_7, final one 

  

{  

  

if (i == 0) //adds pa to mult[7] 

  

mult.set(7, mult.get(7) + o_1.get(i) * o_2.get(i + 7));  

  

if (i == 1) //subtracts ob from mult[7] 

  

mult.set(7, mult.get(7) - o_1.get(i) * o_2.get(i + 5));  

  

if (i == 2) //adds nc to mult[7] 

  

mult.set(7, mult.get(7) + o_1.get(i) * o_2.get(i + 3));  

  

if (i == 3) //adds md to mult[7] 

  

mult.set(7, mult.get(7) + o_1.get(i) * o_2.get(i + 1));  

  

if (i == 4) //subtracts el from mult[7] 

  

mult.set(7, mult.get(7) - o_1.get(i) * o_2.get(i - 1));  

  

if (i == 5) //subtracts fk from mult[7] 

  

mult.set(7, mult.get(7) - o_1.get(i) * o_2.get(i - 3));  

  

if (i == 6) //adds gj to mult[7] 

  

mult.set(7, mult.get(7) + o_1.get(i) * o_2.get(i - 5));  

  

if (i == 7) //adds hi to mult[7] 

  

mult.set(7, mult.get(7) + o_1.get(i) * o_2.get(i - 7));  

  

}  

  

return mult; 

  

}  

  

   

  

// application file     

  

#include <iostream>     

  

using namespace std;  

  

int main()  

  

{  

    char x; 

do{ 

Octonion oof, ouch;  

  

oof.input(); 

oof.output(); 

cout<<endl; 

  

  

ouch.input(); 

ouch.output(); 

cout<<endl; 

  

  

Octonion w;  

  

w = oof * ouch; //multiplies oof and ouch 

  

cout << "The product of these two octonions is: "; 

w.output(); 

cout<<endl<<"Would you like to multiply another two octonions? (y/n)"; 

cin>>x; 

} while (x == 'y'); 

} 
