#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;


int main(int argc, char* argv[]){
    setlocale(LC_ALL,"Russian" );
    stack <double> calc;
    cout.precision(2);
    bool err = false;
    for (int i = 1; i < argc; i++){
        string op = argv[i];
        if (op == "+" && !calc.empty()){
            double tmp1, tmp2;
            tmp2 = calc.top();
            calc.pop();
            tmp1 = calc.top();
            calc.pop();
            calc.push((tmp1 + tmp2));
        } else if (op == "*" && !calc.empty()){
            double tmp1, tmp2;
            tmp2 = calc.top();
            calc.pop();
            tmp1 = calc.top();
            calc.pop();
            calc.push((tmp1 * tmp2));
        } else if (op == "-" && !calc.empty()){
            double tmp1, tmp2;
            tmp2 = calc.top();
            calc.pop();
            tmp1 = calc.top();
            calc.pop();
            calc.push((tmp1 - tmp2));
        } else if (op == "/" && !calc.empty()){
            double tmp1, tmp2;
            tmp2 = calc.top();
            if (tmp2 == 0){
                cout << "Ошибка! Делить на 0 нельзя!" << '\n';
                err = true;
                return 0;
            }
            calc.pop();
            tmp1 = calc.top();
            calc.pop();
            calc.push(tmp1/tmp2);
        } else if (op != "+" && op != "*" && op != "-" && op != "/"){
            string s = argv[i];
            double x = 0;
            int i = 0;
            while (s[i] != '.' && s[i] != ',' && i < s.size()){
                i++;
            }
            int k = i;
            int k1 = -1;
            for (int j = k + 1; j < s.size(); j++){
                x += (s[j] - '0') * pow(10, k1);
                k1--;
            }
            k1 = 0;
            for (int j = k - 1; j >= 0; j--, k1++){
                x += (s[j] - '0') * pow(10, k1);
            }
            calc.push(x);
        }
    }
    if(err == false)
        cout << calc.top() << endl;
    return 0;
}

//C:\Users\User\Desktop\Calc\bin\Debug\Calc.exe
