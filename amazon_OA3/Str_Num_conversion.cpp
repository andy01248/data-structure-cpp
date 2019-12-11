#include<string>
#include<vector>
#include<iostream>

using namespace  std;

vector<int> str_to_num_conversion(string input){
    vector<int> res;
    for (int i=0; i<input.length();i++){
        if (isalpha(input[i])) {
            int temp=(int)input[i]-64;
        res.push_back(temp);
        cout<<temp<<" ";
        }
        else{
            cout<<" "<<input[i]<<"\n";
        }        
    }
    cout<<endl;
    return res;
}

 vector<char> num_to_str_conversion(string input){
    vector<char> res;
    string temp;
    for (int i=0; i<input.size();i++){
        if (isnumber(input[i])) {
            temp+=input[i];
        }
        else{
            int value = stoi(temp);
            char character = 'A'+value-1;
            cout<<character<<" ";
            res.push_back(character);
            temp="";
        }        
    }
    cout<<endl;
    return res;
}

 vector<char> res_conversion(string input){
    vector<char> res;
    string strNum;
    int number_indi=0; //ensure next is number
    vector<int> flag; //0 for + 1 for -
    vector<int> storeNumbers; //store the number in order
    vector<int>storeChar;
    for (int i=0; i<input.size();i++){
        if (isalpha(input[i])) {
            storeChar.push_back(input[i]);
        }
        else if(input[i]=='-')  flag.push_back(1);
        else if(input[i]=='+')  flag.push_back(0);
        else if(isnumber(input[i])){
            strNum+=input[i];
            number_indi=1;
        }
        else{
            if (number_indi==1){
            int value = stoi(strNum);
            storeNumbers.push_back(value);
            strNum="";
            number_indi=0;
            }
        }        
    }
    for (int i =0; i<flag.size();i++){
        if (flag[i]==0) {
            char answer = storeChar[i]+storeNumbers[i];
            if(int(answer)>int('Z')){
                answer -= 26;
            }
            res.push_back(answer);
        }
        else   {
            char answer = storeChar[i]-storeNumbers[i];
            if(int(answer)<int('A')){
                answer+= 26;
            }
            res.push_back(answer);

        }
        cout<< res[i]<<" ";
    }
    cout<<endl;
    return res;
}

int main(){

    //STRING -> numbers 
    cout<<"String Inputs : "<<"\n";
    string str_input;
    getline(cin,str_input);
    vector<int> num_output;
    num_output = str_to_num_conversion(str_input);

    //conversion with relationship
    cout<<"Conversion Inputs : "<<"\n";
    string all_input;
    getline(cin,all_input);
    all_input+=" ";
    vector<char> res_output;
    res_output = res_conversion(all_input);

    //numbers -> string
    cout<<"Number Inputs : "<<"\n";
    string num_input;
    getline(cin,num_input);
    num_input+=" ";
    vector<char> str_output;
    str_output = num_to_str_conversion(num_input);
    
    

}

