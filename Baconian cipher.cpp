#include <iostream>
#include<cmath>
using namespace std;
// FCI – Programming 1 – 2018 - Assignment 2
// Program Name: baconian cipher.cpp
// Last Modification Date: 01/03/2018
// Author1 and ID and Group: Ahmad Khaled Fawzy  20170377 G14
// Author2 and ID and Group: Omar Khaled Ali 20170374 G14
// Teaching Assistant: xxxxx xxxxx
// Purpose:encode and decode messages
int main(){
    int array[5];
    int finalNum=0;
    int exponent=0;
    char alphabet[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    string decodedText,codedText,decider;
    cout<<endl<<"welcome user"<<endl<<"1-cipher a message"<<endl<<"2-decipher a message"<<endl<<"3-end"<<endl;
    cin>>decider;
    if(decider=="1")
    {
        cout<<"enter text to encode: ";
        cin.ignore();
        getline(cin,decodedText);
        for(unsigned int i=0 ; i<decodedText.size() ; i++)
        {
            if(int(decodedText[i])>=65 && int(decodedText[i])<=90)
            {
                decodedText[i]+=32;
            }
        }
        for(unsigned int i=0 ; i<decodedText.size() ; i++)
        {
            if(decodedText[i]==' ')
            {
                cout<<" ";
            }
            for(int j=0 ; j<26 ; j++)
            {
                if(decodedText[i]==alphabet[j])
                {
                    string binary=" ";
                    int k=j;
                    while(k>0 || binary.size()<=5)
                    {
                        binary=char(k%2)+binary;
                        k/=2;
                    }
                    while(k<5)
                    {
                        if(binary[k]==char(0))
                            binary[k]='a';
                        else
                            binary[k]='b';
                        k++;

                    }
                cout<<binary<<" ";
                }

            }

        }
        cout<<endl;
        main();
    }
    if(decider=="2")
    {
        int l=0;
        cout<<"enter text to decode: ";
        cin.ignore();
        getline(cin,codedText);
        for(unsigned int i=0 ; i<codedText.size() ; i+=5)
        {
            exponent=0;
            finalNum=0;
            for(int j=0 ; j<5 ; j++)
            {
                if(codedText[l]==' ')
                    l++;
                if(codedText[l]=='a')
                    array[j]=0;
                if(codedText[l]=='b')
                    array[j]=1;
                l++;

            }
            for(int k=4 ; k>=0 ; k--)
            {
                array[k]=array[k]*pow(2,exponent);
                exponent++;
                finalNum+=array[k];
            }
            cout<<alphabet[finalNum];

        }
        main();
    }
    if(decider=="3")
        {
            cout<<endl<<"Goodbye"<<endl;
        }
    else
    {
        cout<<"choose from the list"<<endl;
        main();
    }

 }
